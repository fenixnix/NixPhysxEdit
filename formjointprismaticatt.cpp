#include "formjointprismaticatt.h"
#include "ui_formjointprismaticatt.h"

FormJointPrismaticAtt::FormJointPrismaticAtt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormJointPrismaticAtt)
{
    ui->setupUi(this);
    ui->anchor->setText(tr("anchor"));
    ui->axis->setText(tr("axis"));
    joint = nullptr;
}

FormJointPrismaticAtt::~FormJointPrismaticAtt()
{
    delete ui;
}

void FormJointPrismaticAtt::attchJoint(NBJoint *joint)
{
    this->joint = joint->toJointPrismatic();
}

void FormJointPrismaticAtt::upload()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    ui->anchor->setb2(joint->anchor);
    ui->axis->setb2(joint->axis);
    ui->enableLimit->setChecked(joint->def.enableLimit);
    ui->enableMotor->setChecked(joint->def.enableMotor);
    ui->referenceAngle->setValue(joint->def.referenceAngle);
    ui->upperTranslation->setValue(joint->def.upperTranslation);
    ui->lowerTranslation->setValue(joint->def.lowerTranslation);
    ui->motorSpeed->setValue(joint->def.motorSpeed);
    ui->maxMotorForce->setValue(joint->def.maxMotorForce);
}

void FormJointPrismaticAtt::download()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    qDebug()<<__FUNCTION__<<__LINE__;
    joint->anchor = ui->anchor->getb2();
    joint->axis = ui->axis->getb2();
    joint->def.enableLimit = ui->enableLimit->checkState();
    joint->def.enableMotor = ui->enableMotor->checkState();
    joint->def.referenceAngle = ui->referenceAngle->value();
    joint->def.upperTranslation = ui->upperTranslation->value();
    joint->def.lowerTranslation = ui->lowerTranslation->value();
    joint->def.motorSpeed = ui->motorSpeed->value();
    joint->def.maxMotorForce = ui->maxMotorForce->value();
}
