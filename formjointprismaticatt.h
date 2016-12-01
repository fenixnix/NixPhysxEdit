#ifndef FORMJOINTPRISMATICATT_H
#define FORMJOINTPRISMATICATT_H

#include <QWidget>
#include <obj/nbjointprismatic.h>

namespace Ui {
class FormJointPrismaticAtt;
}

class FormJointPrismaticAtt : public QWidget
{
    Q_OBJECT

public:
    explicit FormJointPrismaticAtt(QWidget *parent = 0);
    ~FormJointPrismaticAtt();
    void attchJoint(NBJoint* joint);
    void upload();
    void download();
private:
    Ui::FormJointPrismaticAtt *ui;
    NBJointPrismatic *joint;
};

#endif // FORMJOINTPRISMATICATT_H
