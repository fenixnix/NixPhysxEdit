#ifndef NBQGEDITJOINTREVOLUTE_H
#define NBQGEDITJOINTREVOLUTE_H

#include "nbqgeditJoint.h"
#include "obj/nbjointrevolute.h"

class NBQGEditJointRevolute : public NBQGEditJoint
{
public:
    NBQGEditJointRevolute();
    void setNBObj(NBObject *obj);
    virtual void click(float x, float y);
    virtual void move(float x, float y);
    virtual void draw();
private:
    NBJointRevolute* joint;
};

#endif // NBQGEDITJOINTREVOLUTE_H
