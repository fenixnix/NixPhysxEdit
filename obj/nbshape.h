#ifndef NBSHAPE_H
#define NBSHAPE_H

#include "nbobject.h"
#include <vector>

class NBShape : public NBObject
{
public:
    NBShape();
    virtual b2Shape *createb2Shape() = 0;
    std::vector<b2Vec2> vecs;
};

#endif // NBSHAPE_H
