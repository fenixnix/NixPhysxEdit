#ifndef NBJOINTREVOLUTE_H
#define NBJOINTREVOLUTE_H

#include "nbjoint.h"

class NBJointRevolute : public NBJoint
{
public:
    NBJointRevolute();
    NBJointRevolute(string id);
    b2JointType getJointType();

    //获取内部初始化JointDef实例指针
    b2JointDef *getInitDef(B2Unit* unit);

    //write to para to dom parent node
    void write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent);
    //read node to init para
    NBObject *read(tinyxml2::XMLNode* root);

//private:
    b2Vec2 anchor;
    float referenceAngle;
    float lowerAngle;
    float upperAngle;
    float maxMotorTorque;
    float motorSpeed;
    bool enableLimit;
    bool enableMotor;
    b2RevoluteJointDef def;
};

#endif // NBJOINTREVOLUTE_H
