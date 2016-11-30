#ifndef NBQGEDITRIGIDBODY_H
#define NBQGEDITRIGIDBODY_H

#include "nbqgedit.h"

class NBQGEditRigidBody : public NBQGEdit
{
public:
    NBQGEditRigidBody();
    virtual void click(float x, float y);
    virtual void move(float x, float y);
    virtual void draw();
    void rel();

    QVector<bool> selRotArr;
};

#endif // NBQGEDITRIGIDBODY_H
