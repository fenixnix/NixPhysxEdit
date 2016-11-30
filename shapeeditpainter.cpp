#include "shapeeditpainter.h"

ShapeEditPainter::ShapeEditPainter(NQOpenGL2DWidget *widget)
{
    this->widget = widget;
}

void ShapeEditPainter::draw(b2Shape *shape)
{
    switch(shape->GetType()){
    case b2Shape::e_circle:drawCircle(shape);break;
    case b2Shape::e_polygon:drawPolygon(shape);break;
    case b2Shape::e_edge:drawEdge(shape);break;
    case b2Shape::e_chain:drawChain(shape);break;
    }
}

void ShapeEditPainter::drawCircle(b2Shape *s)
{
    b2CircleShape* shape = (b2CircleShape*)s;
    float size = widget->getWorldPixelSize();
    widget->glColor4f(1,1,0,1);
    widget->drawRect(shape->m_p.x,shape->m_p.y,size,size);
    widget->drawRect(shape->m_p.x+shape->m_radius,shape->m_p.y,size,size);
}

void ShapeEditPainter::drawPolygon(b2Shape *s)
{
    b2PolygonShape* shape = (b2PolygonShape*)s;
    float size = widget->getWorldPixelSize();
    widget->glColor4f(1,1,0,1);
    float sumX = 0,sumY = 0;
    for(int i = 0;i<shape->GetVertexCount();i++){
        b2Vec2 v = shape->GetVertex(i);
        sumX += v.x;
        sumY += v.y;
        widget->drawRect(v.x,v.y,size,size);
    }
    b2Vec2 center = b2Vec2(sumX/shape->GetVertexCount(),sumY/shape->GetVertexCount());
    widget->glColor4f(0,1,0,0.5);
    widget->drawRect(center.x,center.y,size,size);
}

void ShapeEditPainter::drawEdge(b2Shape *shape)
{
    qDebug()<<__FUNCTION__<<__LINE__<<"empty";
}

void ShapeEditPainter::drawChain(b2Shape *shape)
{
    qDebug()<<__FUNCTION__<<__LINE__<<"empty";
}
