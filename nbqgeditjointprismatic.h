#ifndef NBQGEDITJOINTPRISMATIC_H
#define NBQGEDITJOINTPRISMATIC_H

#include "nbqgeditjointdistance.h"
#include "obj/nbjointprismatic.h"

class NBQGEditJointPrismatic : public NBQGEditJointDistance
{
public:
    NBQGEditJointPrismatic();
    void setNBObj(NBObject *obj);
    virtual void click(float x, float y);
    virtual void move(float x, float y);
    virtual void draw();
private:
    NBJointPrismatic *joint;
};

#endif // NBQGEDITJOINTPRISMATIC_H
