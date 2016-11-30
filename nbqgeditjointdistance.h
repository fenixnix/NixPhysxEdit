#ifndef NBQGEDITJOINTDISTANCE_H
#define NBQGEDITJOINTDISTANCE_H

#include "nbqgeditJoint.h"

class NBQGEditJointDistance : public NBQGEditJoint
{
public:
    NBQGEditJointDistance();
    virtual void click(float x, float y);
    virtual void move(float x, float y);
    virtual void draw();
};

#endif // NBQGEDITJOINTDISTANCE_H
