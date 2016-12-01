#include "nbqgeditjointdistance.h"

NBQGEditJointDistance::NBQGEditJointDistance()
{
    joint = nullptr;
    selArr.push_back(false);
    selArr.push_back(false);
}

void NBQGEditJointDistance::setNBObj(NBObject *obj)
{
    joint = obj->toJoint()->toJointDistance();
}

void NBQGEditJointDistance::click(float x, float y)
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    b2Vec2x ap,bp;
    ap = b2Vec2x(joint->anchorA);
    bp = b2Vec2x(joint->anchorB);
    float distance = widget->getWorldPixelSize();
    if(ap.approach(b2Vec2(x,y),distance)){
        selArr[0] = true;
        return;
    }
    if(bp.approach(b2Vec2(x,y),distance)){
        selArr[1]= true;
        return;
    }
}

void NBQGEditJointDistance::move(float x, float y)
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    if(selArr[0]){
        joint->anchorA.x = x;
        joint->anchorA.y = y;
        widget->update();
        return;
    }
    if(selArr[1]){
        joint->anchorB.x = x;
        joint->anchorB.y = y;
        widget->update();
        return;
    }
}

void NBQGEditJointDistance::draw()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    widget->glColor4f(1,0,0,1);
    float size = widget->getWorldPixelSize();
    widget->drawCircle(joint->anchorA.x,joint->anchorA.y,size/2,GL_LINE_LOOP);
    widget->drawRect(joint->anchorB.x,joint->anchorB.y,size,size);
    widget->drawLine(joint->anchorA.x,joint->anchorA.y,
                     joint->anchorB.x,joint->anchorB.y);
}
