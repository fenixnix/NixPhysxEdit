#include "nbbody.h"

using namespace tinyxml2;

NBBody::NBBody()
{
    qDebug()<<__FUNCTION__;
    this->id = "";
    def.type = b2_dynamicBody;
    def.linearDamping = 0.1f;
    def.angularDamping = 0.1f;
}

NBBody::~NBBody()
{
    clear();
}

NBBody::NBBody(QString id)
{
    def.type = b2_dynamicBody;
    def.linearDamping = 0.1f;
    def.angularDamping = 0.1f;
    this->id = id;
}

NBObject::NBObjectType NBBody::getType()
{
    return NBObject::type_body;
}

void NBBody::write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent)
{
    XMLElement* root = parent->LinkEndChild(dom->NewElement("Body"))->ToElement();
    root->SetAttribute("id",id.toStdString().c_str());

    XMLElement* position = root->LinkEndChild(dom->NewElement("position"))->ToElement();
    position->SetAttribute("x",def.position.x);
    position->SetAttribute("y",def.position.y);

    XMLElement* angle = root->LinkEndChild(dom->NewElement("angle"))->ToElement();
    angle->SetAttribute("value",def.angle);

    XMLElement* linearVelocity = root->LinkEndChild(dom->NewElement("linearVelocity"))->ToElement();
    linearVelocity->SetAttribute("x",def.linearVelocity.x);
    linearVelocity->SetAttribute("y",def.linearVelocity.y);

    XMLElement* angularVelocity = root->LinkEndChild(dom->NewElement("angularVelocity"))->ToElement();
    angularVelocity->SetAttribute("value",def.angularVelocity);

    XMLElement* linearDamping = root->LinkEndChild(dom->NewElement("linearDamping"))->ToElement();
    linearDamping->SetAttribute("value",def.linearDamping);

    XMLElement* angularDamping = root->LinkEndChild(dom->NewElement("angularDamping"))->ToElement();
    angularDamping->SetAttribute("value",def.angularDamping);

    XMLElement* allowSleep = root->LinkEndChild(dom->NewElement("allowSleep"))->ToElement();
    allowSleep->SetAttribute("value",def.allowSleep);

    XMLElement* awake = root->LinkEndChild(dom->NewElement("awake"))->ToElement();
    awake->SetAttribute("value",def.awake);

    XMLElement* fixedRotation = root->LinkEndChild(dom->NewElement("fixedRotation"))->ToElement();
    fixedRotation->SetAttribute("value",def.fixedRotation);

    XMLElement* bullet = root->LinkEndChild(dom->NewElement("bullet"))->ToElement();
    bullet->SetAttribute("value",def.bullet);

    XMLElement* type = root->LinkEndChild(dom->NewElement("type"))->ToElement();
    type->SetAttribute("value",def.type);

    XMLElement* active = root->LinkEndChild(dom->NewElement("active"))->ToElement();
    active->SetAttribute("value",def.active);

    XMLElement* gravityScale = root->LinkEndChild(dom->NewElement("gravityScale"))->ToElement();
    gravityScale->SetAttribute("value",def.gravityScale);

    foreach(NBFixture* fixture,fixtures.values()){
        fixture->write(dom,root);
    }
}

NBObject *NBBody::read(XMLNode *node)
{
    clear();
    using namespace tinyxml2;
    XMLElement *elm = node->ToElement();
    id = QString(elm->Attribute("id"));
    def.position.x = elm->FirstChildElement("position")->FloatAttribute("x");
    def.position.y = elm->FirstChildElement("position")->FloatAttribute("y");
    def.angle = elm->FirstChildElement("angle")->FloatAttribute("value");
    def.linearVelocity.x = elm->FirstChildElement("linearVelocity")->FloatAttribute("x");
    def.linearVelocity.y = elm->FirstChildElement("linearVelocity")->FloatAttribute("y");
    def.angularVelocity = elm->FirstChildElement("angularVelocity")->FloatAttribute("value");
    def.linearDamping = elm->FirstChildElement("linearDamping")->FloatAttribute("value");
    def.angularDamping = elm->FirstChildElement("angularDamping")->FloatAttribute("value");
    def.allowSleep = elm->FirstChildElement("allowSleep")->BoolAttribute("value");
    def.awake = elm->FirstChildElement("awake")->BoolAttribute("value");
    def.fixedRotation = elm->FirstChildElement("fixedRotation")->BoolAttribute("value");
    def.bullet = elm->FirstChildElement("bullet")->BoolAttribute("value");
    def.type = (b2BodyType)elm->FirstChildElement("type")->IntAttribute("value");
    def.active = elm->FirstChildElement("active")->BoolAttribute("value");
    def.gravityScale = elm->FirstChildElement("gravityScale")->FloatAttribute("value");

    XMLNode *n = node->FirstChild();
    while(n){
        if(QString(n->ToElement()->Name()) == QString("Fixture")){
           NBFixture* fixture = new NBFixture(this,"");
           fixture->read(n);
           this->addFixture(fixture);
        }
        n = n->NextSibling();
    }

    return this;
}

void NBBody::clear()
{
    foreach(NBFixture* fix,fixtures){
        delete fix;
    }
    fixtures.clear();
}

//int NBBody::addFixture(QString fid, b2FixtureDef *fixture)
//{
//    NBFixture* nbfixture = new NBFixture(id,fid,fixture);
//    return addFixture(nbfixture);
//}

int NBBody::addFixture(NBFixture *fixture)
{
    qDebug()<<__FUNCTION__<<__LINE__<<fixture;
    if(fixtures.contains(fixture->id)){
        qDebug()<<__FUNCTION__<<__LINE__;
        return 1;
    }
    qDebug()<<__FUNCTION__<<__LINE__;
    fixtures[fixture->id] = fixture;
    return 0;
}

int NBBody::delFixture(QString id)
{
    NBFixture *fixture = getFixture(id);
    if(fixture == nullptr){
        qDebug()<<__FUNCTION__<<__LINE__;
        return __LINE__;
    }
    delete fixture;
    fixtures.erase(fixtures.find(id));
    return 0;
}

b2FixtureDef *NBBody::getFixtureDef(QString id)
{
    if(fixtures.contains(id)){
        return &fixtures[id]->def;
    }
    return nullptr;
}

NBFixture *NBBody::getFixture(QString id)
{
    if(fixtures.contains(id)){
        return fixtures[id];
    }
    qDebug()<<__FUNCTION__<<__LINE__;
    return nullptr;
}

QStringList NBBody::getFixtureList()
{
    return fixtures.keys();
}
