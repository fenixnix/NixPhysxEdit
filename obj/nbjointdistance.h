#ifndef NBJOINTDISTANCE_H
#define NBJOINTDISTANCE_H

#include "nbjoint.h"

class NBJointDistance : public NBJoint
{
public:
    NBJointDistance();
    NBJointDistance(string id);
    b2JointType getJointType();

    //write to para to dom parent node
    void write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent);
    //read node to init para
    NBObject* read(tinyxml2::XMLNode* root);
    //获取内部初始化JointDef实例指针
    b2JointDef *getInitDef(B2Unit* unit);

//private:
    b2Vec2 anchorA;
    b2Vec2 anchorB;
    float dampingRatio;
    float frequencyHz;
    b2DistanceJointDef def;
};

#endif // NBJOINTDISTANCE_H
