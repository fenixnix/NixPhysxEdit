#include "formjointprismatic.h"
#include "ui_formjointprismatic.h"

FormJointPrismatic::FormJointPrismatic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormJointPrismatic)
{
    ui->setupUi(this);
}

FormJointPrismatic::~FormJointPrismatic()
{
    delete ui;
}
