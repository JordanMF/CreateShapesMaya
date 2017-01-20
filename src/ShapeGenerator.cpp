//
//  ShapeData.cpp
//  ReflectionLocator
//
//  Created by Jordan Issa on 19/01/2017.
//
//

#include "ShapeGenerator.h"

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a);

ShapeData ShapeGenerator::GenerateCube()
{
    ShapeData toReturn;
    
    Vertex cubeVertices[] =
    {
        // Front face
        // 0,1,2
        { glm::vec3(-1.0f,  1.0f, -1.0f)},
        { glm::vec3( 1.0f,  1.0f, -1.0f)},
        { glm::vec3( 1.0f, -1.0f, -1.0f)},
        //2,3,0
        { glm::vec3( 1.0f, -1.0f, -1.0f) },
        { glm::vec3(-1.0f, -1.0f, -1.0f) },
        { glm::vec3(-1.0f,  1.0f, -1.0f) },
       
        // Right face
        //0,3,4
        { glm::vec3(-1.0f,  1.0f, -1.0f) },
        { glm::vec3(-1.0f, -1.0f, -1.0f) },
        { glm::vec3(-1.0f, -1.0f,  1.0f) },
        //4,5,0
        { glm::vec3(-1.0f, -1.0f,  1.0f) },
        { glm::vec3(-1.0f,  1.0f,  1.0f) },
        { glm::vec3(-1.0f,  1.0f, -1.0f) },
       
        // Top face
        //0,5,6
        { glm::vec3(-1.0f,  1.0f, -1.0f) },
        { glm::vec3(-1.0f,  1.0f,  1.0f) },
        { glm::vec3( 1.0f,  1.0f,  1.0f) },
        //6,1,0
        { glm::vec3( 1.0f,  1.0f,  1.0f) },
        { glm::vec3( 1.0f,  1.0f, -1.0f) },
        { glm::vec3(-1.0f,  1.0f, -1.0f) },
       
        // Left face
        //1,6,7
        { glm::vec3( 1.0f,  1.0f, -1.0f) },
        { glm::vec3( 1.0f,  1.0f,  1.0f) },
        { glm::vec3( 1.0f, -1.0f,  1.0f) },
        //7,2,1
        { glm::vec3(1.0f, -1.0f,  1.0f) },
        { glm::vec3(1.0f, -1.0f, -1.0f) },
        { glm::vec3(1.0f,  1.0f, -1.0f) },
        
        // Bottom face
        //7,4,3
        { glm::vec3( 1.0f, -1.0f,  1.0f) },
        { glm::vec3(-1.0f, -1.0f,  1.0f) },
        { glm::vec3(-1.0f, -1.0f, -1.0f) },
        //3,2,7
        { glm::vec3(-1.0f, -1.0f, -1.0f) },
        { glm::vec3( 1.0f, -1.0f, -1.0f) },
        { glm::vec3( 1.0f, -1.0f,  1.0f) },
       
        // Back face
        //4,7,6
        { glm::vec3(-1.0f, -1.0f,  1.0f) },
        { glm::vec3( 1.0f, -1.0f,  1.0f) },
        { glm::vec3( 1.0f,  1.0f,  1.0f) },
        //6,5,4
        { glm::vec3( 1.0f, 1.0f,  1.0f) },
        { glm::vec3(-1.0f, 1.0f,  1.0f) },
        { glm::vec3(-1.0f, -1.0f, 1.0f) },
    };
    
    toReturn.numVertices = NUM_ARRAY_ELEMENTS(cubeVertices);
    toReturn.vertices = new Vertex[toReturn.numVertices];
    
    std::cout << toReturn.numVertices;
    memcpy(toReturn.vertices, cubeVertices, sizeof(cubeVertices));
    
    GLushort indices[] =
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
    
    toReturn.numIndices = NUM_ARRAY_ELEMENTS(indices);
    toReturn.indices = new GLushort[toReturn.numIndices];
    memcpy(toReturn.indices, indices, sizeof(indices));
    
    return toReturn;
}
