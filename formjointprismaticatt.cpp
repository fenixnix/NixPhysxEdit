#include "formjointprismaticatt.h"
#include "ui_formjointprismaticatt.h"

FormJointPrismaticAtt::FormJointPrismaticAtt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormJointPrismaticAtt)
{
    ui->setupUi(this);
}

FormJointPrismaticAtt::~FormJointPrismaticAtt()
{
    delete ui;
}
