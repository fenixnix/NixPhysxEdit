#ifndef NBJOINT_H
#define NBJOINT_H

#include <obj/nbobject.h>
#include "b2Unit.h"

class NBJointDistance;
class NBJointRevolute;
class NBJointPrismatic;

class NBJoint : public NBObject
{
public:
    NBJoint();
    NBObjectType getType();
    virtual b2JointType getJointType();
    virtual b2JointDef *getInitDef(B2Unit* unit) = 0;
    static NBJoint* create(tinyxml2::XMLNode* node);

    void writeJointCommonInfo(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent);
    void readJointCommonInfo(tinyxml2::XMLNode *root);

    std::string id;
    string idA;
    string idB;
    bool collideConnected;

    NBJointDistance *toJointDistance();
    NBJointRevolute *toJointRevolute();
    NBJointPrismatic *toJointPrismatic();

//    b2PulleyJointDef def;
//    b2GearJointDef def;
//    b2WheelJointDef def;

//    b2WeldJointDef def;
//    b2RopeJointDef def;
//    b2FrictionJointDef def;
//    b2MotorJointDef def;

//    b2MouseJointDef def;
};

#endif // NBJOINT_H
