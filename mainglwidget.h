#ifndef MAINGLWIDGET_H
#define MAINGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/GLU.h>
#include <qopenglext.h>
#include <QOpenGLFunctions_4_3_Compatibility>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QVector3D>
#include <nqopengl2dwidget.h>
#include <nbqgedit.h>

class MainGLWidget : public NQOpenGL2DWidget
{
public:
    explicit MainGLWidget(QWidget *parent = 0);
    void draw(NQOpenGL2DWidget *d);
    void click(float x, float y);
    void move(float x, float y);
    void rel();

    void setEditNBObject(NBObject* obj);

    bool getDrawLayer() const;
    void setDrawLayer(bool value);

private:
    NBQGEdit *editor;
    bool drawDebug;
    bool drawLayer;
};


#endif // MAINGLWIDGET_H
