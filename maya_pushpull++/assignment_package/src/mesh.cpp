#include "mesh.h"
#include <stack>
#include <sstream>
#include <cstdlib>
#include <ctime>

#define EPSILON 0.0001

Mesh::Mesh(GLWidget277 *context) : Drawable(context)
{
    initializeCube();
}


Mesh::~Mesh()
{
    destroy();
    freeMemory();
}


void Mesh::freeMemory()
{
    for(int i = 0;i<vVector.size();i++)
    {
        if(vVector.at(i)!=nullptr)
        {
            delete vVector.at(i);
        }
    }
    for(int i = 0;i<hVector.size();i++)
    {
        if(hVector.at(i)!=nullptr)
        {
            delete hVector.at(i);
        }
    }
    for(int i = 0;i<fVector.size();i++)
    {
        if(fVector.at(i)!=nullptr)
        {
            delete fVector.at(i);
        }
    }

    vVector.clear();
    hVector.clear();
    fVector.clear();
}


void Mesh::initializeCube()
{
    freeMemory();
    //Vertex
    //counter clock-wise
    vVector.push_back(new Vertex(glm::vec3(-0.5,-0.5,-0.5)));//0
    vVector.push_back(new Vertex(glm::vec3(0.5,-0.5,-0.5)));//1
    vVector.push_back(new Vertex(glm::vec3(0.5,-0.5,0.5)));//2
    vVector.push_back(new Vertex(glm::vec3(-0.5,-0.5,0.5)));//3
    vVector.push_back(new Vertex(glm::vec3(-0.5,0.5,0.5)));//4
    vVector.push_back(new Vertex(glm::vec3(0.5,0.5,0.5)));//5
    vVector.push_back(new Vertex(glm::vec3(0.5,0.5,-0.5)));//6
    vVector.push_back(new Vertex(glm::vec3(-0.5,0.5,-0.5)));//7

    //HalfEdge
    //counter clock-wise
    //bottom
    hVector.push_back(new HalfEdge(vVector.at(1)));
    hVector.push_back(new HalfEdge(vVector.at(2)));
    hVector.push_back(new HalfEdge(vVector.at(3)));
    hVector.push_back(new HalfEdge(vVector.at(0)));
    //top
    hVector.push_back(new HalfEdge(vVector.at(5)));
    hVector.push_back(new HalfEdge(vVector.at(6)));
    hVector.push_back(new HalfEdge(vVector.at(7)));
    hVector.push_back(new HalfEdge(vVector.at(4)));
    //front
    hVector.push_back(new HalfEdge(vVector.at(2)));
    hVector.push_back(new HalfEdge(vVector.at(5)));
    hVector.push_back(new HalfEdge(vVector.at(4)));
    hVector.push_back(new HalfEdge(vVector.at(3)));
    //right
    hVector.push_back(new HalfEdge(vVector.at(1)));
    hVector.push_back(new HalfEdge(vVector.at(6)));
    hVector.push_back(new HalfEdge(vVector.at(5)));
    hVector.push_back(new HalfEdge(vVector.at(2)));
    //back
    hVector.push_back(new HalfEdge(vVector.at(0)));
    hVector.push_back(new HalfEdge(vVector.at(7)));
    hVector.push_back(new HalfEdge(vVector.at(6)));
    hVector.push_back(new HalfEdge(vVector.at(1)));
    //left
    hVector.push_back(new HalfEdge(vVector.at(3)));
    hVector.push_back(new HalfEdge(vVector.at(4)));
    hVector.push_back(new HalfEdge(vVector.at(7)));
    hVector.push_back(new HalfEdge(vVector.at(0)));

    //new Face
    //bottom
    fVector.push_back(new Face(hVector.at(0),glm::vec3(.99f,.47f,.82f),glm::vec3(0,-1,0),true));
    //top
    fVector.push_back(new Face(hVector.at(4),glm::vec3(.95f,.67f,0.f),glm::vec3(0,1,0),true));
    //front
    fVector.push_back(new Face(hVector.at(8),glm::vec3(0.f,.49f,.23f),glm::vec3(0,0,1),true));
    //right
    fVector.push_back(new Face(hVector.at(12),glm::vec3(.26f,.60f,.87f),glm::vec3(1,0,0),true));
    //back
    fVector.push_back(new Face(hVector.at(16),glm::vec3(.39f,.82f,.24f),glm::vec3(0,0,-1),true));
    //left
    fVector.push_back(new Face(hVector.at(20),glm::vec3(.49f,.53f,.93f),glm::vec3(-1,0,0),true));

    //complete vertex
    vVector.at(0)->halfEdge = hVector.at(0);
    vVector.at(1)->halfEdge = hVector.at(1);
    vVector.at(2)->halfEdge = hVector.at(2);
    vVector.at(3)->halfEdge = hVector.at(3);
    vVector.at(4)->halfEdge = hVector.at(4);
    vVector.at(5)->halfEdge = hVector.at(5);
    vVector.at(6)->halfEdge = hVector.at(6);
    vVector.at(7)->halfEdge = hVector.at(7);

    //complete halfedge
    //bottom
    hVector.at(0)->next = hVector.at(1);
    hVector.at(0)->sym = hVector.at(16);
    hVector.at(0)->face = fVector.at(0);
    hVector.at(1)->next = hVector.at(2);
    hVector.at(1)->sym = hVector.at(12);
    hVector.at(1)->face = fVector.at(0);
    hVector.at(2)->next = hVector.at(3);
    hVector.at(2)->sym = hVector.at(8);
    hVector.at(2)->face = fVector.at(0);
    hVector.at(3)->next = hVector.at(0);
    hVector.at(3)->sym = hVector.at(20);
    hVector.at(3)->face = fVector.at(0);
    //top
    hVector.at(4)->next = hVector.at(5);
    hVector.at(4)->sym = hVector.at(10);
    hVector.at(4)->face = fVector.at(1);
    hVector.at(5)->next = hVector.at(6);
    hVector.at(5)->sym = hVector.at(14);
    hVector.at(5)->face = fVector.at(1);
    hVector.at(6)->next = hVector.at(7);
    hVector.at(6)->sym = hVector.at(18);
    hVector.at(6)->face = fVector.at(1);
    hVector.at(7)->next = hVector.at(4);
    hVector.at(7)->sym = hVector.at(22);
    hVector.at(7)->face = fVector.at(1);
    //front
    hVector.at(8)->next = hVector.at(9);
    hVector.at(8)->sym = hVector.at(2);
    hVector.at(8)->face = fVector.at(2);
    hVector.at(9)->next = hVector.at(10);
    hVector.at(9)->sym = hVector.at(15);
    hVector.at(9)->face = fVector.at(2);
    hVector.at(10)->next = hVector.at(11);
    hVector.at(10)->sym = hVector.at(4);
    hVector.at(10)->face = fVector.at(2);
    hVector.at(11)->next = hVector.at(8);
    hVector.at(11)->sym = hVector.at(21);
    hVector.at(11)->face = fVector.at(2);
    //right
    hVector.at(12)->next = hVector.at(13);
    hVector.at(12)->sym = hVector.at(1);
    hVector.at(12)->face = fVector.at(3);
    hVector.at(13)->next = hVector.at(14);
    hVector.at(13)->sym = hVector.at(19);
    hVector.at(13)->face = fVector.at(3);
    hVector.at(14)->next = hVector.at(15);
    hVector.at(14)->sym = hVector.at(5);
    hVector.at(14)->face = fVector.at(3);
    hVector.at(15)->next = hVector.at(12);
    hVector.at(15)->sym = hVector.at(9);
    hVector.at(15)->face = fVector.at(3);
    //back
    hVector.at(16)->next = hVector.at(17);
    hVector.at(16)->sym = hVector.at(0);
    hVector.at(16)->face = fVector.at(4);
    hVector.at(17)->next = hVector.at(18);
    hVector.at(17)->sym = hVector.at(23);
    hVector.at(17)->face = fVector.at(4);
    hVector.at(18)->next = hVector.at(19);
    hVector.at(18)->sym = hVector.at(6);
    hVector.at(18)->face = fVector.at(4);
    hVector.at(19)->next = hVector.at(16);
    hVector.at(19)->sym = hVector.at(13);
    hVector.at(19)->face = fVector.at(4);
    //left
    hVector.at(20)->next = hVector.at(21);
    hVector.at(20)->sym = hVector.at(3);
    hVector.at(20)->face = fVector.at(5);
    hVector.at(21)->next = hVector.at(22);
    hVector.at(21)->sym = hVector.at(11);
    hVector.at(21)->face = fVector.at(5);
    hVector.at(22)->next = hVector.at(23);
    hVector.at(22)->sym = hVector.at(7);
    hVector.at(22)->face = fVector.at(5);
    hVector.at(23)->next = hVector.at(20);
    hVector.at(23)->sym = hVector.at(17);
    hVector.at(23)->face = fVector.at(5);
}


void Mesh::calculateNormal(Face *f)
{
    if(f==nullptr) return;
    HalfEdge* start = f->halfEdge;
    HalfEdge* current = start;
    glm::vec3 nor(0.f);
    glm::vec3 norSum(0.f);
    int norCount = 0;
    do
    {
        glm::vec3 v1 = current->sym->vert->position;
        glm::vec3 v2 = current->vert->position;
        glm::vec3 v3 = current->next->vert->position;
        nor = glm::cross(v3 - v2, v1 - v2);
        current = current->next;

        if(glm::length(nor) > EPSILON)
        {
            norSum += glm::normalize(nor);
            norCount ++;
        }
    }
    while(current!=start&&current!=nullptr);

    if(norCount != 0)
    {
        f->hasNor = true;
        f->nor = glm::normalize(norSum / (float)norCount);
    }
    else
    {
        if(f->hasNor)//if it originally has a normal
        {
            //do nothing
            //do not change the original normal of the face
        }
        else// if it originally doesn't have a normal
        {
            //something is wrong
            //beacause only zero face can arrive at this point
            //and normal are already set for zero faces when
            //they are created
        }
    }
}


