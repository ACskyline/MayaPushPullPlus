#include "joint.h"

Joint::Joint() : parent(nullptr)
{
    QTreeWidgetItem::setText(0, QString("know/nothing"));
}

Joint::Joint(QString _name) : parent(nullptr)
{
    name = _name;
    QTreeWidgetItem::setText(0, name);
}

glm::mat4 Joint::getLocalTransformation()
{
    return glm::translate(glm::mat4(),position) * glm::toMat4(rotation);
}

glm::mat4 Joint::getOverallTransformation()
{
    if(parent!=nullptr)
    {
        return parent->getOverallTransformation()*getLocalTransformation();
    }
    else
    {
        return getLocalTransformation();
    }
}

Joint::~Joint()
{
    freeMemory();
}

void Joint::freeMemory()
{
    for(int i = 0;i<children.size();i++)
    {
        if(children.at(i) != nullptr) delete children.at(i);
    }
    children.clear();
}
