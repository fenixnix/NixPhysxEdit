#include "nbshapechainglwidget.h"

NBShapeChainGLWidget::NBShapeChainGLWidget(QWidget *parent) : NBShapePolygonGLWidget(parent)
{
    points.clear();
    points.push_back(b2Vec2(-1,0));
    points.push_back(b2Vec2(0,0));
    points.push_back(b2Vec2(1,0));
}

void NBShapeChainGLWidget::draw(NQOpenGL2DWidget *d)
{
    glColor4f(0,0.5,0,0.5);
    d->glBegin(GL_LINE_STRIP);
    float size = getWorldPixelSize();
    for(int i = 0;i<points.size();i++){
        d->glVertex2f(points[i].x,points[i].y);
    }
    d->glEnd();
    glColor4f(1,1,0,1);
    float sumX = 0,sumY = 0;
    for(int i = 0;i<points.size();i++){
        sumX+=points[i].x;
        sumY+=points[i].y;
        d->drawRect(points[i].x,points[i].y,size,size);
    }
    centerX = sumX/points.size();
    centerY = sumY/points.size();
    glColor4f(0,1,0,0.5);
    d->drawRect(centerX,centerY,size,size);
}

b2Shape *NBShapeChainGLWidget::createShape()
{
    b2ChainShape* shape = new b2ChainShape;
    shape->CreateChain(points.data(),points.size());
    return shape;
}

void NBShapeChainGLWidget::setValue(b2Shape *s)
{

}
