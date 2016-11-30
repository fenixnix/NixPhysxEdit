#ifndef NBQGEDITJOINTREVOLUTE_H
#define NBQGEDITJOINTREVOLUTE_H

#include "nbqgeditJoint.h"

class NBQGEditJointRevolute : public NBQGEditJoint
{
public:
    NBQGEditJointRevolute();
    virtual void click(float x, float y);
    virtual void move(float x, float y);
    virtual void draw();
};

#endif // NBQGEDITJOINTREVOLUTE_H
