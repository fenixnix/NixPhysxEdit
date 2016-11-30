#ifndef NBQGEDITSHAPECIRCLE_H
#define NBQGEDITSHAPECIRCLE_H

#include "nbqgeditshape.h"

class NBQGEditShapeCircle : public NBQGEditShape
{
public:
    NBQGEditShapeCircle(NBObject *o);
    void click(float x, float y);
    void move(float x, float y);
    void rel();
    b2CircleShape *getShape();
private:
    bool selRadiusAdj;
};

#endif // NBQGEDITSHAPECIRCLE_H
