#ifndef NBSHAPEPOLYGON_H
#define NBSHAPEPOLYGON_H

#include "nbshape.h"

class NBShapePolygon : public NBShape
{
public:
    NBShapePolygon();
    b2Shape *createb2Shape();
};

#endif // NBSHAPEPOLYGON_H