void Mesh::create()
{
    destroy();
    std::vector<GLuint> mesh_idx;
    std::vector<glm::vec4> mesh_vert_pos;
    std::vector<glm::vec4> mesh_vert_nor;
    std::vector<glm::vec4> mesh_vert_col;
    std::vector<glm::uvec4> mesh_vert_JIndex;
    std::vector<glm::vec4> mesh_vert_JWeight;

    for(int i = 0;i<fVector.size();i++)
    {
        glm::vec3 fcol = fVector.at(i)->col;
        glm::vec3 fnor(0.f);

        //        HalfEdge* startEdge = fVector.at(i)->halfEdge;
        //        glm::vec3 nor = glm::cross(startEdge->next->vert->position-startEdge->vert->position,
        //                                   startEdge->sym->vert->position-startEdge->vert->position);

        //        glm::vec3 lastnor = nor;
        //        HalfEdge* he = startEdge->next;
        //        while((glm::length(nor)==0||glm::abs(glm::dot(nor,lastnor))<EPSILON)&&he!=startEdge&&he!=nullptr)
        //        {
        //            if(glm::length(nor)!=0) lastnor = nor;
        //            nor = glm::cross(he->next->vert->position-he->vert->position,
        //                             he->sym->vert->position-he->vert->position);
        //            he = he->next;
        //        }
        //        nor = glm::normalize(nor);

        //        fVector.at(i)->hasNor = true;
        //        fVector.at(i)->nor = nor;

        calculateNormal(fVector.at(i));
        //qDebug() << fVector.at(i)->id << ":" << fVector.at(i)->nor.x << fVector.at(i)->nor.y << fVector.at(i)->nor.z;

        fnor = fVector.at(i)->nor;

        createConvex(fVector.at(i),
                     fnor,
                     fcol,
                     mesh_idx,
                     mesh_vert_pos,
                     mesh_vert_nor,
                     mesh_vert_col,
                     mesh_vert_JIndex,
                     mesh_vert_JWeight);

        //                        int vperf = 0;
        //                        HalfEdge* curEdge = startEdge;
        //                        do
        //                        {
        //                            mesh_vert_pos.push_back(glm::vec4(curEdge->vert->position,1));
        //                            mesh_vert_nor.push_back(glm::vec4(fnor,1));
        //                            mesh_vert_col.push_back(glm::vec4(fcol,1));
        //                            mesh_vert_JIndex.push_back(curEdge->vert->boneI);
        //                            mesh_vert_JWeight.push_back(curEdge->vert->boneW);
        //                            vperf++;
        //                            if(vperf>2)
        //                            {
        //                                mesh_idx.push_back(mesh_vert_pos.size()-vperf);
        //                                mesh_idx.push_back(mesh_vert_pos.size()-2);
        //                                mesh_idx.push_back(mesh_vert_pos.size()-1);
        //                            }
        //                            curEdge = curEdge->next;
        //                        }
        //                        while(curEdge!=startEdge);
    }
    count = mesh_idx.size();

    generateIdx();
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh_idx.size() * sizeof(GLuint), mesh_idx.data(), GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mesh_vert_pos.size() * sizeof(glm::vec4), mesh_vert_pos.data(), GL_STATIC_DRAW);

    generateNor();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufNor);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mesh_vert_nor.size() * sizeof(glm::vec4), mesh_vert_nor.data(), GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mesh_vert_col.size() * sizeof(glm::vec4), mesh_vert_col.data(), GL_STATIC_DRAW);

    generateJIndex();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJIndex);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mesh_vert_JIndex.size() * sizeof(glm::uvec4), mesh_vert_JIndex.data(), GL_STATIC_DRAW);

    generateJWeight();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJWeight);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mesh_vert_JWeight.size() * sizeof(glm::vec4), mesh_vert_JWeight.data(), GL_STATIC_DRAW);
}


void Mesh::createConvex(Face *f,
                        glm::vec3 fnor,
                        glm::vec3 fcol,
                        std::vector<GLuint>& mesh_idx,
                        std::vector<glm::vec4> &mesh_vert_pos,
                        std::vector<glm::vec4> &mesh_vert_nor,
                        std::vector<glm::vec4> &mesh_vert_col,
                        std::vector<glm::uvec4> &mesh_vert_JIndex,
                        std::vector<glm::vec4> &mesh_vert_JWeight)
{
    //    //qDebug () << "enter createConvex" ;
    //    HalfEdge* a = f->halfEdge;
    //    HalfEdge* b = a;
    //    int c = 0;

    //    do{
    //        //qDebug () << "id: " << b->id;
    //        c++;
    //        b = b->next;
    //    }
    //    while(b!=a&&b!=nullptr);

    if(f!=nullptr)
    {

        HalfEdge* start = findStart(f->halfEdge);//findFirstLessThan180(f);
        if(start==nullptr)
        {
            createTriangle(f->halfEdge,
                           f->halfEdge,
                           fnor,
                           fcol,
                           mesh_idx,
                           mesh_vert_pos,
                           mesh_vert_nor,
                           mesh_vert_col,
                           mesh_vert_JIndex,
                           mesh_vert_JWeight);
        }
        else
        {
            HalfEdge* finish = start->next->next;//findNextGreaterThan180(start);

            //qDebug() << "start: " <<start->id;
            //qDebug() << "finish: " <<finish->id;

            HalfEdge* f2s = new HalfEdge(start->vert);
            HalfEdge* s2f = new HalfEdge(finish->vert);
            Face* face_s2f = new Face(s2f, f->col, fnor, true);

            f2s->face = f;
            f2s->next = start->next;
            f2s->sym = s2f;

            s2f->face = face_s2f;
            s2f->next = finish->next;
            s2f->sym = f2s;

            start->next = s2f;
            finish->next = f2s;

            HalfEdge* begin = s2f;
            HalfEdge* current = begin;
            do{
                current->face = face_s2f;
                current = current->next;
            }
            while(current!=begin&&current!=nullptr);

            createTriangle(f2s,
                           f2s,
                           fnor,
                           fcol,
                           mesh_idx,
                           mesh_vert_pos,
                           mesh_vert_nor,
                           mesh_vert_col,
                           mesh_vert_JIndex,
                           mesh_vert_JWeight
                           );

            createConvex(face_s2f,
                         fnor,
                         fcol,
                         mesh_idx,
                         mesh_vert_pos,
                         mesh_vert_nor,
                         mesh_vert_col,
                         mesh_vert_JIndex,
                         mesh_vert_JWeight
                         );

            current = begin;
            do{
                current->face = f;
                current = current->next;
            }
            while(current!=begin&&current!=nullptr);

            start->next = f2s->next;
            finish->next = s2f->next;

            if(face_s2f!=nullptr) {
                delete face_s2f;
                face_s2f = nullptr;
            }

            if(s2f!=nullptr) {
                delete s2f;
                s2f = nullptr;
            }

            if(f2s!=nullptr) {
                delete f2s;
                f2s = nullptr;
            }
        }
    }
    //qDebug () << "leave createConvex";
}


void Mesh::createTriangle(HalfEdge *begin,
                          HalfEdge *end,
                          glm::vec3 fnor,
                          glm::vec3 fcol,
                          std::vector<GLuint>& mesh_idx,
                          std::vector<glm::vec4> &mesh_vert_pos,
                          std::vector<glm::vec4> &mesh_vert_nor,
                          std::vector<glm::vec4> &mesh_vert_col,
                          std::vector<glm::uvec4> &mesh_vert_JIndex,
                          std::vector<glm::vec4> &mesh_vert_JWeight)
{
    //qDebug() << "enter createTriangle";
    HalfEdge* current = begin;
    int vperf = 0;
    do
    {
        mesh_vert_pos.push_back(glm::vec4(current->vert->position,1));
        mesh_vert_nor.push_back(glm::vec4(fnor,1));
        mesh_vert_col.push_back(glm::vec4(fcol,1));
        mesh_vert_JIndex.push_back(current->vert->boneI);
        mesh_vert_JWeight.push_back(current->vert->boneW);
        vperf++;
        if(vperf>2)
        {
            mesh_idx.push_back(mesh_vert_pos.size()-vperf);
            mesh_idx.push_back(mesh_vert_pos.size()-2);
            mesh_idx.push_back(mesh_vert_pos.size()-1);
        }
        current = current->next;
    }
    while(current!=end&&current!=nullptr);

    //qDebug () << "leave createTriangle";
}


HalfEdge* Mesh::findStart(HalfEdge *e)
{
    if(e==nullptr)
        return nullptr;

    HalfEdge* start = e;
    HalfEdge* current = start;
    do
    {
        glm::vec3 v1 = current->sym->vert->position;
        glm::vec3 v2 = current->vert->position;
        glm::vec3 v3 = current->next->vert->position;
        glm::vec3 v4 = current->next->next->vert->position;

        if(e->face->hasNor &&
                glm::dot(e->face->nor, glm::cross(v3-v2,v1-v2)) < 0 &&
                glm::dot(e->face->nor, glm::cross(v4-v3,v2-v3)) > 0)
        {
            return current;
        }

        current = current->next;
    }
    while(current!=start&&current!=nullptr);

    //shouldn't return current, even if it will return start which is e
    //return nullptr means no angle is greater than 180 so can use normal triangulation
    //this will same the process of split concave polygon
    return nullptr;
}


void Mesh::splitEdge(HalfEdge* h)
{
    //assume h is he1 in the slide
    if(h!=nullptr)
    {
        vVector.push_back(new Vertex((h->vert->position+h->sym->vert->position)/2.f));//v3
        hVector.push_back(new HalfEdge(h->vert));//he1b->vert = he1->vert
        hVector.push_back(new HalfEdge(h->sym->vert));//he2b->vert = he2->vert

        HalfEdge *he1 = h;
        HalfEdge *he2 = h->sym;
        HalfEdge *he1b = hVector.at(hVector.size()-2);
        HalfEdge *he2b = hVector.at(hVector.size()-1);
        Vertex *v3 = vVector.at(vVector.size()-1);

        //v3
        v3->halfEdge = he1b;//he1b

        //he1b
        he1b->sym = he2;//he2
        he1b->next = he1->next;//he1->next
        he1b->face = he1->face;//he1->face

        //he2b
        he2b->sym = he1;//he1
        he2b->next = he2->next;//he2->next
        he2b->face = he2->face;//he2->face

        //he1
        he1->sym = he2b;//he2b
        he1->next = he1b;//he1b
        he1->vert = v3;//v3

        //he2
        he2->sym = he1b;//he1b
        he2->next = he2b;//he2b
        he2->vert = v3;//v3

        create();
    }
}


