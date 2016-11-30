#include "formjoint.h"
#include "ui_formjoint.h"

FormJoint::FormJoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormJoint)
{
    ui->setupUi(this);
}

FormJoint::~FormJoint()
{
    delete ui;
}

void FormJoint::addAttForm(QWidget *widget)
{
    ui->verticalLayout->insertWidget(1,widget);
}
