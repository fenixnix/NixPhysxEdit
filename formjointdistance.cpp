#include "formjointdistance.h"
#include "ui_formjointdistance.h"
#include "obj/nbdatamnger.h"

FormJointDistance::FormJointDistance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormJointDistance)
{
    ui->setupUi(this);
    joint = nullptr;
}

FormJointDistance::~FormJointDistance()
{
    delete ui;
}

void FormJointDistance::setJoint(NBJointDistance *j)
{
    if(!j){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    ui->bodyA->clear();
    ui->bodyB->clear();
    ui->bodyA->addItems(NBDataMnger::the()->layer.getBodyList());
    ui->bodyB->addItems(NBDataMnger::the()->layer.getBodyList());
    joint = j;
    upload();
}

void FormJointDistance::upload()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    ui->bodyA->setCurrentText(QString::fromStdString(joint->idA));
    ui->bodyB->setCurrentText(QString::fromStdString(joint->idB));
    qDebug()<<__FUNCTION__<<joint->anchorA.x<<joint->anchorA.y<<joint->anchorB.x<<joint->anchorB.y;
    ui->anchorAX->setValue(joint->anchorA.x);
    ui->anchorAY->setValue(joint->anchorA.y);
    ui->anchorBX->setValue(joint->anchorB.x);
    ui->anchorBY->setValue(joint->anchorB.y);
    ui->isCollide->setChecked(joint->collideConnected);
    ui->damping->setValue(joint->dampingRatio);
    ui->damping->setValue(joint->frequencyHz);
}

void FormJointDistance::download()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    joint->idA = ui->bodyA->currentText().toStdString();
    joint->idB = ui->bodyB->currentText().toStdString();
    joint->anchorA.x = ui->anchorAX->value();
    joint->anchorA.y = ui->anchorAY->value();
    joint->anchorB.x = ui->anchorBX->value();
    joint->anchorB.y = ui->anchorBY->value();
    joint->collideConnected = ui->isCollide->checkState();
    joint->dampingRatio = ui->damping->value();
    joint->frequencyHz = ui->frequency->value();
}

void FormJointDistance::on_buttonBox_accepted()
{
    download();
}