void Mesh::concave2Convex(Face *f)
{
    if(f==nullptr)
        return;

    HalfEdge* start = findStart(f->halfEdge);//findFirstLessThan180(f);
    if(start==nullptr)
    {
        convex2Triangle(f);
        return;
    }
    HalfEdge* finish = start->next->next;//findNextGreaterThan180(start);

    HalfEdge* f2s = new HalfEdge(start->vert);
    HalfEdge* s2f = new HalfEdge(finish->vert);
    Face* face_s2f = new Face(s2f, f->col, f->nor, f->hasNor);

    f2s->face = f;
    f2s->next = start->next;
    f2s->sym = s2f;

    s2f->face = face_s2f;
    s2f->next = finish->next;
    s2f->sym = f2s;

    start->next = s2f;
    finish->next = f2s;

    HalfEdge* begin = s2f;
    HalfEdge* current = begin;

    do{
        current->face = face_s2f;
        current = current->next;
    }
    while(current!=begin&&current!=nullptr);

    hVector.push_back(f2s);
    hVector.push_back(s2f);
    fVector.push_back(face_s2f);

    convex2Triangle(f);
    concave2Convex(face_s2f);
}


void Mesh::convex2Triangle(Face *f)
{
    if(f!=nullptr)
    {
        HalfEdge* startE = f->halfEdge;
        HalfEdge* curE = startE->next;
        HalfEdge* h1next = startE;

        Face* f1 = f;

        while(curE->next->next!=startE)
        {
            hVector.push_back(new HalfEdge(startE->sym->vert));
            hVector.push_back(new HalfEdge(curE->vert));

            HalfEdge* h1 = hVector.at(hVector.size()-2);
            HalfEdge* h2 = hVector.at(hVector.size()-1);

            h1->next = h1next;
            h1->sym = h2;
            h1->face = f1;

            fVector.push_back(new Face(h2,f->col,f->nor,f->hasNor));
            Face* f2 = fVector.at(fVector.size()-1);

            h2->next = curE->next;
            h2->sym = h1;
            h2->face = f2;

            curE->next = h1;
            curE->face = f1;
            //need to change curE->face

            h1next = h2;

            curE = h2->next;

            f1 = fVector.at(fVector.size()-1);
        }

        //for last face
        curE->face = f1;
        curE->next->face = f1;
        curE->next->next = h1next;
    }
}


void Mesh::triangulateFace(Face* f)
{
    concave2Convex(f);
    create();
}


void Mesh::subdivide()
{
    // step 1: save centroid
    std::map<Face*,glm::vec3> FtoC;
    for(int i = 0;i<fVector.size();i++)
    {
        HalfEdge* startH = fVector.at(i)->halfEdge;
        HalfEdge* currentH = startH;
        float numV = 0;
        glm::vec3 sumV(0,0,0);
        while(currentH->next != startH)
        {
            numV++;
            sumV += currentH->vert->position;
            currentH = currentH->next;
        }
        numV++;
        sumV += currentH->vert->position;

        glm::vec3 centroid = sumV/numV;
        FtoC[fVector.at(i)] = centroid;
    }

    // step 2: add mid point
    int hVsize = hVector.size();
    int vVsize = vVector.size();
    std::map<HalfEdge*, bool> HtoB;
    for(int i = 0;i<hVsize;i++)
    {
        HtoB[hVector.at(i)] = false;
    }
    for(int i = 0;i<hVsize;i++)
    {
        if(HtoB[hVector.at(i)]==false)
        {
            HtoB[hVector.at(i)] = true;
            HtoB[hVector.at(i)->sym] = true;
            smoothMidPoint(hVector.at(i),FtoC);
        }
    }

    // step 3: adjust position of each original vertex(excluding mid point)
    for(int i = 0;i<vVsize;i++)
    {
        Vertex* startV = vVector.at(i);
        HalfEdge* startH = startV->halfEdge;
        if(startH->vert==startV)
            startH = startH->sym;//this makes sure that the half edge is the one pointing out of the vertex
        HalfEdge* currentH = startH;
        glm::vec3 sumE(0,0,0);
        glm::vec3 sumH(0,0,0);
        float n = 0;
        while(currentH->sym->next!=startH)
        {
            n++;
            sumE += currentH->vert->position;
            sumH += FtoC[currentH->face];
            currentH = currentH->sym->next;
        }
        n++;
        sumE += currentH->vert->position;
        sumH += FtoC[currentH->face];

        vVector.at(i)->position = (n-2)*vVector.at(i)->position / n +
                sumE / (n*n) +
                sumH / (n*n);
    }

    // step 4: quadrangulate each face with respect to its centroid
    int fVsize = fVector.size();
    for(int i = 0;i<fVsize;i++)
    {
        HalfEdge* startH = fVector.at(i)->halfEdge;
        HalfEdge* currentH = startH;
        Face* f1 = fVector.at(i);
        vVector.push_back(new Vertex(FtoC[f1]));
        Vertex* c = vVector.at(vVector.size()-1);
        HalfEdge* h1next = nullptr;
        while(currentH->next->next != startH)
        {
            hVector.push_back(new HalfEdge(c));
            hVector.push_back(new HalfEdge(currentH->vert));

            HalfEdge* h1 = hVector.at(hVector.size()-2);
            HalfEdge* h2 = hVector.at(hVector.size()-1);

            h1->next = h1next;
            h1->sym = h2;
            h1->face = f1;

            fVector.push_back(new Face(currentH->next->next,f1->col));
            Face* f2 = fVector.at(fVector.size()-1);

            h2->next = currentH->next;
            h2->sym = h1;
            h2->face = f2;

            currentH->next->face = f2;

            currentH->next = h1;
            currentH->face = f1;

            currentH = h2->next->next;
            f1 = f2;
            h1next = h2;
        }
        //don't forget last time
        //for last face
        hVector.push_back(new HalfEdge(c));
        hVector.push_back(new HalfEdge(currentH->vert));

        HalfEdge* h1 = hVector.at(hVector.size()-2);
        HalfEdge* h2 = hVector.at(hVector.size()-1);

        h1->next = h1next;
        h1->sym = h2;
        h1->face = f1;

        Face* f2 = fVector.at(i);

        h2->next = currentH->next;
        h2->sym = h1;
        h2->face = f2;

        currentH->next->face = f2;

        currentH->next = h1;
        currentH->face = f1;

        currentH = h2->next->next;//not necessary
        f1 = f2;//not necessary
        h1next = h2;//not necessary

        //also don't forget to assaign centorid's half edge
        c->halfEdge = h2;
        //the first h1next is null because it did not exist at that time
        f2->halfEdge->next->next = h1next;
    }

    create();

}


void Mesh::smoothMidPoint(HalfEdge *h, std::map<Face*, glm::vec3>& FtoC)
{
    if(h!=nullptr)
    {
        glm::vec3 v1 = h->vert->position;
        glm::vec3 v2 = h->sym->vert->position;
        glm::vec3 v3 = FtoC[h->face];
        glm::vec3 v4 = FtoC[h->sym->face];
        vVector.push_back(new Vertex((v1+v2+v3+v4)/4.f));//v
        hVector.push_back(new HalfEdge(h->vert));//he1b->vert = he1->vert
        hVector.push_back(new HalfEdge(h->sym->vert));//he2b->vert = he2->vert

        HalfEdge *he1 = h;
        HalfEdge *he2 = h->sym;
        HalfEdge *he1b = hVector.at(hVector.size()-2);
        HalfEdge *he2b = hVector.at(hVector.size()-1);
        Vertex *v = vVector.at(vVector.size()-1);

        //v
        v->halfEdge = he1b;//he1b

        //he1b
        he1b->sym = he2;//he2
        he1b->next = he1->next;//he1->next
        he1b->face = he1->face;//he1->face

        //he2b
        he2b->sym = he1;//he1
        he2b->next = he2->next;//he2->next
        he2b->face = he2->face;//he2->face

        //he1
        he1->sym = he2b;//he2b
        he1->next = he1b;//he1b
        he1->vert = v;//v

        //he2
        he2->sym = he1b;//he1b
        he2->next = he2b;//he2b
        he2->vert = v;//v
    }
}


void Mesh::extrudeFace(Face *f, glm::vec3 offset)
{
    HalfEdge *startEdge = f->halfEdge;
    HalfEdge *currentEdge = startEdge;
    HalfEdge *lastSym = nullptr;
    Vertex *lastV = nullptr;

    do{
        HalfEdge *he1 = currentEdge;
        HalfEdge *he2 = currentEdge->sym;

        Vertex *v1 = he1->vert;
        Vertex *v2 = he2->vert;

        Vertex *v3 = new Vertex(v1->position+offset);
        vVector.push_back(v3);
        Vertex *v4 = lastV;

        he1->vert = v3;

        HalfEdge *he1b = new HalfEdge(v4);
        hVector.push_back(he1b);
        HalfEdge *he2b = new HalfEdge(v1);
        hVector.push_back(he2b);

        v2->halfEdge = he2b;//this is important
        v3->halfEdge = he1b;//this is important

        he1->sym = he1b;
        he1b->sym = he1;

        he2->sym = he2b;
        he2b->sym = he2;

        HalfEdge *he3 = new HalfEdge(v3);
        hVector.push_back(he3);
        HalfEdge *he4 = new HalfEdge(v2);
        hVector.push_back(he4);

        Face *f1 = new Face(he1b,f->col);
        fVector.push_back(f1);

        he1b->face = f1;
        he2b->face = f1;
        he3->face = f1;
        he4->face = f1;

        he1b->next = he4;
        he4->next = he2b;
        he2b->next = he3;
        he3->next = he1b;

        he4->sym = lastSym;
        if(lastSym!=nullptr)
        {
            lastSym->sym = he4;
        }
        lastSym = he3;
        lastV = v3;

        currentEdge = currentEdge->next;
    }while(currentEdge!=startEdge);

    //set lastSym and lastV for the first face
    //lastSym
    startEdge->sym->next->sym = lastSym;
    lastSym->sym = startEdge->sym->next;
    //lastV
    startEdge->sym->vert = lastV;

    create();
}


