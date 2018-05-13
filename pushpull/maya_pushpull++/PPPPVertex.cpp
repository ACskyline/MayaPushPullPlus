#include "PPPPVertex.h"

int PPPPVertex::id_next = 1;

PPPPVertex::PPPPVertex() : position(glm::vec3(0.f,0.f,0.f)), halfEdge(nullptr), id(id_next++)
{

	needToDelete = false;
}

PPPPVertex::PPPPVertex(glm::vec3 pos) : position(pos), halfEdge(nullptr), id(id_next++)
{

	needToDelete = false;
}

PPPPVertex::~PPPPVertex()
{

}
