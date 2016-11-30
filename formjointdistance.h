#ifndef FORMJOINTDISTANCE_H
#define FORMJOINTDISTANCE_H

#include <QWidget>
#include <obj/nbjointdistance.h>

namespace Ui {
class FormJointDistance;
}

class FormJointDistance : public QWidget
{
    Q_OBJECT

public:
    explicit FormJointDistance(QWidget *parent = 0);
    ~FormJointDistance();
    void setJoint(NBJointDistance *joint);
    void upload();
    void download();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::FormJointDistance *ui;
    NBJointDistance* joint;
};

#endif // FORMJOINTDISTANCE_H
