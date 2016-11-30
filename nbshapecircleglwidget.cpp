#include "nbshapecircleglwidget.h"
#include "box2dqtdraw.h"
#include "shapeeditpainter.h"

NBShapeCircleGLWidget::NBShapeCircleGLWidget(QWidget *parent):NQOpenGL2DWidget(parent)
{
    shapeSelect = false;
    radiuSelect = false;
    shape = nullptr;
}

void NBShapeCircleGLWidget::draw(NQOpenGL2DWidget *d)
{
    if(!shape){
        return;
    }
    glColor4f(0,0.5,0,0.5);
    d->drawCircle(shape->m_p.x,shape->m_p.y,shape->m_radius,GL_TRIANGLE_FAN);
    ShapeEditPainter(d).draw(shape);
}

void NBShapeCircleGLWidget::click(float x, float y)
{
    if(!shape){
        return;
    }
    if(CheckPointSelect(QPointF(shape->m_p.x+shape->m_radius,shape->m_p.y),QPointF(x,y))){
        radiuSelect = true;
        return;
    }
    if(CheckPointSelect(QPointF(shape->m_p.x,shape->m_p.y),QPointF(x,y))){
        shapeSelect = true;
        return;
    }
}

void NBShapeCircleGLWidget::move(float x, float y)
{
    if(!shape){
        return;
    }
    if(shapeSelect){
        shape->m_p.x = x;
        shape->m_p.y = y;
        update();
    }
    if(radiuSelect){
        shape->m_radius = abs(shape->m_p.x - x);
        update();
    }
}

void NBShapeCircleGLWidget::rel()
{
    shapeSelect = false;
    radiuSelect = false;
}

void NBShapeCircleGLWidget::set(b2Shape *s)
{
    shape = (b2CircleShape*)s;
}
