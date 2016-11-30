#include "nbshapepolygonglwidget.h"

NBShapePolygonGLWidget::NBShapePolygonGLWidget(QWidget *parent) : NQOpenGL2DWidget(parent)
{
    points.push_back(b2Vec2(-1,-1));
    points.push_back(b2Vec2(-1,1));
    points.push_back(b2Vec2(1,1));
    points.push_back(b2Vec2(1,-1));
    shapeSelect = false;
    allSelect = false;
    shape = nullptr;
}

void NBShapePolygonGLWidget::draw(NQOpenGL2DWidget *d)
{
    glColor4f(0,0.5,0,0.5);
    d->glBegin(GL_TRIANGLE_FAN);
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

void NBShapePolygonGLWidget::click(float x, float y)
{
    for(int i = 0;i<points.size();i++){
        if(CheckPointSelect(QPointF(points[i].x,points[i].y),QPointF(x,y))){
            selectIndex = i;
            shapeSelect = true;
            return;
        }
    }
    if(CheckPointSelect(QPointF(centerX,centerY),QPointF(x,y))){
        allSelect = true;
        return;
    }
}

void NBShapePolygonGLWidget::move(float x, float y)
{
    if(shapeSelect){
        points[selectIndex].x = x;
        points[selectIndex].y = y;
        sync2Shape();
        update();
    }
    if(allSelect){
        for(int i = 0;i<points.size();i++){
            points[i] = points[i] + (b2Vec2(x,y)-b2Vec2(centerX,centerY));
        }
        sync2Shape();
        update();
    }
}

void NBShapePolygonGLWidget::rel()
{
    shapeSelect = false;
    allSelect = false;
}

void NBShapePolygonGLWidget::addPoint()
{
    float size = getWorldPixelSize();
    points.push_back(points.back()+b2Vec2(-size,-size));
    sync2Shape();
    update();
}

void NBShapePolygonGLWidget::delPoint()
{
    if(points.size()<=3){
        return;
    }
    points.pop_back();
    sync2Shape();
    update();
}

void NBShapePolygonGLWidget::delPoint(int index)
{
    if(points.size()<=3){
        return;
    }
    if(index<points.size()){
        return;
    }
    points.erase(points.begin()+index);
    update();
    sync2Shape();
}

void NBShapePolygonGLWidget::sync2Shape()
{
    shape->Set(points.data(),points.size());
}

void NBShapePolygonGLWidget::upload()
{
    qDebug()<<__FUNCTION__<<__LINE__;
    points.clear();
    for(int i = 0;i<shape->GetVertexCount();i++){
        points.append(shape->GetVertex(i));
    }
}

void NBShapePolygonGLWidget::set(b2Shape *s)
{
    shape = (b2PolygonShape*)s;
    upload();
}
