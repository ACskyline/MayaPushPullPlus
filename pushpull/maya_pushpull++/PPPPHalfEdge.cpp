#include "PPPPHalfEdge.h"

int PPPPHalfEdge::id_next = 1;

PPPPHalfEdge::PPPPHalfEdge() : next(nullptr), sym(nullptr), face(nullptr), vert(nullptr), id(id_next++)
{
	needToDelete = false;

}

PPPPHalfEdge::PPPPHalfEdge(PPPPVertex* v) : next(nullptr), sym(nullptr), face(nullptr), vert(v), id(id_next++)
{
	needToDelete = false;

}

PPPPHalfEdge::PPPPHalfEdge(PPPPVertex* v, PPPPFace* f) 
	: next(nullptr), sym(nullptr), face(f), vert(v), id(id_next++)
{

	needToDelete = false;
}

PPPPHalfEdge::~PPPPHalfEdge()
{

}
