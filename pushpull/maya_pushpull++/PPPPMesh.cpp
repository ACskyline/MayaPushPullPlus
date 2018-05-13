#include "PPPPMesh.h"
#include <maya\MItMeshPolygon.h>
#include <maya\MFloatPointArray.h>
#include <maya\MIntArray.h>
#include <maya\MGlobal.h>
#include <sstream>
#include <iostream>
#include "Kmean.cpp"
#include <maya\MDagPath.h>
#include <maya\MItMeshEdge.h>
#include <maya\MItMeshPolygon.h>
#include <maya\MFnTransform.h>
#include<algorithm>
using namespace std;
PPPPMesh::PPPPMesh() : targetFace(nullptr),theta(0.f)
{

}

PPPPMesh::~PPPPMesh()
{
	for each (PPPPVertex* v in vVector)
	{
		if (v != nullptr)
		{
			delete v;
			v = nullptr;
		}
	}

	for each (PPPPHalfEdge* h in hVector)
	{
		if (h != nullptr)
		{
			delete h;
			h = nullptr;
		}
	}

	for each (PPPPFace* f in fVector)
	{
		if (f != nullptr)
		{
			delete f;
			f = nullptr;
		}
	}
}

void PPPPMesh::readFromMFnMesh(const MFnMesh& mesh, const int faceId)
{
	PPPPFace::id_next = 1;//new
	PPPPHalfEdge::id_next = 1;//new
	PPPPVertex::id_next = 1;//new

	MItMeshPolygon faceIter(mesh.object());
	MFloatPointArray points;
	mesh.getPoints(points, MSpace::kWorld);
	MIntArray indexCounts;
	MIntArray indices;
	mesh.getVertices(indexCounts, indices);

	for (int i = 0; i < points.length(); i++)
	{
		vVector.push_back(new PPPPVertex(glm::vec3(points[i].x, points[i].y, points[i].z)));
	}

	int offset = 0;
	for (int i = 0; i < indexCounts.length(); i++)
	{
		MVector nor;
		mesh.getPolygonNormal(i, nor, MSpace::kWorld);
		PPPPFace *f = new PPPPFace(glm::vec3(nor.x, nor.y, nor.z), true);
		fVector.push_back(f);
		if (i == faceId) targetFace = f;
		PPPPHalfEdge *last = nullptr;
		PPPPHalfEdge *first = nullptr;
		for (int j = 0; j < indexCounts[i]; j++)
		{
			PPPPVertex* v = vVector[indices[offset + j]];
			PPPPHalfEdge* e = new PPPPHalfEdge(v, f);
			hVector.push_back(e);
			if (last != nullptr)
			{
				last->vert->halfEdge = e;
				last->next = e;
			}
			if (first == nullptr)
				first = e;
			last = e;
		}
		if (last != nullptr) // or first != nullptr
		{
			f->halfEdge = last;
			last->vert->halfEdge = first;
			last->next = first;
		}
		offset += indexCounts[i];
	}

	setSyms();
	//printMesh();
	//while (!faceIter.isDone())
	//{
	//	//do something
	//	faceIter.next();
	//}
}

void PPPPMesh::writeToMFnMesh(MFnMesh& mesh)
{
	MGlobal::displayInfo(MString("writeToMfnMesh"));
	MIntArray polygonCounts;
	MIntArray polygonConnects;
	MFloatPointArray vertexArray;
	int numVertices = vVector.size();
	int numPolygons = fVector.size();

	for (int i = 0; i < numVertices; i++)
	{
		vertexArray.append(MFloatPoint(
			vVector[i]->position.x,
			vVector[i]->position.y,
			vVector[i]->position.z,
			1.0f));
		vVector[i]->index = i;
	}

	for (int i = 0; i < numPolygons; i++)
	{
		PPPPFace* f = fVector[i];
		PPPPHalfEdge* startE = f->halfEdge;
		PPPPHalfEdge* currentE = startE;
		int count = 0;
		do {
			if (currentE == nullptr) break;//in case first on is nullptr
			polygonConnects.append(currentE->vert->index);
			count++;
			currentE = currentE->next;
		} while (currentE != nullptr&&currentE != startE);
		polygonCounts.append(count);
	}

	//mesh.setFaceVertexNormals;

	printMFloatPointArray(vertexArray);
	printMIntArray(polygonCounts);
	printMIntArray(polygonConnects);

	MObject obj = mesh.create(numVertices, numPolygons, vertexArray, polygonCounts, polygonConnects);// , dag);
	printMFnMesh(obj);

	MFnTransform objT(obj);
	MFnMesh objM = objT.child(0);

	MString cmd1("sets -e -fe initialShadingGroup ");
	cmd1 += objM.name();
	MGlobal::displayInfo(cmd1);
	MGlobal::executeCommand(cmd1);

	MString cmd2("select ");
	cmd2 += objT.name();
	MGlobal::displayInfo(cmd2);
	MGlobal::executeCommand(cmd2);

	MString cmd3("polySoftEdge -a 0");
	MGlobal::displayInfo(cmd3);
	MGlobal::executeCommand(cmd3);

	MString cmd33("xform -cp");
	MGlobal::displayInfo(cmd33);
	MGlobal::executeCommand(cmd33);

	MString cmd4("select -clear");
	MGlobal::displayInfo(cmd4);
	MGlobal::executeCommand(cmd4);
	//mesh.updateSurface();
}

void PPPPMesh::setSyms()
{
	for (int i = 0; i < fVector.size(); i++)
	{
		if (fVector[i]->needToDelete)
			continue;

		for (int j = i + 1; j < fVector.size(); j++)
		{
			if (fVector[j]->needToDelete)
				continue;

			PPPPFace* f1 = fVector.at(i);
			PPPPFace* f2 = fVector.at(j);

			PPPPHalfEdge* f1_LastE = f1->halfEdge;
			PPPPHalfEdge* f2_LastE = f2->halfEdge;

			PPPPHalfEdge* f1_StartE = f1->halfEdge->next;
			PPPPHalfEdge* f2_StartE = f2->halfEdge->next;

			PPPPHalfEdge* f1_CurrentE = f1_StartE;
			PPPPHalfEdge* f2_CurrentE = f2_StartE;

			do
			{
				do
				{

					if (f1_CurrentE->vert == f2_LastE->vert && f1_LastE->vert == f2_CurrentE->vert)
					{
						f1_CurrentE->sym = f2_CurrentE;
						f2_CurrentE->sym = f1_CurrentE;
					}

					f2_CurrentE = f2_CurrentE->next;
					f2_LastE = f2_LastE->next;
				} while (f2_CurrentE != f2_StartE&&f2_CurrentE != nullptr);
				f1_CurrentE = f1_CurrentE->next;
				f1_LastE = f1_LastE->next;
			} while (f1_CurrentE != f1_StartE&&f1_CurrentE != nullptr);
		}
	}
}

void PPPPMesh::fullZeroFace(
	PPPPVertex* v1, PPPPVertex* v2, PPPPVertex* v3,
	PPPPHalfEdge* e, PPPPHalfEdge* e1, PPPPHalfEdge* e2, glm::vec3 n)
{
	//no need to reset the original e1->face->halfEdge
	////qDebug() << "enter fullZeroFace";
	PPPPHalfEdge* eLast = e->next;
	PPPPHalfEdge* e1Last = e1->next;
	while (eLast->next != e&&eLast != nullptr) eLast = eLast->next;
	while (e1Last->next != e1&&e1Last != nullptr) e1Last = e1Last->next;
	PPPPHalfEdge* eLastSymLast = eLast->sym->next;
	while (eLastSymLast->next != eLast->sym&&eLastSymLast != nullptr) eLastSymLast = eLastSymLast->next;

	PPPPVertex* vNew1 = new PPPPVertex(v1->position);
	PPPPVertex* vNew2 = new PPPPVertex(v2->position);
	PPPPHalfEdge* eSym = new PPPPHalfEdge(vNew2);
	PPPPHalfEdge* e1Sym = new PPPPHalfEdge(v1);
	PPPPHalfEdge* eSymNext = new PPPPHalfEdge(v2);
	PPPPHalfEdge* e1SymNext = new PPPPHalfEdge(vNew1);
	PPPPHalfEdge* eSymNextSym = new PPPPHalfEdge(vNew2);
	PPPPHalfEdge* e1SymNextSym = new PPPPHalfEdge(v1);
	PPPPFace* fzero = new PPPPFace(eSym, e1->face->col, glm::normalize(glm::cross(n, e->vert->position - e1->vert->position)), e1->face->hasNor);

	v2->halfEdge = e1Sym;//sssssssssshhhhhhhhhhiiiiiiiiiiiiiiiiitttttttttttttt
	v1->halfEdge = e1;//sssssssssshhhhhhhhhhiiiiiiiiiiiiiiiiitttttttttttttt

	vNew1->halfEdge = eSym;
	vNew2->halfEdge = e;

	e->sym = eSym;
	e->vert = vNew1;
	e1->sym = e1Sym;

	eSym->face = fzero;
	eSym->sym = e;
	eSym->next = eSymNext;
	e1Sym->face = fzero;
	e1Sym->sym = e1;
	e1Sym->next = e1SymNext;
	eSymNext->face = fzero;
	eSymNext->sym = eSymNextSym;
	eSymNext->next = e1Sym;
	e1SymNext->face = fzero;
	e1SymNext->sym = e1SymNextSym;
	e1SymNext->next = eSym;
	eSymNextSym->face = eLast->sym->face;
	eSymNextSym->sym = eSymNext;
	eSymNextSym->next = eLast->sym;
	e1SymNextSym->face = e1Last->sym->face;
	e1SymNextSym->sym = e1SymNext;
	e1SymNextSym->next = e->next->sym->next;//e1Last->sym;

	e->next->sym->vert = vNew1;
	e->next->sym->next = e1SymNextSym;
	eLast->vert = vNew2;
	eLastSymLast->next = eSymNextSym;//e2->sym->next = eSymNextSym;//

	vVector.push_back(vNew1);
	vVector.push_back(vNew2);
	hVector.push_back(eSym);
	hVector.push_back(e1Sym);
	hVector.push_back(eSymNext);
	hVector.push_back(e1SymNext);
	hVector.push_back(eSymNextSym);
	hVector.push_back(e1SymNextSym);
	fVector.push_back(fzero);
	////qDebug() << "fullZeroFace done";
}

