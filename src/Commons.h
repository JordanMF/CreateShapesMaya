//
//  Commons.h
//  OpenGLShapes
//
//  Created by Jordan Issa on 05/01/2017.
//  Copyright © 2017 Jordan Issa. All rights reserved.
//

#ifndef Commons_h
#define Commons_h

//#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <math.h>

#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

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
    glm::vec3 position;
};

struct ShapeData
{
    ShapeData() : vertices(0), numVertices(0), indices(0), numIndices(0) {}
    
    Vertex* vertices;
    GLuint numVertices;
    GLushort* indices;
    GLuint numIndices;
    
    GLsizeiptr vertexBufferSize() const { return numVertices * sizeof(vertices); }
    GLsizeiptr indexBufferSize() const { return numIndices * sizeof(GLushort); }
};

static float cubeVertices[][3] =
{
        // Front face
        // 0,1,2
        { -1.0f,  1.0f, -1.0f },
        {  1.0f,  1.0f, -1.0f },
        {  1.0f, -1.0f, -1.0f },
        //2,3,0
        {  1.0f, -1.0f, -1.0f },
        { -1.0f, -1.0f, -1.0f },
        { -1.0f,  1.0f, -1.0f },
    
        // Right face
        //0,3,4
        { -1.0f,  1.0f, -1.0f },
        { -1.0f, -1.0f, -1.0f },
        { -1.0f, -1.0f,  1.0f },
        //4,5,0
        { -1.0f, -1.0f,  1.0f },
        { -1.0f,  1.0f,  1.0f },
        { -1.0f,  1.0f, -1.0f },
    
        // Top face
        //0,5,6
        { -1.0f,  1.0f, -1.0f },
        { -1.0f,  1.0f,  1.0f },
        {  1.0f,  1.0f,  1.0f },
        //6,1,0
        {  1.0f,  1.0f,  1.0f },
        {  1.0f,  1.0f, -1.0f },
        { -1.0f,  1.0f, -1.0f },
    
        // Left face
        //1,6,7
        {  1.0f,  1.0f, -1.0f },
        {  1.0f,  1.0f,  1.0f },
        {  1.0f, -1.0f,  1.0f },
        //7,2,1
        { 1.0f, -1.0f,  1.0f },
        { 1.0f, -1.0f, -1.0f },
        { 1.0f,  1.0f, -1.0f },
    
        // Bottom face
        //7,4,3
        {  1.0f, -1.0f,  1.0f },
        { -1.0f, -1.0f,  1.0f },
        { -1.0f, -1.0f, -1.0f },
        //3,2,7
        { -1.0f, -1.0f, -1.0f },
        {  1.0f, -1.0f, -1.0f },
        {  1.0f, -1.0f,  1.0f },
    
        // Back face
        //4,7,6
        { -1.0f, -1.0f,  1.0f },
        {  1.0f, -1.0f,  1.0f },
        {  1.0f,  1.0f,  1.0f },
        //6,5,4
        {  1.0f, 1.0f,  1.0f },
        { -1.0f, 1.0f,  1.0f },
        { -1.0f, -1.0f, 1.0f },
};

static int cubeVertsCount = 36;

//static glFloat3 position;
//static MMatrix mat;

//static void SetScale(glFloat3 scale, MMatrix world)
//{
//    static float matrix[4][4];
//    
//    // Scale
//    for(int i = 0; i < 4; i++)
//    {
//        for(int j = 0; j < 4; j++)
//        {
//            if(i == 0 && j == 0)
//            {
//                world[i][j] = matrix[i][i] * scale.x;
//            }
//            if(i == 1 && j == 1)
//            {
//                world[i][j] = matrix[i][j] * scale.y;
//            }
//            if(i == 2 && j == 2)
//            {
//                world[i][j] = matrix[i][j] * scale.z;
//            }
//            if(i == 3 && j == 3)
//            {
//                world[i][j] = 1.0f;
//            }
//        }
//    }
//}

static glm::mat4 mProjection;
static glm::mat4 mTranslation;
static glm::mat4 mRotation;
static glm::mat4 mScale;
static glm::mat4 mModelTransform;
static glm::mat4 mFullTransform;

static glm::vec4 position;

static void SetCubeInfo(glm::mat4 modelMatrix, glm::vec3 pos, float rotAngle, glm::vec3 rotAxis, glm::vec3 aScale)
{
    position = glm::vec4(pos, 1.0f);
    glm::vec4 rotation = glm::vec4(rotAngle, rotAxis);
    glm::vec4 scale = glm::vec4(aScale, 0.0f);
    
    mScale = glm::scale(modelMatrix, aScale);
    scale = mScale * scale;
    
    mRotation = glm::rotate(modelMatrix, rotAngle, rotAxis);
    rotation = mRotation * rotation;
    
    mTranslation = glm::translate(modelMatrix, pos);
    position = mTranslation * position;
    
    mModelTransform = mTranslation * mRotation * mScale;
}

