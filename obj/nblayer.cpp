#include "nblayer.h"
#include "box2dqtdraw.h"
#include "nbjointdistance.h"
#include "nbjointrevolute.h"
#include "nbjointprismatic.h"

NBLayer::NBLayer()
{

}

void NBLayer::draw(NQOpenGL2DWidget *gl)
{
    foreach(NBBody* body,bodys){
        Box2DQtDraw::drawBody(gl,&body->def);
        gl->glPushMatrix();
        gl->glTranslatef(body->def.position.x,body->def.position.y,0);
        gl->glRotatef(body->def.angle*180.0f/M_PI,0,0,1);
        foreach(QString id,body->getFixtureList()){
            Box2DQtDraw::drawFixture(gl,body->getFixtureDef(id));
        }
        gl->glPopMatrix();
    }
    foreach(NBJoint* joint,joints){
        Box2DQtDraw::drawJoint(gl,joint);
    }
}

B2Unit* NBLayer::create(b2World* world)
{
    B2Unit* unit = new B2Unit;
    foreach(NBBody* body,bodys){
        b2Body* b = world->CreateBody(&body->def);
        unit->addBody(body->id.toStdString(),b);
        foreach(QString id,body->getFixtureList()){
            b->CreateFixture(body->getFixtureDef(id));
        }
    }
    foreach(NBJoint* joint,joints){
        b2JointDef* def = joint->getInitDef(unit);
        if(def==nullptr){
            qDebug()<<__FUNCTION__<<__LINE__;
        }
        b2Joint* j = world->CreateJoint(def);
        if(j==nullptr){
            qDebug()<<__FUNCTION__<<__LINE__;
        }
        unit->addJoint(joint->id,j);
    }
    return unit;
}

void NBLayer::write(QString fileName)
{
    using namespace tinyxml2;
    tinyxml2::XMLDocument dom;
    XMLNode* root = dom.LinkEndChild(dom.NewElement("Unit"));
    foreach(NBBody *body,bodys.values()){
        body->write(&dom,root);
    }
    foreach(NBJoint *joint,joints.values()){
        joint->write(&dom,root);
    }
    dom.SaveFile(fileName.toStdString().c_str());
}

void NBLayer::read(QString fileName)
{
    using namespace tinyxml2;
    tinyxml2::XMLDocument dom;
    XMLError err = dom.LoadFile(fileName.toStdString().c_str());
    if(err){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    XMLNode* root = dom.RootElement();
    XMLNode* n = root->FirstChild();
    while(n){
        XMLElement *elm = n->ToElement();
        if(QString(elm->Name()) == QString("Body")){
            NBBody* body = new NBBody;
            body->read(elm);
            addBody(body);
        }
        if(QString(elm->Name()) == QString("Joint")){
            NBJoint* joint = NBJoint::create(elm);
            addJoint(joint);
        }
        n = n->NextSibling();
    }
}

int NBLayer::addBody(NBBody *body)
{
    //qDebug()<<__FUNCTION__<<__LINE__;
    if(bodys.contains(body->id)){
        return 1;
    }
    bodys[body->id] = body;
}

int NBLayer::addFixture(NBFixture *fixture)
{
    QString parentID = fixture->parent->toBody()->id;
    if(!bodys.contains(parentID)){
        return 2;
    }
    return bodys[parentID]->addFixture(fixture);
}

b2BodyDef *NBLayer::getBody(QString id)
{
    return &((NBBody*)(getNBBody(id)))->def;
}

NBObject *NBLayer::getNBBody(QString id)
{
    if(bodys.contains(id)){
        //qDebug()<<__FUNCTION__<<__LINE__;
        return bodys[id];
    }
    //qDebug()<<__FUNCTION__<<__LINE__;
    return nullptr;
}

void NBLayer::delBody(QString id)
{
    qDebug()<<__FUNCTION__<<__LINE__<<id;
    if(bodys.contains(id)){
        delete bodys[id];
        bodys.erase(bodys.find(id));
    }
}

b2FixtureDef *NBLayer::getFixture(QString id, QString fid)
{
    if(bodys.contains(id)){
        return bodys[id]->getFixtureDef(fid);
    }
    return nullptr;
}

NBObject *NBLayer::getNBFixture(QString rid, QString fid)
{
    if(bodys.contains(rid)){
        qDebug()<<__FUNCTION__<<__LINE__;
        return bodys[rid]->getFixture(fid);
    }
    return nullptr;
}

QStringList NBLayer::getBodyList()
{
    return bodys.keys();
}

QStringList NBLayer::getFixtureList(QString rid)
{
    if(bodys.contains(rid)){
        qDebug()<<__FUNCTION__<<bodys[rid]->getFixtureList();
        return bodys[rid]->getFixtureList();
    }
    return QStringList();
}

NBJoint *NBLayer::newDefJoint(string id, QString type)
{
    NBJoint* joint = nullptr;
    if(joints.contains(id)){
        qDebug()<<__FUNCTION__<<__LINE__;
        return nullptr;
    }
    if(type == "distance"){
        qDebug()<<__FUNCTION__<<__LINE__;
        joint = new NBJointDistance(id);
    }
    if(type == "revolute"){
        qDebug()<<__FUNCTION__<<__LINE__;
        joint = new NBJointRevolute(id);
    }
    if(type == "prismatic"){
        qDebug()<<__FUNCTION__<<__LINE__;
        joint = new NBJointPrismatic(id);
    }
    if(joint==nullptr){
        qDebug()<<__FUNCTION__<<__LINE__<<"!!!";
        return joint;
    }
    joints[id] = joint;
    return joint;
}

int NBLayer::addJoint(string id, NBJoint *joint)
{
    if(joints.contains(id)){
        return 1;
    }
    joints[id] = joint;
    return 0;
}

int NBLayer::addJoint(NBJoint *joint)
{
    if(joints.contains(joint->id)){
        return 1;
    }
    joints[joint->id] = joint;
    return 0;
}

//int NBLayer::addJoint(QString id, b2JointDef *def)
//{
//    if(joints.contains(id)){
//        return 1;
//    }
//    NBJoint* j;
//    if(def->type == b2JointType::e_distanceJoint){
//        j = (NBJoint*)(new NBJointDistance(id,def));
//    }
//    qDebug()<<__FUNCTION__<<id;
//    joints[id] = j;
//    return 0;
//}

//b2JointDef *NBLayer::getJoint(QString id)
//{
//    if(joints.contains(id)){
//        return joints[id]->def;
//    }
//    return nullptr;
//}

b2JointDef *NBLayer::getInitJoint(string id, B2Unit* unit)
{
    if(joints.contains(id)){
        return joints[id]->getInitDef(unit);
    }
    return nullptr;
}

NBObject *NBLayer::getNBJoint(string id)
{
    qDebug()<<__FUNCTION__<<QString::fromStdString(id);
    if(joints.contains(id)){
        return joints[id];
    }
    return nullptr;
}

void NBLayer::delJoint(string id)
{
    if(joints.contains(id)){
        delete joints[id];
        joints.erase(joints.find(id));
    }
}

QStringList NBLayer::getJointList()
{
    QStringList sl;
    QList<string> ssl = joints.keys();
    foreach(string str,ssl){
        sl.append(QString::fromStdString(str));
    }
    return sl;
}