void PPPPMesh::firstHalfZeroFace(
	PPPPVertex* v1, PPPPVertex* v2, PPPPVertex* v3,
	PPPPHalfEdge* e, PPPPHalfEdge* e1, PPPPHalfEdge* e2, glm::vec3 n)
{
	//need to reset the original e1->face->halfEdge
	////qDebug() << "enter firstHalfZeroFace";
	PPPPHalfEdge* eLast = e->next;
	PPPPHalfEdge* e1LastLast = e1->next;
	while (eLast->next != e&&eLast != nullptr) eLast = eLast->next;
	while (e1LastLast->next->next != e1&&e1LastLast != nullptr&&e1LastLast->next != nullptr)
		e1LastLast = e1LastLast->next;
	PPPPHalfEdge* e1Last = e1LastLast->next;

	PPPPHalfEdge* eLastSymLast = eLast->sym->next;
	while (eLastSymLast->next != eLast->sym) eLastSymLast = eLastSymLast->next;

	PPPPVertex* vNew2 = new PPPPVertex(v2->position);
	PPPPHalfEdge* e1Next = new PPPPHalfEdge(v2);
	PPPPHalfEdge* e1NextSym = new PPPPHalfEdge(vNew2);
	PPPPHalfEdge* e1NextNext = new PPPPHalfEdge(e1LastLast->vert);
	PPPPHalfEdge* e1NextNextSym = new PPPPHalfEdge(v2);
	PPPPFace* fzero = new PPPPFace(e1Next, e1->face->col, glm::normalize(glm::cross(n, e->vert->position - e1->vert->position)), e2->face->hasNor);

	v2->halfEdge = e1NextNext;//sssssssssshhhhhhhhhhiiiiiiiiiiiiiiiiitttttttttttttt

	vNew2->halfEdge = e;

	e1Next->face = fzero;
	e1Next->sym = e1NextSym;
	e1Next->next = e1NextNext;
	e1NextSym->face = e2->sym->face;
	e1NextSym->sym = e1Next;
	e1NextSym->next = eLast->sym;
	e1NextNext->face = fzero;
	e1NextNext->sym = e1NextNextSym;
	e1NextNext->next = e1Last;
	e1NextNextSym->face = e2->face;
	e1NextNextSym->sym = e1NextNext;
	e1NextNextSym->next = e2;

	e1->vert = vNew2;
	e1->face->halfEdge = e1NextNextSym;//wwwwwwwwhhhhhhhhhhaaaaaaaaaaaattttttttt!!!!!!! // in case e1->face->halfEdge == e1
	e1->face = fzero;
	e1->next = e1Next;

	eLast->vert = vNew2;
	eLastSymLast->next = e1NextSym;//e2->sym->next = e1NextSym;
	e1Last->face = fzero;
	e1LastLast->next = e1NextNextSym;

	vVector.push_back(vNew2);
	hVector.push_back(e1Next);
	hVector.push_back(e1NextSym);
	hVector.push_back(e1NextNext);
	hVector.push_back(e1NextNextSym);
	fVector.push_back(fzero);
	////qDebug() << "firstHalfZeroFace done";
}

void PPPPMesh::secondHalfZeroFace(
	PPPPVertex* v1, PPPPVertex* v2, PPPPVertex* v3,
	PPPPHalfEdge* e, PPPPHalfEdge* e1, PPPPHalfEdge* e2, glm::vec3 n)
{
	//need to reset the original e1->face->halfEdge
	////qDebug() << "enter secondHalfZeroFace";
	PPPPHalfEdge* e1Last = e1->next;
	//int i = 0;
	while (e1Last->next != e1&&e1Last != nullptr)
	{
		////qDebug() << i++ << ":" << e1Last << ":" << e1;
		////qDebug() << e1Last->vert->position.x << "," << e1Last->vert->position.y << "," << e1Last->vert->position.z;
		e1Last = e1Last->next;
	}

	PPPPVertex* vNew1 = new PPPPVertex(v1->position);
	PPPPHalfEdge* e2Next = new PPPPHalfEdge(v1);
	PPPPHalfEdge* e2NextSym = new PPPPHalfEdge(v3);
	PPPPHalfEdge* e2NextNext = new PPPPHalfEdge(vNew1);
	PPPPHalfEdge* e2NextNextSym = new PPPPHalfEdge(v1);
	PPPPFace* fzero = new PPPPFace(e2Next, e1->face->col, glm::normalize(glm::cross(n, e->vert->position - e1->vert->position)), e1Last->face->hasNor);

	v1->halfEdge = e2NextSym;//sssssssssshhhhhhhhhhiiiiiiiiiiiiiiiiitttttttttttttt

	vNew1->halfEdge = e1;

	e2Next->face = fzero;
	e2Next->sym = e2NextSym;
	e2Next->next = e2NextNext;
	e2NextSym->face = e1Last->face;
	e2NextSym->sym = e2Next;
	e2NextSym->next = e2->next;
	e2NextNext->face = fzero;
	e2NextNext->sym = e2NextNextSym;
	e2NextNext->next = e1;
	e2NextNextSym->face = e1Last->sym->face;
	e2NextNextSym->sym = e2NextNext;
	e2NextNextSym->next = e->next->sym->next;//e1Last->sym;

	e->vert = vNew1;
	e1->face->halfEdge = e2NextSym;//wwwwwwwwhhhhhhhhhhaaaaaaaaaaaattttttttt!!!!!!! // in case e1->face->halfEdge == e1
	e1->face = fzero;
	e2->face = fzero;
	e2->next = e2Next;

	e1Last->next = e2NextSym;
	e->next->sym->vert = vNew1;
	e->next->sym->next = e2NextNextSym;

	vVector.push_back(vNew1);
	hVector.push_back(e2Next);
	hVector.push_back(e2NextSym);
	hVector.push_back(e2NextNext);
	hVector.push_back(e2NextNextSym);
	fVector.push_back(fzero);
	////qDebug() << "secondHalfZeroFace done";
}

void PPPPMesh::oneEdgeZeroFace(
	PPPPVertex* v1, PPPPVertex* v2, PPPPVertex* v3,
	PPPPHalfEdge* e, PPPPHalfEdge* e1, PPPPHalfEdge* e2, glm::vec3 n)
{
	//need to reset the original e1->face->halfEdge
	////qDebug() << "enter oneEdgeZeroFace";
	PPPPHalfEdge* e1LastLast = e1->next;
	while (e1LastLast->next->next != e1&&e1LastLast != nullptr&&e1LastLast->next != nullptr)
		e1LastLast = e1LastLast->next;
	PPPPHalfEdge* e1Last = e1LastLast->next;

	PPPPHalfEdge* e2Next = new PPPPHalfEdge(e1LastLast->vert);
	PPPPHalfEdge* e2NextSym = new PPPPHalfEdge(v3);
	PPPPFace* fzero = new PPPPFace(e2Next, e1->face->col, glm::normalize(glm::cross(n, e->vert->position - e1->vert->position)), e1LastLast->face->hasNor);

	e2Next->face = fzero;
	e2Next->sym = e2NextSym;
	e2Next->next = e1Last;
	e2NextSym->face = e1LastLast->face;
	e2NextSym->sym = e2Next;
	e2NextSym->next = e2->next;

	e1LastLast->next = e2NextSym;

	e1Last->face = fzero;//wwwwwwwwwwwwwhhhhhhhhhhhhhhhhhaaaaaaaaaaaaaaatttttttttttttttt!!!!!!!!!!!!!!!!

	e1->face->halfEdge = e2NextSym;//wwwwwwwwhhhhhhhhhhaaaaaaaaaaaattttttttt!!!!!!! // in case e1->face->halfEdge == e1
	e1->face = fzero;
	e2->face = fzero;
	e2->next = e2Next;

	hVector.push_back(e2Next);
	hVector.push_back(e2NextSym);
	fVector.push_back(fzero);
	////qDebug() << "oneEdgeZeroFace done";
}

