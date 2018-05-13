#pragma once

#include "PPPPHalfEdge.h"

class PPPPHalfEdge;

class PPPPFace
{
public:
	PPPPFace();
	PPPPFace(PPPPHalfEdge *h);
	PPPPFace(PPPPHalfEdge *h, glm::vec3 _col);
	PPPPFace(PPPPHalfEdge *h, glm::vec3 _col, glm::vec3 _nor, bool _hasNor);
	PPPPFace(glm::vec3 _nor, bool hasNor);
	~PPPPFace();

	PPPPHalfEdge* halfEdge;
	glm::vec3 col;
	glm::vec3 nor;
	bool hasNor;
	int id;
	bool needToDelete;

	static int id_next;
};

