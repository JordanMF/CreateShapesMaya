#include "createShapesDrawOverride.h"

#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject obj)
{
    MStatus status;

    MFnPlugin fnPlugin(obj, "JI", "1.0", "Any");
    
    // Legacy viewport
    // Tell Maya that the node is a locator node type
    // Done using MPxNode;:kLocatorNode
    // MPxNode::kWhateverType
    status = fnPlugin.registerNode("reflection", CreateShapes::_id, CreateShapes::Creator, CreateShapes::Initialize, MPxNode::kLocatorNode, &CreateShapes::drawDbClassification);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    
    // Viewport 2.0
    status = MHWRender::MDrawRegistry::registerDrawOverrideCreator(CreateShapes::drawDbClassification, CreateShapes::drawRegistrantId, CreateShapesDrawOverride::creator);
    if (!status)
    {
        status.perror("registerDrawOverrideCreator");
        return status;
    }
    
    CHECK_MSTATUS_AND_RETURN_IT(status);

    return MStatus::kSuccess;
}

MStatus uninitializePlugin(MObject obj)
{
    MStatus status;

    MFnPlugin fnPlugin(obj);
    
    // Viewport 2.0
    status = MHWRender::MDrawRegistry::deregisterDrawOverrideCreator(CreateShapes::drawDbClassification, CreateShapes::drawRegistrantId);
    if (!status)
    {
        status.perror("deregisterDrawOverrideCreator");
        return status;
    }
    CHECK_MSTATUS_AND_RETURN_IT(status);
    
    // Legacy viewport
    status = fnPlugin.deregisterNode(CreateShapes::_id);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    
    return MStatus::kSuccess;
}
