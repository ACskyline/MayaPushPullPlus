#include "marker.h"
#include <glm/gtc/constants.hpp>

Marker::Marker(GLWidget277 *context, glm::vec4 _col_frame_x, glm::vec4 _col_frame_y,glm::vec4 _col_frame_z, glm::vec4 _col_line, float _radius)
    : Drawable(context), radius(_radius), col_frame_x(_col_frame_x), col_frame_y(_col_frame_y),col_frame_z(_col_frame_z),col_line(_col_line), jointCount(0)
{
}

void Marker::create()
{
    destroy();
    std::vector<GLuint> idx;
    std::vector<glm::vec4> vert_col;

    int vNumPerMarker = vV.size()/jointCount;
    int vNumPerRing = (vNumPerMarker-2)/3;
    for(int k = 0;k<jointCount;k++)
    {
        for(int j = 0;j<3;j++)
        {
            int istart = j * vNumPerRing + k * vNumPerMarker;
            glm::vec4 col_frame = j==0 ? col_frame_x : (j==1 ? col_frame_y : (j==2 ? col_frame_z : glm::vec4(1,1,1,1)));
            for(int i = 0;i<vNumPerRing;i++)
            {
                idx.push_back(istart + i);
                idx.push_back(istart + (i+1)%(vNumPerRing));
                vert_col.push_back(col_frame);
            }
        }
        idx.push_back((k+1) * vNumPerMarker - 2);
        idx.push_back((k+1) * vNumPerMarker - 1);
        vert_col.push_back(col_line);
        vert_col.push_back(glm::vec4(1-col_line.r,1-col_line.g,1-col_line.b,1));
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

GLenum Marker::drawMode()
{
    return GL_LINES;
}

void Marker::setUpJoint(Joint *j, int segment)
{
    if(j!=nullptr)
    {
        glm::mat4 worldM = j->getOverallTransformation();
        glm::vec4 posWorld = worldM * glm::vec4(0,0,0,1);

        //y-z plane, x axis
        for(int i = 0;i<segment;i++)
        {
            vV.push_back(posWorld + worldM *
                         (
                          glm::rotate(glm::mat4(),i * 2.f * glm::pi<float>()/segment, glm::vec3(1,0,0)) *
                          glm::vec4(0,radius,0,1)));
        }
        //x-z plane, y axis
        for(int i = 0;i<segment;i++)
        {
            vV.push_back(posWorld + worldM *
                         (
                          glm::rotate(glm::mat4(),i * 2.f * glm::pi<float>()/segment, glm::vec3(0,1,0)) *
                          glm::vec4(0,0,radius,1)));
        }
        //x-y plane, z axis
        for(int i = 0;i<segment;i++)
        {
            vV.push_back(posWorld + worldM *
                         (
                          glm::rotate(glm::mat4(),i * 2.f * glm::pi<float>()/segment, glm::vec3(0,0,1)) *
                          glm::vec4(radius,0,0,1)));
        }
        vV.push_back(posWorld);
        if(j->parent!=nullptr)
        {
            vV.push_back(j->parent->getOverallTransformation()*glm::vec4(0,0,0,1));
        }
        else
        {
            vV.push_back(posWorld);
        }

        jointCount++;
    }
}

void Marker::setUpJoints(Joint *j, int segment)
{
    if(j!=nullptr)
    {
        glm::mat4 worldM = j->getOverallTransformation();
        glm::vec4 posWorld = worldM * glm::vec4(0,0,0,1);

        //y-z plane, x axis
        for(int i = 0;i<segment;i++)
        {
            vV.push_back(posWorld + worldM *
                         (
                          glm::rotate(glm::mat4(),i * 2.f * glm::pi<float>()/segment, glm::vec3(1,0,0)) *
                          glm::vec4(0,radius,0,1)));
        }
        //x-z plane, y axis
        for(int i = 0;i<segment;i++)
        {
            vV.push_back(posWorld + worldM *
                         (
                          glm::rotate(glm::mat4(),i * 2.f * glm::pi<float>()/segment, glm::vec3(0,1,0)) *
                          glm::vec4(0,0,radius,1)));
        }
        //x-y plane, z axis
        for(int i = 0;i<segment;i++)
        {
            vV.push_back(posWorld + worldM *
                         (
                          glm::rotate(glm::mat4(),i * 2.f * glm::pi<float>()/segment, glm::vec3(0,0,1)) *
                          glm::vec4(radius,0,0,1)));
        }
        vV.push_back(posWorld);
        if(j->parent!=nullptr)
        {
            vV.push_back(j->parent->getOverallTransformation()*glm::vec4(0,0,0,1));
        }
        else
        {
            vV.push_back(posWorld);
        }

        jointCount++;

        for(int i = 0;i<j->children.size();i++)
        {
            setUpJoints(j->children.at(i));
        }
    }
}

//display one joint
void Marker::setUp(Joint *j, int segment)
{
    jointCount = 0;
    vV.clear();
    setUpJoint(j, segment);
    create();
}

//display whole skeleton
void Marker::setUp(const Skeleton &s, int segment)
{
    jointCount = 0;
    vV.clear();
    setUpJoints(s.root, segment);
    create();
}
