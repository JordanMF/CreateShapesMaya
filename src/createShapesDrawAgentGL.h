//
//  CreateShapesDrawAgentGL.h
//  CreateShapes
//
//  Created by Jordan Issa on 11/01/2017.
//
//

#ifndef CreateShapesDrawAgentGL_h
#define CreateShapesDrawAgentGL_h

#include "createShapesDrawAgent.h"
//#include "Commons.h"

class CreateShapesDrawAgentGL : public CreateShapesDrawAgent
{
public:
    static CreateShapesDrawAgentGL& getDrawAgent() { static CreateShapesDrawAgentGL obj; return obj; }
    
    void drawShaded() override;
    void drawBoundingBox() override;
    void drawWireframe() override;
    void beginDraw(const MHWRender::MDrawContext& context, MHWRender::MShaderInstance* passShaderOverride) override;
    void endDraw() override;
    
    void DrawDisc(float radius, int divisions, bool filled);
    
    void setMatrix(const MHWRender::MDrawContext& context) override
    {
        // Get  world view matrix
        MStatus status;
        mWorldViewMatrix = context.getMatrix(MHWRender::MFrameContext::kWorldViewMtx, &status);
        if (status != MStatus::kSuccess) return;
        // Get projection matrix
        mProjectionMatrix = context.getMatrix(MHWRender::MFrameContext::kProjectionMtx, &status);
    }
    
private:
    CreateShapesDrawAgentGL() {}
    ~CreateShapesDrawAgentGL() override {}
    CreateShapesDrawAgentGL(const CreateShapesDrawAgentGL& v) {}
    CreateShapesDrawAgentGL operator = (const CreateShapesDrawAgentGL& v) { return *this; }
    MMatrix mWorldViewMatrix;
    MMatrix mProjectionMatrix;
    
};

#endif
