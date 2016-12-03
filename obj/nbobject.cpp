#include "nbobject.h"
#include "nbbody.h"
#include "nbfixture.h"
#include "nbjoint.h"

NBObject::NBObject()
{

}

NBObject::NBObjectType NBObject::getType()
{
    return type_unknow;
}

void NBObject::write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent)
{
    return;
}

NBObject *NBObject::read(tinyxml2::XMLNode *node)
{
    qDebug()<<__FUNCTION__<<"empty";
    return nullptr;
}

void NBObject::writeB2Vec2(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *root, string name, b2Vec2 vec)
{
    using namespace tinyxml2;
    XMLElement* elm  = root->LinkEndChild(dom->NewElement(name.c_str()))->ToElement();
    elm->SetAttribute("x",vec.x);
    elm->SetAttribute("y",vec.y);
}

b2Vec2 NBObject::readB2Vec2(tinyxml2::XMLNode *root)
{
    using namespace tinyxml2;
    b2Vec2 vec;
    vec.x = root->ToElement()->FloatAttribute("x");
    vec.y = root->ToElement()->FloatAttribute("y");
    return vec;
}

NBBody *NBObject::toBody()
{
    return (NBBody*)this;
}

NBFixture *NBObject::toFixture()
{
    return (NBFixture*)this;
}

NBJoint *NBObject::toJoint()
{
    return (NBJoint*)this;
}
