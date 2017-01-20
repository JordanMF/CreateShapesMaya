//
//  CreateShapesDrawAgentCoreProfile.h
//  CreateShapes
//
//  Created by Jordan Issa on 11/01/2017.
//
//

#ifndef CreateShapesDrawAgentCoreProfile_h
#define CreateShapesDrawAgentCoreProfile_h

#include "createShapesDrawAgent.h"
#include "ShapeGenerator.h"

class CreateShapesDrawAgentCoreProfile : public CreateShapesDrawAgent
{
public:
    static CreateShapesDrawAgentCoreProfile& getDrawAgent() { static CreateShapesDrawAgentCoreProfile obj; return obj; }
    
    void drawShaded() override;
    void drawBoundingBox() override;
    void drawWireframe() override;
    void beginDraw(const MHWRender::MDrawContext& context, MHWRender::MShaderInstance* passShaderOverride) override;
    void endDraw() override;
    
    void setMatrix(const MHWRender::MDrawContext& context) override
    {
        // Get  world view projection matrix
        MStatus status;
        
        mWorldMatrix = context.getMatrix(MHWRender::MFrameContext::kWorldMtx, &status);
        mModelWorldMatrix = context.getMatrix(MHWRender::MFrameContext::kWorldInverseMtx, &status);
        mViewMatrix = context.getMatrix(MHWRender::MFrameContext::kViewMtx, &status);
        mProjMatrix = context.getMatrix(MHWRender::MFrameContext::kProjectionMtx, &status);
        mViewProjMatrix = context.getMatrix(MHWRender::MFrameContext::kViewProjMtx, &status);
        
        mWorldViewProjMatrix = context.getMatrix(MHWRender::MFrameContext::kWorldViewProjMtx, &status);
    }
    
    bool releaseCoreProfileResources();
private:
    GLuint mShaderProgram;
    GLint mWVPIndex;
    GLint mColorIndex;
    GLint mVtxAttrib;
    GLint mPos;
    
    ShapeData cube = ShapeGenerator::GenerateCube();
    
    GLuint mBBoxVAO;
    GLuint mCubeWireframeVAO;
    GLuint mCubeShadedVAO;
    
    GLuint mBoundingboxVertexBuffer;
    GLuint mBoundingboxIndexBuffer;
    GLuint mCubeVertexBuffer;
    GLuint mCubeWireIndexBuffer;
    GLuint mCubeShadedIndexBuffer;
    
    MMatrix mWorldMatrix;
    MMatrix mModelWorldMatrix;
    MMatrix mViewMatrix;
    MMatrix mProjMatrix;
    MMatrix mViewProjMatrix;
    MMatrix mWorldViewProjMatrix;
    
    glm::mat4 world;
    glm::mat4 modelWorld;
    glm::mat4 worldToProj;
    glm::mat4 worldToView;
    glm::mat4 proj;
    glm::mat4 viewProj;
    
    
    bool mInitialized;
    bool mValid;
    bool initShadersCoreProfile();
    bool initBuffersCoreProfile();
    void setupUniforms();
private:
    CreateShapesDrawAgentCoreProfile()
    // Shader program data
    : mShaderProgram(0)
    , mWVPIndex(0)
    , mColorIndex(0)
    , mVtxAttrib(0)
    , mPos(0)
    // VAOs
    , mBBoxVAO(0)
    , mCubeWireframeVAO(0)
    , mCubeShadedVAO(0)
    // Draw buffers
    , mBoundingboxVertexBuffer(0)
    , mBoundingboxIndexBuffer(0)
    , mCubeVertexBuffer(0)
    , mCubeWireIndexBuffer(0)
    , mCubeShadedIndexBuffer(0)
    , mInitialized(false)
    , mValid(false)
    {}
    
    ~CreateShapesDrawAgentCoreProfile() override {}
    CreateShapesDrawAgentCoreProfile(const CreateShapesDrawAgentCoreProfile& v) {}
    CreateShapesDrawAgentCoreProfile operator = (const CreateShapesDrawAgentCoreProfile& v) { return *this; }
};

#endif
