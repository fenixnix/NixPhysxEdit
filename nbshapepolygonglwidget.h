#ifndef NBSHAPEPOLYGONGLWIDGET_H
#define NBSHAPEPOLYGONGLWIDGET_H

#include <nqopengl2dwidget.h>
#include <QVector>
#include <Box2D/Box2D.h>

class NBShapePolygonGLWidget : public NQOpenGL2DWidget
{
    Q_OBJECT
public:
    explicit NBShapePolygonGLWidget(QWidget *parent = 0);
    void draw(NQOpenGL2DWidget *d);
    void click(float x, float y);
    void move(float x, float y);
    void rel();
    void addPoint();
    void delPoint();
    void delPoint(int index);
    void sync2Shape();
    void upload();

    QVector<b2Vec2> points;
    float centerX;
    float centerY;
public slots:
    void set(b2Shape* s);
    b2Shape *get();
signals:
    void valueChange();
private:
    int selectIndex;
    bool shapeSelect;
    bool allSelect;
    b2PolygonShape *shape;
};

#endif // NBSHAPEPOLYGONGLWIDGET_H
