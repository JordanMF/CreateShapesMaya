//
//  Commons.h
//  OpenGLShapes
//
//  Created by Jordan Issa on 05/01/2017.
//  Copyright © 2017 Jordan Issa. All rights reserved.
//

#ifndef Commons_h
#define Commons_h

#if defined (_WIN32)
    #if defined (_WIN64)
#include <windows.h>
#include <GL/gl.h>
    #endif
#endif

#include <OpenGL/gl.h>
#include <math.h>
#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <maya/MUintArray.h>
#include <maya/MPointArray.h>

#define ARRLENGTH 36

struct glFloat3
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    
    glFloat3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    
    glFloat3(GLfloat _x, GLfloat _y, GLfloat _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    
    glFloat3 operator+ (const glFloat3& v1)
    {
        glFloat3 result;
        result.x = this->x + v1.x;
        result.y = this->y + v1.y;
        return result;
    };
};

struct glFloat4
{
    GLfloat angle;
    GLfloat x;
    GLfloat y;
    GLfloat z;
    
    glFloat4()
    {
        angle = 0.0f;
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    
    glFloat4(GLfloat _angle, GLfloat _x, GLfloat _y, GLfloat _z)
    {
        angle = _angle;
        x = _x;
        y = _y;
        z = _z;
    }
};

static float bbData[][3] =
{
    { -0.18f, 0.f, -0.71f},
    {  0.18f, 0.f, -0.71f},
    {  0.18f, 0.f,  0.31f},
    { -0.18f, 0.f,  0.31f},
    { -0.18f, 0.f, -0.71f},
    {  0.18f, 0.f, -0.71f},
    {  0.18f, 0.f,  0.31f},
    { -0.18f, 0.f,  0.31f}
};

// Index buffer for Wireframe drawing in Dx and Core Profile
static unsigned short bbWireIndices[] =
{
    0,1,
    1,2,
    2,3,
    3,0,
    4,5,
    5,6,
    6,7,
    7,4,
    0,4,
    1,5,
    2,6,
    3,7
};

struct Vertex
{
    float x, y, z;
    
};

struct ShapeData
{
    ShapeData() : vertices(0, MPoint(0.0f, 0.0f, 0.0f, 1.0f)), numVertices(0), indices(0), numIndices(0), numTotalVerts(0), numTotalIndices(0) {}
    
    MPointArray vertices;
    unsigned int numVertices;
    
    MUintArray* indices;
    unsigned int numIndices;
    
    unsigned int numTotalVerts;
    unsigned int numTotalIndices;
};

#endif
