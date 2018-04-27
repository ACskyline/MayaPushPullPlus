#include "point.h"

Point::Point(GLWidget277 *context) : Drawable(context)
{

}

void Point::create()
{
    destroy();
    glm::vec4 vert_pos[1];
    glm::vec4 vert_col[1];
    GLuint idx[1];

    vert_pos[0] = v1;
    vert_col[0] = glm::vec4(1,1,1,1);
    idx[0] = 0;

    count = 1;

    // Create a VBO on our GPU and store its handle in bufIdx
    generateIdx();
    // Tell OpenGL that we want to perform subsequent operations on the VBO referred to by bufIdx
    // and that it will be treated as an element array buffer (since it will contain triangle indices)
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    // Pass the data stored in cyl_idx into the bound buffer, reading a number of bytes equal to
    // CYL_IDX_COUNT multiplied by the size of a GLuint. This data is sent to the GPU to be read by shader programs.
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, 1 * sizeof(GLuint), idx, GL_STATIC_DRAW);

    // The next few sets of function calls are basically the same as above, except bufPos and bufNor are
    // array buffers rather than element array buffers, as they store vertex attributes like position.
    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, 1 * sizeof(glm::vec4), vert_pos, GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, 1 * sizeof(glm::vec4), vert_col, GL_STATIC_DRAW);
}

GLenum Point::drawMode()
{
    return GL_POINTS;
}

void Point::setUp(Vertex* v)
{
    if(v!=nullptr)
    {
        v1 = glm::vec4(v->position,1);
        create();
    }
}
