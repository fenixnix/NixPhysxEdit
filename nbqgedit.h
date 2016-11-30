#ifndef NBQGEDIT_H
#define NBQGEDIT_H

#include "obj/nbobject.h"
#include "nqopengl2dwidget.h"
#define _USE_MATH_DEFINES
#include <math.h>

class NBQGEdit
{
public:
    NBQGEdit();
    static NBQGEdit *create(NBObject* o,NQOpenGL2DWidget* widget);
    static void releaseEdit(NBQGEdit *editor);
    virtual void setNBObj(NBObject* obj);
    virtual void click(float x, float y) = 0;
    virtual void move(float x, float y) = 0;
    virtual void rel();
    virtual void draw() = 0;
//private:
    NBObject *obj;
    NQOpenGL2DWidget *widget;
    QVector<bool> selArr;
};

#endif // NBQGEDIT_H
