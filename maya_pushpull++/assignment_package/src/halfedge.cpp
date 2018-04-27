#include "halfedge.h"

int HalfEdge::id_next = 1;

HalfEdge::HalfEdge() : next(nullptr), sym(nullptr), face(nullptr), vert(nullptr), id(id_next++)
{
    QListWidgetItem::setText(QString("HalfEdge ") + QString::number(id));
}

HalfEdge::HalfEdge(Vertex* v) : next(nullptr), sym(nullptr), face(nullptr), vert(v), id(id_next++)
{
    QListWidgetItem::setText(QString("HalfEdge ") + QString::number(id));
}

