#ifndef NBOBJECT_H
#define NBOBJECT_H

#include <b2physx.h>
#include <QString>
#include <QDebug>
#include <tinyxml2.h>

#define _PR(x) #x
#define _WRITEPR(x) root->LinkEndChild(dom->NewElement(_PR(x)))->ToElement()->SetAttribute("value",this->x);
#define _WRITEDEFPR(x) root->LinkEndChild(dom->NewElement(_PR(x)))->ToElement()->SetAttribute("value",this->def.x);
#define _READPR(x) x=elm->FirstChildElement(#x)->Attribute("value")
#define _READBOOLPR(x) x=elm->FirstChildElement(#x)->BoolAttribute("value")
#define _READFLOATPR(x) x=elm->FirstChildElement(#x)->FloatAttribute("value")
#define _READDEFBOOLPR(x) def.x=elm->FirstChildElement(#x)->BoolAttribute("value")
#define _READDEFFLOATPR(x) def.x=elm->FirstChildElement(#x)->FloatAttribute("value")

class NBBody;
class NBFixture;
class NBJoint;

class NBObject
{
public:
    NBObject();
    virtual QString getType();
    virtual void write(tinyxml2::XMLDocument* dom,tinyxml2::XMLNode* parent);
    virtual NBObject *read(tinyxml2::XMLNode* node);

    static void writeB2Vec2(tinyxml2::XMLDocument* dom,tinyxml2::XMLNode* parent,
                     string name,b2Vec2 vec);
    static b2Vec2 readB2Vec2(tinyxml2::XMLNode* root);

    NBBody *toBody();
    NBFixture *toFixture();
    NBJoint *toJoint();
};

#endif // NBOBJECT_H
