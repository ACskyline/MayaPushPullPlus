#ifndef FACE_H
#define FACE_H

#include "la.h"
#include "halfedge.h"
#include <QListWidgetItem>

class HalfEdge;

class Face : public QListWidgetItem
{
public:
    Face();
    Face(HalfEdge* h);
    Face(HalfEdge *h, glm::vec3 _col);
    Face(HalfEdge *h, glm::vec3 _col, glm::vec3 _nor, bool hasNor);
    virtual ~Face();

    HalfEdge* halfEdge;
    glm::vec3 col;
    glm::vec3 nor;
    bool hasNor;
    int id;

    static int id_next;
};

#endif // FACE_H
