#ifndef LINE_H
#define LINE_H

#include "drawable.h"
#include "halfedge.h"

class Line : public Drawable
{
public:
    glm::vec4 v1;
    glm::vec4 v2;

    Line(GLWidget277* mp_context);
    virtual void create();
    virtual GLenum drawMode();

    void setUp(HalfEdge* h);
};

#endif // LINE_H