void PPPPMesh::pushPullPP(PPPPFace* f, glm::vec3 d, float theta, glm::vec3 p, glm::vec3 n, int isfirst, float dis, int thre,int kmeansel,int axis)
{
	this->theta = theta;

	if (f == nullptr) return;
	facedirectionRecomendation(f, p, isfirst, theta, n , dis ,thre,kmeansel,axis);
	std::stringstream log;

	// When pushing, n and f->nor should point to the same direction and p is on the -f->nor direction of the face f
	// When pulling, n and f->nor should point to the opposite direction and p is on the f->nor direction of the face f
	// To make this process robust, we test it and set the plane to point to the correct direction it didn't
	if (f->halfEdge != nullptr && f->halfEdge->vert != nullptr && f->hasNor)
	{
		float pDirection = glm::dot(f->nor, p - f->halfEdge->vert->position);
		float nDirection = glm::dot(f->nor, n);
		if (pDirection > 0 && nDirection < 0)//normal pull case
		{
			//do nothing
		}
		else if (pDirection > 0 && nDirection > 0)//pull case but plane facing wrong direction
		{
			n = -n;
		}
		else if (pDirection < 0 && nDirection > 0)//normal psuh case
		{
			//do nothing
		}
		else if (pDirection < 0 && nDirection < 0)//push case but plane facing wrong direction
		{
			n = -n;
		}
	}

	glm::vec3 ptemp = p, ntemp = glm::normalize(n);//just to be robust
	glm::vec3 plast, nlast;
	int i = 0;
	
	if (!getNextStep(f, n, p, &ntemp, &ptemp))
		return;

	do
	{
		//facedirectionRecomendation(f, ptemp, isfirst, theta, ntemp);
		log << ">>>>>>>>>>>>>> Step:" << i << std::endl;
		log << ">>>>>>>>>>>>>> ntemp:" << ntemp.x << "," << ntemp.y << "," << ntemp.z << std::endl;
		log << ">>>>>>>>>>>>>> ptemp:" << ptemp.x << "," << ptemp.y << "," << ptemp.z << std::endl;
		log << "insert start" << std::endl;
		MGlobal::displayInfo(log.str().c_str());
		log.str("");

		pushPullPPInsertFace(f, theta, ntemp);
		log << "insert finish" << std::endl;
		log << "update start" << std::endl;
		MGlobal::displayInfo(log.str().c_str());
		log.str("");
	
		//printMesh();

		pushPullPPUpdateMesh(f, ptemp, ntemp);
		log << "update finish" << std::endl;
		log << "setSyms start" << std::endl;
		MGlobal::displayInfo(log.str().c_str());
		log.str("");

		setSyms();
		log << "setSyms finish" << std::endl;
		log << "calculateNormal start" << std::endl;
		MGlobal::displayInfo(log.str().c_str());
		log.str("");


		//need to update normal after UpdateMesh because the face might face to a different direction now
		//calculateNormal(f);//only normal of f could be affected
		f->nor = glm::dot(f->nor, ntemp) > 0 ? ntemp : -ntemp;//use this way is better, since when f is really small(face to edge case), the value will be invalid
		log << "calculateNormal finish" << std::endl;
		log << "cleanUp start" << std::endl;
		MGlobal::displayInfo(log.str().c_str());
		log.str("");

		cleanUp(f);
		log << "cleanUp finish" << std::endl;
		log << ">>>>>>>>>>>>>> Step:" << i << " is finished" << std::endl;
		MGlobal::displayInfo(log.str().c_str());
		log.str("");


		plast = ptemp;
		nlast = ntemp;

		realDelete();
		if (fVector.size() < 4) break;//not a volume anymore

		i++;
	} while (getNextStep(f, n, p, &ntemp, &ptemp) &&
		!samePlane(plast, nlast, ptemp, nlast) &&
		f->needToDelete == false);//make sure face still exist using the new way, since we are not going to erase anything untill realDelete
								  //std::find(fVector.begin(), fVector.end(), f)!=fVector.end());//obsolete

	//realDelete();
}

void PPPPMesh::pushPullPPInsertFace(PPPPFace *f, float theta, glm::vec3 n)
{
	/// ALERT
	/// The normal of the plane always points to the opposite of the operation direction,
	/// i.e. when pulling towards right, the normal of the desired plane should points to left
	/// and when pushing towards left, the normal of the desired plane should points to right.
	/// This makes sure that when pushing, the angle between the normal of an adjacent face
	/// and the desired plane normal is always greater than 90 degree, hence no zero face will
	/// be created. Otherwise, zero face could be inserted when pushing. In some situation, this
	/// will create self intersection and it can not be solved by the stepped technique.

	n = glm::normalize(n);

	PPPPHalfEdge* start = f->halfEdge;
	PPPPHalfEdge* e = start;

	bool lastOneGenerated = false;
	bool firstOneGenerated = false;

	//int i = 0;
	do {
		////qDebug() << i++ << "edge:" << e->id << ":";
		PPPPHalfEdge* e1 = e->sym;
		PPPPHalfEdge* e2 = e1->next;

		PPPPVertex* v1 = e->vert;
		PPPPVertex* v2 = e1->vert;
		PPPPVertex* v3 = e2->vert;

		////qDebug() << "e:" << e->id << ",e1:" << e1->id << ",e2:" << e2->id;
		////qDebug() << "v1:" << v1->position.x << "," << v1->position.y << "," << v1->position.z;
		////qDebug() << "v2:" << v2->position.x << "," << v2->position.y << "," << v2->position.z;
		////qDebug() << "v3:" << v3->position.x << "," << v3->position.y << "," << v3->position.z;

		PPPPFace* adjF = e1->face;
		glm::vec3 adjFNormal(0.f);
		if (!lastOneGenerated)
		{
			//no difference, v2 and v3 are not the same, v1 is different from v2 and v3 by definition
			if (e->next == start&&firstOneGenerated)
				adjFNormal = (glm::cross(v3->position - v2->position, v1->position - v2->position));
			else
				adjFNormal = (glm::cross(v3->position - v2->position, v1->position - v2->position));
		}
		else
		{
			//no difference, v2 and v3 are the same, v1 is different from v2 and v3 by definition
			if (e->next == start&&firstOneGenerated)
				adjFNormal = (glm::cross(e2->next->vert->position - v2->position, v1->position - v2->position));
			else
				adjFNormal = (glm::cross(e2->next->vert->position - v2->position, v1->position - v2->position));
		}

		if (glm::length(adjFNormal) < EPSILON)
			return;//!!!
		else
			adjFNormal = glm::normalize(adjFNormal);

		////qDebug() << "adjF:" << (adjF == nullptr) << ":adjFNormal:" << adjFNormal.x << "," << adjFNormal.y << "," << adjFNormal.z;

		if (adjF == nullptr
			|| (glm::acos(glm::clamp(glm::dot(n, adjFNormal), -1.f, 1.f)) < glm::radians(90 - theta) && glm::dot(f->nor, n) > 0)//when push, do not use absolute value
			|| (glm::acos(glm::clamp(glm::abs(glm::dot(n, adjFNormal)), -1.f, 1.f)) < glm::radians(90 - theta) && glm::dot(f->nor, n) < 0))//when pull, use absolute value
		{
			// generate zero face
			if (!lastOneGenerated)//if a zero face was not generated for the last edge
			{
				if (e->next == start&&firstOneGenerated)//if a zero face was generated for the next edge
				{
					firstHalfZeroFace(v1, v2, v3, e, e1, e2, n);//generate first half only
				}
				else//if a zero face was not generated for the next edge
				{
					fullZeroFace(v1, v2, v3, e, e1, e2, n);//generate first half and second half
				}
			}
			else//if a zero face was generated for the last edge
			{
				if (e->next == start&&firstOneGenerated)//if a zero face was generated for the next edge
				{
					oneEdgeZeroFace(v1, v2, v3, e, e1, e2, n);//split the zero face from the polygon
				}
				else//if a zero face was not generated for the next edge
				{
					secondHalfZeroFace(v1, v2, v3, e, e1, e2, n);//generate second half only
				}
			}

			if (e == start) firstOneGenerated = true;
			lastOneGenerated = true;
		}
		else
		{
			//do not generate zero face
			lastOneGenerated = false;
		}
		e = e->next;
	} while (e != start);
}

