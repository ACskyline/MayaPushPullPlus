#ifndef JOINT_H
#define JOINT_H
#include <QString>
#include <QTreeWidgetItem>
#include "la.h"

class Joint : public QTreeWidgetItem
{
public:
    QString name;
    Joint* parent;
    std::vector<Joint*> children;
    glm::vec3 position;
    glm::quat rotation;
    glm::mat4 bindMatrix;

    Joint();
    Joint(QString _name);
    ~Joint();
    glm::mat4 getLocalTransformation();
    glm::mat4 getOverallTransformation();
    void freeMemory();
};

#endif // JOINT_H
