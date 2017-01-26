//
//  ShapeData.cpp
//  ReflectionLocator
//
//  Created by Jordan Issa on 19/01/2017.
//
//

#include "ShapeGenerator.h"

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a);

ShapeData ShapeGenerator::GenerateCubes(int numCubes, float distX, float distY, float distZ)
{
    if(addedInitialCube == false)
    {
        AddCubeVertex(-0.5f, -0.5f, 0.5, 1.0f);
        AddCubeVertex(0.5f, -0.5f, 0.5, 1.0f);
        AddCubeVertex(-0.5f, 0.5f, 0.5, 1.0f);
        AddCubeVertex(0.5f, 0.5f, 0.5, 1.0f);
        AddCubeVertex(-0.5f, 0.5f, -0.5, 1.0f);
        AddCubeVertex(0.5f, 0.5f, -0.5, 1.0f);
        AddCubeVertex(-0.5f, -0.5f, -0.5, 1.0f);
        AddCubeVertex(0.5f, -0.5f, -0.5, 1.0f);
        AddCubeVertex(0.5f, -0.5f, 0.5, 1.0f);
        AddCubeVertex(0.5f, -0.5f, -0.5, 1.0f);
        AddCubeVertex(-0.5f, -0.5f, -0.5, 1.0f);
        AddCubeVertex(-0.5f, -0.5f, 0.5, 1.0f);
    }
    
        unsigned int cubeIndices[] =
        {
            0, 1, 2,
            2, 1, 3,
            2, 3, 4,
            4, 3, 5,
            4, 5, 6,
            6, 5, 7,
            6, 7, 0,
            0, 7, 1,
            1, 7, 3,
            3, 7, 5,
            6, 0, 4,
            4, 0, 2,
        };
    
    cubeRet.numVertices = cubeRet.vertices.length();
    cubeRet.numTotalVerts = cubeRet.numVertices;
    
    cubeRet.numIndices = sizeof(cubeIndices) / sizeof(*cubeIndices);
    cubeRet.numTotalIndices = cubeRet.numIndices;
    
    cubeRet.indices = new MUintArray(cubeIndices, cubeRet.numIndices);
    
    addedInitialCube = true;
    
    if(distX <= 1.5f)
    {
        if(distX != 0.0f)
        {
            distX = 1.5f;
        }
        else
        {
            distX = 0.0f;
        }
    }
    if(distY <= 1.5f)
    {
        if(distY != 0.0f)
        {
            distY = 1.5f;
        }
        else
        {
            distY = 0.0f;
        }
    }
    if(distZ <= 1.5f)
    {
        if(distZ != 0.0f)
        {
            distZ = 1.5f;
        }
        else
        {
            distZ = 0.0f;
        }
    }
    
    if(addedInitialCube)
    {
        if(numCubes > 1)
        {
            for(int i = 1; i < numCubes; i++)
            {                
                for(int j = 0; j < cubeRet.numVertices; j++)
                {
                    cubeRet.vertices.append((cubeRet.vertices[j].x + (distX * i)), (cubeRet.vertices[j].y + (distY * i )), (cubeRet.vertices[j].z + (distZ * i)), 1.0f);
                    cubeRet.numTotalVerts++;
                }
                
                for(unsigned int k = 0; k < (cubeRet.numIndices); k++)
                {
                    cubeRet.indices->append((cubeIndices[k] + (cubeRet.numVertices * i)));
                    cubeRet.numTotalIndices++;
                }
            }
        }
    }
    
    return cubeRet;
}

