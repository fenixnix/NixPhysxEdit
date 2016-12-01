#include "nbqgeditjointrevolute.h"

NBQGEditJointRevolute::NBQGEditJointRevolute()
{
    joint = nullptr;
    selArr.push_back(false);
}

void NBQGEditJointRevolute::setNBObj(NBObject *obj)
{
    joint = obj->toJoint()->toJointRevolute();
}

void NBQGEditJointRevolute::click(float x, float y)
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    b2Vec2 ap;
    ap = joint->anchor;
    if(widget->CheckPointSelect(QPointF(ap.x,ap.y),QPointF(x,y))){
        selArr[0] = true;
        return;
    }
}

void NBQGEditJointRevolute::move(float x, float y)
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    if(selArr[0]){
        joint->anchor.x = x;
        joint->anchor.y = y;
        widget->update();
        return;
    }
}

void NBQGEditJointRevolute::draw()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    widget->glColor4f(1,0,0,1);
    float size = widget->getWorldPixelSize();
    widget->drawRect(joint->anchor.x,joint->anchor.y,size,size);
}
