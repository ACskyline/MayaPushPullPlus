#ifndef POINT_H
#define POINT_H

#include "drawable.h"
#include "vertex.h"

class Point : public Drawable
{
public:
    glm::vec4 v1;

    Point(GLWidget277* mp_context);
    virtual void create();
    virtual GLenum drawMode();
    void setUp(Vertex* v);
};

#endif // POINT_H
