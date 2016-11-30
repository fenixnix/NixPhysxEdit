#ifndef NBSHAPECIRCLE_H
#define NBSHAPECIRCLE_H

#include "nbshape.h"

class NBShapeCircle : public NBShape
{
public:
    NBShapeCircle();
    b2Shape *createb2Shape();
private:
    float radius;
};

#endif // NBSHAPECIRCLE_H
