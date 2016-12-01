#include "formjoint.h"
#include "ui_formjoint.h"
#include "obj/nbdatamnger.h"

FormJoint::FormJoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormJoint)
{
    ui->setupUi(this);
    joint = nullptr;
}

FormJoint::~FormJoint()
{
    delete ui;
}

void FormJoint::addAttForm(QWidget *widget)
{
    ui->verticalLayout->insertWidget(1,widget);
}

void FormJoint::attchJoint(NBJoint *joint)
{
    this->joint = joint;
    ui->ObjA_ID->clear();
    ui->ObjB_ID->clear();
    ui->ObjA_ID->addItems(NBDataMnger::the()->layer.getBodyList());
    ui->ObjB_ID->addItems(NBDataMnger::the()->layer.getBodyList());
    upload();
}

void FormJoint::upload()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    ui->ObjA_ID->setCurrentText(QString::fromStdString(joint->idA));
    ui->ObjB_ID->setCurrentText(QString::fromStdString(joint->idB));
    ui->isCollision->setChecked(joint->collideConnected);
}

void FormJoint::download()
{
    if(!joint){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    qDebug()<<__FUNCTION__<<__LINE__;
    joint->idA = ui->ObjA_ID->currentText().toStdString();
    joint->idB = ui->ObjB_ID->currentText().toStdString();
    joint->collideConnected = ui->isCollision->checkState();
}

void FormJoint::on_buttonBox_accepted()
{
    on_accepted();
}
