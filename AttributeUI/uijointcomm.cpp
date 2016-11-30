#include "uijointcomm.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QDebug>

UIJointComm::UIJointComm(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* vBoxLayout = new QVBoxLayout(this);
    QFormLayout* formLayout = new QFormLayout(this);
    vBoxLayout->addLayout(formLayout);

    buttonBox = new QDialogButtonBox();
    QObject::connect(buttonBox,&QDialogButtonBox::accepted,this,&UIJointComm::onPushOK);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    vBoxLayout->addWidget(buttonBox);
    formLayout->setWidget(0,QFormLayout::LabelRole,new QLabel("ID A"));
    formLayout->setWidget(1,QFormLayout::LabelRole,new QLabel("ID B"));
    formLayout->setWidget(2,QFormLayout::LabelRole,new QLabel("collide"));
    //this->addi
}

void UIJointComm::pushOK()
{
    qDebug()<<__FUNCTION__;
}

void UIJointComm::onPushOK()
{
    pushOK();
}
