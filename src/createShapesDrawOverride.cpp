//
//  CreateShapesDrawOverride.cpp
//  CreateShapes
//
//  Created by Jordan Issa on 10/01/2017.
//
//

#include "createShapesDrawOverride.h"

#include <maya/MFnDependencyNode.h>
#include <maya/MFloatArray.h>

CreateShapesDrawOverride::CreateShapesDrawOverride(const MObject& obj) : MHWRender::MPxDrawOverride(obj, CreateShapesDrawOverride::draw, false), mCustomBoxDraw(true)
, mExcludeFromPostEffects(false)
, mTransparencySort(false)
, mLastFrameStamp(0)
, fCreateShapes(obj)
, mBlendState(NULL)
{
    fModelEditorChangedCbId = MEventMessage::addEventCallback("modelEditorChanged", OnModelEditorChanged, this);
}

CreateShapesDrawOverride::~CreateShapesDrawOverride()
{
    if (mBlendState)
    {
        MHWRender::MStateManager::releaseBlendState(mBlendState);
        mBlendState = NULL;
    }
    
    if (fModelEditorChangedCbId != 0)
    {
        MMessage::removeCallback(fModelEditorChangedCbId);
        fModelEditorChangedCbId = 0;
    }
}

void CreateShapesDrawOverride::OnModelEditorChanged(void *clientData)
{
    // Mark the node as being dirty so that it can update on display appearance
    // switch among wireframe and shaded.
    CreateShapesDrawOverride* ovr = static_cast<CreateShapesDrawOverride*>(clientData);
    if (ovr)
        MHWRender::MRenderer::setGeometryDrawDirty(ovr->fCreateShapes);
}

float CreateShapesDrawOverride::getMultiplier(const MDagPath& objPath) const
{
    // Retrieve value of) the size attribute from the node
    MStatus status;
    MObject CreateShapesNode = objPath.node(&status);
    if (status)
    {
        MPlug plug(CreateShapesNode, CreateShapes::size);
        if (!plug.isNull())
        {
            MDistance sizeVal;
            if (plug.getValue(sizeVal))
            {
                return (float)sizeVal.asCentimeters();
            }
        }
    }
    
    return 1.0f;
}

bool CreateShapesDrawOverride::isTransparentSort(const MDagPath& objPath) const
{
    MStatus status;
    MObject CreateShapesNode = objPath.node(&status);
    if (status)
    {
        MPlug plug(CreateShapesNode, CreateShapes::transparencySort);
        if (!plug.isNull())
        {
            bool isTransparent;
            if (plug.getValue(isTransparent))
            {
                return isTransparent;
            }
        }
    }
    
    return false;
}

float CreateShapesDrawOverride::getTransparency(const MDagPath& objPath) const
{
    // Retrieve value of) the transparency attribute from the node
    MStatus status;
    MObject CreateShapesNode = objPath.node(&status);
    if (status)
    {
        MPlug plug(CreateShapesNode, CreateShapes::transparency);
        if (!plug.isNull())
        {
            float transparencyVal;
            if (plug.getValue(transparencyVal))
            {
                return transparencyVal;
            }
        }
    }
    
    return 1.0f;
}

bool CreateShapesDrawOverride::isBounded(const MDagPath& /*objPath*/, const MDagPath& /*cameraPath*/) const
{
    return true;
}

MMatrix CreateShapesDrawOverride::transform(const MDagPath& objPath, const MDagPath& cameraPath) const
{
    // Update the transform matrix with the multiplier value,
    // this way, the matrices of) the draw context will already contain the multiplier factor.
    // That way the WorldViewProjection uniform of) the selection shader - which we do not have access to -
    // will be set properly.
    
    MMatrix transform = objPath.inclusiveMatrix();
    float multiplier = getMultiplier(objPath);
    
    transform[0][0] *= multiplier;
    transform[1][1] *= multiplier;
    transform[2][2] *= multiplier;

    return transform;
}

