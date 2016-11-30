#ifndef NBSHAPECIRCLEGLWIDGET_H
#define NBSHAPECIRCLEGLWIDGET_H

#include "nqopengl2dwidget.h"
#include <Box2D/Box2D.h>

class NBShapeCircleGLWidget : public NQOpenGL2DWidget
{
public:
     explicit NBShapeCircleGLWidget(QWidget *parent = 0);
     void draw(NQOpenGL2DWidget *d);
     void click(float x, float y);
     void move(float x, float y);
     void rel();
     void set(b2Shape *s);
private:
     b2CircleShape *shape;
     bool shapeSelect;
     bool radiuSelect;
};

#endif // NBSHAPECIRCLEGLWIDGET_H
