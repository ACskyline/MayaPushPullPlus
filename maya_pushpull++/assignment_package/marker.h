#ifndef MARKER_H
#define MARKER_H

#include "drawable.h"
#include "skeleton.h"

class Marker : public Drawable
{
private:
    void setUpJoint(Joint* j, int segment = 20);
    void setUpJoints(Joint* j, int segment = 20);
public:
    std::vector<glm::vec4> vV;
    glm::vec4 lineV1;
    glm::vec4 lineV2;
    glm::vec4 col_frame_x;
    glm::vec4 col_frame_y;
    glm::vec4 col_frame_z;
    glm::vec4 col_line;
    float radius;
    int jointCount;

    Marker(GLWidget277 *mp_context,
           glm::vec4 _col_frame_x = glm::vec4(1,0,0,1),
           glm::vec4 _col_frame_y = glm::vec4(0,1,0,1),
           glm::vec4 _col_frame_z = glm::vec4(0,0,1,1),
           glm::vec4 _col_line = glm::vec4(0.8,0.2,0.6,1),
           float _radius = .5f);
    virtual void create();
    virtual GLenum drawMode();

    void setUp(Joint* j, int segment = 20);
    void setUp(const Skeleton &s, int segment = 20);
};

#endif // MARKER_H
