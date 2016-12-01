#include "uijointprismatic.h"

UIJointPrismatic::UIJointPrismatic(QWidget *parent) : FormJoint(parent)
{
    addAttForm(&att);
}

void UIJointPrismatic::attchJoint(NBJoint *joint)
{
    FormJoint::attchJoint(joint);
    att.attchJoint(joint);
    this->upload();
}

void UIJointPrismatic::upload()
{
    FormJoint::upload();
    att.upload();
}

void UIJointPrismatic::download()
{
    FormJoint::download();
    att.download();
}

void UIJointPrismatic::on_accepted()
{
    qDebug()<<__FUNCTION__<<__LINE__;
    this->download();
}