MBoundingBox CreateShapesDrawOverride::boundingBox(const MDagPath& objPath, const MDagPath& cameraPath) const
{
    MPoint corner1(-0.17, 0.0, -0.7);
    MPoint corner2(0.17, 0.0, 0.3);
    
    float multiplier = getMultiplier(objPath);
    corner1 = corner1 * multiplier;
    corner2 = corner2 * multiplier;
    
    CreateShapesDrawOverride* nonConstThis = (CreateShapesDrawOverride*)this;
    nonConstThis->mCurrentBoundingBox.clear();
    nonConstThis->mCurrentBoundingBox.expand( corner1 );
    nonConstThis->mCurrentBoundingBox.expand( corner2 );
    
    return mCurrentBoundingBox;
}

bool CreateShapesDrawOverride::disableInternalBoundingBoxDraw() const
{
    return mCustomBoxDraw;
}

bool CreateShapesDrawOverride::excludedFromPostEffects() const
{
    return mExcludeFromPostEffects;
}

bool CreateShapesDrawOverride::isTransparent() const
{
    return mTransparencySort;
}

MUserData* CreateShapesDrawOverride::prepareForDraw(const MDagPath& objPath, const MDagPath& cameraPath, const MHWRender::MFrameContext& frameContext, MUserData* oldData)
{
    // We only care about post effects when in shaded mode
    const unsigned int displayStyle = frameContext.getDisplayStyle();
    bool shadedMode = (displayStyle & MHWRender::MFrameContext::kGouraudShaded) || (displayStyle & MHWRender::MFrameContext::kFlatShaded);
    mExcludeFromPostEffects = !shadedMode;
    
    mTransparencySort = isTransparentSort(objPath);
    
    // Retrieve data cache (create if) does not exist)
    CreateShapesData* data = dynamic_cast<CreateShapesData*>(oldData);
    if (!data)
    {
        data = new CreateShapesData();
        data->mLastFrameStamp = 0;
    }
    
    // compute data and cache it
    data->fMultiplier = getMultiplier(objPath);
    
    MHWRender::DisplayStatus displayStatus = MHWRender::MGeometryUtilities::displayStatus(objPath);
    if ((displayStatus == MHWRender::kLead) || (displayStatus == MHWRender::kActive) || (displayStatus == MHWRender::kHilite) || (displayStatus == MHWRender::kActiveComponent))
    {
        MColor color = MHWRender::MGeometryUtilities::wireframeColor(objPath);
        
        data->fColor[0] = 1.0f;
        data->fColor[1] = 0.0f;
        data->fColor[2] = 0.0f;
    }
    else
    {
        data->fColor[0] = 1.0f;
        data->fColor[1] = 0.0f;
        data->fColor[2] = 0.0f;
    }
    data->fColor[3] = getTransparency(objPath);
    
    data->fCustomBoxDraw = mCustomBoxDraw;
    data->fCurrentBoundingBox = mCurrentBoundingBox;
    
    // Get the draw override information
    data->fDrawOV = objPath.getDrawOverrideInfo();
    
    // Get a blend state override
    if (!mBlendState)
    {
        MHWRender::MBlendStateDesc blendStateDesc;
        for(int i = 0; i < (blendStateDesc.independentBlendEnable ? MHWRender::MBlendState::kMaxTargets : 1); ++i)
        {
            blendStateDesc.targetBlends[i].blendEnable = true;
            blendStateDesc.targetBlends[i].sourceBlend = MHWRender::MBlendState::kSourceAlpha;
            blendStateDesc.targetBlends[i].destinationBlend = MHWRender::MBlendState::kInvSourceAlpha;
            blendStateDesc.targetBlends[i].blendOperation = MHWRender::MBlendState::kAdd;
            blendStateDesc.targetBlends[i].alphaSourceBlend = MHWRender::MBlendState::kOne;
            blendStateDesc.targetBlends[i].alphaDestinationBlend = MHWRender::MBlendState::kInvSourceAlpha;
            blendStateDesc.targetBlends[i].alphaBlendOperation = MHWRender::MBlendState::kAdd;
        }
        
        blendStateDesc.blendFactor[0] = 1.0f;
        blendStateDesc.blendFactor[1] = 1.0f;
        blendStateDesc.blendFactor[2] = 1.0f;
        blendStateDesc.blendFactor[3] = 1.0f;
        
        mBlendState = MHWRender::MStateManager::acquireBlendState(blendStateDesc);
    }
    data->mBlendState = mBlendState;
    
    return data;
}

