#include "nbqgeditjointdistance.h"
#include "obj/nbjointdistance.h"

NBQGEditJointDistance::NBQGEditJointDistance()
{
    selArr.push_back(false);
    selArr.push_back(false);
}

void NBQGEditJointDistance::click(float x, float y)
{
    NBJointDistance *j = obj->toJoint()->toJointDistance();
    b2Vec2 ap,bp;
    ap = j->anchorA;
    bp = j->anchorB;
    if(widget->CheckPointSelect(QPointF(ap.x,ap.y),QPointF(x,y))){
        selArr[0] = true;
        return;
    }
    if(widget->CheckPointSelect(QPointF(bp.x,bp.y),QPointF(x,y))){
        selArr[1]= true;
        return;
    }
}

void NBQGEditJointDistance::move(float x, float y)
{
    NBJointDistance *j  = obj->toJoint()->toJointDistance();
    if(selArr[0]){
        j->anchorA.x = x;
        j->anchorA.y = y;
        widget->update();
        return;
    }
    if(selArr[1]){
        j->anchorB.x = x;
        j->anchorB.y = y;
        widget->update();
        return;
    }
}

void NBQGEditJointDistance::draw()
{
    NBJointDistance *j  = obj->toJoint()->toJointDistance();
    widget->glColor4f(1,0,0,1);
    float size = widget->getWorldPixelSize();
    widget->drawCircle(j->anchorA.x,j->anchorA.y,size/2,GL_LINE_LOOP);
    widget->drawRect(j->anchorB.x,j->anchorB.y,size,size);
    widget->drawLine(j->anchorA.x,j->anchorA.y,
                     j->anchorB.x,j->anchorB.y);
}
