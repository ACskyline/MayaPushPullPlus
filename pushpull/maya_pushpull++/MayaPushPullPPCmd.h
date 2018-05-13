#pragma once

#include <maya\MPxCommand.h>
#include "glm\glm.hpp"

class MayaPushPullPPCmd : public MPxCommand
{
public:
	//MObject fComponentList;
	MayaPushPullPPCmd();
	virtual ~MayaPushPullPPCmd();
	static void* creator() { return new MayaPushPullPPCmd; }
	MStatus doIt(const MArgList& args);


	glm::vec3 targetDirection;
	float targetTheta;
	glm::vec3 targetPlane;
	glm::vec3 targetNormal;
	float targetDistance;
};

