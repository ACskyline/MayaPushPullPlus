#pragma once

#include <maya\MFnMesh.h>
#include <vector>
#include <deque>
#include "PPPPFace.h"

#define EPSILON 0.0001

class PPPPMesh
{
public:
	PPPPMesh();
	~PPPPMesh();

	PPPPFace* targetFace;

	std::vector<PPPPVertex*> vVector;
	std::vector<PPPPHalfEdge*> hVector;
	std::vector<PPPPFace*> fVector;
	float theta;

	void readFromMFnMesh(const MFnMesh& mesh, const int faceId);
	void writeToMFnMesh(MFnMesh& mesh);

	void setSyms();
	void pushPullPP(PPPPFace* f, glm::vec3 d, float theta, glm::vec3 p, glm::vec3 n,int isfirst, float dis,int thre,int kmeansel,int axis);
	void pushPullPPInsertFace(PPPPFace* f, float theta, glm::vec3 n);
	void pushPullPPUpdateMesh(PPPPFace* f, glm::vec3 p, glm::vec3 n);
	void replaceVertex(PPPPFace* f, PPPPVertex* v, std::vector<PPPPVertex*>& Vsel);
	void insertBefore(PPPPFace* f, PPPPVertex* v, std::vector<PPPPVertex*>& Vsel);
	void insertAfter(PPPPFace* f, PPPPVertex* v, std::vector<PPPPVertex*>& Vsel);
	PPPPFace* getNextFace(PPPPFace* f, const std::deque<PPPPFace*>& Ffan);
	PPPPFace* getPreviousFace(PPPPFace* f, const std::deque<PPPPFace*>& Ffan);
	void deleteVertex(PPPPVertex** v);
	bool faceBelong(PPPPFace*f, std::vector<PPPPFace*> Faff);
	bool intersectFacePlane(PPPPFace* f, glm::vec3 p, glm::vec3 n);
	bool intersectPlanePlanePlane(PPPPFace* f1, PPPPFace* f2, glm::vec3 p, glm::vec3 n, glm::vec3* intersection);
	void fullZeroFace(PPPPVertex* v1, PPPPVertex* v2, PPPPVertex* v3, PPPPHalfEdge* e, PPPPHalfEdge* e1, PPPPHalfEdge *e2, glm::vec3 n);
	void firstHalfZeroFace(PPPPVertex* v1, PPPPVertex* v2, PPPPVertex* v3, PPPPHalfEdge* e, PPPPHalfEdge* e1, PPPPHalfEdge *e2, glm::vec3 n);
	void secondHalfZeroFace(PPPPVertex* v1, PPPPVertex* v2, PPPPVertex* v3, PPPPHalfEdge* e, PPPPHalfEdge* e1, PPPPHalfEdge *e2, glm::vec3 n);
	void oneEdgeZeroFace(PPPPVertex* v1, PPPPVertex* v2, PPPPVertex* v3, PPPPHalfEdge* e, PPPPHalfEdge* e1, PPPPHalfEdge *e2, glm::vec3 n);
	void printFace(PPPPFace* f);
	void printMesh();
	void printMIntArray(const MIntArray &arr);
	void printMFloatPointArray(const MFloatPointArray &arr);
	void printMFnMesh(MObject &mesh);

	void facedirectionRecomendation(PPPPFace* f, glm::vec3 &p, int isfirst, float &theta, glm::vec3& n , float dis ,int thre, int kmeansel,int axis);

	bool getNextStep(PPPPFace* f, glm::vec3 n, glm::vec3 p, glm::vec3 *nResult, glm::vec3 *pResult);
	void calculateNormal(PPPPFace* f);
	void cleanUp(PPPPFace* f);
	bool samePlane(glm::vec3 p1, glm::vec3 n1, glm::vec3 p2, glm::vec3 n2);
	void realDelete();
	bool intersectPlanePlanePlane(PPPPFace* f1, PPPPFace* f2, PPPPFace* f3, glm::vec3* intersection);
	bool betweenFacePlane(PPPPVertex* v, PPPPFace* f, glm::vec3 p, glm::vec3 n);
	float distanceToPlane(PPPPVertex* v, PPPPFace* f);
	bool intersectPlanePlane(PPPPFace *f, glm::vec3 p, glm::vec3 n, glm::vec3* origin, glm::vec3* direction);
	int mergeVertex(PPPPVertex* vKeep, PPPPVertex* vDiscard, PPPPHalfEdge* KeepToDiscard);
	bool removeEdge(PPPPHalfEdge* e);
	void deleteFace(PPPPFace** f);
	void deleteEdge(PPPPHalfEdge** e);
};