void CreateShapesDrawOverride::addUIDrawables(const MDagPath& objPath, MHWRender::MUIDrawManager& drawManager, const MHWRender::MFrameContext& frameContext, const MUserData* data)
{
    drawManager.beginDrawable();
    
    if(drawShapes)
    {
        std::random_device rd;
        std::mt19937_64 gen(rd());
        std::uniform_real_distribution<float> dis(-20.0f, 20.0f);
        
        cout << &CreateShapes::parentMatrix;
        
        shape.GenerateCubes(50000, glFloat3(dis(gen), dis(gen), dis(gen)), glFloat3(1.0f, 1.0f, 1.0f));
        shape.GenerateCylinders(10000, glFloat3(dis(gen), 0.0f, dis(gen)));
        shape.GenerateCapsules(30000, glFloat3(dis(gen), 2.0f, dis(gen)));

        drawShapes = false;
    }

    drawManager.mesh(MHWRender::MUIDrawManager::kTriangles, shape.GetCubeVertices() , NULL, NULL, shape.GetCubeIndices(), NULL);
    drawManager.setColor(MColor(1.0f, 0.0f, 0.0f, 1.0f));
    drawManager.mesh(MHWRender::MUIDrawManager::kTriangles, shape.GetCylinderVertices(), NULL, NULL, shape.GetCylinderIndices(), NULL);
    drawManager.setColor(MColor(0.0f, 1.0f, 0.0f, 1.0f));
    drawManager.mesh(MHWRender::MUIDrawManager::kTriangles, shape.GetCapsuleVertices(), NULL, NULL, shape.GetCapsuleIndices(), NULL);
    
    drawManager.setColor(textColor);
    drawManager.setFontSize(MHWRender::MUIDrawManager::kSmallFontSize);
    drawManager.text(textPos, MString("Some Text"), MHWRender::MUIDrawManager::kCenter);
    
    drawManager.endDrawable();
}

