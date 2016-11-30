#ifndef FORMJOINTREVOLUTE_H
#define FORMJOINTREVOLUTE_H

#include <QWidget>
#include <obj/nbjointrevolute.h>

namespace Ui {
class FormJointRevolute;
}

class FormJointRevolute : public QWidget
{
    Q_OBJECT

public:
    explicit FormJointRevolute(QWidget *parent = 0);
    ~FormJointRevolute();
    void setJoint(NBJointRevolute *joint);
    void upload();
    void download();

private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::FormJointRevolute *ui;
    NBJointRevolute* joint;
};

#endif // FORMJOINTREVOLUTE_H
