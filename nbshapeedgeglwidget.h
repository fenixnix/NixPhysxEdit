#ifndef NBSHAPEEDGEGLWIDGET_H
#define NBSHAPEEDGEGLWIDGET_H

#include "nbshapechainglwidget.h"
#include <Box2D/Box2D.h>

class NBShapeEdgeGLWidget : public NBShapeChainGLWidget
{
    Q_OBJECT
public:
    explicit NBShapeEdgeGLWidget(QWidget *parent = 0);
    b2Shape *createShape();
public slots:
    void setValue(b2Shape *s);
};

#endif // NBSHAPEEDGEGLWIDGET_H
