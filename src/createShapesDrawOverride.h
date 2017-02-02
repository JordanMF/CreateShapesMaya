//
//  createShapesDrawOverride.h
//  CreateShapes
//
//  Created by Jordan Issa on 10/01/2017.
//
//

#ifndef createShapesDrawOverride_h
#define createShapesDrawOverride_h

#include "createShapes.h"
#include "createShapesDrawAgentGL.h"
#include "createShapesDrawAgentCoreProfile.h"
#include "ShapeGenerator.h"
#include <assert.h>

class CreateShapesDrawOverride : public MHWRender::MPxDrawOverride
{
public:
    static MHWRender::MPxDrawOverride* creator(const MObject& obj)
    {
        return new CreateShapesDrawOverride(obj);
    }
    
    ~CreateShapesDrawOverride() override;
    
    MHWRender::DrawAPI supportedDrawAPIs() const override { return (MHWRender::kOpenGL | MHWRender::kDirectX11 | MHWRender::kOpenGLCoreProfile); }
    
    MMatrix transform(const MDagPath& objPath, const MDagPath& cameraPath) const override;
        
    virtual bool isBounded(const MDagPath& objPath, const MDagPath& cameraPath) const override;
    virtual MBoundingBox boundingBox(const MDagPath& objPath, const MDagPath& cameraPath) const override;
    
    MUserData* prepareForDraw(const MDagPath& objPath, const MDagPath& cameraPath, const MHWRender::MFrameContext& frameContext, MUserData* oldData) override;
    
    void preDrawUI(const M3dView& view);
    void drawUI(MHWRender::MUIDrawManager& drawManager, const MHWRender::MFrameContext& frameContext) const;
    
    bool hasUIDrawables() const override { return true; }
    void addUIDrawables(const MDagPath& objPath, MHWRender::MUIDrawManager& drawManager, const MHWRender::MFrameContext& frameContext, const MUserData* data) override;
    
    static void draw(const MHWRender::MDrawContext& context, const MUserData* data);
    
    bool disableInternalBoundingBoxDraw() const override;
    bool excludedFromPostEffects() const override;
    bool isTransparent() const override;
    
    void FillCube(double x, double y, double z, double w);
    void FillCylinder(double x, double y, double z, double w);
    void FillCapsule(double x, double y, double z, double w);
    
    void SetCylinderIndices();
    
    ShapeGenerator shape;
    
protected:
    MBoundingBox mCurrentBoundingBox;
    bool mCustomBoxDraw;
    bool mExcludeFromPostEffects;
    bool mTransparencySort;
    MUint64 mLastFrameStamp;
    
private:
    CreateShapesDrawOverride(const MObject& obj);
    float getMultiplier(const MDagPath& objPath) const;
    
    bool isTransparentSort(const MDagPath& objPath) const;
    float getTransparency(const MDagPath& objPath) const;
    
    static void OnModelEditorChanged(void *clientData);
    MCallbackId fModelEditorChangedCbId;
    
    MObject fCreateShapes;
    
    const MHWRender::MBlendState* mBlendState;

    bool drawShapes = true;
    
    MPoint textPos = MPoint(0.0, 0.0, 0.0);
    MColor textColor = MColor(0.1f, 0.8f, 0.8f, 1.0f);
};

#endif 
