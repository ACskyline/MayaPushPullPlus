#ifndef HALFEDGE_H
#define HALFEDGE_H

#include "face.h"
#include "vertex.h"
#include <QListWidgetItem>

class Face;
class Vertex;

class HalfEdge : public QListWidgetItem
{
public:
    HalfEdge();
    HalfEdge(Vertex* v);

    HalfEdge* next;
    HalfEdge* sym;
    Face* face;
    Vertex* vert;
    int id;

    static int id_next;
};

#endif // HALFEDGE_H