void Mesh::bevelEdge(HalfEdge *h)
{
    //need to check if there are only 3 edge come out of both ends
    HalfEdge *h1 = h;
    HalfEdge *h2 = h->sym;
    Vertex* v1 = h1->vert;
    Vertex* v2 = h2->vert;

    HalfEdge* test1 = v1->halfEdge;
    if(test1->vert==v1) test1 = test1->sym;
    HalfEdge* test2 = v2->halfEdge;
    if(test2->vert==v2) test2 = test2->sym;

    HalfEdge* test1_cur = test1->sym->next;
    int count1 = 1;
    while(test1_cur!=test1)
    {
        count1++;
        test1_cur = test1_cur->sym->next;
    }
    if(count1!=3) return;

    HalfEdge* test2_cur = test2->sym->next;
    int count2 = 1;
    while(test2_cur!=test2)
    {
        count2++;
        test2_cur = test2_cur->sym->next;
    }
    if(count2!=3) return;

    HalfEdge* h1Next = h1->next;
    HalfEdge* h2Next = h2->next;
    HalfEdge* h1Last = h1;
    HalfEdge* h2Last = h2;
    while(h1Last->next!=h1) h1Last=h1Last->next;
    while(h2Last->next!=h2) h2Last=h2Last->next;
    Vertex* v3 = h1Next->vert;
    Vertex* v4 = h2Next->vert;
    Vertex* v5 = h1Last->sym->vert;
    Vertex* v6 = h2Last->sym->vert;
    glm::vec3 v1p = v1->position + (v3->position-v1->position)*0.25f;
    glm::vec3 v2p = v2->position + (v4->position-v2->position)*0.25f;
    Vertex* v1b = new Vertex(glm::vec3(v1->position + (v6->position-v1->position)*0.25f));
    Vertex* v2b = new Vertex(glm::vec3(v2->position + (v5->position-v2->position)*0.25f));
    v1->position = v1p;
    v2->position = v2p;
    HalfEdge* h1b = new HalfEdge(v2b);
    HalfEdge* h2b = new HalfEdge(v1b);
    HalfEdge* h3 = new HalfEdge(v2);
    HalfEdge* h4 = new HalfEdge(v1);
    HalfEdge* h5 = new HalfEdge(v2b);
    HalfEdge* h6 = new HalfEdge(v1b);
    Face* f = new Face(h1b,h1->face->col);
    v1b->halfEdge = h4;
    v2b->halfEdge = h3;
    h1b->next = h3;
    h1b->sym = h1;
    h1b->face = f;
    h2b->next = h4;
    h2b->sym = h2;
    h2b->face = f;
    h3->next = h2b;
    h3->sym = h5;
    h3->face = f;
    h4->next = h1b;
    h4->sym = h6;
    h4->face = f;
    h5->next = h1Last->sym;
    h5->sym = h3;
    h5->face = h1Last->sym->face;
    h6->next = h2Last->sym;
    h6->sym = h4;
    h6->face = h2Last->sym->face;
    h1->sym = h1b;
    h2->sym = h2b;
    h1Last->vert = v2b;
    h2Last->vert = v1b;
    h1Next->sym->next = h6;
    h2Next->sym->next = h5;
    v1->halfEdge = h1b;//important
    v2->halfEdge = h2b;//important
    vVector.push_back(v1b);
    vVector.push_back(v2b);
    hVector.push_back(h1b);
    hVector.push_back(h2b);
    hVector.push_back(h3);
    hVector.push_back(h4);
    hVector.push_back(h5);
    hVector.push_back(h6);
    fVector.push_back(f);

    create();
}


void Mesh::fullZeroFace(Vertex* v1, Vertex* v2, Vertex* v3, HalfEdge* e, HalfEdge* e1, HalfEdge* e2, glm::vec3 n)
{
    //no need to reset the original e1->face->halfEdge
    qDebug() << "enter fullZeroFace";
    HalfEdge* eLast = e->next;
    HalfEdge* e1Last = e1->next;
    while(eLast->next!=e&&eLast!=nullptr) eLast = eLast->next;
    while(e1Last->next!=e1&&e1Last!=nullptr) e1Last = e1Last->next;
    HalfEdge* eLastSymLast = eLast->sym->next;
    while(eLastSymLast->next!=eLast->sym&&eLastSymLast!=nullptr) eLastSymLast = eLastSymLast->next;

    Vertex* vNew1 = new Vertex(v1->position);
    Vertex* vNew2 = new Vertex(v2->position);
    HalfEdge* eSym = new HalfEdge(vNew2);
    HalfEdge* e1Sym = new HalfEdge(v1);
    HalfEdge* eSymNext = new HalfEdge(v2);
    HalfEdge* e1SymNext = new HalfEdge(vNew1);
    HalfEdge* eSymNextSym = new HalfEdge(vNew2);
    HalfEdge* e1SymNextSym = new HalfEdge(v1);
    Face* fzero = new Face(eSym, e1->face->col, glm::normalize(glm::cross(n, e->vert->position - e1->vert->position)), e1->face->hasNor);

    v2->halfEdge = e1Sym;//sssssssssshhhhhhhhhhiiiiiiiiiiiiiiiiitttttttttttttt
    v1->halfEdge = e1;//sssssssssshhhhhhhhhhiiiiiiiiiiiiiiiiitttttttttttttt

    vNew1->halfEdge = eSym;
    vNew2->halfEdge = e;

    e->sym = eSym;
    e->vert = vNew1;
    e1->sym = e1Sym;

    eSym->face = fzero;
    eSym->sym = e;
    eSym->next = eSymNext;
    e1Sym->face = fzero;
    e1Sym->sym = e1;
    e1Sym->next = e1SymNext;
    eSymNext->face = fzero;
    eSymNext->sym = eSymNextSym;
    eSymNext->next = e1Sym;
    e1SymNext->face = fzero;
    e1SymNext->sym = e1SymNextSym;
    e1SymNext->next = eSym;
    eSymNextSym->face = eLast->sym->face;
    eSymNextSym->sym = eSymNext;
    eSymNextSym->next = eLast->sym;
    e1SymNextSym->face = e1Last->sym->face;
    e1SymNextSym->sym = e1SymNext;
    e1SymNextSym->next = e->next->sym->next;//e1Last->sym;

    e->next->sym->vert = vNew1;
    e->next->sym->next = e1SymNextSym;
    eLast->vert = vNew2;
    eLastSymLast->next = eSymNextSym;//e2->sym->next = eSymNextSym;//

    vVector.push_back(vNew1);
    vVector.push_back(vNew2);
    hVector.push_back(eSym);
    hVector.push_back(e1Sym);
    hVector.push_back(eSymNext);
    hVector.push_back(e1SymNext);
    hVector.push_back(eSymNextSym);
    hVector.push_back(e1SymNextSym);
    fVector.push_back(fzero);
    qDebug() << "fullZeroFace done";
}


void Mesh::firstHalfZeroFace(Vertex* v1, Vertex* v2, Vertex* v3, HalfEdge* e, HalfEdge* e1, HalfEdge* e2, glm::vec3 n)
{
    //need to reset the original e1->face->halfEdge
    qDebug() << "enter firstHalfZeroFace";
    HalfEdge* eLast = e->next;
    HalfEdge* e1LastLast = e1->next;
    while(eLast->next!=e&&eLast!=nullptr) eLast = eLast->next;
    while(e1LastLast->next->next!=e1&&e1LastLast!=nullptr&&e1LastLast->next!=nullptr)
        e1LastLast = e1LastLast->next;
    HalfEdge* e1Last = e1LastLast->next;

    HalfEdge* eLastSymLast = eLast->sym->next;
    while(eLastSymLast->next!=eLast->sym) eLastSymLast = eLastSymLast->next;

    Vertex* vNew2 = new Vertex(v2->position);
    HalfEdge* e1Next = new HalfEdge(v2);
    HalfEdge* e1NextSym = new HalfEdge(vNew2);
    HalfEdge* e1NextNext = new HalfEdge(e1LastLast->vert);
    HalfEdge* e1NextNextSym = new HalfEdge(v2);
    Face* fzero = new Face(e1Next, e1->face->col, glm::normalize(glm::cross(n, e->vert->position - e1->vert->position)), e2->face->hasNor);

    v2->halfEdge = e1NextNext;//sssssssssshhhhhhhhhhiiiiiiiiiiiiiiiiitttttttttttttt

    vNew2->halfEdge = e;

    e1Next->face = fzero;
    e1Next->sym = e1NextSym;
    e1Next->next = e1NextNext;
    e1NextSym->face = e2->sym->face;
    e1NextSym->sym = e1Next;
    e1NextSym->next = eLast->sym;
    e1NextNext->face = fzero;
    e1NextNext->sym = e1NextNextSym;
    e1NextNext->next = e1Last;
    e1NextNextSym->face = e2->face;
    e1NextNextSym->sym = e1NextNext;
    e1NextNextSym->next = e2;

    e1->vert = vNew2;
    e1->face->halfEdge = e1NextNextSym;//wwwwwwwwhhhhhhhhhhaaaaaaaaaaaattttttttt!!!!!!! // in case e1->face->halfEdge == e1
    e1->face = fzero;
    e1->next = e1Next;

    eLast->vert = vNew2;
    eLastSymLast->next = e1NextSym;//e2->sym->next = e1NextSym;
    e1Last->face = fzero;
    e1LastLast->next = e1NextNextSym;

    vVector.push_back(vNew2);
    hVector.push_back(e1Next);
    hVector.push_back(e1NextSym);
    hVector.push_back(e1NextNext);
    hVector.push_back(e1NextNextSym);
    fVector.push_back(fzero);
    qDebug() << "firstHalfZeroFace done";
}


