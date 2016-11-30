#ifndef FORMRIGIDBODY_H
#define FORMRIGIDBODY_H

#include <QWidget>
#include <QDebug>
#include <Box2D/Box2D.h>
#include "obj/NbBody.h"

namespace Ui {
class FormRigidBody;
}

class FormRigidBody : public QWidget
{
    Q_OBJECT

public:
    explicit FormRigidBody(QWidget *parent = 0);
    ~FormRigidBody();
    void setBody(NBBody* body);
    void setB2Body(b2BodyDef* bodyDef);
    void upload();
    void download();
private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::FormRigidBody *ui;
    b2BodyDef* def;
    NBBody* def2;
};

#endif // FORMRIGIDBODY_H