//static void SetCubeInfo(float arr[][3], MMatrix world, MVector pos, glFloat4 rot, glFloat3 scale)
//{
//    SetScale(scale, world);
//    
//    // Translate
//    for(int i = 0; i < 4; i++)
//    {
//        for(int j = 0; j < 4; j++)
//        {
//            if(j == 0)
//            {
//                world[i][j] = world[i][i] * pos.x;
//            }
//            else if(j == 1)
//            {
//                world[i][j] = world[i][j] * pos.y;
//            }
//            else if(j == 2)
//            {
//                world[i][j] = world[i][j] * pos.z;
//            }
//            if(i == 3)
//            {
//                world[i][j] = 0.0f;
//                
//                if(j == 3)
//                {
//                    world[i][j] = 1.0f;
//                }
//            }
//        }
//    }
    
//    world[0][0]=sinf(scale.x);  world[0][1]=0.0f;           world[0][2]=0.0f;           world[0][3]=pos.x;
//    world[1][0]=0.0f;           world[1][1]=sinf(scale.y);  world[1][2]=0.0f;           world[1][3]=pos.y;
//    world[2][0]=0.0f;           world[2][1]=0.0f;           world[2][2]=sinf(scale.z);  world[2][3]=pos.z;
//    world[3][0]=0.0f;           world[3][1]=0.0f;           world[3][2]=0.0f;           world[3][3]=1.0f;
//    
//    // Scale
//    mat[0][0] *= scale.x;
//    mat[1][1] *= scale.y;
//    mat[2][2] *= scale.z;
//    mat[3][3] = 1.0f;
//    
//    for(int ii = 0; ii < cubeVertsCount; ii++)
//    {
//        arr[ii][0] = arr[ii][0] * mat[0][0];
//        arr[ii][1] = arr[ii][1] * mat[1][1];
//        arr[ii][2] = arr[ii][2] * mat[2][2];
//    }
//    
//    // Translate
//    position = pos;
//    mat[0][3] += pos.x;
//    mat[1][3] += pos.y;
//    mat[2][3] += pos.z;
//    
//    for(int i = 0; i < cubeVertsCount; i++)
//    {
//        for(int jj = 0; jj < 3; jj++)
//        {
//            if(jj == 0)
//            {
//                arr[i][jj] = arr[i][jj] + pos.x;
//            }
//            else if(jj == 1)
//            {
//                arr[i][jj] = arr[i][jj] + pos.y;
//            }
//            else
//            {
//                arr[i][jj] = arr[i][jj] + pos.z;
//            }
//        }
//    }

    
//    // Scale
//    mat[0][0] *= scale.x;
//    mat[1][1] *= scale.y;
//    mat[2][2] *= scale.z;
//    mat[3][3] = 1.0f;
//    
//    for(int ii = 0; ii < cubeVertsCount; ii++)
//    {
//        arr[ii][0] = arr[ii][0] * mat[0][0];
//        arr[ii][1] = arr[ii][1] * mat[1][1];
//        arr[ii][2] = arr[ii][2] * mat[2][2];
//    }
//    
//    // Translate
//    position = pos;
//    mat[0][3] += pos.x;
//    mat[1][3] += pos.y;
//    mat[2][3] += pos.z;
//    
//    for(int i = 0; i < cubeVertsCount; i++)
//    {
//        for(int jj = 0; jj < 3; jj++)
//        {
//            if(jj == 0)
//            {
//                arr[i][jj] = arr[i][jj] + pos.x;
//            }
//            else if(jj == 1)
//            {
//                arr[i][jj] = arr[i][jj] + pos.y;
//            }
//            else
//            {
//                arr[i][jj] = arr[i][jj] + pos.z;
//            }
//        }
//    }
//}

// Create cube index buffer
//static unsigned short indices[] =
//{
//    0,1,2,
//    2,3,0,
//    
//    0,3,4,
//    4,5,0,
//    
//    0,5,6,
//    6,1,0,
//    
//    1,6,7,
//    7,2,1,
//    
//    7,4,3,
//    3,2,7,
//    
//    4,7,6,
//    6,5,4
//};

static unsigned short wireIndices[] =
{
    0,1,2,
    2,3,0,
    
    0,3,4,
    4,5,0,
    
    0,5,6,
    6,1,0,
    
    1,6,7,
    7,2,1,
    
    7,4,3,
    3,2,7,
    
    4,7,6,
    6,5,4
};

#endif
