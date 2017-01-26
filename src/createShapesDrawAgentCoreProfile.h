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
        
        mWorldViewProjMatrix = context.getMatrix(MHWRender::MFrameContext::kWorldViewProjMtx, &status);
    }
    
    bool releaseCoreProfileResources();
private:
    GLuint mShaderProgram;
    GLint mWVPIndex;
    GLint mColorIndex;
    GLint mVtxAttrib;
    
    GLuint mBBoxVAO;
    
    GLuint mBoundingboxVertexBuffer;
    GLuint mBoundingboxIndexBuffer;

    MMatrix mWorldViewProjMatrix;
    
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
    // VAOs
    , mBBoxVAO(0)
    // Draw buffers
    , mBoundingboxVertexBuffer(0)
    , mBoundingboxIndexBuffer(0)
    , mInitialized(false)
    , mValid(false)
    {}
    
    ~CreateShapesDrawAgentCoreProfile() override {}
    CreateShapesDrawAgentCoreProfile(const CreateShapesDrawAgentCoreProfile& v) {}
    CreateShapesDrawAgentCoreProfile operator = (const CreateShapesDrawAgentCoreProfile& v) { return *this; }
};

#endif
