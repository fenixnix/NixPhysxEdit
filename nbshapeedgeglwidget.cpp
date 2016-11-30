#include "nbshapeedgeglwidget.h"

NBShapeEdgeGLWidget::NBShapeEdgeGLWidget(QWidget *parent) : NBShapeChainGLWidget(parent)
{
    points.clear();
    points.push_back(b2Vec2(-1,0));
    points.push_back(b2Vec2(1,0));
}

b2Shape *NBShapeEdgeGLWidget::createShape()
{
    b2EdgeShape* shape = new b2EdgeShape;
    shape->Set(points[0],points[1]);
    return shape;
}

void NBShapeEdgeGLWidget::setValue(b2Shape *s)
{

}

