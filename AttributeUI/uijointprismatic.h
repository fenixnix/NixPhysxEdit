#ifndef UIJOINTPRISMATIC_H
#define UIJOINTPRISMATIC_H

#include <formjoint.h>
#include <formjointprismaticatt.h>

class UIJointPrismatic : public FormJoint
{
    Q_OBJECT
public:
    explicit UIJointPrismatic(QWidget *parent = 0);
    void attchJoint(NBJoint* joint);
    void upload();
    void download();
    void on_accepted();
signals:

public slots:

private:
    FormJointPrismaticAtt att;
};

#endif // UIJOINTPRISMATIC_H
