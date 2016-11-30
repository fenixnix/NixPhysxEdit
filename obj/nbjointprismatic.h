#ifndef NBJOINTPRISMATIC_H
#define NBJOINTPRISMATIC_H

#include "nbjoint.h"

class NBJointPrismatic : public NBJoint
{
public:
    NBJointPrismatic();
    NBJointPrismatic(string id);
    string getJointType();
    //获取内部初始化JointDef实例指针
    b2JointDef *getInitDef(B2Unit* unit);

    //write to para to dom parent node
    void write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent);
    //read node to init para
    NBObject *read(tinyxml2::XMLNode* root);

//private:
    b2Vec2 anchor;
    b2Vec2 axis;
//    bool enableLimit;
//    bool enableMotor;
//    float lowerTranslation;
//    float maxMotorForce;
//    float motorSpeed;
//    float referenceAngle;
//    float upperTranslation;
    b2PrismaticJointDef def;
};

#endif // NBJOINTPRISMATIC_H
