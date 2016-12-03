#include "nbjointdistance.h"

NBJointDistance::NBJointDistance()
{
    idA = "";
    idB = "";
    this->id = "";
    dampingRatio = 0.0f;
    frequencyHz = 0.0f;
    anchorA = b2Vec2(0,0);
    anchorB = b2Vec2(0,0);
}

NBJointDistance::NBJointDistance(string id)
{
    idA = "";
    idB = "";
    dampingRatio = 0.0f;
    frequencyHz = 0.0f;
    anchorA = b2Vec2(0,0);
    anchorB = b2Vec2(0,0);
    this->id = id;
}

void NBJointDistance::write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent)
{
    using namespace tinyxml2;
    XMLElement* root = parent->LinkEndChild(dom->NewElement("Joint"))->ToElement();
    writeJointCommonInfo(dom,root);

//    root->SetAttribute("id",id.c_str());
//    root->SetAttribute("type",getJointType().c_str());

//    XMLElement* bodyA = root->LinkEndChild(dom->NewElement("idA"))->ToElement();
//    bodyA->SetAttribute("value",this->idA.c_str());

//    XMLElement* bodyB = root->LinkEndChild(dom->NewElement("idB"))->ToElement();
//    bodyB->SetAttribute("value",this->idB.c_str());

    XMLElement* anchorA  = root->LinkEndChild(dom->NewElement("anchorA"))->ToElement();
    anchorA->SetAttribute("x",this->anchorA.x);
    anchorA->SetAttribute("y",this->anchorA.y);

    XMLElement* anchorB  = root->LinkEndChild(dom->NewElement("anchorB"))->ToElement();
    anchorB->SetAttribute("x",this->anchorB.x);
    anchorB->SetAttribute("y",this->anchorB.y);

//    _WRITEPR(collideConnected);
    _WRITEPR(dampingRatio);
    _WRITEPR(frequencyHz);
}

NBObject* NBJointDistance::read(tinyxml2::XMLNode *root)
{
    using namespace tinyxml2;
    XMLElement *elm = root->ToElement();
    id = string(elm->Attribute("id"));
    idA = string(elm->FirstChildElement("idA")->Attribute("value"));
    idB = string(elm->FirstChildElement("idB")->Attribute("value"));
    anchorA.x = elm->FirstChildElement("anchorA")->FloatAttribute("x");
    anchorA.y = elm->FirstChildElement("anchorA")->FloatAttribute("y");
    anchorB.x = elm->FirstChildElement("anchorB")->FloatAttribute("x");
    anchorB.y = elm->FirstChildElement("anchorB")->FloatAttribute("y");
    _READBOOLPR(collideConnected);
    _READFLOATPR(dampingRatio);
    _READFLOATPR(frequencyHz);
    return this;
}

b2JointDef *NBJointDistance::getInitDef(B2Unit* unit)
{
    b2Body* A = unit->getBody(idA);
    b2Body* B = unit->getBody(idB);
    if((A == nullptr)||(B == nullptr)){
        qDebug()<<__FUNCTION__<<__LINE__;
        return nullptr;
    }
    def.collideConnected = collideConnected;
    def.dampingRatio = dampingRatio;
    def.frequencyHz = frequencyHz;
    def.Initialize(A,B,anchorA,anchorB);
    return &def;
}

b2JointType NBJointDistance::getJointType()
{
    return e_distanceJoint;
}
