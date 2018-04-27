#ifndef MESH_H
#define MESH_H

#include "drawable.h"
#include "halfedge.h"
#include "skeleton.h"
#include <QFile>
#include <deque>

class Mesh : public Drawable
{
private:
    void parseObjFace(std::stringstream &ss);
    void setSyms();
public:
    std::vector<HalfEdge*> hVector;
    std::vector<Vertex*> vVector;
    std::vector<Face*> fVector;
    Mesh(GLWidget277 *context);
    ~Mesh();
    void freeMemory();
    void initializeCube();
    void virtual create();
    void createConvex(Face* f,
                      glm::vec3 fnor,
                      glm::vec3 fcol,
                      std::vector<GLuint>& mesh_idx,
                      std::vector<glm::vec4>& mesh_vert_pos,
                      std::vector<glm::vec4>& mesh_vert_nor,
                      std::vector<glm::vec4>& mesh_vert_col,
                      std::vector<glm::uvec4>& mesh_vert_JIndex,
                      std::vector<glm::vec4>& mesh_vert_JWeight);
    void createTriangle(HalfEdge* begin,
                        HalfEdge* end,
                        glm::vec3 fnor,
                        glm::vec3 fcol,
                        std::vector<GLuint>& mesh_idx,
                        std::vector<glm::vec4>& mesh_vert_pos,
                        std::vector<glm::vec4>& mesh_vert_nor,
                        std::vector<glm::vec4>& mesh_vert_col,
                        std::vector<glm::uvec4>& mesh_vert_JIndex,
                        std::vector<glm::vec4>& mesh_vert_JWeight);
    void splitEdge(HalfEdge* h);
    void triangulateFace(Face* f);
    void concave2Convex(Face *f);
    void convex2Triangle(Face *f);
    HalfEdge* findStart(HalfEdge *e);//starting from e, find the first angle which is greater than 180 whose next angle is less than 180
    void subdivide();
    void smoothMidPoint(HalfEdge* h, std::map<Face*, glm::vec3>& FtoC);
    void extrudeFace(Face*f, glm::vec3 offset);
    void bevelEdge(HalfEdge* h);
    void parseFile(QFile* F);
    void skin(const Skeleton &s);
    void pushPullPP(Face* f, glm::vec3 d, float theta, glm::vec3 p, glm::vec3 n);
    void pushPullPPInsertFace(Face* f, float theta, glm::vec3 n);
    void pushPullPPUpdateMesh(Face* f, glm::vec3 p, glm::vec3 n);
    void replaceVertex(Face* f, Vertex* v, std::vector<Vertex*>& Vsel);
    void insertBefore(Face* f, Vertex* v, std::vector<Vertex*>& Vsel);
    void insertAfter(Face* f, Vertex* v, std::vector<Vertex*>& Vsel);
    Face* getNextFace(Face* f, const std::deque<Face*>& Ffan);
    Face* getPreviousFace(Face* f, const std::deque<Face*>& Ffan);
    void deleteVertex(Vertex** v);
    bool faceBelong(Face*f, std::vector<Face*> Faff);
    bool samePlane(glm::vec3 p1, glm::vec3 n1, glm::vec3 p2, glm::vec3 n2);
    float distanceToPlane(Vertex* v, Face* f);bool intersectFacePlane(Face* f, glm::vec3 p, glm::vec3 n);
    bool intersectPlanePlane(Face *f, glm::vec3 p, glm::vec3 n, glm::vec3* origin, glm::vec3* direction);
    bool intersectPlanePlanePlane(Face* f1, Face* f2, glm::vec3 p, glm::vec3 n, glm::vec3* intersection);
    bool intersectPlanePlanePlane(Face* f1, Face* f2, Face* f3, glm::vec3* intersection);
    bool betweenFacePlane(Vertex* v, Face* f, glm::vec3 p, glm::vec3 n);
    void calculateNormal(Face* f);
    void fullZeroFace(Vertex* v1, Vertex* v2, Vertex* v3, HalfEdge* e, HalfEdge* e1, HalfEdge *e2, glm::vec3 n);
    void firstHalfZeroFace(Vertex* v1, Vertex* v2, Vertex* v3, HalfEdge* e, HalfEdge* e1, HalfEdge *e2, glm::vec3 n);
    void secondHalfZeroFace(Vertex* v1, Vertex* v2, Vertex* v3, HalfEdge* e, HalfEdge* e1, HalfEdge *e2, glm::vec3 n);
    void oneEdgeZeroFace(Vertex* v1, Vertex* v2, Vertex* v3, HalfEdge* e, HalfEdge* e1, HalfEdge *e2, glm::vec3 n);
    void printFace(Face* f);
    void cleanUp(Face* f);
    bool getNextStep(Face* f, glm::vec3 n, glm::vec3 p, glm::vec3 *nResult, glm::vec3 *pResult);
    bool mergeVertex(Vertex* vKeep, Vertex* vDiscard, HalfEdge* KeepToDiscard);
    bool removeEdge(HalfEdge* e);
    void deleteFace(Face** f);
    void deleteEdge(HalfEdge** e);
};

#endif // MESH_H
