#include "mainglwidget.h"
#include "b2physx.h"
#include <obj/nbdatamnger.h>

MainGLWidget::MainGLWidget(QWidget *parent) : NQOpenGL2DWidget(parent)
{
    drawDebug = true;
    drawLayer = true;
}

void MainGLWidget::draw(NQOpenGL2DWidget *d)
{
    if(drawDebug){
        B2Physx::the()->render();
    }
    if(drawLayer){
        NBDataMnger::the()->draw(d);
    }
    if(editor){
        editor->draw();
    }
}

void MainGLWidget::click(float x, float y)
{
    if(editor){
        editor->click(x,y);
    }
}

void MainGLWidget::move(float x, float y)
{
    if(editor){
        editor->move(x,y);
    }
}

void MainGLWidget::rel()
{
    if(editor){
        editor->rel();
    }
}

void MainGLWidget::setEditNBObject(NBObject *obj)
{
    if(editor){
        delete editor;
        editor = nullptr;
    }
    qDebug()<<__FUNCTION__<<__LINE__;
    editor = NBQGEdit::create(obj,this);
}

bool MainGLWidget::getDrawLayer() const
{
    return drawLayer;
}

void MainGLWidget::setDrawLayer(bool value)
{
    drawLayer = value;
}