void PPPPMesh::pushPullPPUpdateMesh(PPPPFace *f, glm::vec3 p, glm::vec3 n)
{
	/// keep the normal normalized, because dot product will be used to determine whether it overlap with another direction or not
	n = glm::normalize(n);//shiiiiiiit

	if (f == nullptr) return;
	PPPPHalfEdge* start = f->halfEdge;
	PPPPHalfEdge* current = start;

	std::vector<PPPPHalfEdge*> FEoriginal;

	do
	{
		FEoriginal.push_back(current);
		current = current->next;
	} while (current != start && current != nullptr);

	for (PPPPHalfEdge* h : FEoriginal)
	{
		PPPPVertex* v = h->vert;
		//current points to v
		std::deque<PPPPFace*> Ffan;
		std::vector<PPPPFace*> Faff;
		MGlobal::displayInfo(MString("-v.id:") + v->id);

		//determine affected faces
		////qDebug() << "determine affected faces";
		PPPPHalfEdge* hNext = h->next;
		PPPPHalfEdge* now = hNext->sym;
		do
		{
			Ffan.push_front(now->face);
			now = now->next->sym;
		} while (now != h&&now != nullptr);
		MGlobal::displayInfo(MString("-Ffan.size:") + Ffan.size());
		//for (int i = 0; i<Ffan.size(); i++) ////qDebug() << Ffan[i]->id;

		for (int i = 0; i < Ffan.size(); i++)
		{
			if (i == 0 || i == Ffan.size() - 1 || intersectFacePlane(Ffan[i], p, n))
				Faff.push_back(Ffan[i]);
		}

		MGlobal::displayInfo(MString("-Faff.size:") + Faff.size());
		//for (int i = 0; i<Faff.size(); i++)
		//{
			//////qDebug() << Faff[i]->id;
			//printFace(Faff[i]);
		//}

		//compute new vertices
		////qDebug() << "compute new vertices";
		std::vector<PPPPVertex*> Vnew;
		for (int i = 0; i < Faff.size() - 1; i++)
		{
			glm::vec3 point;
			//WHEN COMMENTING OUT STUFF DO NOT COMMENT THE FUNCTION CODE WITH IT !!!!!!!!!!!!!!!!
			//intersectPlanePlanePlane(Faff[i], Faff[i + 1], p, n, &point);
			MGlobal::displayInfo(MString("3 plane intersection:") + intersectPlanePlanePlane(Faff[i], Faff[i + 1], p, n, &point));
			MGlobal::displayInfo(MString("new vertex ") + i + MString(" is:") + point.x + MString(",") + point.y + MString(",") + point.z);
			PPPPVertex* v = new PPPPVertex(point);
			Vnew.push_back(v);
			vVector.push_back(v);
		}
		MGlobal::displayInfo(MString("-Vnew.size:") + Vnew.size());
		for (int i = 0; i < Vnew.size(); i++) MGlobal::displayInfo(MString("Vnew[") + i + MString("]:") + Vnew[i]->id);

		//update vertex indices of faces
		MGlobal::displayInfo(MString("update vertex indices of faces"));
		replaceVertex(f, v, Vnew);
		printFace(f);
		bool deleteV = true;
		for (int i = 0; i < Faff.size(); i++)
		{
			std::vector<PPPPVertex*> Vsel;
			if (i == 0) Vsel.push_back(Vnew[0]);
			else if (i == Faff.size() - 1) Vsel.push_back(Vnew[Vnew.size() - 1]);
			else
			{
				Vsel.push_back(Vnew[i]);//this order is important
				Vsel.push_back(Vnew[i - 1]);//this order is important
			}
			MGlobal::displayInfo(MString("-Vsel.size:") + Vsel.size());
			PPPPFace* fn = getNextFace(Faff[i], Ffan);
			PPPPFace* fp = getPreviousFace(Faff[i], Ffan);
			if (!faceBelong(fn, Faff))
			{
				insertAfter(Faff[i], v, Vsel);
				deleteV = false;
				MGlobal::displayInfo(MString("insertAfter"));
			}
			else if (!faceBelong(fp, Faff))
			{
				insertBefore(Faff[i], v, Vsel);
				deleteV = false;
				MGlobal::displayInfo(MString("insertBefore"));
			}
			else
			{
				replaceVertex(Faff[i], v, Vsel);
				MGlobal::displayInfo(MString("replaceVertex"));
			}
			printFace(Faff[i]);
		}
		MGlobal::displayInfo(MString("-All done"));
		if (deleteV) deleteVertex(&v);
	}
}

void PPPPMesh::deleteVertex(PPPPVertex **v)
{
	if (*v == nullptr) return;

	for (int i = 0; i < vVector.size(); i++)
	{
		if (vVector[i] == *v)
		{
			//vVector.erase(vVector.begin() + i);
			vVector[i]->needToDelete = true;
			break;
		}
	}
	//delete *v;
	*v = nullptr;
}

bool PPPPMesh::faceBelong(PPPPFace *f, std::vector<PPPPFace*> Faff)
{
	if (f == nullptr) return false;

	int n = Faff.size();
	for (int i = 0; i < n; i++)
	{
		if (Faff[i] == f)
			return true;
	}
	return false;
}

PPPPFace* PPPPMesh::getNextFace(PPPPFace *f, const std::deque<PPPPFace*>& Ffan)
{
	if (f == nullptr) return nullptr;

	int n = Ffan.size();
	for (int i = 0; i < n; i++)
	{
		if (Ffan[i] == f)
			return Ffan[(i + 1) % n];
	}
	return nullptr;
}

PPPPFace* PPPPMesh::getPreviousFace(PPPPFace *f, const std::deque<PPPPFace*>& Ffan)
{
	if (f == nullptr) return nullptr;

	int n = Ffan.size();
	for (int i = 0; i < n; i++)
	{
		if (Ffan[i] == f)
			return Ffan[(i - 1 + n) % n];
	}
	return nullptr;
}

void PPPPMesh::insertBefore(PPPPFace *f, PPPPVertex *v, std::vector<PPPPVertex *> &Vsel)
{
	if (f == nullptr || v == nullptr || Vsel.size() == 0)
		return;

	PPPPHalfEdge* start = f->halfEdge;
	PPPPHalfEdge* current = start;
	bool found = false;
	do
	{
		if (current->vert == v)
		{
			found = true;
			break;
		}
		else
			current = current->next;
	} while (current != start&&current != nullptr);

	if (found)
	{
		current->vert = Vsel[0];
		PPPPHalfEdge* final = current;
		PPPPHalfEdge* finalNext = current->next;
		for (int i = 1; i < Vsel.size(); i++)
		{
			PPPPHalfEdge* e = new PPPPHalfEdge(Vsel[i]);
			e->face = f;
			if (Vsel[i - 1]->halfEdge == nullptr) Vsel[i - 1]->halfEdge = e;

			if (i > 1)
			{
				hVector[hVector.size() - 1]->next = e;
			}
			else
			{
				current->next = e;
			}
			final = e;
			hVector.push_back(e);
		}
		PPPPHalfEdge* lastEdge = new PPPPHalfEdge(v);
		if (Vsel[Vsel.size() - 1]->halfEdge == nullptr) Vsel[Vsel.size() - 1]->halfEdge = lastEdge;
		final->next = lastEdge;
		lastEdge->face = f;
		lastEdge->next = finalNext;
		hVector.push_back(lastEdge);
	}
}

void PPPPMesh::insertAfter(PPPPFace *f, PPPPVertex *v, std::vector<PPPPVertex *> &Vsel)
{
	if (f == nullptr || v == nullptr || Vsel.size() == 0)
		return;

	PPPPHalfEdge* start = f->halfEdge;
	PPPPHalfEdge* current = start;
	bool found = false;
	do
	{
		if (current->vert == v)
		{
			found = true;
			break;
		}
		else
			current = current->next;
	} while (current != start&&current != nullptr);

	if (found)
	{
		PPPPHalfEdge* finalNext = current->next;
		for (int i = 0; i < Vsel.size(); i++)
		{
			PPPPHalfEdge* e = new PPPPHalfEdge(Vsel[i]);
			e->face = f;
			if (i > 0)
			{
				if (Vsel[i - 1]->halfEdge == nullptr) Vsel[i - 1]->halfEdge = e;
			}
			else
			{
				if (v->halfEdge == nullptr) v->halfEdge = e;
			}

			if (i > 1)
			{
				hVector[hVector.size() - 1]->next = e;
			}
			else
			{
				current->next = e;
			}

			hVector.push_back(e);
		}
		if (Vsel[Vsel.size() - 1]->halfEdge == nullptr) Vsel[Vsel.size() - 1]->halfEdge = hVector[hVector.size() - 1];
		hVector[hVector.size() - 1]->next = finalNext;
	}
}

