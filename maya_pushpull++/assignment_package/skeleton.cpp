#include "skeleton.h"

Skeleton::Skeleton() : root(nullptr)
{
}

void Skeleton::printAll()
{
    printJoint(root);
}

void Skeleton::printJoint(Joint *j)
{
    printf("%s:",j->name.toLatin1().data());
    printf("%f,%f,%f,%f ", j->position.x, j->position.y, j->position.z);
    for(int i = 0;i<j->children.size();i++)
    {
        printJoint(j->children.at(i));
    }
}

void Skeleton::parseFile(QFile* f)
{
    if(root!=nullptr) delete root;
    jVector.clear();
    QByteArray data = f->readAll();
    QJsonDocument jsonData = QJsonDocument::fromJson(data);
    root = parseJoint(jsonData.object());
}

Joint* Skeleton::parseJoint(const QJsonObject &json)
{
    if(json["root"]!=QJsonValue::Undefined)
    {
        return parseJoint(json["root"].toObject());
    }
    else
    {
        Joint* j = new Joint();
        jVector.push_back(j);

        if(json["name"]!=QJsonValue::Undefined)
        {
            j->name = json["name"].toString();
        }
        else
        {
            j->name = QString("jon/snow");
        }

        j->setText(0, j->name);

        if(json["pos"]!=QJsonValue::Undefined)
        {
            QJsonArray posArray = json["pos"].toArray();
            for(int i = 0;i<3;i++)
            {
                j->position[i] = posArray[i].toDouble();
            }
        }
        else
        {
            j->position = glm::vec3(0,0,0);
        }

        if(json["rot"]!=QJsonValue::Undefined)
        {
            QJsonArray rotArray = json["rot"].toArray();
            float angle = rotArray[0].toDouble();
            float x = rotArray[1].toDouble();
            float y = rotArray[2].toDouble();
            float z = rotArray[3].toDouble();
            float sinHalf = glm::sin(angle/2.f);
            float cosHalf = glm::cos(angle/2.f);
            glm::vec3 temp(x,y,z);
            temp = glm::normalize(temp);
            j->rotation = glm::quat(cosHalf,sinHalf*temp.x,sinHalf*temp.y,sinHalf*temp.z);
        }
        else
        {
            j->rotation = glm::quat(1,0,0,0);
        }

        //should not do it here since the parent node is not set
        //it is better to add a seperate function to calculate bindMatrix
        //so that we can set our bind pose whenever we want
//        j->bindMatrix = glm::inverse(j->getOverallTransformation());
//        glm::mat4 temp = j->bindMatrix * j->getOverallTransformation();
//        printf("transformMatrix * bindMatrix 2\n");
//        for(int m = 0;m<4;m++)
//        {
//            printf("%f,%f,%f,%f\n",temp[0][m],temp[1][m],temp[2][m],temp[3][m]);
//        }
//        printf("\n");

        if(json["children"]!=QJsonValue::Undefined)
        {
            QJsonArray childrenArray = json["children"].toArray();
            for(int i = 0;i<childrenArray.size();i++)
            {
                Joint* cj = parseJoint(childrenArray[i].toObject());
                j->children.push_back(cj);
                j->addChild(cj);
                cj->parent = j;
            }
        }
        else
        {
            // do nothing
        }
        return j;
    }
}

void Skeleton::bind()
{
    for(int i = 0;i<jVector.size();i++)
    {
        jVector.at(i)->bindMatrix = glm::inverse(jVector.at(i)->getOverallTransformation());
    }
}
