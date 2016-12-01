#ifndef FORMJOINT_H
#define FORMJOINT_H

#include <QWidget>
#include <obj/nbjoint.h>

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
    void attchJoint(NBJoint* joint);
    void upload();
    void download();
    virtual void on_accepted() = 0;
protected:
    NBJoint* joint;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::FormJoint *ui;
};

#endif // FORMJOINT_H
