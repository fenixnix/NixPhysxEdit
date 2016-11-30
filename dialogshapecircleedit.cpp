#include "dialogshapecircleedit.h"
#include "ui_dialogshapecircleedit.h"

DialogShapeCircleEdit::DialogShapeCircleEdit(QWidget *parent) :
    DlgShape(parent),
    ui(new Ui::DialogShapeCircleEdit)
{
    ui->setupUi(this);
}

DialogShapeCircleEdit::~DialogShapeCircleEdit()
{
    delete ui;
}

void DialogShapeCircleEdit::set(b2Shape *s)
{
    shape = (b2CircleShape*)s;
    ui->openGLWidget->set(shape);
}

void DialogShapeCircleEdit::widgetValueChanged()
{
    ui->x->setValue(shape->m_p.x);
    ui->y->setValue(shape->m_p.y);
    ui->radius->setValue(shape->m_radius);
}

void DialogShapeCircleEdit::on_x_valueChanged(double arg1)
{
    shape->m_p.x = arg1;
    ui->openGLWidget->update();
}

void DialogShapeCircleEdit::on_y_valueChanged(double arg1)
{
    shape->m_p.y = arg1;
    ui->openGLWidget->update();
}

void DialogShapeCircleEdit::on_radius_valueChanged(double arg1)
{
    shape->m_radius = arg1;
    ui->openGLWidget->update();
}

void DialogShapeCircleEdit::on_openGLWidget_frameSwapped()
{
    widgetValueChanged();
}

void DialogShapeCircleEdit::on_buttonBox_accepted()
{

}
