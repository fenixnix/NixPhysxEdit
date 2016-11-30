#ifndef NBQGEDITSHAPEPOLYGON_H
#define NBQGEDITSHAPEPOLYGON_H

#include "nbqgeditshape.h"

class NBQGEditShapePolygon : public NBQGEditShape
{
public:
    NBQGEditShapePolygon(NBObject *o);
    void click(float x, float y);
    void move(float x, float y);
    void rel();
    void setNBObj(NBObject *o);
    b2PolygonShape *getShape();
private:
    bool selCenterAdj;
    QVector<b2Vec2> tmpVecs;
    b2Vec2 center;
};

#endif // NBQGEDITSHAPEPOLYGON_H
