#pragma once

#include "PPPPVertex.h"
#include "PPPPFace.h"

class PPPPFace;
class PPPPVertex;

class PPPPHalfEdge
{
public:
	PPPPHalfEdge();
	PPPPHalfEdge(PPPPVertex* v);
	PPPPHalfEdge(PPPPVertex* v, PPPPFace* f);
	~PPPPHalfEdge();

	PPPPHalfEdge* next;
	PPPPHalfEdge* sym;
	PPPPFace* face;
	PPPPVertex* vert;
	int id;
	bool needToDelete;

	static int id_next;
};

