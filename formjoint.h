#ifndef FORMJOINT_H
#define FORMJOINT_H

#include <QWidget>

namespace Ui {
class FormJoint;
}

class FormJoint : public QWidget
{
    Q_OBJECT

public:
    explicit FormJoint(QWidget *parent = 0);
    ~FormJoint();
    void addAttForm(QWidget* widget);//use Once!!!;
private:
    Ui::FormJoint *ui;
};

#endif // FORMJOINT_H
