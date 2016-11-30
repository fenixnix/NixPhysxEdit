#ifndef NBSHAPECHAIN_H
#define NBSHAPECHAIN_H

#include "nbshape.h"

class NBShapeChain : public NBShape
{
public:
    NBShapeChain();
    b2Shape *createb2Shape();
};

#endif // NBSHAPECHAIN_H