ShapeData ShapeGenerator::GenerateCylinders(int numCylinders, float distX, float distY, float distZ)
{
    if(addedInitialCylinder == false)
    {
        AddCylinderVertex(0.87f, -1.0f, -0.5, 1.0f);
        AddCylinderVertex(0.5f, -1.0f, -0.87, 1.0f);
        AddCylinderVertex(0.0f, -1.0f, -1.0, 1.0f);
        AddCylinderVertex(-0.5f, -1.0f, -0.87, 1.0f);
        AddCylinderVertex(-0.87f, -1.0f, -0.5, 1.0f);
        AddCylinderVertex(-1.0f, -1.0f, 0.0, 1.0f);
        AddCylinderVertex(-0.87f, -1.0f, 0.5, 1.0f);
        AddCylinderVertex(-0.5f, -1.0f, 0.87, 1.0f);
        AddCylinderVertex(0.0f, -1.0f, 1.0, 1.0f);
        AddCylinderVertex(0.5f, -1.0f, 0.87, 1.0f);
        AddCylinderVertex(0.87f, -1.0f, 0.5, 1.0f);
        AddCylinderVertex(1.0f, -1.0f, 0.0, 1.0f);
        AddCylinderVertex(0.87f, 1.0f, -0.5, 1.0f);
        AddCylinderVertex(0.5f, 1.0f, -0.87, 1.0f);
        AddCylinderVertex(0.0f, 1.0f, -1.0, 1.0f);
        AddCylinderVertex(-0.5f, 1.0f, -0.87, 1.0f);
        AddCylinderVertex(-0.87f, 1.0f, -0.5, 1.0f);
        AddCylinderVertex(-1.0f, 1.0f, 0.0, 1.0f);
        AddCylinderVertex(-0.87f, 1.0f, 0.5, 1.0f);
        AddCylinderVertex(-0.5f, 1.0f, 0.87, 1.0f);
        AddCylinderVertex(0.0f, 1.0f, 1.0, 1.0f);
        AddCylinderVertex(0.5f, 1.0f, 0.87, 1.0f);
        AddCylinderVertex(0.87f, 1.0f, 0.5, 1.0f);
        AddCylinderVertex(1.0f, 1.0f, 0.0, 1.0f);
        AddCylinderVertex(0.0f, -1.0f, 0.0, 1.0f);
        AddCylinderVertex(0.0f, 1.0f, 0.0, 1.0f);
    }
    
    unsigned int cylinderIndices[] =
    {
        0, 1, 12,
        12, 1, 13,
        
        1, 2, 13,
        13, 2, 14,
        
        2, 3, 14,
        14, 3, 15,
        
        3, 4, 15,
        15, 4, 16,
        
        4, 5, 16,
        16, 5, 17,
        
        5, 6, 17,
        17, 6, 18,
        
        6, 7, 18,
        18, 7, 19,
        
        7, 8, 19,
        19, 8, 20,
        
        8, 9, 20,
        20, 9, 21,
        
        9, 10, 21,
        21, 10, 22,
        
        10, 11, 22,
        22, 11, 23,
        
        11, 0, 23,
        23, 0, 12,
        
        1, 0, 24,
        2, 1, 24,
        
        3, 2, 24,
        4, 3, 24,
        
        5, 4, 24,
        6, 5, 24,
        
        7, 6, 24,
        8, 7, 24,
        
        9, 8, 24,
        10, 9, 24,
        
        11, 10, 24,
        0, 11, 24,
        
        12, 13, 25,
        13, 14, 25,
        
        14, 15, 25,
        15, 16, 25,
        
        16, 17, 25,
        17, 18, 25,
        
        18, 19, 25,
        19, 20, 25,
        
        20, 21, 25,
        21, 22, 25,
        
        22, 23, 25,
        23, 12, 25,
    };
    
    cylinderRet.numVertices = cylinderRet.vertices.length();
    cylinderRet.numTotalVerts = cylinderRet.numVertices;
    
    cylinderRet.numIndices = sizeof(cylinderIndices) / sizeof(*cylinderIndices);
    cylinderRet.numTotalIndices = cylinderRet.numIndices;
    
    cylinderRet.indices = new MUintArray(cylinderIndices, cylinderRet.numIndices);
    
    addedInitialCylinder = true;
    
    if(distX <= 2.0f)
    {
        if(distX != 0.0f)
        {
            distX = 2.5f;
        }
        else
        {
            distX = 0.0f;
        }
    }
    if(distY <= 2.0f)
    {
        if(distY != 0.0f)
        {
            distY = 2.5f;
        }
        else
        {
            distY = 0.0f;
        }
    }
    if(distZ <= 2.0f)
    {
        if(distZ != 0.0f)
        {
            distZ = 2.5f;
        }
        else
        {
            distZ = 0.0f;
        }
    }
    
    if(addedInitialCylinder)
    {
        if(numCylinders > 1)
        {
            for(int i = 1; i < numCylinders; i++)
            {
                for(int j = 0; j < cylinderRet.numVertices; j++)
                {
                    cylinderRet.vertices.append((cylinderRet.vertices[j].x + (distX * i)), (cylinderRet.vertices[j].y + (distY * i )), (cylinderRet.vertices[j].z + (distZ * i)), 1.0f);
                    cylinderRet.numTotalVerts++;
                }
                
                for(unsigned int k = 0; k < (cylinderRet.numIndices); k++)
                {
                    cylinderRet.indices->append((cylinderIndices[k] + (cylinderRet.numVertices * i)));
                    cylinderRet.numTotalIndices++;
                }
            }
        }
    }
    
    return cylinderRet;
}