void Mesh::secondHalfZeroFace(Vertex* v1, Vertex* v2, Vertex* v3, HalfEdge* e, HalfEdge* e1, HalfEdge* e2, glm::vec3 n)
{
    //need to reset the original e1->face->halfEdge
    qDebug() << "enter secondHalfZeroFace";
    HalfEdge* e1Last = e1->next;
    int i = 0;
    while(e1Last->next!=e1&&e1Last!=nullptr)
    {
        qDebug() << i++ << ":" << e1Last << ":" << e1;
        qDebug() << e1Last->vert->position.x << "," << e1Last->vert->position.y << "," << e1Last->vert->position.z;
        e1Last = e1Last->next;
    }

    Vertex* vNew1 = new Vertex(v1->position);
    HalfEdge* e2Next = new HalfEdge(v1);
    HalfEdge* e2NextSym = new HalfEdge(v3);
    HalfEdge* e2NextNext = new HalfEdge(vNew1);
    HalfEdge* e2NextNextSym = new HalfEdge(v1);
    Face* fzero = new Face(e2Next, e1->face->col,glm::normalize(glm::cross(n, e->vert->position - e1->vert->position)),e1Last->face->hasNor);

    v1->halfEdge = e2NextSym;//sssssssssshhhhhhhhhhiiiiiiiiiiiiiiiiitttttttttttttt

    vNew1->halfEdge = e1;

    e2Next->face = fzero;
    e2Next->sym = e2NextSym;
    e2Next->next = e2NextNext;
    e2NextSym->face = e1Last->face;
    e2NextSym->sym = e2Next;
    e2NextSym->next = e2->next;
    e2NextNext->face = fzero;
    e2NextNext->sym = e2NextNextSym;
    e2NextNext->next = e1;
    e2NextNextSym->face = e1Last->sym->face;
    e2NextNextSym->sym = e2NextNext;
    e2NextNextSym->next = e->next->sym->next;//e1Last->sym;

    e->vert = vNew1;
    e1->face->halfEdge = e2NextSym;//wwwwwwwwhhhhhhhhhhaaaaaaaaaaaattttttttt!!!!!!! // in case e1->face->halfEdge == e1
    e1->face = fzero;
    e2->face = fzero;
    e2->next = e2Next;

    e1Last->next = e2NextSym;
    e->next->sym->vert = vNew1;
    e->next->sym->next = e2NextNextSym;

    vVector.push_back(vNew1);
    hVector.push_back(e2Next);
    hVector.push_back(e2NextSym);
    hVector.push_back(e2NextNext);
    hVector.push_back(e2NextNextSym);
    fVector.push_back(fzero);
    qDebug() << "secondHalfZeroFace done";
}


void Mesh::oneEdgeZeroFace(Vertex* v1, Vertex* v2, Vertex* v3, HalfEdge* e, HalfEdge* e1, HalfEdge* e2, glm::vec3 n)
{
    //need to reset the original e1->face->halfEdge
    qDebug() << "enter oneEdgeZeroFace";
    HalfEdge* e1LastLast = e1->next;
    while(e1LastLast->next->next!=e1&&e1LastLast!=nullptr&&e1LastLast->next!=nullptr)
        e1LastLast = e1LastLast->next;
    HalfEdge* e1Last = e1LastLast->next;

    HalfEdge* e2Next = new HalfEdge(e1LastLast->vert);
    HalfEdge* e2NextSym = new HalfEdge(v3);
    Face* fzero = new Face(e2Next, e1->face->col, glm::normalize(glm::cross(n, e->vert->position - e1->vert->position)), e1LastLast->face->hasNor);

    e2Next->face = fzero;
    e2Next->sym = e2NextSym;
    e2Next->next = e1Last;
    e2NextSym->face = e1LastLast->face;
    e2NextSym->sym = e2Next;
    e2NextSym->next = e2->next;

    e1LastLast->next = e2NextSym;

    e1Last->face = fzero;//wwwwwwwwwwwwwhhhhhhhhhhhhhhhhhaaaaaaaaaaaaaaatttttttttttttttt!!!!!!!!!!!!!!!!

    e1->face->halfEdge = e2NextSym;//wwwwwwwwhhhhhhhhhhaaaaaaaaaaaattttttttt!!!!!!! // in case e1->face->halfEdge == e1
    e1->face = fzero;
    e2->face = fzero;
    e2->next = e2Next;

    hVector.push_back(e2Next);
    hVector.push_back(e2NextSym);
    fVector.push_back(fzero);
    qDebug() << "oneEdgeZeroFace done";
}


void Mesh::pushPullPP(Face* f, glm::vec3 d, float theta, glm::vec3 p, glm::vec3 n)
{
    glm::vec3 ptemp, ntemp;
    glm::vec3 plast, nlast;
    int i = 0;

    if(!getNextStep(f, n, p, &ntemp, &ptemp))
        return;

    do
    {
        qDebug() << ">>>>>>>>>>>>>> Step:" << i;
        qDebug() << ">>>>>>>>>>>>>> ntemp:" << ntemp.x << ","<< ntemp.y << ","<< ntemp.z;
        qDebug() << ">>>>>>>>>>>>>> ptemp:" << ptemp.x << ","<< ptemp.y << ","<< ptemp.z;
        qDebug() << "insert start";
        pushPullPPInsertFace(f, theta, ntemp);
        qDebug() << "insert finish";
        qDebug() << "update start";
        pushPullPPUpdateMesh(f, ptemp, ntemp);
        qDebug() << "update finish";
        qDebug() << "cleanUp start";
        cleanUp(f);
        qDebug() << "cleanUp finish";

        plast = ptemp;
        nlast = ntemp;
        qDebug() << ">>>>>>>>>>>>>> Step:" << i << " is finished";
        i++;
    }
    while(getNextStep(f, n, p, &ntemp, &ptemp) &&
          !samePlane(plast, nlast, ptemp, nlast) &&
          std::find(fVector.begin(), fVector.end(), f)!=fVector.end());

    create();
}

bool Mesh::samePlane(glm::vec3 p1, glm::vec3 n1, glm::vec3 p2, glm::vec3 n2)
{
    n1 = glm::normalize(n1);//just to be robust
    n2 = glm::normalize(n2);//just to be robust
    if(glm::abs(1 - glm::dot(n1, n2)) < EPSILON && glm::abs(glm::dot(p2 - p1, n1)) < EPSILON)
        return true;
    else
        return false;
}

bool Mesh::getNextStep(Face *f, glm::vec3 n, glm::vec3 p, glm::vec3 *nResult, glm::vec3 *pResult)
{
    if(f==nullptr) return false;

    bool result = false;

    n = glm::normalize(n);//just to be robust

    HalfEdge *startE = f->halfEdge->next;
    HalfEdge *lastE = f->halfEdge;
    HalfEdge *currentE = startE;

    std::vector<Vertex*> Vev;

    do
    {
        //Vev.push_back(currentE->vert);//should add all the vertices of the adjacent face to Vev instead of only the ones shared with f
        ////////////////////////////////////
        HalfEdge* substartE = currentE->sym;
        HalfEdge* subcurrentE = substartE;
        do
        {
            Vev.push_back(subcurrentE->vert);
            subcurrentE = subcurrentE->next;
        }
        while(subcurrentE!=substartE&&subcurrentE!=nullptr);
        ////////////////////////////////////////////////////

        Face *fAdj = currentE->sym->face;
        Face *fAdjLast = lastE->sym->face;
        Face *fAdjNext = currentE->next->sym->face;

        glm::vec3 point;
        if(intersectPlanePlanePlane(fAdjLast, fAdj, fAdjNext, &point))
            Vev.push_back(new Vertex(point));

        lastE = lastE->next;
        currentE = currentE->next;
    }
    while(currentE!=startE&&currentE!=nullptr);

    qDebug() << "---Vev before clamp:";
    for(int i = 0;i<Vev.size();i++)
    {
        qDebug() << "----Vev" << i << ":" << Vev[i]->position.x << "," << Vev[i]->position.y << "," << Vev[i]->position.z;
    }
    qDebug() << "---Vev before end";

    for(auto iter = Vev.begin(); iter!=Vev.end();)
    {
        if(!betweenFacePlane(*iter, f, p, n))
            iter = Vev.erase(iter);
        else
            iter++;
    }

    qDebug() << "---Vev after clamp:";
    for(int i = 0;i<Vev.size();i++)
    {
        qDebug() << "----Vev" << i << ":" << Vev[i]->position.x << "," << Vev[i]->position.y << "," << Vev[i]->position.z;
    }
    qDebug() << "---Vev after clamp end";

    if(Vev.size()==0)
    {
        *nResult = n;
        *pResult = p;
        result = true;
    }
    else if(1 - glm::abs(glm::dot(glm::normalize(f->nor), glm::normalize(n))) < EPSILON)//f is parellel to the plane
    {
        Vertex *vNear = nullptr;
        float distanceNear = std::numeric_limits<float>::max();

        for(int i = 0;i<Vev.size();i++)
        {
            float distance = distanceToPlane(Vev[i], f);
            if(distance >= 0 && distance < distanceNear)
            {
                distanceNear = distance;
                vNear = Vev[i];
            }
        }

        if(vNear!=nullptr)
        {
            *pResult = vNear->position;
            *nResult = n;
            result = true;
        }
    }
    else
    {
        glm::vec3 origin, direction;
        if(intersectPlanePlane(f, p, n, &origin, &direction))
        {
            glm::vec3 nPotential, pPotential;
            float mostParellel = std::numeric_limits<float>::max();
            for(auto item : Vev)
            {
                nPotential = glm::cross(direction, item->position - origin);
                if(glm::dot(nPotential, n)<0) nPotential *= -1.f;
                pPotential = item->position;
                float parellel = glm::dot(nPotential, n);
                if(parellel < mostParellel)
                {
                    *pResult = pPotential;
                    *nResult = nPotential;
                    result = true;
                }
            }
        }
    }

    return result;
}

float Mesh::distanceToPlane(Vertex *v, Face *f)
{
    if(v==nullptr||f==nullptr)
        return -1;//negative number indicating error

    glm::vec3 V = v->position;
    glm::vec3 n = glm::normalize(f->nor);
    glm::vec3 p = f->halfEdge->vert->position;

    return glm::abs(glm::dot(V-p, n));
}

void Mesh::cleanUp(Face *f)
{
    if(f==nullptr) return;

    HalfEdge* start = f->halfEdge;
    HalfEdge* current = start;

    do{
        Vertex* currentVertex = current->vert;
        HalfEdge* subCurrent = current->next;//check adjacent vertices except for the one connected with current

        qDebug() << "current:" << current->id;

        do{
            qDebug() << "subCurrent:" << subCurrent->id;

            HalfEdge* subNext = subCurrent->sym->next;
            HalfEdge* subNextSym = subNext->sym;//incase subNext is deleted
            HalfEdge* subNextEx = subNext->sym->next;//incase subNext is deleted
            float length = glm::length(currentVertex->position - subCurrent->vert->position);
            if(length<EPSILON)
            {
                if(mergeVertex(currentVertex, subCurrent->vert, subCurrent))//the triangle on the DiscardToKeep side is deleted
                {
                    if(subNextSym==current) break;
                    else subCurrent = subNextEx;
                }
                else
                {
                    subCurrent = subNext;
                }
            }
            else
            {
                //mergeVertex will delete the whole triangle when there are less than 3 edges,
                //subNext may get deleted in this case. To avoid this invalid pointer, one simple
                //way is when deleting edges(or other elements in general), do not actually delete them
                //but only make the pointers pointing to them point to other elements or null,
                //and keeping them stored in the vectors temporarily with a tag. After the whole operation,
                //loop through the vectors and delete those elements which are tagged earlier.
                //Here we are using another method. Use the return value of mergeVertex to indicate whether the
                //triangle is deleted and act accordingly.
                subCurrent = subNext;
            }

        }
        while(subCurrent!=nullptr&&subCurrent->sym!=current);

        current = current->next;
    }
    while(current!=nullptr&&current!=start);
}


