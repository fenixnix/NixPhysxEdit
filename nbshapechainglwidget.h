#ifndef NBSHAPECHAINGLWIDGET_H
#define NBSHAPECHAINGLWIDGET_H

#include <NBShapePolygonGLWidget.h>
#include <QVector>
#include <Box2D/Box2D.h>

class NBShapeChainGLWidget : public NBShapePolygonGLWidget
{
    Q_OBJECT
public:
    explicit NBShapeChainGLWidget(QWidget *parent = 0);
    void draw(NQOpenGL2DWidget *d);
    b2Shape *createShape();
public slots:
    void setValue(b2Shape* s);

};

#endif // NBSHAPECHAINGLWIDGET_H
