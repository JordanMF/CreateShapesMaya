#ifndef CREATESHAPES_H
#define CREATESHAPES_H

#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MFloatPointArray.h>
#include <maya/MFnCompoundAttribute.h>
#include <maya/MFnMatrixAttribute.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MGlobal.h>
#include <maya/MMatrix.h>
#include <maya/MObject.h>
#include <maya/MPoint.h>
#include <maya/MPointArray.h>
#include <maya/MPxLocatorNode.h>
#include <maya/MPxNode.h>

// Viewport 2.0 includes
#include <maya/MPxDrawOverride.h>
#include <maya/MDistance.h>
#include <maya/MEventMessage.h>

class CreateShapes : public MPxLocatorNode
{
public:
    CreateShapes();
    virtual void postConstructor();
	virtual	~CreateShapes();
    
	static void* Creator();
    static MStatus Initialize();
    
    virtual MStatus Compute(const MPlug& plug, MDataBlock& data);
    
    virtual void Draw(M3dView&, const MDagPath&, M3dView::DisplayStyle, M3dView::DisplayStatus);
    
    //void DrawDisc(float radius, int divisions, bool filled);
    //void DrawReflection(const MPoint& src, const MPoint& dest);
    
    virtual bool IsBounded() const;
    virtual bool IsTransparent() const;
    virtual MBoundingBox BoundingBox() const;
    
    //void setcolorR(float col);
    
    static MObject size;                // The size of the foot
    static MObject sizeX;
    static MObject sizeY;
    static MObject sizeZ;
    static MObject scale;
    static MObject transparencySort;   // The transparent status of the foot
    static MObject transparency;       // The transparent value of the foot
    static MObject colorR;
    static MObject colorG;
    static MObject colorB;
    static MObject color;
    
    static MTypeId _id;
    
    static MString drawDbClassification;
    static MString drawRegistrantId;
    
//private:
    //MPoint m_srcPoint, m_destPoint, m_planePoint;

};

// -------------------------- Viewport 2.0 ---------------------------------------------------------------------

class CreateShapesData : public MUserData
{
public:
    CreateShapesData() : MUserData(false), mBlendState(NULL)
    {
        mLastFrameStamp = 0;
    } // don't delete after draw
    
    ~CreateShapesData() override { mBlendState = NULL; }
    
    float fMultiplier;
    float fColor[4];
    bool  fCustomBoxDraw;
    MBoundingBox fCurrentBoundingBox;
    MDAGDrawOverrideInfo fDrawOV;
    const MHWRender::MBlendState* mBlendState;
    MUint64 mLastFrameStamp;
};

#endif
