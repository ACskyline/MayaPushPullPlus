#include "PPPPFace.h"

int PPPPFace::id_next = 1;

PPPPFace::PPPPFace() : halfEdge(nullptr), col(glm::vec3(0,0,1)), id(id_next++)
{

	needToDelete = false;
}

PPPPFace::PPPPFace(PPPPHalfEdge *h) : halfEdge(h), col(glm::vec3(0,0,1)), id(id_next++)
{

	needToDelete = false;
}

PPPPFace::PPPPFace(PPPPHalfEdge *h, glm::vec3 _col) : PPPPFace(h, _col, glm::vec3(0,0,0), false)
{

	needToDelete = false;
}

PPPPFace::PPPPFace(PPPPHalfEdge *h, glm::vec3 _col, glm::vec3 _nor, bool _hasNor) : 
	halfEdge(h), col(_col), nor(_nor), hasNor(_hasNor), id(id_next++)
{

	needToDelete = false;
}

PPPPFace::PPPPFace(glm::vec3 _nor, bool _hasNor) : halfEdge(nullptr), nor(_nor), hasNor(_hasNor), id(id_next++)
{

	needToDelete = false;
}

PPPPFace::~PPPPFace()
{
}