ShapeData ShapeGenerator::GenerateCapsules(int numCapsules, float distX, float distY, float distZ)
{
    if(addedInitialCapsule == false)
    {
        AddCapsuleVertex(0.43f, -1.87f, -0.25, 1.0f);
        AddCapsuleVertex(0.25f, -1.87f, -0.43, 1.0f);
        AddCapsuleVertex(-0.0f, -1.87f, -0.5, 1.0f);
        AddCapsuleVertex(-0.25f, -1.87f, -0.43, 1.0f);
        AddCapsuleVertex(-0.43f, -1.87f, -0.25, 1.0f);
        AddCapsuleVertex(-0.5f, -1.87f, 0.0, 1.0f);
        AddCapsuleVertex(-0.43f, -1.87f, 0.25, 1.0f);
        AddCapsuleVertex(-0.25f, -1.87f, 0.43, 1.0f);
        AddCapsuleVertex(0.0f, -1.87f, 0.5, 1.0f);
        AddCapsuleVertex(0.25f, -1.87f, 0.43, 1.0f);
        AddCapsuleVertex(0.43f, -1.87f, 0.25, 1.0f);
        AddCapsuleVertex(0.5f, -1.87f, 0.0, 1.0f);
        AddCapsuleVertex(0.75f, -1.5f, -0.43, 1.0f);
        AddCapsuleVertex(0.43f, -1.5f, -0.75, 1.0f);
        AddCapsuleVertex(-0.0f, -1.5f, -0.87, 1.0f);
        AddCapsuleVertex(-0.43f, -1.5f, -0.75, 1.0f);
        AddCapsuleVertex(-0.75f, -1.5f, -0.43, 1.0f);
        AddCapsuleVertex(-0.87f, -1.5f, 0.0, 1.0f);
        AddCapsuleVertex(-0.75f, -1.5f, 0.43, 1.0f);
        AddCapsuleVertex(-0.43f, -1.5f, 0.75, 1.0f);
        AddCapsuleVertex(0.0f, -1.5f, 0.87, 1.0f);
        AddCapsuleVertex(0.43f, -1.5f, 0.75, 1.0f);
        AddCapsuleVertex(0.75f, -1.5f, 0.43, 1.0f);
        AddCapsuleVertex(0.87f, -1.5f, 0.0, 1.0f);
        AddCapsuleVertex(0.87f, -1.0f, -0.5, 1.0f);
        AddCapsuleVertex(0.5f, -1.0f, -0.87, 1.0f);
        AddCapsuleVertex(0.0f, -1.0f, -1.0, 1.0f);
        AddCapsuleVertex(-0.5f, -1.0f, -0.87, 1.0f);
        AddCapsuleVertex(-0.87f, -1.0f, -0.5, 1.0f);
        AddCapsuleVertex(-1.0f, -1.0f, 0.0, 1.0f);
        AddCapsuleVertex(-0.87f, -1.0f, 0.5, 1.0f);
        AddCapsuleVertex(-0.5f, -1.0f, 0.87, 1.0f);
        AddCapsuleVertex(0.0f, -1.0f, 1.0, 1.0f);
        AddCapsuleVertex(0.5f, -1.0f, 0.87, 1.0f);
        AddCapsuleVertex(0.87f, -1.0f, 0.5, 1.0f);
        AddCapsuleVertex(1.0f, -1.0f, 0.0, 1.0f);
        AddCapsuleVertex(0.87f, 1.0f, -0.5, 1.0f);
        AddCapsuleVertex(0.5f, 1.0f, -0.87, 1.0f);
        AddCapsuleVertex(0.0f, 1.0f, -1.0, 1.0f);
        AddCapsuleVertex(-0.5f, 1.0f, -0.87, 1.0f);
        AddCapsuleVertex(-0.87f, 1.0f, -0.5, 1.0f);
        AddCapsuleVertex(-1.0f, 1.0f, 0.0, 1.0f);
        AddCapsuleVertex(-0.87f, 1.0f, 0.5, 1.0f);
        AddCapsuleVertex(-0.5f, 1.0f, 0.87, 1.0f);
        AddCapsuleVertex(0.0f, 1.0f, 1.0, 1.0f);
        AddCapsuleVertex(0.5f, 1.0f, 0.87, 1.0f);
        AddCapsuleVertex(0.87f, 1.0f, 0.5, 1.0f);
        AddCapsuleVertex(1.0f, 1.0f, 0.0, 1.0f);
        AddCapsuleVertex(0.75f, 1.5f, -0.43, 1.0f);
        AddCapsuleVertex(0.43f, 1.5f, -0.75, 1.0f);
        AddCapsuleVertex(-0.0f, 1.5f, -0.87, 1.0f);
        AddCapsuleVertex(-0.43f, 1.5f, -0.75, 1.0f);
        AddCapsuleVertex(-0.75f, 1.5f, -0.43, 1.0f);
        AddCapsuleVertex(-0.87f, 1.5f, 0.0, 1.0f);
        AddCapsuleVertex(-0.75f, 1.5f, 0.43, 1.0f);
        AddCapsuleVertex(-0.43f, 1.5f, 0.75, 1.0f);
        AddCapsuleVertex(0.0f, 1.5f, 0.87, 1.0f);
        AddCapsuleVertex(0.43f, 1.5f, 0.75, 1.0f);
        AddCapsuleVertex(0.75f, 1.5f, 0.43, 1.0f);
        AddCapsuleVertex(0.87f, 1.5f, 0.0, 1.0f);
        AddCapsuleVertex(0.43f, 1.87f, -0.25, 1.0f);
        AddCapsuleVertex(0.25f, 1.87f, -0.43, 1.0f);
        AddCapsuleVertex(-0.0f, 1.87f, -0.5, 1.0f);
        AddCapsuleVertex(-0.25f, 1.87f, -0.43, 1.0f);
        AddCapsuleVertex(-0.43f, 1.87f, -0.25, 1.0f);
        AddCapsuleVertex(-0.5f, 1.87f, 0.0, 1.0f);
        AddCapsuleVertex(-0.43f, 1.87f, 0.25, 1.0f);
        AddCapsuleVertex(-0.25f, 1.87f, 0.43, 1.0f);
        AddCapsuleVertex(0.0f, 1.87f, 0.5, 1.0f);
        AddCapsuleVertex(0.25f, 1.87f, 0.43, 1.0f);
        AddCapsuleVertex(0.43f, 1.87f, 0.25, 1.0f);
        AddCapsuleVertex(0.5f, 1.87f, 0.0, 1.0f);
        AddCapsuleVertex(0.0f, -2.0f, 0.0, 1.0f);
        AddCapsuleVertex(0.0f, 2.0f, 0.0, 1.0f);
    }
    
    unsigned int capsuleIndices[] =
    {
        0, 1, 12,
        12, 1, 13,
        1, 2, 13,
        13, 2, 14,
        2, 3, 14,
        14, 3, 15,
        3, 4, 15,
        15, 4, 16,
        4, 5, 16,
        16, 5, 17,
        5, 6, 17,
        17, 6, 18,
        6, 7, 18,
        18, 7, 19,
        7, 8, 19,
        19, 8, 20,
        8, 9, 20,
        20, 9, 21,
        9, 10, 21,
        21, 10, 22,
        10, 11, 22,
        22, 11, 23,
        11, 0, 23,
        23, 0, 12,
        12, 13, 24,
        24, 13, 25,
        13, 14, 25,
        25, 14, 26,
        14, 15, 26,
        26, 15, 27,
        15, 16, 27,
        27, 16, 28,
        16, 17, 28,
        28, 17, 29,
        17, 18, 29,
        29, 18, 30,
        18, 19, 30,
        30, 19, 31,
        19, 20, 31,
        31, 20, 32,
        20, 21, 32,
        32, 21, 33,
        21, 22, 33,
        33, 22, 34,
        22, 23, 34,
        34, 23, 35,
        23, 12, 35,
        35, 12, 24,
        24, 25, 36,
        36, 25, 37,
        25, 26, 37,
        37, 26, 38,
        26, 27, 38,
        38, 27, 39,
        27, 28, 39,
        39, 28, 40,
        28, 29, 40,
        40, 29, 41,
        29, 30, 41,
        41, 30, 42,
        30, 31, 42,
        42, 31, 43,
        31, 32, 43,
        43, 32, 44,
        32, 33, 44,
        44, 33, 45,
        33, 34, 45,
        45, 34, 46,
        34, 35, 46,
        46, 35, 47,
        35, 24, 47,
        47, 24, 36,
        36, 37, 48,
        48, 37, 49,
        37, 38, 49,
        49, 38, 50,
        38, 39, 50,
        50, 39, 51,
        39, 40, 51,
        51, 40, 52,
        40, 41, 52,
        52, 41, 53,
        41, 42, 53,
        53, 42, 54,
        42, 43, 54,
        54, 43, 55,
        43, 44, 55,
        55, 44, 56,
        44, 45, 56,
        56, 45, 57,
        45, 46, 57,
        57, 46, 58,
        46, 47, 58,
        58, 47, 59,
        47, 36, 59,
        59, 36, 48,
        48, 49, 60,
        60, 49, 61,
        49, 50, 61,
        61, 50, 62,
        50, 51, 62,
        62, 51, 63,
        51, 52, 63,
        63, 52, 64,
        52, 53, 64,
        64, 53, 65,
        53, 54, 65,
        65, 54, 66,
        54, 55, 66,
        66, 55, 67,
        55, 56, 67,
        67, 56, 68,
        56, 57, 68,
        68, 57, 69,
        57, 58, 69,
        69, 58, 70,
        58, 59, 70,
        70, 59, 71,
        59, 48, 71,
        71, 48, 60,
        1, 0, 72,
        2, 1, 72,
        3, 2, 72,
        4, 3, 72,
        5, 4, 72,
        6, 5, 72,
        7, 6, 72,
        8, 7, 72,
        9, 8, 72,
        10, 9, 72,
        11, 10, 72,
        0, 11, 72,
        60, 61, 73,
        61, 62, 73,
        62, 63, 73,
        63, 64, 73,
        64, 65, 73,
        65, 66, 73,
        66, 67, 73,
        67, 68, 73,
        68, 69, 73,
        69, 70, 73,
        70, 71, 73,
        71, 60, 73,
    };
    
    capsuleRet.numVertices = capsuleRet.vertices.length();
    capsuleRet.numTotalVerts = capsuleRet.numVertices;
    
    capsuleRet.numIndices = sizeof(capsuleIndices) / sizeof(*capsuleIndices);
    capsuleRet.numTotalIndices = capsuleRet.numIndices;
    
    capsuleRet.indices = new MUintArray(capsuleIndices, capsuleRet.numIndices);
    
    addedInitialCapsule = true;
    
    if(distX <= 2.0f)
    {
        if(distX != 0.0f)
        {
            distX = 2.5f;
        }
        else
        {
            distX = 0.0f;
        }
    }
    if(distY <= 4.0f)
    {
        if(distY != 0.0f)
        {
            distY = 4.0f;
        }
        else
        {
            distY = 0.0f;
        }
    }
    if(distZ <= 2.0f)
    {
        if(distZ != 0.0f)
        {
            distZ = 2.5f;
        }
        else
        {
            distZ = 0.0f;
        }
    }
    
    if(addedInitialCapsule)
    {
        if(numCapsules > 1)
        {
            for(int i = 1; i < numCapsules; i++)
            {
                for(int j = 0; j < capsuleRet.numVertices; j++)
                {
                    capsuleRet.vertices.append((capsuleRet.vertices[j].x + (distX * i)), (capsuleRet.vertices[j].y + (distY * i )), (capsuleRet.vertices[j].z + (distZ * i)), 1.0f);
                    capsuleRet.numTotalVerts++;
                }
                
                for(unsigned int k = 0; k < (capsuleRet.numIndices); k++)
                {
                    capsuleRet.indices->append((capsuleIndices[k] + (capsuleRet.numVertices * i)));
                    capsuleRet.numTotalIndices++;
                }
            }
        }
    }
    
    return capsuleRet;
}

void ShapeGenerator::AddCubeVertex(double x, double y, double z, double w)
{
    w = 1.0f;
    
    MPoint pnt(x, y, z, w);
    cubeRet.vertices.append(pnt);
    cubeRet.numVertices++;
}

void ShapeGenerator::AddCylinderVertex(double x, double y, double z, double w)
{
    w = 1.0f;
    
    MPoint pnt(x, y, z, w);
    cylinderRet.vertices.append(pnt);
    cylinderRet.numVertices++;
}

void ShapeGenerator::AddCapsuleVertex(double x, double y, double z, double w)
{
    w = 1.0f;
    
    MPoint pnt(x, y, z, w);
    capsuleRet.vertices.append(pnt);
    capsuleRet.numVertices++;
}
