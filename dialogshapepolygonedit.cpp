#include "dialogshapepolygonedit.h"
#include "ui_dialogshapepolygonedit.h"

DialogShapePolygonEdit::DialogShapePolygonEdit(QWidget *parent) :
    DlgShape(parent),
    ui(new Ui::DialogShapePolygonEdit)
{
    ui->setupUi(this);
}

DialogShapePolygonEdit::~DialogShapePolygonEdit()
{
    delete ui;
}

void DialogShapePolygonEdit::set(b2Shape *s)
{
    getWidget()->set((b2PolygonShape*)s);
}

void DialogShapePolygonEdit::widgetValueChanged()
{

}

void DialogShapePolygonEdit::on_buttonBox_accepted()
{

}

void DialogShapePolygonEdit::on_pushButton_add_clicked()
{
    getWidget()->addPoint();
}

void DialogShapePolygonEdit::on_pushButton_delete_clicked()
{
    getWidget()->delPoint();
}

NBShapePolygonGLWidget *DialogShapePolygonEdit::getWidget()
{
    return ui->openGLWidget;
}