void PPPPMesh::replaceVertex(PPPPFace *f, PPPPVertex *v, std::vector<PPPPVertex*> &Vsel)
{
	if (f == nullptr || v == nullptr || Vsel.size() == 0)
		return;

	PPPPHalfEdge* start = f->halfEdge;
	PPPPHalfEdge* current = start;
	bool found = false;
	do
	{
		if (current->vert == v)
		{
			found = true;
			break;
		}
		else
			current = current->next;
	} while (current != start&&current != nullptr);

	if (found)
	{
		current->vert = Vsel[0];
		PPPPHalfEdge* finalNext = current->next;
		for (int i = 1; i < Vsel.size(); i++)
		{
			PPPPHalfEdge* e = new PPPPHalfEdge(Vsel[i]);
			e->face = f;
			if (Vsel[i - 1]->halfEdge == nullptr) Vsel[i - 1]->halfEdge = e;

			if (i > 1)
			{
				hVector[hVector.size() - 1]->next = e;
			}
			else
			{
				current->next = e;
			}
			e->next = finalNext;//will be overwriten except for last one
			hVector.push_back(e);
		}
		if (Vsel[Vsel.size() - 1]->halfEdge == nullptr) Vsel[Vsel.size() - 1]->halfEdge = finalNext;
	}
}

bool PPPPMesh::intersectFacePlane(PPPPFace *f, glm::vec3 p, glm::vec3 n)
{
	if (f == nullptr) return false;
	PPPPHalfEdge* start = f->halfEdge;
	PPPPHalfEdge* current = start;
	bool first = true;
	bool direction = true;

	do
	{
		glm::vec3 v = current->vert->position;
		if (first)
		{
			direction = glm::dot(v - p, n) > 0;
			first = false;
		}
		else if ((glm::dot(v - p, n) > 0) != direction)
		{
			return true;
		}
		current = current->next;
	} while (current != start&&current != nullptr);
	return false;
}

bool PPPPMesh::intersectPlanePlanePlane(PPPPFace *f1,
	PPPPFace *f2,
	glm::vec3 p, glm::vec3 n,
	glm::vec3 *intersection)
{
	if (f1 == nullptr || f2 == nullptr) return false;
	glm::vec3 v1 = f1->halfEdge->vert->position;
	glm::vec3 v2 = f2->halfEdge->vert->position;
	glm::vec3 n1 = glm::normalize(f1->nor);
	glm::vec3 n2 = glm::normalize(f2->nor);

	/// keep the normal normalized, because dot product will be used to determine whether it overlap with another direction or not
	n = glm::normalize(n);//shiiiiiiit, just to be robust, we do it here again,

	if (glm::abs(glm::dot(n1, n2)) == 1)//parallel
	{
		n1.x += EPSILON;//change n1 a little bit
		n1 = glm::normalize(n1);
	}

	////qDebug() << "PPP>>>n1:" << n1.x << "," << n1.y << "," << n1.z << ">>>n2:" << n2.x << "," << n2.y << "," << n2.z << ">>>n:" << n.x << "," << n.y << "," << n.z;
	if (glm::abs(glm::dot(n1, n)) == 1 || glm::abs(glm::dot(n2, n)) == 1)//invalid situation
		return false;

	glm::mat3 invA = glm::inverse(glm::transpose(glm::mat3(n1, n2, n)));
	glm::vec3 b(glm::dot(v1, n1), glm::dot(v2, n2), glm::dot(p, n));
	*intersection = invA * b;
	return true;
}

void PPPPMesh::printFace(PPPPFace *f)
{
	std::stringstream ss;
	if (f == nullptr) return;
	PPPPHalfEdge* start = f->halfEdge;
	PPPPHalfEdge* current = start;
	ss << ">>>face:" << f->id << ",normal:" << f->nor.x << "," << f->nor.y << "," << f->nor.z << std::endl;
	do
	{
		ss << ">>>>>>edge:"
			<< current->id
			<< ",sym:";
		//<< current->sym->id
		//<< ",face:"
		//<< current->face->id
		//<< std::endl;
		ss << ">>>>>>>>>vertex:"
			<< current->vert->id
			//<< ",halfEdge:"
			//<< current->vert->halfEdge->id
			//<< ",position:"
			//<< current->vert->position.x << ","
			//<< current->vert->position.y << ","
			//<< current->vert->position.z
			<< std::endl;
		current = current->next;
	} while (current != start&&current != nullptr);
	MGlobal::displayInfo(ss.str().c_str());
}

void PPPPMesh::printMesh()
{
	std::stringstream ss;
	ss << ">>fVector size:" << fVector.size() << std::endl
		<< ">>hVector size:" << hVector.size() << std::endl
		<< ">>vVector size:" << vVector.size() << std::endl
		<< ">>targetFace:" << targetFace->id << std::endl;
	MGlobal::displayInfo(ss.str().c_str());

	for each(auto iter in fVector)
	{
		printFace(iter);
	}
}

void PPPPMesh::printMIntArray(const MIntArray &arr)
{
	std::stringstream ss;
	int length = arr.length();
	ss << "PrintMIntArray Size:" << length << std::endl;
	for (int i = 0; i < length; i++)
	{
		ss << i << ":" << arr[i] << std::endl;
	}
	MGlobal::displayInfo(ss.str().c_str());
}

void PPPPMesh::printMFloatPointArray(const MFloatPointArray &arr)
{
	std::stringstream ss;
	int length = arr.length();
	ss << "PrintMFloatPointArray Size:" << length << std::endl;
	for (int i = 0; i < length; i++)
	{
		ss << i << ":"
			<< arr[i].x << ","
			<< arr[i].y << ","
			<< arr[i].z << ","
			<< arr[i].w << std::endl;
	}
	MGlobal::displayInfo(ss.str().c_str());
}

void PPPPMesh::printMFnMesh(MObject &mesh)
{
	MItMeshPolygon itP(mesh);

	while (!itP.isDone())
	{
		MItMeshEdge itE(mesh, itP.polygon());
		MVector nor;
		itP.getNormal(nor, MSpace::kWorld);
		std::stringstream ssss;
		ssss << "Polygon" << itP.index() << "(" << nor.x << "," << nor.y << "," << nor.z << ",):" << endl;
		while (!itE.isDone())
		{
			int i1 = itE.index(0);
			int i2 = itE.index(1);
			MPoint p1 = itE.point(0, MSpace::kWorld);
			MPoint p2 = itE.point(1, MSpace::kWorld);
			MIntArray fIndices;
			itE.getConnectedFaces(fIndices);
			ssss << "Edge" << itE.index() << ": P"
				<< i1 << "(" << p1.x << "," << p1.y << "," << p1.z << ")->P"
				<< i2 << "(" << p2.x << "," << p2.y << "," << p2.z << ") ";
			for (int i = 0; i < fIndices.length(); i++)
			{
				ssss << "f" << i << ": " << fIndices[i] << " ";
			}
			ssss << endl;
			itE.next();
		}
		MGlobal::displayInfo(MString(ssss.str().c_str()));

		itP.next();
	}
}

