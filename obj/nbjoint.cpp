#include "nbjoint.h"
#include "nbjointdistance.h"
#include "nbjointrevolute.h"
#include "nbjointprismatic.h"

NBJoint::NBJoint()
{
    idA = "";
    idB = "";
    id = "";
}

NBObject::NBObjectType NBJoint::getType()
{
    return NBObject::type_joint;
}

b2JointDef *NBJoint::getInitDef(B2Unit *unit)
{
    return nullptr;
}

NBJoint *NBJoint::create(tinyxml2::XMLNode *node)
{
    NBJoint *joint = nullptr;
    if(node->ToElement()->IntAttribute("type") == e_distanceJoint){
        joint = new NBJointDistance;
    }
    if(node->ToElement()->IntAttribute("type") == e_revoluteJoint){
        joint = new NBJointRevolute;
    }
    if(node->ToElement()->IntAttribute("type") == e_prismaticJoint){
        joint = new NBJointPrismatic;
    }
    joint->read(node);
    return joint;
}

void NBJoint::writeJointCommonInfo(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *root)
{
    using namespace tinyxml2;
    root->ToElement()->SetAttribute("id",id.c_str());
    root->ToElement()->SetAttribute("type",getJointType());
    //cout<<__FUNCTION__<<":"<<getJointType()<<endl;

    XMLElement* bodyA = root->LinkEndChild(dom->NewElement("idA"))->ToElement();
    bodyA->SetAttribute("value",this->idA.c_str());

    XMLElement* bodyB = root->LinkEndChild(dom->NewElement("idB"))->ToElement();
    bodyB->SetAttribute("value",this->idB.c_str());

    _WRITEPR(collideConnected);
}

void NBJoint::readJointCommonInfo(tinyxml2::XMLNode *root)
{
    using namespace tinyxml2;
    XMLElement *elm = root->ToElement();
    id = string(elm->Attribute("id"));
    idA = string(elm->FirstChildElement("idA")->Attribute("value"));
    idB = string(elm->FirstChildElement("idB")->Attribute("value"));
    _READBOOLPR(collideConnected);
}

NBJointDistance *NBJoint::toJointDistance()
{
    return (NBJointDistance*)this;
}

NBJointRevolute *NBJoint::toJointRevolute()
{
    return (NBJointRevolute*)this;
}

NBJointPrismatic *NBJoint::toJointPrismatic()
{
    return (NBJointPrismatic*)this;
}

b2JointType NBJoint::getJointType()
{
    return e_unknownJoint;
}
