//
//  Header.h
//  ReflectionLocator
//
//  Created by Jordan Issa on 19/01/2017.
//
//

#ifndef ShapeGenerator_h
#define ShapeGenerator_h

#include "Commons.h"

class ShapeGenerator
{
public:
    ShapeData GenerateCubes(int numCubes, glFloat3 pos, glFloat3 offsetPos);
    ShapeData GenerateCylinders(int numCylinders, glFloat3 pos, glFloat3 offsetPos);
    ShapeData GenerateCapsules(int numCapsules, glFloat3 pos, glFloat3 offsetPos);
    
    void AddCubeVertex(double x, double y, double z, double w);
    void AddCylinderVertex(double x, double y, double z, double w);
    void AddCapsuleVertex(double x, double y, double z, double w);
    
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
    
    bool addedInitialCube = false;
    bool addedInitialCylinder = false;
    bool addedInitialCapsule = false;
};

#endif
