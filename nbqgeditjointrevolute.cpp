#include "nbqgeditjointrevolute.h"
#include "obj/nbjointrevolute.h"

NBQGEditJointRevolute::NBQGEditJointRevolute()
{
    selArr.push_back(false);
}

void NBQGEditJointRevolute::click(float x, float y)
{
    NBJointRevolute *j = obj->toJoint()->toJointRevolute();
    b2Vec2 ap;
    ap = j->anchor;
    if(widget->CheckPointSelect(QPointF(ap.x,ap.y),QPointF(x,y))){
        selArr[0] = true;
        return;
    }
}

void NBQGEditJointRevolute::move(float x, float y)
{
    NBJointRevolute *j = obj->toJoint()->toJointRevolute();
    if(selArr[0]){
        j->anchor.x = x;
        j->anchor.y = y;
        widget->update();
        return;
    }
}

void NBQGEditJointRevolute::draw()
{
    NBJointRevolute *j = obj->toJoint()->toJointRevolute();
    widget->glColor4f(1,0,0,1);
    float size = widget->getWorldPixelSize();
    widget->drawRect(j->anchor.x,j->anchor.y,size,size);
}
