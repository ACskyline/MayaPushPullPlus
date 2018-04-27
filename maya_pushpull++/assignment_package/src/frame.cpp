#include "frame.h"

Frame::Frame(GLWidget277 *context) : Drawable(context)
{

}

void Frame::create()
{
    destroy();
    std::vector<GLuint> idx;
    std::vector<glm::vec4> vert_col;

    for(int i = 0;i<vV.size();i++)
    {
        idx.push_back(i);
        idx.push_back((i+1)%vV.size());
        vert_col.push_back(col);
    }

    count = idx.size();

    // Create a VBO on our GPU and store its handle in bufIdx
    generateIdx();
    // Tell OpenGL that we want to perform subsequent operations on the VBO referred to by bufIdx
    // and that it will be treated as an element array buffer (since it will contain triangle indices)
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    // Pass the data stored in cyl_idx into the bound buffer, reading a number of bytes equal to
    // CYL_IDX_COUNT multiplied by the size of a GLuint. This data is sent to the GPU to be read by shader programs.
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, idx.size() * sizeof(GLuint), idx.data(), GL_STATIC_DRAW);

    // The next few sets of function calls are basically the same as above, except bufPos and bufNor are
    // array buffers rather than element array buffers, as they store vertex attributes like position.
    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, vV.size() * sizeof(glm::vec4), vV.data(), GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, vert_col.size() * sizeof(glm::vec4), vert_col.data(), GL_STATIC_DRAW);
}

GLenum Frame::drawMode()
{
    return GL_LINES;
}

void Frame::setUp(Face* f)
{
    if(f!=nullptr)
    {
        vV.clear();
        HalfEdge *startE = f->halfEdge;
        HalfEdge *curE = startE;
        do
        {
            vV.push_back(glm::vec4(curE->vert->position,1));
            curE = curE->next;
        }
        while(curE!=startE);
        col = glm::vec4(glm::vec3(1,1,1) - glm::vec3(f->col),1);

        create();
    }
}
