#include "MayaPushPullPPCmd.h"
#include <maya\MGlobal.h>
#include <maya\MFnPlugin.h>

MStatus initializePlugin(MObject obj)
{
	MStatus   status = MStatus::kSuccess;
	MFnPlugin plugin(obj, "MyPlugin", "1.0", "Any");

	// Register Command
	status = plugin.registerCommand("MayaPushPullPPCmd", MayaPushPullPPCmd::creator);
	if (!status) {
		status.perror("registerCommand");
		return status;
	}

	char buffer[2048];
	sprintf_s(buffer, 2048, "source \"%s/ui.mel\";", plugin.loadPath().asChar());
	MGlobal::displayInfo(buffer);
	MGlobal::executeCommand(buffer, true);

	return status;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus   status = MStatus::kSuccess;
	MFnPlugin plugin(obj);

	status = plugin.deregisterCommand("MayaPushPullPPCmd");
	if (!status) {
		status.perror("deregisterCommand");
		return status;
	}

	return status;
}