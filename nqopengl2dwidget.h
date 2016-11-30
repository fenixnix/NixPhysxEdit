#ifndef NQOPENGL2DWIDGET_H
#define NQOPENGL2DWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/GLU.h>
#include <qopenglext.h>
#include <QOpenGLFunctions_4_3_Compatibility>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QVector3D>

class NQOpenGL2DWidget : public QOpenGLWidget,public QOpenGLFunctions_4_3_Compatibility
{
public:
    explicit NQOpenGL2DWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();

    virtual void draw(NQOpenGL2DWidget* d);
    virtual void click(float x, float y);
    virtual void move(float x, float y);
    virtual void rel();

    void drawCircle(float x, float y, float r, int type);
    void drawRect(float x, float y, float w, float h);
    void drawLine(float x1, float y1, float x2, float y2);

    void drawGroundGrid();
    QPointF ScreenLoc2WorldLoc(QPointF loc);
    bool CheckPointSelect(QPointF selectPoint,QPointF mouseLoc);
    float getWorldPixelSize(int mul = 5);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* event);
private:
    QVector3D camPos;
    QPointF mousePos;
    QPointF worldPos;
    QPointF mouseProPos;
    QPointF camProPos;
    QColor bgColor;
    bool viewMov;
};

#endif // NQOPENGL2DWIDGET_H
