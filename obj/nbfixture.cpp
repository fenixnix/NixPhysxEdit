#include "nbfixture.h"
#include "nbdatamnger.h"

NBFixture::NBFixture()
{
    parent = nullptr;
    id = "";
    def.density = 1.0f;
    def.friction = 0.3f;
    def.restitution = 0.3f;
}

NBFixture::NBFixture(NBObject *p, QString id)
{
    NBFixture();
    this->parent = p;
    this->id = id;
    def.density = 1.0f;
    def.friction = 0.3f;
    def.restitution = 0.3f;
}

NBFixture::~NBFixture()
{
    clear();
    parent = nullptr;
    if(def.shape!=nullptr){
        qDebug()<<__FUNCTION__<<__LINE__<<"empty";
        //delete def.shape;
        def.shape = nullptr;
    }
}

void NBFixture::clear()
{
    qDebug()<<__FUNCTION__<<__LINE__<<"empty";
}

QString NBFixture::getType()
{
    return "fixture";
}

void NBFixture::write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent)
{
    using namespace tinyxml2;
    XMLElement* root = parent->LinkEndChild(dom->NewElement("Fixture"))->ToElement();
    root->SetAttribute("id",id.toStdString().c_str());
    root->SetAttribute("parent",this->parent->toBody()->id.toStdString().c_str());

    XMLElement* friction = root->LinkEndChild(dom->NewElement("friction"))->ToElement();
    friction->SetAttribute("value",def.friction);


    XMLElement* restitution = root->LinkEndChild(dom->NewElement("restitution"))->ToElement();
    restitution->SetAttribute("value",def.restitution);


    XMLElement* density = root->LinkEndChild(dom->NewElement("density"))->ToElement();
    density->SetAttribute("value",def.density);


    XMLElement* isSensor = root->LinkEndChild(dom->NewElement("isSensor"))->ToElement();
    isSensor->SetAttribute("value",def.isSensor);

    NBDataMnger::the()->writeShape(dom,root,id.toStdString(),(b2Shape*)def.shape);
    NBDataMnger::the()->writeFilter(dom,root,id.toStdString(),&def.filter);
}

NBObject *NBFixture::read(XMLNode *node)
{
    using namespace tinyxml2;
    XMLElement *elm = node->ToElement();
    id = QString(elm->Attribute("id"));
    def.friction = elm->FirstChildElement("friction")->FloatAttribute("value");
    def.restitution = elm->FirstChildElement("restitution")->FloatAttribute("value");
    def.density = elm->FirstChildElement("density")->FloatAttribute("value");
    def.isSensor = elm->FirstChildElement("isSensor")->BoolAttribute("value");
    def.shape = NBDataMnger::the()->readShape(elm->FirstChildElement("Shape"));
    NBDataMnger::the()->readFilter(elm,&def.filter);
    return this;
}

b2Vec2 NBFixture::getWorldFromLoc(b2Vec2 vec)
{
    b2Transform bodyTra = b2Transform(parent->toBody()->def.position,b2Rot(parent->toBody()->def.angle));
    return b2Vec2x(vec).transform(bodyTra);
}

b2Vec2 NBFixture::getLocFromWorld(b2Vec2 vec)
{
    b2Transform bodyTra = b2Transform(parent->toBody()->def.position,b2Rot(parent->toBody()->def.angle));
    return b2Vec2x(vec).invTransform(bodyTra);
}

int NBFixture::getShapeType()
{
    return def.shape->GetType();
}
