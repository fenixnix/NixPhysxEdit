#ifndef NBLAYER_H
#define NBLAYER_H

#include <Box2D/Box2D.h>
#include <QMap>
#include <QDebug>
#include <obj/nbbody.h>
#include <obj/nbjoint.h>
#include <nqopengl2dwidget.h>
#include <b2unit.h>

class NBLayer
{
public:
    NBLayer();
    void draw(NQOpenGL2DWidget* widget);
    B2Unit* create(b2World* world);
    void write(QString fileName);
    void read(QString fileName);
    void clear();

    int addBody(NBBody* body);
    b2BodyDef* getBody(QString id);
    NBObject *getNBBody(QString id);
    void delBody(QString id);
    QStringList getBodyList();
    void clearAllBody();

    int addFixture(NBFixture* fixture);
    b2FixtureDef *getFixture(QString id, QString fid);
    NBObject *getNBFixture(QString rid, QString fid);
    QStringList getFixtureList(QString rid);

    NBJoint *newDefJoint(string id,QString type);
    int addJoint(string id, NBJoint* joint);
    int addJoint(NBJoint *joint);
    b2JointDef *getInitJoint(string id, B2Unit* unit);
    NBObject *getNBJoint(string id);
    void delJoint(string);
    QStringList getJointList();
    void clearAllJoint();
private:
    QMap<QString,NBBody*> bodys;
    QMap<string,NBJoint*> joints;
};

#endif // NBLAYER_H
