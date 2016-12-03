#ifndef NBBODY_H
#define NBBODY_H

#include <QMap>
#include <obj/nbfixture.h>

class NBBody : public NBObject
{
public:
    NBBody();
    ~NBBody();
    void clear();
    NBBody(QString id);
    QString getType();
    void write(tinyxml2::XMLDocument *dom, tinyxml2::XMLNode *parent);
    NBObject* read(tinyxml2::XMLNode *node);

    QString id;
    b2BodyDef def;
    //int addFixture(QString fid,b2FixtureDef* fixture);
    int addFixture(NBFixture* fixture);
    int delFixture(QString id);
    b2FixtureDef *getFixtureDef(QString id);
    NBFixture *getFixture(QString id);
    QStringList getFixtureList();

private:
    QMap<QString, NBFixture*> fixtures;
};

#endif // NBBODY_H
