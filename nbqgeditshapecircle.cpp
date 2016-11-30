#include "nbqgeditshapecircle.h"

NBQGEditShapeCircle::NBQGEditShapeCircle(NBObject *o)
{
    selArr.push_back(false);
    selRadiusAdj = false;
    this->obj = o;
}

void NBQGEditShapeCircle::click(float x, float y)
{
    if(!obj){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    b2CircleShape* shape = getShape();
    b2Vec2 p = obj->toFixture()->getWorldFromLoc(shape->m_p);
    if(widget->CheckPointSelect(QPointF(p.x+shape->m_radius,p.y),QPointF(x,y))){
        selRadiusAdj = true;
        return;
    }
    if(widget->CheckPointSelect(QPointF(p.x,p.y),QPointF(x,y))){
        selArr[0] = true;
        return;
    }
}

void NBQGEditShapeCircle::move(float x, float y)
{
    if(!obj){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    b2CircleShape* shape = getShape();
    b2Vec2 newPoint = obj->toFixture()->getLocFromWorld(b2Vec2(x,y));
    if(selArr[0]){
        shape->m_p = newPoint;
        widget->update();
    }
    if(selRadiusAdj){
        shape->m_radius = abs(shape->m_p.x - newPoint.x);
        widget->update();
    }
}

void NBQGEditShapeCircle::rel()
{
    NBQGEdit::rel();
    selRadiusAdj = false;
}

b2CircleShape *NBQGEditShapeCircle::getShape()
{
    return (b2CircleShape*)obj->toFixture()->def.shape;
}
