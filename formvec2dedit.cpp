#include "formvec2dedit.h"
#include "ui_formvec2dedit.h"

FormVec2DEdit::FormVec2DEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVec2DEdit)
{
    ui->setupUi(this);
}

FormVec2DEdit::~FormVec2DEdit()
{
    delete ui;
}

void FormVec2DEdit::set(QPointF p)
{
    ui->x->setValue(p.x());
    ui->y->setValue(p.y());
}

QPointF FormVec2DEdit::get()
{
    QPointF p;
    p.setX(ui->x->value());
    p.setY(ui->y->value());
    return p;
}

void FormVec2DEdit::on_y_valueChanged(double arg1)
{
    emit valueChanged();
}

void FormVec2DEdit::on_x_valueChanged(double arg1)
{
    emit valueChanged();
}
