#include "nbqgeditjointprismatic.h"

NBQGEditJointPrismatic::NBQGEditJointPrismatic()
{
    joint = nullptr;
    selArr.push_back(false);
    selArr.push_back(false);
}

void NBQGEditJointPrismatic::setNBObj(NBObject *obj)
{
    joint = obj->toJoint()->toJointPrismatic();
}

void NBQGEditJointPrismatic::click(float x, float y)
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    b2Vec2 ap,bp;
    ap = joint->anchor;
    bp = joint->axis;
    if(widget->CheckPointSelect(QPointF(ap.x,ap.y),QPointF(x,y))){
        selArr[0] = true;
        return;
    }
    if(widget->CheckPointSelect(QPointF(bp.x,bp.y),QPointF(x,y))){
        selArr[1]= true;
        return;
    }
}

void NBQGEditJointPrismatic::move(float x, float y)
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
    if(selArr[1]){
        joint->axis.x = x;
        joint->axis.y = y;
        widget->update();
        return;
    }
}

void NBQGEditJointPrismatic::draw()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    widget->glColor4f(1,0,0,1);
    float size = widget->getWorldPixelSize();
    widget->drawCircle(joint->anchor.x,joint->anchor.y,size/2,GL_LINE_LOOP);
    widget->drawRect(joint->axis.x,joint->axis.y,size,size);
    widget->drawLine(joint->anchor.x,joint->anchor.y,
                     joint->axis.x,joint->axis.y);
}
