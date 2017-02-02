//
//  ShapeGenerator.h
//  CreateShapes
//
//  Created by Jordan Issa on 19/01/2017.
//
//

#ifndef ShapeGenerator_h
#define ShapeGenerator_h

#include "Commons.h"
#include <random>
#include <numeric>

#include <maya/MFnTransform.h>
#include <maya/MPxTransform.h>
#include <maya/MPxTransformationMatrix.h>
#include <maya/MTransformationMatrix.h>
#include <maya/MVectorArray.h>

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
    
    const float degtoRad = 0.0174533;
};

#endif