//return value indicates whether a triangle is deleted or not!!!
bool Mesh::mergeVertex(Vertex *vKeep, Vertex *vDiscard, HalfEdge* KeepToDiscard)
{
    if(vKeep==nullptr||vDiscard==nullptr||KeepToDiscard==nullptr)
        return false;

    qDebug() << "mergeVertex:" << vKeep->id << "," << vDiscard->id << "," << KeepToDiscard->id;

    HalfEdge* start = vDiscard->halfEdge;
    HalfEdge* current = start;
    do{
        qDebug() << "current:" << current->id;
        qDebug() << "currentSym:" << current->sym->id;
        current->sym->vert = vKeep;
        current = current->sym->next;
    }
    while(current!=nullptr&&current!=start);
    deleteVertex(&vDiscard);

    HalfEdge* DiscardToKeep = KeepToDiscard->sym;
    removeEdge(KeepToDiscard);//we don't care whether the triangle on this side is deleted
    bool deletedTriangle = removeEdge(DiscardToKeep);//we only care whether the triangle on this side is deleted, because subnext depends on the existence of an edge of this triangle

    qDebug() << "mergeVertex finish, deleted triangle ? :" << deletedTriangle;

    return deletedTriangle;
}

//return value indicates whether a triangle is deleted or not!!!
bool Mesh::removeEdge(HalfEdge *e)
{
    if(e==nullptr) return false;

    bool result = false;

    qDebug() << "removeEdge:" << e->id;
    printFace(e->face);

    HalfEdge* start = e;
    HalfEdge* last = start->next;
    int count = 2;
    while(last->next!=start&&last!=nullptr)
    {
        count++;
        last = last->next;
    }

    if(start->face->halfEdge==start)
        start->face->halfEdge=last;

    if(count<=3)
    {
        last->sym->sym = start->next->sym;
        start->next->sym->sym = last->sym;
        deleteEdge(&last);
        deleteEdge(&start->next);
        deleteFace(&start->face);
        result = true;
    }
    else
    {
        last->next = start->next;
    }

    qDebug() << "removeEdge finish";
    printFace(e->face);

    deleteEdge(&e);
    return result;
}


void Mesh::deleteEdge(HalfEdge **e)
{
    if(*e==nullptr) return;

    for(auto iter = hVector.begin();iter!=hVector.end();iter++)
    {
        if(*iter == *e)
        {
            iter = hVector.erase(iter);
            break;
        }
    }
    delete *e;
    *e = nullptr;
}

void Mesh::deleteFace(Face **f)
{
    if(*f==nullptr) return;

    qDebug() << "deleteFace:" << (*f)->id;
    for(auto iter = fVector.begin();iter!=fVector.end();iter++)
    {
        if(*iter == *f)
        {
            iter = fVector.erase(iter);
            break;
        }
    }
    delete *f;
    *f = nullptr;
}


void Mesh::pushPullPPInsertFace(Face *f, float theta, glm::vec3 n)
{
    /// ALERT
    /// The normal of the plane always points to the opposite of the operation direction,
    /// i.e. when pulling towards right, the normal of the desired plane should points to left
    /// and when pushing towards left, the normal of the desired plane should points to right.
    /// This makes sure that when pushing, the angle between the normal of an adjacent face
    /// and the desired plane normal is always greater than 90 degree, hence no zero face will
    /// be created. Otherwise, zero face could be inserted when pushing. In some situation, this
    /// will create self intersection and it can not be solved by the stepped technique.

    n = glm::normalize(n);

    HalfEdge* start = f->halfEdge;
    HalfEdge* e = start;

    bool lastOneGenerated = false;
    bool firstOneGenerated = false;

    int i = 0;
    do{
        qDebug() << i++ << "edge:" << e->id << ":";
        HalfEdge* e1 = e->sym;
        HalfEdge* e2 = e1->next;

        Vertex* v1 = e->vert;
        Vertex* v2 = e1->vert;
        Vertex* v3 = e2->vert;

        qDebug() << "e:" << e->id << ",e1:" << e1->id << ",e2:" << e2->id;
        qDebug() << "v1:" << v1->position.x << "," << v1->position.y << "," << v1->position.z;
        qDebug() << "v2:" << v2->position.x << "," << v2->position.y << "," << v2->position.z;
        qDebug() << "v3:" << v3->position.x << "," << v3->position.y << "," << v3->position.z;

        Face* adjF = e1->face;
        glm::vec3 adjFNormal(0.f);
        if(!lastOneGenerated)
        {
            //no difference, v2 and v3 are not the same, v1 is different from v2 and v3 by definition
            if(e->next==start&&firstOneGenerated)
                adjFNormal = (glm::cross(v3->position - v2->position, v1->position - v2->position));
            else
                adjFNormal = (glm::cross(v3->position - v2->position, v1->position - v2->position));
        }
        else
        {
            //no difference, v2 and v3 are the same, v1 is different from v2 and v3 by definition
            if(e->next==start&&firstOneGenerated)
                adjFNormal = (glm::cross(e2->next->vert->position - v2->position, v1->position - v2->position));
            else
                adjFNormal = (glm::cross(e2->next->vert->position - v2->position, v1->position - v2->position));
        }

        if(glm::length(adjFNormal) < EPSILON)
            return;//!!!
        else
            adjFNormal = glm::normalize(adjFNormal);

        qDebug() << "adjF:" << (adjF==nullptr) << ":adjFNormal:" << adjFNormal.x << "," << adjFNormal.y << "," << adjFNormal.z;

        if(adjF == nullptr
                || (glm::acos(glm::clamp(glm::dot(n,adjFNormal), -1.f, 1.f)) < glm::radians(90 - theta) && glm::dot(f->nor, n) > 0)//when push, do not use absolute value
                || (glm::acos(glm::clamp(glm::abs(glm::dot(n,adjFNormal)), -1.f, 1.f)) < glm::radians(90 - theta) && glm::dot(f->nor, n) < 0))//when pull, use absolute value
        {
            // generate zero face
            if(!lastOneGenerated)//if a zero face was not generated for the last edge
            {
                if(e->next==start&&firstOneGenerated)//if a zero face was generated for the next edge
                {
                    firstHalfZeroFace(v1, v2, v3, e, e1, e2, n);//generate first half only
                }
                else//if a zero face was not generated for the next edge
                {
                    fullZeroFace(v1, v2, v3, e, e1, e2, n);//generate first half and second half
                }
            }
            else//if a zero face was generated for the last edge
            {
                if(e->next==start&&firstOneGenerated)//if a zero face was generated for the next edge
                {
                    oneEdgeZeroFace(v1, v2, v3, e, e1, e2, n);//split the zero face from the polygon
                }
                else//if a zero face was not generated for the next edge
                {
                    secondHalfZeroFace(v1, v2, v3, e, e1, e2, n);//generate second half only
                }
            }

            if(e==start) firstOneGenerated = true;
            lastOneGenerated = true;
        }
        else
        {
            //do not generate zero face
            lastOneGenerated = false;
        }
        e = e->next;
    }
    while(e!=start);
}


void Mesh::pushPullPPUpdateMesh(Face *f, glm::vec3 p, glm::vec3 n)
{
    /// keep the normal normalized, because dot product will be used to determine whether it overlap with another direction or not
    n = glm::normalize(n);//shiiiiiiit

    if(f==nullptr) return;
    HalfEdge* start = f->halfEdge;
    HalfEdge* current = start;

    std::vector<HalfEdge*> FEoriginal;

    do
    {
        FEoriginal.push_back(current);
        current = current->next;
    }
    while(current!=start && current!=nullptr);

    for(HalfEdge* h : FEoriginal)
    {
        Vertex* v = h->vert;
        //current points to v
        std::deque<Face*> Ffan;
        std::vector<Face*> Faff;
        qDebug() << "-v.id:" << v->id;

        //determine affected faces
        qDebug() << "determine affected faces";
        HalfEdge* hNext = h->next;
        HalfEdge* now = hNext->sym;
        do
        {
            Ffan.push_front(now->face);
            now = now->next->sym;
        }
        while(now!=h&&now!=nullptr);
        qDebug() << "-Ffan.size:" << Ffan.size();
        for(int i = 0;i<Ffan.size();i++) qDebug() << Ffan[i]->id;

        for(int i = 0;i<Ffan.size();i++)
        {
            if(i==0||i==Ffan.size()-1||intersectFacePlane(Ffan[i],p,n))
                Faff.push_back(Ffan[i]);
        }
        qDebug() << "-Faff.size:" << Faff.size();
        for(int i = 0;i<Faff.size();i++)
        {
            //qDebug() << Faff[i]->id;
            printFace(Faff[i]);
        }

        //compute new vertices
        qDebug() << "compute new vertices";
        std::vector<Vertex*> Vnew;
        for(int i = 0;i<Faff.size()-1;i++)
        {
            glm::vec3 point;
            qDebug() << "3 plane intersection:" << intersectPlanePlanePlane(Faff[i], Faff[i+1], p, n, &point);
            qDebug() << "new vertex " << i << " is:" << point.x << "," << point.y << "," <<  point.z;
            Vertex* v = new Vertex(point);
            Vnew.push_back(v);
            vVector.push_back(v);
        }
        qDebug() << "-Vnew.size:" << Vnew.size();
        for(int i = 0;i<Vnew.size();i++) qDebug() << Vnew[i]->id;

        //update vertex indices of faces
        qDebug() << "update vertex indices of faces";
        replaceVertex(f, v, Vnew);
        printFace(f);//
        bool deleteV = true;
        for(int i = 0;i<Faff.size();i++)
        {
            std::vector<Vertex*> Vsel;
            if(i==0) Vsel.push_back(Vnew[0]);
            else if(i==Faff.size()-1) Vsel.push_back(Vnew[Vnew.size()-1]);
            else
            {
                Vsel.push_back(Vnew[i]);//this order is important
                Vsel.push_back(Vnew[i-1]);//this order is important
            }
            qDebug() << "-Vsel.size:" << Vsel.size();
            Face* fn = getNextFace(Faff[i], Ffan);
            Face* fp = getPreviousFace(Faff[i], Ffan);
            if(!faceBelong(fn,Faff))
            {
                insertAfter(Faff[i], v, Vsel);
                deleteV = false;
                qDebug() << "insertAfter";
            }
            else if(!faceBelong(fp,Faff))
            {
                insertBefore(Faff[i], v, Vsel);
                deleteV = false;
                qDebug() << "insertBefore";
            }
            else
            {
                replaceVertex(Faff[i], v, Vsel);
                qDebug() << "replaceVertex";
            }
            printFace(Faff[i]);//
        }
        qDebug() << "-All done";
        if(deleteV) deleteVertex(&v);
    }
    setSyms();
}


