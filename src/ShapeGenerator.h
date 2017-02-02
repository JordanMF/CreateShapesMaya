//
//  ShapeGenerator.h
//  CreateShapes
//
//  Created by Jordan Issa on 19/01/2017.
//
//

#ifndef ShapeGenerator_h
#define ShapeGenerator_h

#include <math.h>
#include <random>
#include <iostream>

#include <maya/MPointArray.h>
#include <maya/MUintArray.h>
#include <maya/MPxTransformationMatrix.h>
#include <maya/MTransformationMatrix.h>

struct ShapeData
{
    ShapeData() : vertices(0, MPoint(0.0f, 0.0f, 0.0f, 1.0f)), numVertices(0), indices(0), numIndices(0) {}
    
    MPointArray vertices;
    unsigned int numVertices;
    
    MUintArray* indices;
    unsigned int numIndices;
};

class ShapeGenerator
{
public:
    ShapeData GenerateCubes(int numCubes, MVector pos, MVector rot, MVector scale);
    ShapeData GenerateCylinders(int numCylinders, MVector pos, MVector rot, MVector scale);
    ShapeData GenerateCapsules(int numCapsules, MVector pos, MVector rot, MVector scale);
    
    void AddCubeVertex(MVector pos);
    void AddCylinderVertex(MVector pos);
    void AddCapsuleVertex(MVector pos);
    
    MPointArray GetCubeVertices() { return cubeRet.vertices; }
    MUintArray* GetCubeIndices() { return cubeRet.indices; }
    MPointArray GetCylinderVertices() { return cylinderRet.vertices; }
    MUintArray* GetCylinderIndices() { return cylinderRet.indices; }
    MPointArray GetCapsuleVertices() { return capsuleRet.vertices; }
    MUintArray* GetCapsuleIndices() { return capsuleRet.indices; }
    
private:
    ShapeData cubeRet;
    ShapeData cylinderRet;
    ShapeData capsuleRet;
    
    const float degtoRad = 0.0174533f;
};

#endif
