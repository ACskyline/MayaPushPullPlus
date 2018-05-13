#include "MayaPushPullPPCmd.h"
#include <maya\MGlobal.h>
#include <maya\MSelectionList.h>
#include <maya\MItSelectionList.h>
#include <maya\MFnComponentListData.h>
#include <maya\MFnSingleIndexedComponent.h>
#include <maya\MDagPath.h>
#include <maya\MFnMesh.h>
#include <maya\MFloatPointArray.h>
#include <string>
#include <sstream>
#include <maya\MItMeshPolygon.h>
#include <maya\MItMeshEdge.h>
#include <maya\MPointArray.h>
#include <maya\MArgList.h>
#include <maya\MFnTransform.h>
#include "PPPPMesh.h"

MayaPushPullPPCmd::MayaPushPullPPCmd() : 
	targetDirection(glm::vec3(0, 1, 0)), targetTheta(30.f),
	targetPlane(glm::vec3(0, 1, 0)), targetNormal(glm::vec3(0, 1, 0)) , targetDistance(1.f)
{
}


MayaPushPullPPCmd::~MayaPushPullPPCmd()
{
}


MStatus MayaPushPullPPCmd::doIt(const MArgList& args)
{
	MStatus status;

	// Each mesh operation only supports one type of components
	// 
	MFn::Type componentType = MFn::kMeshPolygonComponent;

	MSelectionList selList;
	MGlobal::getActiveSelectionList(selList);
	MItSelectionList selListIter(selList);
	selListIter.setFilter(MFn::kMesh);

	// The meshOperation node only accepts a component list input, so we build
	// a component list using MFnComponentListData.
	//
	// MIntArrays could also be passed into the node to represent the ids,
	// but are less storage efficient than component lists, since consecutive 
	// components are bundled into a single entry in component lists.
	//

	MDagPath dagPath;
	MObject component;
	selListIter.getDagPath(dagPath, component);

	if (component.apiType() == componentType)
	{
		MGlobal::displayInfo(dagPath.fullPathName());
		MGlobal::displayInfo(component.apiTypeStr());

		MIntArray cpIds;
		MFnSingleIndexedComponent compFn(component);
		std::stringstream s;
		compFn.getElements(cpIds);
		for (int i = 0; i < cpIds.length(); i++)
		{
			s << "element class:" << compFn.className() << ",element number:" << i << ",element index:" << cpIds[i];
			//MGlobal::displayInfo(MString(s.str().c_str()));
		}

		MFnMesh meshEx(dagPath);

		MFloatPointArray points;
		meshEx.getPoints(points, MSpace::kWorld);

		for (int i = 0; i < points.length(); i++)
		{
			std::stringstream ss;
			ss << i << ":" << points[i].x << ',' << points[i].y << ',' << points[i].z << ',' << points[i].w;
			//MGlobal::displayInfo(MString(ss.str().c_str()));
		}


		for (int i = 0; i < cpIds.length(); i++)
		{
			MIntArray pointsIndexSelect;
			meshEx.getPolygonVertices(cpIds[i], pointsIndexSelect);
			std::stringstream sss;
			sss << "element index:" << cpIds[i] << endl;
			for (int j = 0; j < pointsIndexSelect.length(); j++)
			{
				sss << pointsIndexSelect[j] << ":" << points[pointsIndexSelect[j]].x << "," << points[pointsIndexSelect[j]].y << "," << points[pointsIndexSelect[j]].z << "," << points[pointsIndexSelect[j]].w << endl;
			}
			//MGlobal::displayInfo(MString(sss.str().c_str()));
		}


		float tDX = 0.f, tDY = 0.f, tDZ = 0.f;
		float tTheta = 0.f;
		float tPX = 0.f, tPY = 0.f, tPZ = 0.f;
		float tNX = 0.f, tNY = 0.f, tNZ = 0.f;
		float tDis = 0.f;
		int thre = 1;
		int isfirst = 1;
		int kmeansel=1;
		int axis = 1;
		for (int i = 0; i < args.length(); i++)
		{
			if (MString("-dx") == args.asString(i))
				tDX = args.asDouble(++i);
			else if (MString("-dy") == args.asString(i))
				tDY = args.asDouble(++i);
			else if (MString("-dz") == args.asString(i))
				tDZ = args.asDouble(++i);
			else if (MString("-a") == args.asString(i))
				tTheta = args.asDouble(++i);
			else if (MString("-px") == args.asString(i))
				tPX = args.asDouble(++i);
			else if (MString("-py") == args.asString(i))
				tPY = args.asDouble(++i);
			else if (MString("-pz") == args.asString(i))
				tPZ = args.asDouble(++i);
			else if (MString("-nx") == args.asString(i))
				tNX = args.asDouble(++i);
			else if (MString("-ny") == args.asString(i))
				tNY = args.asDouble(++i);
			else if (MString("-nz") == args.asString(i))
				tNZ = args.asDouble(++i);
			else if (MString("-sel") == args.asString(i))
				isfirst = args.asInt(++i);
			else if (MString("-dis") == args.asString(i))
				tDis = args.asDouble(++i);
			else if (MString("-thre") == args.asString(i))
				thre = args.asInt(++i);
			else if (MString("-kmean") == args.asString(i))
				kmeansel = args.asInt(++i);
			else if (MString("-axis") == args.asString(i))
				axis = args.asInt(++i);
		}
		targetDirection = glm::vec3(tDX, tDY, tDZ);
		targetTheta = tTheta;
		targetPlane = glm::vec3(tPX, tPY, tPZ);
		targetNormal = glm::vec3(tNX, tNY, tNZ);
		targetDistance = tDis;

		MGlobal::displayInfo(MString("<<<<<<start>>>>>>"));

		PPPPMesh meshP4;
		MGlobal::displayInfo(MString("<<<<<<read start>>>>>>"));
		meshP4.readFromMFnMesh(meshEx, cpIds[0]);
		MGlobal::displayInfo(MString("<<<<<<read finish>>>>>>"));
	

		MGlobal::displayInfo(MString("<<<<<<pushpull++ start>>>>>>"));
		meshP4.pushPullPP(meshP4.targetFace, targetDirection, targetTheta, targetPlane, targetNormal,isfirst , tDis,thre,kmeansel,axis);
		MGlobal::displayInfo(MString("<<<<<<pushpull++ finish>>>>>>"));

		//meshP4.printMesh();//
		
		MGlobal::displayInfo(MString("<<<<<<write start>>>>>>"));
		MFnMesh meshExx;
		meshP4.writeToMFnMesh(meshExx);
		MGlobal::displayInfo(MString("<<<<<<write finish>>>>>>"));


		MGlobal::displayInfo(MString("<<<<<<finish>>>>>>"));

		//delete the original mesh
		MFnTransform transformEx(meshEx.parent(0));
		MGlobal::executeCommand(MString("delete ") + transformEx.name(), true, true);

		//dagPath.extendToShape();
	}

	return status;
}