void Mesh::deleteVertex(Vertex **v)
{
    if(*v==nullptr) return;

    for(int i = 0;i<vVector.size();i++)
    {
        if(vVector[i]==*v)
        {
            vVector.erase(vVector.begin() + i);
            break;
        }
    }
    delete *v;
    *v = nullptr;
}


bool Mesh::faceBelong(Face *f, std::vector<Face*> Faff)
{
    if(f==nullptr) return false;

    int n = Faff.size();
    for(int i = 0;i<n;i++)
    {
        if(Faff[i]==f)
            return true;
    }
    return false;
}


Face* Mesh::getNextFace(Face *f, const std::deque<Face*>& Ffan)
{
    if(f==nullptr) return nullptr;

    int n = Ffan.size();
    for(int i = 0;i<n;i++)
    {
        if(Ffan[i]==f)
            return Ffan[(i+1)%n];
    }
    return nullptr;
}

Face* Mesh::getPreviousFace(Face *f, const std::deque<Face*>& Ffan)
{
    if(f==nullptr) return nullptr;

    int n = Ffan.size();
    for(int i = 0;i<n;i++)
    {
        if(Ffan[i]==f)
            return Ffan[(i-1+n)%n];
    }
    return nullptr;
}


void Mesh::insertBefore(Face *f, Vertex *v, std::vector<Vertex *> &Vsel)
{
    if(f==nullptr||v==nullptr||Vsel.size()==0)
        return;

    HalfEdge* start = f->halfEdge;
    HalfEdge* current = start;
    bool found = false;
    do
    {
        if(current->vert==v)
        {
            found = true;
            break;
        }
        else
            current = current->next;
    }
    while(current!=start&&current!=nullptr);

    if(found)
    {
        current->vert = Vsel[0];
        HalfEdge* final = current;
        HalfEdge* finalNext = current->next;
        for(int i = 1;i<Vsel.size();i++)
        {
            HalfEdge* e = new HalfEdge(Vsel[i]);
            e->face = f;
            if(Vsel[i-1]->halfEdge==nullptr) Vsel[i-1]->halfEdge = e;

            if(i>1)
            {
                hVector[hVector.size()-1]->next = e;
            }
            else
            {
                current->next = e;
            }
            final = e;
            hVector.push_back(e);
        }
        HalfEdge* lastEdge = new HalfEdge(v);
        if(Vsel[Vsel.size()-1]->halfEdge==nullptr) Vsel[Vsel.size()-1]->halfEdge = lastEdge;
        final->next = lastEdge;
        lastEdge->face = f;
        lastEdge->next = finalNext;
        hVector.push_back(lastEdge);
    }
}


void Mesh::insertAfter(Face *f, Vertex *v, std::vector<Vertex *> &Vsel)
{
    if(f==nullptr||v==nullptr||Vsel.size()==0)
        return;

    HalfEdge* start = f->halfEdge;
    HalfEdge* current = start;
    bool found = false;
    do
    {
        if(current->vert==v)
        {
            found = true;
            break;
        }
        else
            current = current->next;
    }
    while(current!=start&&current!=nullptr);

    if(found)
    {
        HalfEdge* finalNext = current->next;
        for(int i = 0;i<Vsel.size();i++)
        {
            HalfEdge* e = new HalfEdge(Vsel[i]);
            e->face = f;
            if(i>0)
            {
                if(Vsel[i-1]->halfEdge==nullptr) Vsel[i-1]->halfEdge = e;
            }
            else
            {
                if(v->halfEdge==nullptr) v->halfEdge = e;
            }

            if(i>1)
            {
                hVector[hVector.size()-1]->next = e;
            }
            else
            {
                current->next = e;
            }

            hVector.push_back(e);
        }
        if(Vsel[Vsel.size()-1]->halfEdge==nullptr) Vsel[Vsel.size()-1]->halfEdge = hVector[hVector.size()-1];
        hVector[hVector.size()-1]->next = finalNext;
    }
}


void Mesh::replaceVertex(Face *f, Vertex *v, std::vector<Vertex*> &Vsel)
{
    if(f==nullptr||v==nullptr||Vsel.size()==0)
        return;

    HalfEdge* start = f->halfEdge;
    HalfEdge* current = start;
    bool found = false;
    do
    {
        if(current->vert==v)
        {
            found = true;
            break;
        }
        else
            current = current->next;
    }
    while(current!=start&&current!=nullptr);

    if(found)
    {
        current->vert = Vsel[0];
        HalfEdge* finalNext = current->next;
        for(int i = 1;i<Vsel.size();i++)
        {
            HalfEdge* e = new HalfEdge(Vsel[i]);
            e->face = f;
            if(Vsel[i-1]->halfEdge==nullptr) Vsel[i-1]->halfEdge = e;

            if(i>1)
            {
                hVector[hVector.size()-1]->next = e;
            }
            else
            {
                current->next = e;
            }
            e->next = finalNext;//will be overwriten except for last one
            hVector.push_back(e);
        }
        if(Vsel[Vsel.size()-1]->halfEdge==nullptr) Vsel[Vsel.size()-1]->halfEdge = finalNext;
    }
}


bool Mesh::betweenFacePlane(Vertex *v, Face *f, glm::vec3 p, glm::vec3 n)
{
    if(v==nullptr||f==nullptr) return false;

    bool result = false;

    glm::vec3 v1 = f->halfEdge->vert->position;
    glm::vec3 n1 = glm::normalize(f->nor);

    /// keep the normal normalized, because dot product will be used to determine whether it overlap with another direction or not
    n = glm::normalize(n);//shiiiiiiit, just to be robust, we do it here again,

    if(glm::dot(n1, n) > 0)//when push, to find vertices between the two plane, we need to flip the normal of the surface plane
    {
        n1*=-1.f;
    }

    if(glm::abs(glm::dot(v->position - v1, n1)) > EPSILON &&
            glm::abs(glm::dot(v->position - p, n)) > EPSILON &&
            glm::dot(v->position - v1, n1) * glm::dot(v->position - p, n) > 0)//on the same side of both plane, and not on either of them
        result = true;
    else
        result = false;

    qDebug() << "------In betweenFacePlane v:"
             << v->position.x << "," << v->position.y << "," << v->position.z << " v1:"
             << v1.x << "," << v1.y << "," << v1.z << " n1:"
             << n1.x << "," << n1.y << "," << n1.z << " p:"
             << p.x << "," << p.y << "," << p.z << " n:"
             << n.x << "," << n.y << "," << n.z << " between ? :" << result;

    return result;
}

bool Mesh::intersectPlanePlane(Face *f, glm::vec3 p, glm::vec3 n, glm::vec3 *origin, glm::vec3 *direction)
{
    if(f==nullptr) return false;
    glm::vec3 v1 = f->halfEdge->vert->position;
    glm::vec3 n1 = glm::normalize(f->nor);

    n = glm::normalize(n);//just to be robust

    if(1 - glm::abs(glm::dot(n1, n)) < EPSILON)//parallel
        return false;


    //ALERT: following code is not stable, inverse is not guaranteed
    //EDIT: it seems preventing parallel situation guaranteed the inverse exist

    glm::vec3 cross = glm::cross(n1, n);

    if(cross.x!=0)//can safely assume dx = 1
    {
        //assume dx = 1
        glm::vec2 b(-n1.x, -n.x);
        glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.y, n.y), glm::vec2(n1.z, n.z)));
        glm::vec2 x = invA * b;
        *direction = glm::normalize(glm::vec3(1, x.x, x.y));
    }
    else if(cross.y!=0)//can safely assume dy = 1
    {
        //assume dx = 1
        glm::vec2 b(-n1.y, -n.y);
        glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.x, n.x), glm::vec2(n1.z, n.z)));
        glm::vec2 x = invA * b;
        *direction = glm::normalize(glm::vec3(x.x, 1, x.y));
    }
    else if(cross.z!=0)//can safely assume dz = 1
    {
        //assume dz = 1
        glm::vec2 b(-n1.z, -n.z);
        glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.x, n.x), glm::vec2(n1.y, n.y)));
        glm::vec2 x = invA * b;
        *direction = glm::normalize(glm::vec3(x.x, x.y, 1));
    }
    else
    {
        return false;
    }

    float v1n1 = glm::dot(v1, n1);
    float pn = glm::dot(p, n);
    if(cross.x!=0)//can safely assume ox = 1
    {
        //assume ox = 1
        glm::vec2 b(v1n1-n1.x, pn-n.x);
        glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.y, n.y), glm::vec2(n1.z, n.z)));
        glm::vec2 x = invA * b;
        *origin = glm::vec3(1, x.x, x.y);
    }
    else if(cross.y!=0)//can safely assume oy = 1
    {
        //assume oy = 1
        glm::vec2 b(v1n1-n1.y, pn-n.y);
        glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.x, n.x), glm::vec2(n1.z, n.z)));
        glm::vec2 x = invA * b;
        *origin = glm::vec3(x.x, 1, x.y);
    }
    else if(cross.z!=0)//can safely assume oz = 1
    {
        //assume oz = 1
        glm::vec2 b(v1n1-n1.z, pn-n.z);
        glm::mat2x2 invA = glm::inverse(glm::mat2x2(glm::vec2(n1.x, n.x), glm::vec2(n1.y, n.y)));
        glm::vec2 x = invA * b;
        *origin = glm::vec3(x.x, x.y, 1);
    }
    else
    {
        return false;
    }

    return true;
}

bool Mesh::intersectFacePlane(Face *f, glm::vec3 p, glm::vec3 n)
{
    if(f==nullptr) return false;
    HalfEdge* start = f->halfEdge;
    HalfEdge* current = start;
    bool first = true;
    bool direction = true;

    do
    {
        glm::vec3 v = current->vert->position;
        if(first)
        {
            direction = glm::dot(v - p, n) > 0;
            first = false;
        }
        else if((glm::dot(v - p, n) > 0) != direction)
        {
            return true;
        }
        current = current->next;
    }
    while(current!=start&&current!=nullptr);
    return false;
}