//
// Main drawing routine
//
void CreateShapesDrawOverride::draw(const MHWRender::MDrawContext& context, const MUserData* data)
{
    // Get renderer
    MHWRender::MRenderer* theRenderer = MHWRender::MRenderer::theRenderer();
    if (!theRenderer)
    {
        return;
    }
    
    // Get user draw data
    const CreateShapesData* footData = dynamic_cast<const CreateShapesData*>(data);
    if (!footData)
    {
        return;
    }
    
    // Get DAG object draw override
    const MDAGDrawOverrideInfo& objectOverrideInfo = footData->fDrawOV;
    
    // Just return and draw nothing, if) it is overridden invisible
    if (objectOverrideInfo.fOverrideEnabled && !objectOverrideInfo.fEnableVisible)
    {
        return;
    }
    
    // If) in playback but hidden in playback, skip drawing
    bool animPlay = MAnimControl::isPlaying();
    bool animScrub = MAnimControl::isScrubbing();
    if (!objectOverrideInfo.fPlaybackVisible &&
        (animPlay || animScrub))
    {
        return;
    }
    
    // Check display styles to determine what modes to draw with
    //
    const unsigned int displayStyle = context.getDisplayStyle();
    
    bool drawAsBoundingbox = (displayStyle & MHWRender::MFrameContext::kBoundingBox) || (footData->fDrawOV.fLOD == MDAGDrawOverrideInfo::kLODBoundingBox);
    
    // Require shadeded draw
    bool drawShaded = ((displayStyle & MHWRender::MFrameContext::kGouraudShaded) || (displayStyle & MHWRender::MFrameContext::kFlatShaded));
    // Require wireframe draw
    bool drawWireframe = (displayStyle & MHWRender::MFrameContext::kWireFrame) > 0;
    
    // Templated, only draw wirefame and it is not selectale
    bool overideTemplated = objectOverrideInfo.fOverrideEnabled && (objectOverrideInfo.fDisplayType == MDAGDrawOverrideInfo::kDisplayTypeTemplate);
    if (overideTemplated)
    {
        drawWireframe = true;
    }
    
    // Override no shaded, only show wireframe
    bool overrideNoShaded = objectOverrideInfo.fOverrideEnabled && !objectOverrideInfo.fEnableShading;
    if (overideTemplated || overrideNoShaded)
    {
        drawShaded = false;
    }
    
    // If) we don't want to draw the bounds within this plugin
    // manually, then skip drawing altogether in bounding box mode
    // since the bounds draw is handled by the renderer and
    // doesn't need to be drawn here.
    //
//    if ( drawAsBoundingbox && !footData->fCustomBoxDraw )
//    {
//        drawAsBoundingbox = false;
//    }
    
    // For any viewport interactions switch to bounding box mode,
    // except when we are in playback. Uncomment to enable usage.
    if (context.inUserInteraction() || context.userChangingViewContext())
    {
        if (!animPlay && !animScrub)
        {
            //drawAsBoundingbox = true;
        }
    }
    
    // Check to see if) we are drawing with a shader override,
    // and look for any specific branching required for different passes
    // (e.g. for selection)
    //
    bool inSelection = false;
    bool inBeautyPass = false;
    bool inTransparencyPass = false;
    const MString beautyPassSemantic("shadedBeautyGraphSemantic");
    const MHWRender::MPassContext & passCtx = context.getPassContext();
    const MStringArray & passSem = passCtx.passSemantics();
    MHWRender::MShaderInstance* passShaderOverride = NULL;
    for (unsigned int i=0; i<passSem.length(); i++)
    {
        if (passSem[i] == MHWRender::MPassContext::kSelectionPassSemantic)
        {
            inSelection = true;
        }
        else if (passSem[i] == beautyPassSemantic)
        {
            inBeautyPass = true;
        }
        
        if (passCtx.hasShaderOverride())
        {
            passShaderOverride = passCtx.shaderOverrideInstance();
            
            // Update single-sided state and normal multiplier as needed
            passShaderOverride->setParameter("isSingleSided", (displayStyle & MHWRender::MFrameContext::kTwoSidedLighting) == 0);
            passShaderOverride->setParameter("mayaNormalMultiplier", -1.0f);
        }
        
        if (passSem[i] == MHWRender::MPassContext::kCullBackSemantic || passSem[i] == MHWRender::MPassContext::kCullFrontSemantic)
        {
            inTransparencyPass = true;
        }
    }
    
    // Get cached data
    float color[4] =
    {
        footData->fColor[0] * footData->fColor[3],
        footData->fColor[1] * footData->fColor[3],
        footData->fColor[2] * footData->fColor[3],
        footData->fColor[3]
    };
    
    bool requireBlending = false;
    
    if (!inSelection)
    {
        // Use some monotone version of) color to show "default material mode"
        //
        if (displayStyle & MHWRender::MFrameContext::kDefaultMaterial)
        {
        	color[0] = color[1] = color[2] = (color[0] + color[1] + color[2]) / 3.0f;
        }
        // Do some alpha blending if) in x-ray mode
        //
        if (displayStyle & MHWRender::MFrameContext::kXray)
        {
            // If) in beauty pass should still allow blending e.g. kMaterialOverrideSemantic
            requireBlending = !passShaderOverride;
            color[3] = 0.3f;
        }
    }
    
    //================================================
    // Set blend and raster state
    //================================================
    MHWRender::MStateManager* stateMgr = context.getStateManager();
    const MHWRender::MBlendState* pOldBlendState = NULL;
    const MHWRender::MRasterizerState* pOldRasterState = NULL;
    const MHWRender::MRasterizerState* rasterState = NULL;
    
    if(stateMgr && ((displayStyle & MHWRender::MFrameContext::kGouraudShaded) || (displayStyle & MHWRender::MFrameContext::kFlatShaded)))
    {
        // draw filled, and with blending if) required
        if (stateMgr && requireBlending)
        {
            if (footData->mBlendState)
            {
                pOldBlendState = stateMgr->getBlendState();
                stateMgr->setBlendState(footData->mBlendState);
            }
        }
        
        // If) the object is not draw as transparency,
        // override culling mode since we always want double-sided
        //
        if (!inTransparencyPass)
        {
            pOldRasterState = stateMgr ? stateMgr->getRasterizerState() : NULL;
            if (pOldRasterState)
            {
                
                MHWRender::MRasterizerStateDesc desc( pOldRasterState->desc() );
                // It's also possible to change this to kCullFront or kCullBack if) we
                // wanted to set it to that.
                MHWRender::MRasterizerState::CullMode cullMode = MHWRender::MRasterizerState::kCullNone;
                if (desc.cullMode != cullMode)
                {
                    // Just override the cullmode
                    desc.cullMode = cullMode;
                    rasterState = stateMgr->acquireRasterizerState(desc);
                    if (rasterState)
                    {
                        stateMgr->setRasterizerState(rasterState);
                    }
                }
            }
        }
    }
    
    //================================================
    // Start the draw work
    //================================================
    
    // Prepare draw agent, default using OpenGL
    CreateShapesDrawAgentGL& drawAgentRef = CreateShapesDrawAgentGL::getDrawAgent();
    CreateShapesDrawAgent* drawAgentPtr = &drawAgentRef;
    
    if (theRenderer->drawAPI() == MHWRender::kOpenGLCoreProfile)
    {
        CreateShapesDrawAgentCoreProfile& drawAgentRef = CreateShapesDrawAgentCoreProfile::getDrawAgent();
        drawAgentPtr = &drawAgentRef;
    }
    
    assert(drawAgentPtr);
    
    if (drawAgentPtr)
    {
        // Set color
        drawAgentPtr->setColor(MColor(color[0], color[1], color[2], color[3]));
        //drawAgentPtr->setColor(getColor);
        // Set matrix
        drawAgentPtr->setMatrix(context);
        
        drawAgentPtr->beginDraw(context, passShaderOverride);
        
        if (drawAsBoundingbox)
        {
            // If) it is in bounding boxz mode, draw only bounding box wireframe, nothing else
            drawAgentPtr->drawBoundingBox();
        }
        else
        {
            if (drawWireframe || overideTemplated || overrideNoShaded)
            {
                drawAgentPtr->drawWireframe();
            }
            if (!overideTemplated && !overrideNoShaded  && drawShaded)
            {
                drawAgentPtr->drawShaded();
                //drawAgentPtr->drawWireframe();
            }
        }
        
        drawAgentPtr->endDraw();
    }
    
    //================================================
    // End the draw work
    //================================================
    
    if (passShaderOverride)
    {
        theRenderer->getShaderManager()->releaseShader(passShaderOverride);
    }
    
    //================================================
    // Restore old blend state and old raster state
    //================================================
    if(stateMgr && (displayStyle & MHWRender::MFrameContext::kGouraudShaded  || displayStyle & MHWRender::MFrameContext::kFlatShaded))
    {
        if (stateMgr && pOldBlendState)
        {
            stateMgr->setBlendState(pOldBlendState);
            stateMgr->releaseBlendState(pOldBlendState);
        }
        if (pOldRasterState)
        {
            stateMgr->setRasterizerState(pOldRasterState);
            stateMgr->releaseRasterizerState(pOldRasterState);
        }
        if (rasterState)
        {
            stateMgr->releaseRasterizerState(rasterState);
            rasterState = NULL;
        }
    }
}

