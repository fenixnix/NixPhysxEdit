#ifndef NBSHAPEEDGE_H
#define NBSHAPEEDGE_H

#include "nbshape.h"

class NBShapeEdge : public NBShape
{
public:
    NBShapeEdge();
    b2Shape *createb2Shape();
};

#endif // NBSHAPEEDGE_H
