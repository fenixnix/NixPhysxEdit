#ifndef NBFIXTURE_H
#define NBFIXTURE_H

#include <obj/nbshape.h>

class NBFixture : public NBObject
{
public:
    NBFixture();
    NBFixture(NBObject *parent, QString id);
    ~NBFixture();
    void clear();
    NBObjectType getType();
    void write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent);
    NBObject *read(tinyxml2::XMLNode *node);
    b2Vec2 getWorldFromLoc(b2Vec2 vec);
    b2Vec2 getLocFromWorld(b2Vec2 vec);
    NBObject* parent;
    QString id;
    int getShapeType();
    b2FixtureDef def;
};

#endif // NBFIXTURE_H
