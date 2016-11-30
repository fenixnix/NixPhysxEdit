#ifndef SHAPEEDITPAINTER_H
#define SHAPEEDITPAINTER_H

#include "nqopengl2dwidget.h"
#include "Box2D/Box2D.h"

class ShapeEditPainter
{
public:
    ShapeEditPainter(NQOpenGL2DWidget* widget);
    void draw(b2Shape* shape);
    void drawCircle(b2Shape* shape);
    void drawPolygon(b2Shape* s);
    void drawEdge(b2Shape* shape);
    void drawChain(b2Shape* shape);
private:
    NQOpenGL2DWidget* widget;
};

#endif // SHAPEEDITPAINTER_H
