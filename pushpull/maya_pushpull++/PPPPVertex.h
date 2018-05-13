#pragma once

#include "glm\glm.hpp"
#include "PPPPHalfEdge.h"

class PPPPHalfEdge;

class PPPPVertex
{
public:
	PPPPVertex();
	PPPPVertex(glm::vec3 pos);
	~PPPPVertex();

	glm::vec3 position;
	PPPPHalfEdge* halfEdge;
	int id;
	int index;//for temporary mapping vertex pointer to index in the vector
	bool needToDelete;

	static int id_next;
};