bool PPPPMesh::getNextStep(PPPPFace* f, glm::vec3 n, glm::vec3 p, glm::vec3 *nResult, glm::vec3 *pResult)
{

	if (f == nullptr || f->needToDelete) return false;

	bool result = false;

	n = glm::normalize(n);//just to be robust

	PPPPHalfEdge *startE = f->halfEdge->next;
	PPPPHalfEdge *lastE = f->halfEdge;
	PPPPHalfEdge *currentE = startE;

	std::vector<PPPPVertex*> Vev;

	do
	{
		//Vev.push_back(currentE->vert);//should add all the vertices of the adjacent face to Vev instead of only the ones shared with f
		////////////////////////////////////
		PPPPHalfEdge* substartE = currentE->sym;
		PPPPHalfEdge* subcurrentE = substartE;
		do
		{
			Vev.push_back(subcurrentE->vert);
			subcurrentE = subcurrentE->next;
		} while (subcurrentE != substartE&&subcurrentE != nullptr);
		////////////////////////////////////////////////////

		PPPPFace *fAdj = currentE->sym->face;
		PPPPFace *fAdjLast = lastE->sym->face;
		PPPPFace *fAdjNext = currentE->next->sym->face;

		glm::vec3 point;
		if (intersectPlanePlanePlane(fAdjLast, fAdj, fAdjNext, &point))
			Vev.push_back(new PPPPVertex(point));

		lastE = lastE->next;
		currentE = currentE->next;
	} while (currentE != startE&&currentE != nullptr);

	MGlobal::displayInfo(MString("---Vev before clamp:"));
	for (int i = 0; i < Vev.size(); i++)
	{
		MGlobal::displayInfo(MString("----Vev") + i + MString(":") + Vev[i]->position.x + MString(",") + Vev[i]->position.y + MString(",") + Vev[i]->position.z);
	}
	MGlobal::displayInfo(MString("---Vev before clmap end"));

	for (auto iter = Vev.begin(); iter != Vev.end();)
	{
		if (!betweenFacePlane(*iter, f, p, n))
			iter = Vev.erase(iter);
		else
			iter++;
	}

	MGlobal::displayInfo(MString("---Vev after clamp:"));
	for (int i = 0; i < Vev.size(); i++)
	{
		MGlobal::displayInfo(MString("----Vev") + i + MString(":") + Vev[i]->position.x + MString(",") + Vev[i]->position.y + MString(",") + Vev[i]->position.z);
	}
	MGlobal::displayInfo(MString("---Vev after clamp end"));

	if (Vev.size() == 0)
	{
		*nResult = n;
		*pResult = p;
		result = true;
	}
	else if (1 - glm::abs(glm::dot(glm::normalize(f->nor), glm::normalize(n))) < EPSILON)//f is parellel to the plane
	{
		PPPPVertex *vNear = nullptr;
		float distanceNear = std::numeric_limits<float>::max();

		for (int i = 0; i < Vev.size(); i++)
		{
			float distance = distanceToPlane(Vev[i], f);
			if (distance >= 0 && distance < distanceNear)
			{
				distanceNear = distance;
				vNear = Vev[i];
			}
		}

		if (vNear != nullptr)
		{
			*pResult = vNear->position;
			*nResult = n;
			result = true;
		}
	}
	else
	{
		glm::vec3 origin, direction;
		if (intersectPlanePlane(f, p, n, &origin, &direction))
		{
			glm::vec3 nPotential, pPotential;
			float mostParellel = std::numeric_limits<float>::min();
			for (auto item : Vev)
			{
				nPotential = glm::cross(direction, item->position - origin);
				if (glm::length(nPotential) != 0) nPotential = glm::normalize(nPotential);
				if (glm::dot(nPotential, n) < 0) nPotential *= -1.f;
				pPotential = item->position;
				float parellel = glm::abs(glm::dot(nPotential, glm::normalize(f->nor)));//find the one most parellel to f
				MGlobal::displayInfo(MString("nPotential:") + nPotential.x + MString(",") + nPotential.y + MString(",") + nPotential.z + MString(" pPotential:") + pPotential.x + MString(",") + pPotential.y + MString(",") + pPotential.z + MString(" parallel:") + parellel);
				if (parellel > mostParellel)
				{
					*pResult = pPotential;
					*nResult = nPotential;
					mostParellel = parellel;
					result = true;
				}
			}
		}
	}

	return result;
}

void PPPPMesh::calculateNormal(PPPPFace *f)
{
	if (f == nullptr) return;
	PPPPHalfEdge* start = f->halfEdge;
	PPPPHalfEdge* current = start;
	glm::vec3 nor(0.f);
	glm::vec3 norSum(0.f);
	int norCount = 0;

	MGlobal::displayInfo(MString("calculate normal before do while"));

	do
	{
		MGlobal::displayInfo(MString("current edge id is:") + current->id);

		MGlobal::displayInfo(MString("current edge vert id is:") + current->vert->id);
		glm::vec3 v2 = current->vert->position;

		MGlobal::displayInfo(MString("current edge next id is:") + current->next->id);
		glm::vec3 v3 = current->next->vert->position;

		MGlobal::displayInfo(MString("current edge sym id is:") + current->sym->id);
		glm::vec3 v1 = current->sym->vert->position;



		nor = glm::cross(v3 - v2, v1 - v2);
		current = current->next;

		if (glm::length(nor) > EPSILON)
		{
			norSum += glm::normalize(nor);
			norCount++;
		}
	} while (current != start&&current != nullptr);

	MGlobal::displayInfo(MString("calculate normal after do while"));

	if (norCount != 0)
	{
		f->hasNor = true;
		f->nor = glm::normalize(norSum / (float)norCount);
	}
	else
	{
		if (f->hasNor)//if it originally has a normal
		{
			//do nothing
			//do not change the original normal of the face
		}
		else// if it originally doesn't have a normal
		{
			//something is wrong
			//beacause only zero face can arrive at this point
			//and normal are already set for zero faces when
			//they are created
		}
	}
}

void PPPPMesh::cleanUp(PPPPFace *f)
{
	if (f == nullptr) return;

	PPPPHalfEdge* start = f->halfEdge;
	PPPPHalfEdge* current = start;

	MGlobal::displayInfo(MString("cleanUp fadj"));

	do {
		PPPPVertex* currentVertex = current->vert;
		PPPPHalfEdge* subCurrent = current->next->sym->next;//check adjacent vertices except for the one connected with current
														/// by separating cleanUp function in to vertices on f and vertices adjacent to f
														/// we don't need to deal with the situation where current is accidentally deleted
														/// whereas subnext still can be deleted

		//qDebug() << "current:" << current->id;

		do {
			//qDebug() << "subCurrent:" << subCurrent->id;

			//last outer loop may delete a triangle by merging vertices,
			//resulting current and subcurrent becoming eachother's sym,
			//so we need to check first
			if (subCurrent == current->sym) break;//!!!!!

			PPPPHalfEdge* subNext = subCurrent->sym->next;
			PPPPHalfEdge* subNextSym = subNext->sym;//incase subNext is deleted
			PPPPHalfEdge* subNextEx = subNext->sym->next;//incase subNext is deleted
			float length = glm::length(currentVertex->position - subCurrent->vert->position);
			if (length < EPSILON)
			{
				int result = mergeVertex(currentVertex, subCurrent->vert, subCurrent);

				if (result & 3)//the triangle on both sides are deleted, subnext is gone
				{
					if (subNextSym == current) break;
					else subCurrent = subNextEx;
				}
				else if (result & 2)//the triangle on the DiscardToKeep side is deleted, subnext is gone
				{
					if (subNextSym == current) break;
					else subCurrent = subNextEx;
				}
				else if (result & 1)// the triangle on the KeepToDiscard side is deleted
				{
					subCurrent = subNext;
				}
				else
				{
					subCurrent = subNext;
				}
			}
			else
			{
				//mergeVertex will delete the whole triangle when there are less than 3 edges,
				//subNext may get deleted in this case. To avoid this invalid pointer, one simple
				//way is when deleting edges(or other elements in general), do not actually delete them
				//but only make the pointers pointing to them point to other elements or null,
				//and keeping them stored in the vectors temporarily with a tag. After the whole operation,
				//loop through the vectors and delete those elements which are tagged earlier.
				//Here we are using another method. Use the return value of mergeVertex to indicate whether the
				//triangle is deleted and act accordingly.

				//actually we are using both now
				//because when current and subcurrent are both on the face f and f is about to deleted
				//then there will be problems. we solved it by marking their flags as needToDelete and
				//delete them afterwards
				subCurrent = subNext;
			}

		} while (subCurrent != nullptr&&subCurrent != current->sym);//while(subCurrent!=nullptr&&subCurrent->sym!=current);

		current = current->next;
	} while (current != nullptr&&current != start);

	MGlobal::displayInfo(MString("cleanUp f"));
	/// after cleaning up the adjacent faces, we come back to clean f
	current = start;
	do
	{
		PPPPHalfEdge* currentNext = current->next;
		PPPPHalfEdge* currentNextNext = current->next->next;
		PPPPHalfEdge* currentSym = current->sym;
		PPPPVertex* currentVertex = current->vert;
		PPPPVertex* nextVertex = current->next->vert;
		float length = glm::length(currentVertex->position - nextVertex->position);
		if (length < EPSILON)//currentNext will be deleted
		{
			//if the edge we are about to delete is the start edge, we need to exit the loop by set the start to start->next
			if (current->next == start)
				start = current->next->next;

			int result = mergeVertex(currentVertex, nextVertex, current->next);
			if (result & 3)//the triangle on both sides are deleted, current, currentNext and currentNextNext is gone, face to edge case
			{
				//                //account for the remaining two vertices, but since the face is gone, we deal with it on the adjacent face
				//                current = currentSym->next;
				//                start = currentSym;
				current = currentSym;
				break;
			}
			else if (result & 2)//the triangle on the DiscardToKeep side is deleted, subnext is deleted
			{
				current = currentNextNext;
			}
			else if (result & 1)// the triangle on the KeepToDiscard side is deleted, current, currentNext and currentNextNext is gone, face to edge case
			{
				//                //account for the remaining two vertices, but since the face is gone, we deal with it on the adjacent face
				//                current = currentSym->next;
				//                start = currentSym;
				current = currentSym;
				break;
			}
			else
			{
				current = currentNextNext;
			}
		}
		else//currentNext will not be deleted
		{
			current = currentNext;
		}
	} while (current != nullptr&&current != start);


	/////////////////////Debugging/////////////////////////////////
	////////////////////not sure why///////////////////////////////
	MGlobal::displayInfo(MString("cleanUp edge to vertex case"));
	if (current == nullptr)
	{
		MGlobal::displayInfo(MString("current is nullptr"));
		return;
	}
	else 
	{
		bool rt = false;
		if (current->vert == nullptr)
		{
			MGlobal::displayInfo(MString("current->vert is nullptr"));
			rt = true;
		}

		if (current->sym == nullptr)
		{
			MGlobal::displayInfo(MString("current->sym is nullptr"));
			rt = true;
		}
		else if (current->sym->vert == nullptr)
		{
			MGlobal::displayInfo(MString("current->sym is nullptr"));
			rt = true;
		}

		if (rt) return;
	}
	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////

	//account for face to edge case, because it can become edge to vertex case
	float length = glm::length(current->vert->position - current->sym->vert->position);
	if (length < EPSILON)//currentNext will be deleted
	{
		int result = mergeVertex(current->vert, current->sym->vert, current);
		//don't care about result, because this can not be an edge to vertex case
	}
}

