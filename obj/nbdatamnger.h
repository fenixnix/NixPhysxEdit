#ifndef NBDATAMNGER_H
#define NBDATAMNGER_H

#include "singleton.h"
#include <QtCore>
#include <QMap>
#include <QDebug>
#include <Box2D/Box2D.h>
#include <tinyxml2.h>
#include <string>
#include <obj/nblayer.h>
#include <nqopengl2dwidget.h>

using namespace std;
using namespace tinyxml2;

class NBDataMnger : public NSingleton<NBDataMnger>
{
public:
    NBDataMnger();

    void load(std::string fileName);
    void import(std::string fileName);
    void save(QString fileName);

    void shapeExport(QString fileName, QString shapeID);

    static void writeShape(tinyxml2::XMLDocument* dom,XMLNode* parent,string id,b2Shape* shape);
    //根据参数new一个形状
    static b2Shape *readShape(tinyxml2::XMLNode *node);
    static void writeFilter(tinyxml2::XMLDocument* dom,XMLNode* parent,string id,b2Filter* filter);
    static void readFilter(tinyxml2::XMLNode *node,b2Filter* filter);

    int createShape(QString id,b2Shape* s);
    int createShape(XMLElement* elm);
    int delShape(QString id);
    b2Shape *getShape(QString id);
    b2Shape *getShapeClone(QString id);
    QStringList getShapeList();

    void draw(NQOpenGL2DWidget* widget);

    NBLayer layer;
private:
    //预设参数
    QMap<QString,b2Shape*> shapes;
    QMap<QString,b2BodyDef*> bodyDefs;
    QMap<QString,b2FixtureDef*> fixtureDefs;
    QMap<QString,b2JointDef*> jointDefs;
    b2BlockAllocator blockAllocator;
};

#endif // NBDATAMNGER_H
