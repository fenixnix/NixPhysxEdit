#include "nbqgedit.h"
#include "obj/nbbody.h"
#include "obj/nbjointdistance.h"
#include "nbqgeditrigidbody.h"
#include "nbqgeditshapecircle.h"
#include "nbqgeditshapepolygon.h"
#include "nbqgeditjointdistance.h"
#include "nbqgeditjointrevolute.h"

NBQGEdit::NBQGEdit()
{
    obj = nullptr;
    widget = nullptr;
    selArr.clear();
}

NBQGEdit *NBQGEdit::create(NBObject *o, NQOpenGL2DWidget *widget)
{
    NBQGEdit* editor = nullptr;
    qDebug()<<__FUNCTION__<<o->getType();
    if(o->getType() == "body"){
        editor = new NBQGEditRigidBody;
    }
    if(o->getType() == "fixture"){
        b2Shape::Type shapeType = o->toFixture()->def.shape->GetType();
        switch(shapeType){
        case b2Shape::e_circle:editor = new NBQGEditShapeCircle(o);break;
        case b2Shape::e_polygon:editor = new NBQGEditShapePolygon(o);break;
        default: break;
        }
    }
    if(o->getType() == "joint"){
        NBJoint* j = o->toJoint();
        //qDebug()<<__FUNCTION__<<__LINE__;
        if(j->getJointType() == "distance"){
            //qDebug()<<__FUNCTION__<<__LINE__;
            editor = new NBQGEditJointDistance;
        }
        if(j->getJointType() == "revolute"){
            //qDebug()<<__FUNCTION__<<__LINE__;
            editor = new NBQGEditJointRevolute;
        }
    }
    if(editor){
        editor->obj = o;
        editor->widget = widget;
    }else{
        qDebug()<<__FUNCTION__<<__LINE__<<"warning!!!";
    }
    return editor;
}

void NBQGEdit::releaseEdit(NBQGEdit *editor)
{
    if(editor){
        delete editor;
        editor = nullptr;
    }
}

void NBQGEdit::setNBObj(NBObject *obj)
{

}

void NBQGEdit::rel()
{
    for(int i = 0;i<selArr.size();i++){
        selArr[i] = false;
    }
}
