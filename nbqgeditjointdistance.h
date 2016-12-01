#ifndef NBQGEDITJOINTDISTANCE_H
#define NBQGEDITJOINTDISTANCE_H

#include "nbqgeditJoint.h"
#include "obj/nbjointdistance.h"

class NBQGEditJointDistance : public NBQGEditJoint
{
public:
    NBQGEditJointDistance();
    void setNBObj(NBObject *obj);
    virtual void click(float x, float y);
    virtual void move(float x, float y);
    virtual void draw();
private:
    NBJointDistance *joint;
};

#endif // NBQGEDITJOINTDISTANCE_H
