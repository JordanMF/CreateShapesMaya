#include "createShapes.h"
#include <maya/MHWGeometryUtilities.h>

MTypeId CreateShapes::_id(0x00000235);

// Viewport 2.0 info
MObject CreateShapes::size;
//MObject CreateShapes::sizeX;
MObject CreateShapes::transparencySort;
MObject CreateShapes::transparency;
MObject CreateShapes::colorR;
MObject CreateShapes::colorG;
MObject CreateShapes::colorB;
MObject CreateShapes::color;
MString CreateShapes::drawDbClassification("drawdb/geometry/createShapes");
MString CreateShapes::drawRegistrantId("createShapesNodePlugin");

CreateShapes::CreateShapes()
{
}

void CreateShapes::postConstructor()
{
    MObject oThis = thisMObject();
    MFnDependencyNode fnNode( oThis );
    fnNode.setName( "reflectionShape#" );
}

CreateShapes::~CreateShapes()
{
}

void* CreateShapes::Creator()
{ 
    return new CreateShapes();
}

MStatus CreateShapes::Initialize()
{
    MStatus status;
    
    MFnMatrixAttribute matrixAttr;
    
    MFnUnitAttribute unitAttr;
    MFnNumericAttribute numAttr;
    MFnCompoundAttribute compAttr;
    
    //size = numAttr.create("size", "sz", MFnNumericData::k3Float);
    
    size = unitAttr.create("size", "sx", MFnUnitAttribute::kDistance);
    unitAttr.setDefault(1.0);
    status = addAttribute(size);
    if (!status)
    {
        status.perror("addAttribute");
        return status;
    }
    // Add dependency on the localScale attribute, so that when size is modified CreateShapesDrawOverride::transform will get called
    attributeAffects(CreateShapes::size, MPxLocatorNode::localScale);
    
//    sizeX = unitAttr.create("sizeX", "sX", MFnUnitAttribute::kDistance);
//    unitAttr.setDefault(1.0);
//    status = addAttribute(sizeX);
//    if (!status)
//    {
//        status.perror("addAttribute");
//        return status;
//    }
//    // Add dependency on the localScale attribute, so that when size is modified CreateShapesDrawOverride::transform will get called
//    attributeAffects(CreateShapes::sizeX, MPxLocatorNode::localScaleX);
    
    colorR = numAttr.createColor("color", "cR");
    addAttribute(colorR);
    if (!status)
    {
        status.perror("addAttribute");
        return status;
    }
    attributeAffects(CreateShapes::colorR, CreateShapes::color);
    
    color = numAttr.createColor("color", "c");
    addAttribute(color);
    if (!status)
    {
        status.perror("addAttribute");
        return status;
    }
    
    transparencySort = numAttr.create("transparencySort", "ts", MFnNumericData::kBoolean);
    numAttr.setDefault(false);
    status = addAttribute(transparencySort);
    if (!status)
    {
        status.perror("addAttribute");
        return status;
    }
    
    transparency = numAttr.create("transparency", "t", MFnNumericData::kFloat);
    numAttr.setDefault(1.0);
    numAttr.setMax(1.0);
    numAttr.setMin(0.0);
    
    status = addAttribute(transparency);
    if (!status)
    {
        status.perror("addAttribute");
        return status;
    }
    
    return MS::kSuccess;
}

MStatus CreateShapes::Compute(const MPlug& plug, MDataBlock& data)
{
    return MStatus::kUnknownParameter;
}

void CreateShapes::Draw(M3dView& view, const MDagPath& DGPath, M3dView::DisplayStyle style, M3dView::DisplayStatus status)
{
}

//void CreateShapes::DrawDisc(float radius, int divisions, bool filled)
//{
//    int renderstatuse = filled ? GL_POLYGON : GL_LINE_LOOP;
//    float degreesPerDiv = 360.0f / divisions;
//    float radiansPerDiv = degreesPerDiv * 0.01745327778f;
//    MFloatPointArray points(divisions);
//    for (int i = 0; i < divisions; i++)
//    {
//        float angle = i * radiansPerDiv;
//        float x = cos(angle) * radius;
//        float z = sin(angle) * radius;
//        points[i].x = x;
//        points[i].z = z;
//    }
//    
//    glBegin(renderstatuse);
//        for (int i = 0; i < divisions; i++)
//        {
//            glVertex3f(points[i].x, 0.0f, points[i].z);
//        }
//    glEnd();
//}

//void CreateShapes::DrawReflection(const MPoint& src, const MPoint &dest)
//{
//    // Draw reflection lines
//    // One from source line (src) to plane (0, 0, 0)
//    // One from plane (0, 0, 0) to reflection end (dest)
//    // Plane is always at the origin of the reflection lines i.e. the point where the reflection happens.
//    glBegin(GL_LINES);
//        glVertex3f((float)src.x, (float)src.y, (float)src.z);
//        glVertex3f(0.0f, 0.0f, 0.0f);
//        glVertex3f(0.0f, 0.0f, 0.0f);
//        glVertex3f((float)dest.x, (float)dest.y, (float)dest.z);
//    glEnd();
//}

bool CreateShapes::IsBounded() const
{
    return true;
}

bool CreateShapes::IsTransparent() const
{
    return true;
}

MBoundingBox CreateShapes::BoundingBox() const
{
    MBoundingBox _boundBox;
    
    // Bounding Box is used for selecting and moving the locator
    // If box is too small, user will be unable to select the locator
    // If so, change values
//    _boundBox.expand(m_srcPoint);
//    _boundBox.expand(m_destPoint);
//    _boundBox.expand(m_planePoint);
//    _boundBox.expand(m_planePoint + MVector(1.0, 0.0, 0.0));
//    _boundBox.expand(m_planePoint + MVector(-1.0, 0.0, 0.0));
//    _boundBox.expand(m_planePoint + MVector(0.0, 0.0, 1.0));
//    _boundBox.expand(m_planePoint + MVector(0.0, 0.0, -1.0));
    
    return _boundBox;
}
