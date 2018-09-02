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

const string defShapePrefabFileName = "defShape.xml";
const string defFilterPrefabFileName = "defFilter.xml";

class NBDataMnger : public NSingleton<NBDataMnger>
{
public:
    NBDataMnger();
    void saveAllPrefab();
    void loadShapePrefab(std::string fileName = defShapePrefabFileName);
    void saveShapePrefab(std::string fileName = defShapePrefabFileName);
    int addShape(QString id,b2Shape* s);
    int addShape(XMLElement* elm);
    int delShape(QString id);
    b2Shape *getShape(QString id);
    b2Shape *getShapeClone(QString id);
    QStringList getShapeList();
    static void writeShape(tinyxml2::XMLDocument* dom,XMLNode* parent,string id,b2Shape* shape);
    //根据参数new一个形状
    static b2Shape *readShape(tinyxml2::XMLNode *node);

    void loadFilterPrefab(std::string fileName = defFilterPrefabFileName);
    void saveFilterPrefab(std::string fileName = defFilterPrefabFileName);
    static void writeFilter(tinyxml2::XMLDocument* dom,XMLNode* parent,string id,b2Filter* filter);
    static b2Filter readFilter(tinyxml2::XMLNode *node);
    int addFilter(QString id, b2Filter filter);
    int addFilter(XMLElement* elm);
    QStringList getFilterList();

    //todo: rigidbody prefab
    //todo: fixture prefab

    void draw(NQOpenGL2DWidget* widget);

    NBLayer layer;
private:
    //预设参数
    QMap<QString,b2Shape*> shapes;
    QMap<QString,b2BodyDef*> bodyDefs;
    QMap<QString,b2FixtureDef*> fixtureDefs;
    QMap<QString,b2JointDef*> jointDefs;
    QMap<QString,b2Filter> filterDefs;
    b2BlockAllocator blockAllocator;
};

#endif // NBDATAMNGER_H