bool Mesh::intersectPlanePlanePlane(Face *f1,
                                    Face *f2,
                                    Face *f3,
                                    glm::vec3 *intersection)
{
    if(f1==nullptr||f2==nullptr||f3==nullptr) return false;
    glm::vec3 v1 = f1->halfEdge->vert->position;
    glm::vec3 v2 = f2->halfEdge->vert->position;
    glm::vec3 v3 = f3->halfEdge->vert->position;

    /// keep the normal normalized, because dot product will be used to determine whether it overlap with another direction or not
    glm::vec3 n1 = glm::normalize(f1->nor);
    glm::vec3 n2 = glm::normalize(f2->nor);
    glm::vec3 n3 = glm::normalize(f3->nor);

    if(glm::abs(glm::dot(n1,n2)) == 1)//parallel
    {
        n1.x += EPSILON;//change n1 a little bit
        n1 = glm::normalize(n1);
    }

    if(glm::abs(glm::dot(n3,n2)) == 1)//parallel
    {
        n3.y += EPSILON;//change n3 a little bit
        n3 = glm::normalize(n3);
    }

    qDebug() << "PPP>>>n1:" << n1.x << ","<< n1.y << ","<< n1.z
             << ">>>n2:"<< n2.x << ","<< n2.y << ","<< n2.z
             << ">>>n3:"<< n3.x << ","<< n3.y << ","<< n3.z;
    if(glm::abs(glm::dot(n1,n3)) == 1 || glm::abs(glm::dot(n2,n3)) == 1 || glm::abs(glm::dot(n1,n2)) == 1)//invalid situation
        return false;

    //ALERT: following code is not stable, inverse is not guaranteed
    //EDIT: it seems preventing parallel situation guaranteed the inverse exist
    glm::mat3x3 invA = glm::inverse(glm::transpose(glm::mat3x3(n1, n2, n3)));
    glm::vec3 b(glm::dot(v1,n1), glm::dot(v2,n2), glm::dot(v3,n3));
    *intersection = invA * b;
    return true;
}


bool Mesh::intersectPlanePlanePlane(Face *f1,
                                    Face *f2,
                                    glm::vec3 p, glm::vec3 n,
                                    glm::vec3 *intersection)
{
    if(f1==nullptr||f2==nullptr) return false;
    glm::vec3 v1 = f1->halfEdge->vert->position;
    glm::vec3 v2 = f2->halfEdge->vert->position;
    glm::vec3 n1 = glm::normalize(f1->nor);
    glm::vec3 n2 = glm::normalize(f2->nor);

    /// keep the normal normalized, because dot product will be used to determine whether it overlap with another direction or not
    n = glm::normalize(n);//shiiiiiiit, just to be robust, we do it here again,

    if(glm::abs(glm::dot(n1,n2)) == 1)//parallel
    {
        n1.x += EPSILON;//change n1 a little bit
        n1 = glm::normalize(n1);
    }

    qDebug() << "PPP>>>n1:" << n1.x << ","<< n1.y << ","<< n1.z
             << ">>>n2:"<< n2.x << ","<< n2.y << ","<< n2.z
             << ">>>n:"<< n.x << ","<< n.y << ","<< n.z;
    if(glm::abs(glm::dot(n1,n)) == 1 || glm::abs(glm::dot(n2,n)) == 1)//invalid situation
        return false;

    glm::mat3 invA = glm::inverse(glm::transpose(glm::mat3(n1, n2, n)));
    glm::vec3 b(glm::dot(v1,n1), glm::dot(v2,n2), glm::dot(p,n));
    *intersection = invA * b;
    return true;
}

void Mesh::parseFile(QFile* file)
{
    freeMemory();
    Face::id_next = 1;
    HalfEdge::id_next = 1;
    Vertex::id_next = 1;

    QTextStream in(file);
    std::srand(std::time(0));

    while (!in.atEnd()) {
        QString line = in.readLine();
        std::string str = line.toStdString();

        if (str.substr(0, 2) == "v ")
        {
            std::stringstream ss;
            ss << str.substr(2);
            glm::vec3 v;
            ss >> v.x;
            ss >> v.y;
            ss >> v.z;
            Vertex* V = new Vertex(v);
            V->halfEdge = nullptr;//explicitly set to nullptr to remind me setting it later even not necessary
            vVector.push_back(V);
        }
        else if (str.substr(0, 3) == "vt ")
        {
            //texture coord
        }
        else if (str.substr(0, 3) == "vn ")
        {
            //normal coord
        }
        else if (str.substr(0, 2) == "f ")
        {
            std::stringstream ss;
            ss << str.substr(2);

            //Parsing
            parseObjFace(ss);
        }
        else if (str[0] == '#')
        {
            //comment
        }
        else
        {
            //others
        }

    }

    setSyms();
    create();
}


void Mesh::parseObjFace(std::stringstream &ss)
{
    char discard;
    char peek;
    int data;
    std::stack<int> indexStack;

    //One vertex in one loop
    do
    {
        ss >> peek;
        if (peek >= '0' && peek <= '9')
        {
            ss.putback(peek);
            ss >> data;
            indexStack.push(--data);
            ss >> discard;
        }
        else
        {
            //no position coord
        }

        ss >> peek;
        if (peek >= '0' && peek <= '9')
        {
            ss.putback(peek);
            ss >> data;
            //texture coord
            ss >> discard;
        }
        else
        {
            //no texture coord
        }

        ss >> peek;
        if (peek >= '0' && peek <= '9')
        {
            ss.putback(peek);
            ss >> data;
            //normal coord
            //no discard here because it is the end for this vertex
        }
        else
        {
            //no normal coord
        }
    } while (!ss.eof());

    HalfEdge* lastH = nullptr;
    Face* f = new Face();
    int count = indexStack.size();
    while(!indexStack.empty())
    {
        int index = indexStack.top();
        indexStack.pop();

        Vertex* v1 = vVector.at(index);
        HalfEdge* h1 = new HalfEdge(v1);
        h1->next = lastH;
        h1->face = f;
        h1->sym = nullptr;//explicitly set to nullptr to remind me setting it later even not necessary

        hVector.push_back(h1);

        if(v1->halfEdge==nullptr)
            v1->halfEdge = lastH;//always keep vertex's halfedge pointing out of the vertex, which is not necessary but good habit

        lastH = h1;
    }
    f->halfEdge = lastH;
    f->col = glm::vec3((float)std::rand()/RAND_MAX, (float)std::rand()/RAND_MAX, (float)std::rand()/RAND_MAX);
    fVector.push_back(f);
    HalfEdge* firstH = hVector.at(hVector.size()-count);
    firstH->next = lastH;
    if(firstH->vert->halfEdge==nullptr)
        firstH->vert->halfEdge=lastH;//always keep vertex's halfedge pointing out of the vertex, which is not necessary but good habit
}


void Mesh::setSyms()
{
    for(int i = 0;i<fVector.size();i++)
    {
        for(int j = i+1;j<fVector.size();j++)
        {
            Face* f1 = fVector.at(i);
            Face* f2 = fVector.at(j);

            HalfEdge* f1_LastE = f1->halfEdge;
            HalfEdge* f2_LastE = f2->halfEdge;

            HalfEdge* f1_StartE = f1->halfEdge->next;
            HalfEdge* f2_StartE = f2->halfEdge->next;

            HalfEdge* f1_CurrentE = f1_StartE;
            HalfEdge* f2_CurrentE = f2_StartE;

            do
            {
                do
                {

                    if(f1_CurrentE->vert == f2_LastE->vert && f1_LastE->vert == f2_CurrentE->vert)
                    {
                        f1_CurrentE->sym = f2_CurrentE;
                        f2_CurrentE->sym = f1_CurrentE;
                    }

                    f2_CurrentE = f2_CurrentE->next;
                    f2_LastE = f2_LastE->next;
                }while(f2_CurrentE!=f2_StartE);
                f1_CurrentE = f1_CurrentE->next;
                f1_LastE = f1_LastE->next;
            }while(f1_CurrentE!=f1_StartE);
        }
    }
}


void Mesh::skin(const Skeleton &s)
{
    if(s.root!=nullptr)
    {
        for(int i = 0;i<vVector.size();i++)
        {
            std::vector<float> length;
            std::vector<int> id;
            Vertex* v = vVector.at(i);
            for(int k = 0;k<s.jVector.size();k++)
            {
                Joint* j = s.jVector.at(k);
                glm::vec3 jPos = glm::vec3(j->getOverallTransformation()*glm::vec4(0,0,0,1));
                length.push_back(glm::length(jPos - v->position));
                id.push_back(k);
            }

            for(int m = 0;m<length.size();m++)
            {
                for(int n = m+1;n<length.size();n++)
                {
                    if(length.at(m)>length.at(n))
                    {
                        float temp = length.at(m);
                        length.at(m) = length.at(n);
                        length.at(n) = temp;

                        int tempI = id.at(m);
                        id.at(m) = id.at(n);
                        id.at(n) = tempI;
                    }
                }
            }

            float total = 0.f;
            int boneCount = 0;
            for(int a = 0;a<length.size();a++)
            {
                boneCount++;
                total += length.at(a);
                if(boneCount>=4) break;
            }
            for(int b = 0;b<4;b++)
            {
                if(length.size()>=4)
                {
                    v->boneI[b] = id.at(b);
                    v->boneW[b] = length.at(3-b)/total;
                }
                else
                {
                    v->boneI[b] = b >= length.size() ? 0:id.at(b);
                    v->boneW[b] = b >= length.size() ? 0.f:length.at(length.size()-1-b)/total;
                }
            }
            //printf("%d,%d,%d,%d:%f,%f,%f,%f\n", v->boneI.x, v->boneI.y,v->boneI.z,v->boneI.w,v->boneW.x,v->boneW.y,v->boneW.z,v->boneW.w);
        }
        create();
    }
}

void Mesh::printFace(Face *f)
{
    if(f==nullptr) return;
    HalfEdge* start = f->halfEdge;
    HalfEdge* current = start;
    qDebug() << ">>>face:" << f->id;
    do
    {
        qDebug() << "--edge:" << current->id << "--vertex:" << current->vert->id;
        current = current->next;
    }
    while(current!=start&&current!=nullptr);
}
