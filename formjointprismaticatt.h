#ifndef FORMJOINTPRISMATICATT_H
#define FORMJOINTPRISMATICATT_H

#include <QWidget>

namespace Ui {
class FormJointPrismaticAtt;
}

class FormJointPrismaticAtt : public QWidget
{
    Q_OBJECT

public:
    explicit FormJointPrismaticAtt(QWidget *parent = 0);
    ~FormJointPrismaticAtt();

private:
    Ui::FormJointPrismaticAtt *ui;
};

#endif // FORMJOINTPRISMATICATT_H
