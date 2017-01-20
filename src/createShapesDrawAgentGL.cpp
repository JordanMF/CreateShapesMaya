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
    
    //    glBegin(GL_TRIANGLE_FAN);
    //    int i;
    //    int last = soleCount - 1;
    //    for ( i = 0; i < last; ++i )
    //    {
    //        glNormal3f(0.0f, 1.0f, 0.0f );
    //        glVertex3f(sole[i][0],
    //                   sole[i][1],
    //                   sole[i][2]);
    //    }
    //    glEnd();
    //    glBegin(GL_TRIANGLE_FAN);
    //    last = heelCount - 1;
    //    for (i = 0; i < last; ++i)
    //    {
    //        glNormal3f(0.0f, 1.0f, 0.0f);
    //        glVertex3f(heel[i][0],
    //                   heel[i][1],
    //                   heel[i][2]);
    //    }
    //    glEnd();
    
//    glPushAttrib(GL_CURRENT_BIT);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glDepthMask(GL_FALSE);
    
    //MColor solidColour, wireColour;
    
    //DrawReflection(m_srcPoint, m_destPoint);
    DrawDisc(1.0f, 32, true);
    //DrawCube(1, 1, 1, glFloat3(0.0, 0.0, 0.0), glFloat4(0.0, 0.0, 0.0, 0.0f), 255, 0, 0, true);
    //DrawCube(glFloat3(0.0, 0.0, 0.0), glFloat4(0.0, 0.0, 0.0, 0.0f), 255, 0, 0, true);
    
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
    //
    //    // draw wire
    //    glBegin(GL_LINES);
    //    int i;
    //    int last = soleCount - 1;
    //    for (i = 0; i < last; ++i)
    //    {
    //        glVertex3f(sole[i][0],
    //                   sole[i][1],
    //                   sole[i][2]);
    //        glVertex3f(sole[i+1][0],
    //                   sole[i+1][1],
    //                   sole[i+1][2]);
    //    }
    //    last = heelCount - 1;
    //    for (i = 0; i < last; ++i)
    //    {
    //        glVertex3f(heel[i][0],
    //                   heel[i][1],
    //                   heel[i][2]);
    //        glVertex3f(heel[i+1][0],
    //                   heel[i+1][1],
    //                   heel[i+1][2]);
    //    }
    //    glEnd();
    
//    glPushAttrib(GL_CURRENT_BIT);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glDepthMask(GL_FALSE);
    
    //MColor solidColour, wireColour;
    
    //DrawReflection(m_srcPoint, m_destPoint);
    DrawDisc(1.0f, 32, false);
    //DrawCube(1, 1, 1, glFloat3(0.0, 0.0, 0.0), glFloat4(0.0, 0.0, 0.0, 0.0f), 255, 0, 0, false);
    //DrawCube(glFloat3(0.0, 0.0, 0.0), glFloat4(0.0, 0.0, 0.0, 0.0f), 255, 0, 0, false);
    
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

//void CreateShapesDrawAgentGL::DrawCube(GLfloat width, GLfloat height, GLfloat depth, glFloat3 position, glFloat4 rotation, GLubyte r, GLubyte g, GLubyte b, bool filled)
void CreateShapesDrawAgentGL::DrawCube(glFloat3 position, glFloat4 rotation, GLubyte r, GLubyte g, GLubyte b, bool filled)
{
//    int renderState = filled ? GL_TRIANGLES : GL_LINE_STRIP;
//    
//    if (filled)
//    {
//        glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
//    }
//    else
//    {
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE_STRIP);
//    }
//    glBegin(renderState);
//        int last = cubeVertsCount - 1;
//        for (int i = 0; i < last; ++i)
//        {
//            //glNormal3f(0.0f, 1.0f, 0.0f);
//            glVertex3f(cubeVertices[i][0], cubeVertices[i][1], cubeVertices[i][2]);
//        }
//    glEnd();
}
