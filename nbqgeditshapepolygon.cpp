#include "nbqgeditshapepolygon.h"

NBQGEditShapePolygon::NBQGEditShapePolygon(NBObject *o)
{
    selArr.clear();
    selCenterAdj = false;
    setNBObj(o);
}

void NBQGEditShapePolygon::click(float x, float y)
{
    if(!obj){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    b2PolygonShape* shape = getShape();
    float sumX = 0,sumY = 0;
    for(int i = 0;i<shape->GetVertexCount();i++){
        b2Vec2 p = obj->toFixture()->getWorldFromLoc(shape->GetVertex(i));
        sumX += shape->GetVertex(i).x;
        sumY += shape->GetVertex(i).y;
        if(widget->CheckPointSelect(QPointF(p.x,p.y),QPointF(x,y))){
            selArr[i] = true;
            return;
        }
    }
    center = b2Vec2(sumX/shape->GetVertexCount(),sumY/shape->GetVertexCount());
    b2Vec2 worldCenter = obj->toFixture()->getWorldFromLoc(center);
    if(widget->CheckPointSelect(QPointF(worldCenter.x,worldCenter.y),QPointF(x,y))){
        selCenterAdj = true;
        tmpVecs.clear();
        for(int i = 0;i<shape->GetVertexCount();i++){
            tmpVecs.append(shape->GetVertex(i));
        }
        return;
    }
}

void NBQGEditShapePolygon::move(float x, float y)
{
    if(!obj){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    b2PolygonShape* shape = getShape();

    if(shape->GetVertexCount()!=selArr.size()){
        qDebug()<<__FUNCTION__<<__LINE__<<shape->GetVertexCount()<<selArr.size();
    }

    b2Vec2 newPoint = obj->toFixture()->getLocFromWorld(b2Vec2(x,y));
    for(int i = 0;i<selArr.size();i++){
        if(selArr[i]){
            shape->m_vertices[i] = newPoint;
            widget->update();
            return;
        }
    }
    if(selCenterAdj){
        for(int i = 0;i<shape->GetVertexCount();i++){
            shape->m_vertices[i] = tmpVecs[i] + (newPoint - center);
        }
        widget->update();
        return;
    }
}

void NBQGEditShapePolygon::rel()
{
    NBQGEdit::rel();
    selCenterAdj = false;
}

void NBQGEditShapePolygon::setNBObj(NBObject *o)
{
    this->obj = o;
    b2PolygonShape* shape = getShape();
    selArr.clear();
    for(int i = 0;i<shape->GetVertexCount();i++){
        selArr.append(false);
    }
}

b2PolygonShape *NBQGEditShapePolygon::getShape()
{
    return (b2PolygonShape*)obj->toFixture()->def.shape;
}
