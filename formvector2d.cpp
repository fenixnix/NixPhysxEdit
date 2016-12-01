#include "formvector2d.h"
#include "ui_formvector2d.h"
#include <box2d/Box2D.h>

FormVector2D::FormVector2D(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVector2D)
{
    ui->setupUi(this);
    ui->x->setText("x");
    ui->y->setText("y");
    QObject::connect(ui->x,&LabeledSpinBox::finishEdit,this,&FormVector2D::onXYfinishEdit);
    QObject::connect(ui->y,&LabeledSpinBox::finishEdit,this,&FormVector2D::onXYfinishEdit);
}

void FormVector2D::setText(QString str)
{
    ui->label->setText(str);
}

FormVector2D::~FormVector2D()
{
    delete ui;
}

void FormVector2D::setb2(QVector2D vector)
{
    ui->x->set(vector.x());
    ui->y->set(vector.y());
}

QVector2D FormVector2D::get()
{
    QVector2D vector;
    vector.setX(ui->x->get());
    vector.setY(ui->y->get());
    return vector;
}

void FormVector2D::setb2(b2Vec2 vec)
{
    ui->x->set(vec.x);
    ui->y->set(vec.y);
}

b2Vec2 FormVector2D::getb2()
{
    b2Vec2 vec;
    vec.x = ui->x->get();
    vec.y = ui->y->get();
    return vec;
}

void FormVector2D::onXYfinishEdit()
{
    emit finishEdit();
}
