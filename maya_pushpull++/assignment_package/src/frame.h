#ifndef FRAME_H
#define FRAME_H

#include "drawable.h"
#include "face.h"

class Frame : public Drawable
{
public:
    std::vector<glm::vec4> vV;
    glm::vec4 col;

    Frame(GLWidget277* mp_context);
    virtual void create();
    virtual GLenum drawMode();

    void setUp(Face* f);
};

#endif // FRAME_H
