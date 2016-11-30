#include "formjointrevolute.h"
#include "ui_formjointrevolute.h"
#include "obj/nbdatamnger.h"

FormJointRevolute::FormJointRevolute(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormJointRevolute)
{
    ui->setupUi(this);
    joint = nullptr;
}

FormJointRevolute::~FormJointRevolute()
{
    delete ui;
}

void FormJointRevolute::setJoint(NBJointRevolute *j)
{
    if(!j){
        return;
    }
    ui->BodyA->clear();
    ui->BodyB->clear();
    ui->BodyA->addItems(NBDataMnger::the()->layer.getBodyList());
    ui->BodyB->addItems(NBDataMnger::the()->layer.getBodyList());
    joint = j;
    upload();
}

void FormJointRevolute::upload()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    ui->BodyA->setCurrentText(QString::fromStdString(joint->idA));
    ui->BodyB->setCurrentText(QString::fromStdString(joint->idB));
    ui->anchorX->setValue(joint->anchor.x);
    ui->anchorY->setValue(joint->anchor.y);
    ui->collideConnected->setChecked(joint->collideConnected);
    ui->referenceAngle->setValue(joint->referenceAngle);
    ui->lowerAngle->setValue(joint->lowerAngle);
    ui->upperAngle->setValue(joint->upperAngle);
    ui->maxMotorTorque->setValue(joint->maxMotorTorque);
    ui->motorSpeed->setValue(joint->motorSpeed);
    ui->enableLimit->setChecked(joint->enableLimit);
    ui->enableMotor->setChecked(joint->enableMotor);
}

void FormJointRevolute::download()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    joint->idA = ui->BodyA->currentText().toStdString();
    joint->idB = ui->BodyB->currentText().toStdString();
    joint->anchor.x = ui->anchorX->value();
    joint->anchor.y = ui->anchorY->value();
    joint->collideConnected = ui->collideConnected->checkState();
    joint->referenceAngle = ui->referenceAngle->value();
    joint->enableLimit = ui->enableLimit->checkState();
    joint->lowerAngle = ui->lowerAngle->value();
    joint->upperAngle = ui->upperAngle->value();
    joint->enableMotor = ui->enableMotor->checkState();
    joint->maxMotorTorque = ui->maxMotorTorque->value();
    joint->motorSpeed = ui->motorSpeed->value();
}

void FormJointRevolute::on_pushButton_OK_clicked()
{
    download();
}
