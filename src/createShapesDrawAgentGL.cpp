//
//  CreateShapesDrawAgentGL.cpp
//  CreateShapes
//
//  Created by Jordan Issa on 11/01/2017.
//
//

#include "createShapesDrawAgentGL.h"

void CreateShapesDrawAgentGL::beginDraw(const MHWRender::MDrawContext& context, MHWRender::MShaderInstance* passShaderOverride)
{
    CreateShapesDrawAgent::beginDraw(context, passShaderOverride);
    
    if (!mShaderOverride)
    {
        // set world view matrix
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadMatrixd(mWorldViewMatrix.matrix[0]);
        
        // set projection matrix
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadMatrixd(mProjectionMatrix.matrix[0]);
        glPushAttrib( GL_CURRENT_BIT );
    }
}

void CreateShapesDrawAgentGL::endDraw()
{
    if (!mShaderOverride)
    {
        glPopAttrib();
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
    }
    
    CreateShapesDrawAgent::endDraw();
}

void CreateShapesDrawAgentGL::drawShaded()
{
    /// set color
    glColor4fv(&(mColor.r));
    
//    glPushAttrib(GL_CURRENT_BIT);
    //    glEnable(GL_BLEND);
    //    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //    glDepthMask(GL_FALSE);
        
        //MColor solidColour, wireColour;
        
        //DrawReflection(m_srcPoint, m_destPoint);
        DrawDisc(1.0f, 32, true);
        
    //    glDepthMask(GL_TRUE);
    //    glDisable(GL_BLEND);
//    glPopAttrib();
}

void CreateShapesDrawAgentGL::drawBoundingBox()
{
    // set color
    glColor4fv(&(mColor.r));
    
    const float* bottomLeftFront = bbData[0];
    const float* topLeftFront = bbData[4];
    const float* bottomRightFront = bbData[1];
    const float* topRightFront = bbData[5];
    const float* bottomLeftBack = bbData[3];
    const float* topLeftBack = bbData[7];
    const float* bottomRightBack = bbData[2];
    const float* topRightBack = bbData[6];
    
    glBegin(GL_LINES);
    
    // 4 Bottom lines
    //
    glVertex3fv(bottomLeftFront);
    glVertex3fv(bottomRightFront);
    glVertex3fv(bottomRightFront);
    glVertex3fv(bottomRightBack);
    glVertex3fv(bottomRightBack);
    glVertex3fv(bottomLeftBack);
    glVertex3fv(bottomLeftBack);
    glVertex3fv(bottomLeftFront);
    
    // 4 Top lines
    //
    glVertex3fv(topLeftFront);
    glVertex3fv(topRightFront);
    glVertex3fv(topRightFront);
    glVertex3fv(topRightBack);
    glVertex3fv(topRightBack);
    glVertex3fv(topLeftBack);
    glVertex3fv(topLeftBack);
    glVertex3fv(topLeftFront);
    
    // 4 Side lines
    //
    glVertex3fv(bottomLeftFront);
    glVertex3fv(topLeftFront);
    glVertex3fv(bottomRightFront);
    glVertex3fv(topRightFront);
    glVertex3fv(bottomRightBack);
    glVertex3fv(topRightBack);
    glVertex3fv(bottomLeftBack);
    glVertex3fv(topLeftBack);
    
    glEnd();
}

void CreateShapesDrawAgentGL::drawWireframe()
{
    // set color
    glColor4fv(&(mColor.r));
    
//    glPushAttrib(GL_CURRENT_BIT);
    //    glEnable(GL_BLEND);
    //    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //    glDepthMask(GL_FALSE);
    
        //MColor solidColour, wireColour;
        
        //DrawReflection(m_srcPoint, m_destPoint);
        DrawDisc(1.0f, 32, false);
        
    //    glDepthMask(GL_TRUE);
    //    glDisable(GL_BLEND);
//    glPopAttrib();
}

void CreateShapesDrawAgentGL::DrawDisc(float radius, int divisions, bool filled)
{
    int renderstatuse = filled ? GL_POLYGON : GL_LINE_LOOP;
    float degreesPerDiv = 360.0f / divisions;
    float radiansPerDiv = degreesPerDiv * 0.01745327778f;
    MFloatPointArray points(divisions);
    for (int i = 0; i < divisions; i++)
    {
        float angle = i * radiansPerDiv;
        float x = cos(angle) * radius;
        float z = sin(angle) * radius;
        points[i].x = x;
        points[i].z = z;
    }
    
    glBegin(renderstatuse);
    for (int i = 0; i < divisions; i++)
    {
        glVertex3f(points[i].x, 0.0f, points[i].z);
    }
    glEnd();
}
