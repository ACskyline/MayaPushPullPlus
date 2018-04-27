#ifndef SKELETON_H
#define SKELETON_H

#include "joint.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

class Skeleton
{
public:
    Skeleton();
    Joint* root;
    std::vector<Joint*> jVector;
    void parseFile(QFile* f);
    Joint* parseJoint(const QJsonObject &json);
    void printAll();
    void printJoint(Joint* j);
    void bind();
};

#endif // SKELETON_H