bool PPPPMesh::samePlane(glm::vec3 p1, glm::vec3 n1, glm::vec3 p2, glm::vec3 n2)
{
	n1 = glm::normalize(n1);//just to be robust
	n2 = glm::normalize(n2);//just to be robust
	if (glm::abs(1 - glm::dot(n1, n2)) < EPSILON && glm::abs(glm::dot(p2 - p1, n1)) < EPSILON)
		return true;
	else
		return false;
}

void PPPPMesh::realDelete()
{
	for (auto iter = hVector.begin(); iter != hVector.end();)
	{
		if ((*iter)->needToDelete)
		{

			delete(*iter);
			iter = hVector.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	for (auto iter = vVector.begin(); iter != vVector.end();)
	{
		if ((*iter)->needToDelete)
		{
			delete(*iter);
			iter = vVector.erase(iter);
		}
		else
		{
			iter++;
		}
	}


	for (auto iter = fVector.begin(); iter != fVector.end();)
	{
		if ((*iter)->needToDelete)
		{
			delete(*iter);
			iter = fVector.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

bool PPPPMesh::intersectPlanePlanePlane(PPPPFace *f1,
	PPPPFace *f2,
	PPPPFace *f3,
	glm::vec3 *intersection)
{
	if (f1 == nullptr || f2 == nullptr || f3 == nullptr) return false;
	glm::vec3 v1 = f1->halfEdge->vert->position;
	glm::vec3 v2 = f2->halfEdge->vert->position;
	glm::vec3 v3 = f3->halfEdge->vert->position;

	/// keep the normal normalized, because dot product will be used to determine whether it overlap with another direction or not
	glm::vec3 n1 = glm::normalize(f1->nor);
	glm::vec3 n2 = glm::normalize(f2->nor);
	glm::vec3 n3 = glm::normalize(f3->nor);

	if (glm::abs(glm::dot(n1, n2)) == 1)//parallel
	{
		n1.x += EPSILON;//change n1 a little bit
		n1 = glm::normalize(n1);
	}

	if (glm::abs(glm::dot(n3, n2)) == 1)//parallel
	{
		n3.y += EPSILON;//change n3 a little bit
		n3 = glm::normalize(n3);
	}

	//qDebug() << "PPP>>>n1:" << n1.x << "," << n1.y << "," << n1.z << ">>>n2:" << n2.x << "," << n2.y << "," << n2.z << ">>>n3:" << n3.x << "," << n3.y << "," << n3.z;
	if (glm::abs(glm::dot(n1, n3)) == 1 || glm::abs(glm::dot(n2, n3)) == 1 || glm::abs(glm::dot(n1, n2)) == 1)//invalid situation
		return false;

	//ALERT: following code is not stable, inverse is not guaranteed
	//EDIT: it seems preventing parallel situation guaranteed the inverse exist
	glm::mat3x3 invA = glm::inverse(glm::transpose(glm::mat3x3(n1, n2, n3)));
	glm::vec3 b(glm::dot(v1, n1), glm::dot(v2, n2), glm::dot(v3, n3));
	*intersection = invA * b;
	return true;
}

bool PPPPMesh::betweenFacePlane(PPPPVertex *v, PPPPFace *f, glm::vec3 p, glm::vec3 n)
{
	if (v == nullptr || f == nullptr) return false;

	bool result = false;

	glm::vec3 v1 = f->halfEdge->vert->position;
	glm::vec3 n1 = glm::normalize(f->nor);

	/// keep the normal normalized, because dot product will be used to determine whether it overlap with another direction or not
	n = glm::normalize(n);//shiiiiiiit, just to be robust, we do it here again,

	if (glm::dot(n1, n) > 0)//when push, to find vertices between the two plane, we need to flip the normal of the surface plane
	{
		n1 *= -1.f;
	}

	if (glm::abs(glm::dot(v->position - v1, n1)) > EPSILON &&
		glm::abs(glm::dot(v->position - p, n)) > EPSILON &&
		glm::dot(v->position - v1, n1) * glm::dot(v->position - p, n) > 0)//on the same side of both plane, and not on either of them
		result = true;
	else
		result = false;

	//qDebug() << "------In betweenFacePlane v:"
		//<< v->position.x << "," << v->position.y << "," << v->position.z << " v1:"
		//<< v1.x << "," << v1.y << "," << v1.z << " n1:"
		//<< n1.x << "," << n1.y << "," << n1.z << " p:"
		//<< p.x << "," << p.y << "," << p.z << " n:"
		//<< n.x << "," << n.y << "," << n.z << " between ? :" << result;

	return result;
}

float PPPPMesh::distanceToPlane(PPPPVertex *v, PPPPFace *f)
{
	if (v == nullptr || f == nullptr)
		return -1;//negative number indicating error

	glm::vec3 V = v->position;
	glm::vec3 n = glm::normalize(f->nor);
	glm::vec3 p = f->halfEdge->vert->position;

	return glm::abs(glm::dot(V - p, n));
}

bool PPPPMesh::intersectPlanePlane(PPPPFace *f, glm::vec3 p, glm::vec3 n, glm::vec3 *origin, glm::vec3 *direction)
{
	if (f == nullptr) return false;
	glm::vec3 v1 = f->halfEdge->vert->position;
	glm::vec3 n1 = glm::normalize(f->nor);

	n = glm::normalize(n);//just to be robust

	if (1 - glm::abs(glm::dot(n1, n)) < EPSILON)//parallel
		return false;


	//ALERT: following code is not stable, inverse is not guaranteed
	//EDIT: it seems preventing parallel situation guaranteed the inverse exist

	glm::vec3 cross = glm::cross(n1, n);

	if (cross.x != 0)//can safely assume dx = 1
	{
		//assume dx = 1
		glm::vec2 b(-n1.x, -n.x);
		glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.y, n.y), glm::vec2(n1.z, n.z)));
		glm::vec2 x = invA * b;
		*direction = glm::normalize(glm::vec3(1, x.x, x.y));
	}
	else if (cross.y != 0)//can safely assume dy = 1
	{
		//assume dx = 1
		glm::vec2 b(-n1.y, -n.y);
		glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.x, n.x), glm::vec2(n1.z, n.z)));
		glm::vec2 x = invA * b;
		*direction = glm::normalize(glm::vec3(x.x, 1, x.y));
	}
	else if (cross.z != 0)//can safely assume dz = 1
	{
		//assume dz = 1
		glm::vec2 b(-n1.z, -n.z);
		glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.x, n.x), glm::vec2(n1.y, n.y)));
		glm::vec2 x = invA * b;
		*direction = glm::normalize(glm::vec3(x.x, x.y, 1));
	}
	else
	{
		return false;
	}

	float v1n1 = glm::dot(v1, n1);
	float pn = glm::dot(p, n);
	if (cross.x != 0)//can safely assume ox = 1
	{
		//assume ox = 1
		glm::vec2 b(v1n1 - n1.x, pn - n.x);
		glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.y, n.y), glm::vec2(n1.z, n.z)));
		glm::vec2 x = invA * b;
		*origin = glm::vec3(1, x.x, x.y);
	}
	else if (cross.y != 0)//can safely assume oy = 1
	{
		//assume oy = 1
		glm::vec2 b(v1n1 - n1.y, pn - n.y);
		glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.x, n.x), glm::vec2(n1.z, n.z)));
		glm::vec2 x = invA * b;
		*origin = glm::vec3(x.x, 1, x.y);
	}
	else if (cross.z != 0)//can safely assume oz = 1
	{
		//assume oz = 1
		glm::vec2 b(v1n1 - n1.z, pn - n.z);
		glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.x, n.x), glm::vec2(n1.y, n.y)));
		glm::vec2 x = invA * b;
		*origin = glm::vec3(x.x, x.y, 1);
	}
	else
	{
		return false;
	}

	return true;
}

