//
//  CreateShapesBaseDrawAgent.h
//  CreateShapes
//
//  Created by Jordan Issa on 10/01/2017.
//
//

#ifndef createShapesDrawAgent_h
#define createShapesDrawAgent_h

// Viewport 2.0 includes
#include <maya/MDrawRegistry.h>
#include <maya/MPxDrawOverride.h>
#include <maya/MDrawContext.h>
#include <maya/MHWGeometryUtilities.h>
#include <maya/MShaderManager.h>
#include <maya/MAnimControl.h>

#include <vector>
#include "Commons.h"

class CreateShapesDrawAgent
{
public:
    CreateShapesDrawAgent() : mDrawContext(NULL), mShaderOverride(NULL) {}
    virtual ~CreateShapesDrawAgent() {}
    
    virtual void drawShaded() = 0;
    virtual void drawBoundingBox() = 0;
    virtual void drawWireframe() = 0;
    
    virtual void setMatrix(const MHWRender::MDrawContext& context) = 0;
    
    virtual void beginDraw(const MHWRender::MDrawContext& context, MHWRender::MShaderInstance* passShaderOverride)
    {
        mDrawContext = &context;
        mShaderOverride = passShaderOverride;
        
        // Sample code to debug geometry streams required for the override
        // shader.
        if (mShaderOverride)
        {
            mShaderOverride->bind(*mDrawContext);
            mShaderOverride->updateParameters(*mDrawContext);
            mShaderOverride->activatePass(*mDrawContext, 0);
        }
    }
    
    //void SetCubeInfo(std::vector<std::vector<float> > vec, float w, float h, float d, glFloat3 position, glFloat4 rotation, GLubyte r, GLubyte g, GLubyte b);
    
    //std::vector<std::vector<float> > GetCubeInfo() { return cubeVertices; }
    
    //static std::vector<std::vector<float> > cubeVertices;
    //float x, y, z;
    
    //std::vector<std::vector<float> > vec
    
    //virtual void SetCubeInfo(float vec[][3], float w, float h, float d);
    
    //void SetSole(float w, float h,float d);
    
    virtual void endDraw()
    {
        if (mShaderOverride)
        {
            mShaderOverride->unbind(*mDrawContext);
        }
        
        mDrawContext = NULL;
        mShaderOverride = NULL;
    }
    
    void setColor(const MColor& color) { mColor = color; }
    
protected:
    const MHWRender::MDrawContext* mDrawContext;
    MHWRender::MShaderInstance* mShaderOverride;
    MColor mColor;
    
    //const int cubeVertsCount = 36;
};

#endif
