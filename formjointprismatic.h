#ifndef FORMJOINTPRISMATIC_H
#define FORMJOINTPRISMATIC_H

#include <QWidget>

namespace Ui {
class FormJointPrismatic;
}

class FormJointPrismatic : public QWidget
{
    Q_OBJECT

public:
    explicit FormJointPrismatic(QWidget *parent = 0);
    ~FormJointPrismatic();

private:
    Ui::FormJointPrismatic *ui;
};

#endif // FORMJOINTPRISMATIC_H
