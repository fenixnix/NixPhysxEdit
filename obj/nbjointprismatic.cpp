#include "nbjointprismatic.h"

NBJointPrismatic::NBJointPrismatic()
{
    idA = "";
    idB = "";
    this->id = "";
    anchor = b2Vec2(0,0);
    axis = b2Vec2(0,0);
}

NBJointPrismatic::NBJointPrismatic(string id)
{
    idA = "";
    idB = "";
    this->id = id;
    anchor = b2Vec2(0,0);
    axis = b2Vec2(0,0);
}

b2JointType NBJointPrismatic::getJointType()
{
    return e_prismaticJoint;
}

b2JointDef *NBJointPrismatic::getInitDef(B2Unit *unit)
{
    b2Body* A = unit->getBody(idA);
    b2Body* B = unit->getBody(idB);
    if((A == nullptr)||(B == nullptr)){
        cout<<__FUNCTION__<<__LINE__<<":"<<idA<<","<<idB<<endl;
        return nullptr;
    }
    b2Vec2 difAxis = axis-anchor;
    difAxis.Normalize();
    def.Initialize(A,B,anchor,difAxis);
    qDebug()<<__FUNCTION__<<__LINE__<<anchor.x<<anchor.y<<axis.x<<axis.y;
    def.collideConnected = this->collideConnected;
    return &def;
}

void NBJointPrismatic::write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent)
{
    using namespace tinyxml2;
    XMLElement* root = parent->LinkEndChild(dom->NewElement("Joint"))->ToElement();
    writeJointCommonInfo(dom,root);
    writeB2Vec2(dom,root,"anchor",anchor);
    writeB2Vec2(dom,root,"axis",axis);
    _WRITEDEFPR(enableLimit);
    _WRITEDEFPR(enableMotor);
    _WRITEDEFPR(lowerTranslation);
    _WRITEDEFPR(maxMotorForce);
    _WRITEDEFPR(motorSpeed);
    _WRITEDEFPR(referenceAngle);
    _WRITEDEFPR(upperTranslation);
}

NBObject *NBJointPrismatic::read(tinyxml2::XMLNode *root)
{
    using namespace tinyxml2;
    XMLElement *elm = root->ToElement();
    readJointCommonInfo(root);
    anchor = readB2Vec2(elm->FirstChildElement("anchor"));
    axis = readB2Vec2(elm->FirstChildElement("axis"));
    _READDEFBOOLPR(enableLimit);
    _READDEFBOOLPR(enableMotor);
    _READDEFFLOATPR(lowerTranslation);
    _READDEFFLOATPR(maxMotorForce);
    _READDEFFLOATPR(motorSpeed);
    _READDEFFLOATPR(referenceAngle);
    _READDEFFLOATPR(upperTranslation);
    return this;
}