//return value indicates whether a triangle is deleted or not!!!
int PPPPMesh::mergeVertex(PPPPVertex *vKeep, PPPPVertex *vDiscard, PPPPHalfEdge* KeepToDiscard)
{
	if (vKeep == nullptr || vDiscard == nullptr || KeepToDiscard == nullptr)
		return 0;


	MGlobal::displayInfo(MString("mergeVertex: ") + vKeep->id + MString(",") + vDiscard->id + MString(",") + KeepToDiscard->id);

	PPPPHalfEdge* start = vDiscard->halfEdge;
	PPPPHalfEdge* current = start;
	do {
		if (current == nullptr) break;//in case the first time is nullptr
		MGlobal::displayInfo(MString("merge current:") + current->id);
		if (current->sym == nullptr) break;
		MGlobal::displayInfo(MString("merge currentSym:") + current->sym->id);
		current->sym->vert = vKeep;//point all the edges pointing to vDiscard to vKeep
		current = current->sym->next;
	} while (current != nullptr&&current != start);
	deleteVertex(&vDiscard);

	PPPPHalfEdge* DiscardToKeep = KeepToDiscard->sym;
	int result = 0;
	if (removeEdge(KeepToDiscard)) result = result | 1;// 1 for deleting k2d triangle
	if (removeEdge(DiscardToKeep)) result = result | 2;// 2 for deleting d2k triangle
													   // 3 for deleting both

	MGlobal::displayInfo(MString("mergeVertex finish, deleted triangle ? :") + result);

	return result;
}

//return value indicates whether a triangle is deleted or not!!!
bool PPPPMesh::removeEdge(PPPPHalfEdge *e)
{
	if (e == nullptr) return false;

	bool result = false;

	MGlobal::displayInfo(MString("removeEdge:") + e->id);
	//printFace(e->face);

	PPPPHalfEdge* start = e;
	PPPPHalfEdge* last = start->next;
	int count = 2;
	while (last != nullptr&&last->next != start)
	{
		count++;
		last = last->next;
	}

	if (start->face->halfEdge == start)
		start->face->halfEdge = last;

	if (count <= 3)
	{
		if (last != nullptr)
		{
			last->sym->sym = start->next->sym;
			start->next->sym->sym = last->sym;
			if (start->vert->halfEdge == start->next) start->vert->halfEdge = last->sym;
			if (start->next->vert->halfEdge == last) start->next->vert->halfEdge = start->next->sym;
			if (last->vert->halfEdge == start) last->vert->halfEdge = last->sym;
			deleteEdge(&last);
		}
		deleteEdge(&start->next);
		deleteFace(&start->face);
		result = true;
	}
	else
	{
		if (last != nullptr)
			last->next = start->next;
	}

	MGlobal::displayInfo(MString("removeEdge finish"));
	//printFace(e->face);

	deleteEdge(&e);
	return result;
}

void PPPPMesh::deleteEdge(PPPPHalfEdge **e)
{
	if (*e == nullptr) return;

	for (auto iter = hVector.begin(); iter != hVector.end(); iter++)
	{
		if (*iter == *e)
		{
			//iter = hVector.erase(iter);
			(*iter)->needToDelete = true;
			break;
		}
	}
	//delete *e;
	*e = nullptr;
}

void PPPPMesh::deleteFace(PPPPFace **f)
{
	if (*f == nullptr) return;

	MGlobal::displayInfo(MString("deleteFace:") + (*f)->id);
	for (auto iter = fVector.begin(); iter != fVector.end(); iter++)
	{
		if (*iter == *f)
		{
			//iter = fVector.erase(iter);
			(*iter)->needToDelete = true;
			break;
		}
	}
	//delete *f;
	*f = nullptr;
}
std::vector<glm::vec3> Kmean(int k, std::vector<glm::vec3> vec_set)
{
	vector<Point> points;
	int total_points, total_values, max_iterations;
	total_values = 3;
	total_points = vec_set.size();
	max_iterations = 100;
	for (int i = 0; i<total_points; i++)
	{
		vector<double> values;
		for (int j = 0; j<total_values; j++)
		{
			values.push_back(vec_set[i][j]);
		}
		points.push_back(Point(i, values));
	}
	KMeans kmeans(k, total_points, total_values, max_iterations);
	kmeans.run(points);
	vector<glm::vec3> new_set;
	for (int i = 0; i<k; i++)
	{
		glm::vec3 tmp;
		for (int j = 0; j<total_values; j++)
		{

			tmp[j] = kmeans.clusters[i].getCentralValue(j);

		}
		new_set.push_back(tmp);
	}

	return new_set;
}
void PPPPMesh::facedirectionRecomendation(PPPPFace *f, glm::vec3& p, int isfirst, float& theta, glm::vec3& n , float dis ,int thre,int kmeansel,int axis)
{
	int dir_count = 0;
	calculateNormal(f);
	std::vector<glm::vec3> Dirs;
	glm::vec3 Dir_sum(0.f);
	PPPPHalfEdge* start_HF = f->halfEdge;
	PPPPHalfEdge* Hf = start_HF;
	glm::vec3 facecenter(0, 0, 0);
	do
	{
		PPPPFace* adjF = Hf->sym->face;
		PPPPHalfEdge* adjE = Hf->sym;
		facecenter += Hf->vert->position;
		calculateNormal(adjF);
		glm::vec3 advecDir = glm::normalize(glm::cross(adjF->nor, (Hf->vert->position - adjE->vert->position)));
		Dirs.push_back(advecDir);
		Dir_sum += advecDir;
		dir_count++;
		Hf = Hf->next;
	}
	while (Hf != f->halfEdge);
	facecenter /= dir_count;
	Dirs = Kmean(2, Dirs);//currently set to 2 clusters, can be changed if want different results
	if (isfirst == 1&&axis==1) 
	{ 
		if (thre == 1)
		{
			theta = 0;
		}
		else
			theta = this->theta;
		n = glm::vec3(1, 0, 0); 
		p = n*dis + facecenter;
		//n = glm::normalize(f->nor);//you can change the final target face normal
	}
	else if (isfirst == 1 && axis == 2)
	{
		if (thre == 1)
		{
			theta = 0;
		}
		else
			theta = this->theta;
		n = glm::vec3(0, 1, 0);
		p = n*dis + facecenter;
		//n = glm::normalize(f->nor);//you can change the final target face normal
	}

	else if (isfirst == 1 && axis == 3)
	{
		if (thre == 1)
		{
			theta = 0;
		}
		else
			theta = this->theta;
		n = glm::vec3(0, 0, 1);
		p = n*dis + facecenter;
		//n = glm::normalize(f->nor);//you can change the final target face normal
	}

	else if (isfirst == 2) 
	{
		if (thre==1)
		{
			theta = 0;
		}
		else
			theta = this->theta;
		n = glm::normalize(f->nor);
		p = n*dis + facecenter;
	}
	else if (isfirst == 3) 
	{ 
		if (thre == 1)
		{
			theta = 80;
		}
		else
			theta = this->theta;
		n = glm::normalize(f->nor);
		p = n*dis + facecenter;
		//n = glm::normalize(f->nor);//you can change the final target face normal
	}
	else if (isfirst == 4&&kmeansel==1) //the first k-mean value for the adj face dirs
	{
		if (thre==1)
		{
			theta = 15;
		}
		else
			theta = this->theta;
		/*n=glm::normalize(glm::vec3(f->nor.x,0,f->nor.y))*/
		n = glm::dot(f->nor, Dirs[0]) > 0 ? Dirs[0] : -Dirs[0];
		p = n*dis + facecenter;
		//n = glm::normalize(f->nor);//you can change the final target face normal
		
	}
	else if (isfirst == 4&&kmeansel==2)//the second k-mean value
	{
		if (thre==1)
		{
			theta = 15;
		}
		else
			theta = this->theta;
		/*n=glm::normalize(glm::vec3(f->nor.x,0,f->nor.y))*/
		n = glm::dot(f->nor, Dirs[1]) > 0 ? Dirs[1] : -Dirs[1];
		p = n*dis + facecenter;
		//n = glm::normalize(f->nor);//you can change the final target face normal
	}
}