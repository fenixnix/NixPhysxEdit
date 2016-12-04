#include "nbjointrevolute.h"

NBJointRevolute::NBJointRevolute()
{
    idA = "";
    idB = "";
    this->id = "";
    referenceAngle = 0.0f;
    lowerAngle = 0.0f;
    upperAngle = 0.0f;
    maxMotorTorque = 0.0f;
    motorSpeed = 0.0f;
    enableLimit = false;
    enableMotor = false;
    anchor = b2Vec2(0,0);
}

NBJointRevolute::NBJointRevolute(string id)
{
    idA = "";
    idB = "";
    referenceAngle = 0.0f;
    lowerAngle = 0.0f;
    upperAngle = 0.0f;
    maxMotorTorque = 0.0f;
    motorSpeed = 0.0f;
    enableLimit = false;
    enableMotor = false;
    anchor = b2Vec2(0,0);
    this->id = id;
}

b2JointType NBJointRevolute::getJointType()
{
    return e_revoluteJoint;
}

void NBJointRevolute::write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent)
{
    using namespace tinyxml2;
    XMLElement* root = parent->LinkEndChild(dom->NewElement("Joint"))->ToElement();
    writeJointCommonInfo(dom,root);

    XMLElement* anchorA  = root->LinkEndChild(dom->NewElement("anchor"))->ToElement();
    anchorA->SetAttribute("x",this->anchor.x);
    anchorA->SetAttribute("y",this->anchor.y);

    _WRITEPR(referenceAngle);
    _WRITEPR(lowerAngle);
    _WRITEPR(upperAngle);
    _WRITEPR(maxMotorTorque);
    _WRITEPR(motorSpeed);
    _WRITEPR(enableLimit);
    _WRITEPR(enableMotor);
}

NBObject *NBJointRevolute::read(tinyxml2::XMLNode *root)
{
    using namespace tinyxml2;
    XMLElement *elm = root->ToElement();
    id = string(elm->Attribute("id"));
    idA = string(elm->FirstChildElement("idA")->Attribute("value"));
    idB = string(elm->FirstChildElement("idB")->Attribute("value"));
    anchor.x = elm->FirstChildElement("anchor")->FloatAttribute("x");
    anchor.y = elm->FirstChildElement("anchor")->FloatAttribute("y");
    _READBOOLPR(collideConnected);
    _READFLOATPR(referenceAngle);
    _READFLOATPR(lowerAngle);
    _READFLOATPR(upperAngle);
    _READFLOATPR(maxMotorTorque);
    _READFLOATPR(motorSpeed);
    _READBOOLPR(enableLimit);
    _READBOOLPR(enableMotor);
    return this;
}

b2JointDef *NBJointRevolute::getInitDef(B2Unit *unit)
{
    qDebug()<<__FUNCTION__<<__LINE__;
    b2Body* A = unit->getBody(idA);
    b2Body* B = unit->getBody(idB);
    if((A == nullptr)||(B == nullptr)){
        cout<<__FUNCTION__<<__LINE__<<":"<<idA<<","<<idB<<endl;
        return nullptr;
    }
    def.Initialize(A,B,anchor);
    def.collideConnected = collideConnected;
    def.referenceAngle = referenceAngle;
    def.lowerAngle = lowerAngle;
    def.upperAngle = upperAngle;
    def.maxMotorTorque = maxMotorTorque;
    def.motorSpeed = motorSpeed;
    def.enableLimit = enableLimit;
    def.enableMotor = enableMotor;

    qDebug()<<def.type<<def.bodyA<<def.bodyB<<def.localAnchorA.x<<def.localAnchorA.y;
    qDebug()<<def.localAnchorB.x<<def.localAnchorB.y<<def.collideConnected;
    qDebug()<<def.referenceAngle<<def.enableLimit<<def.enableMotor;

    return &def;
}
