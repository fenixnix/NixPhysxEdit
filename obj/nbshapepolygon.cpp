#include "nbshapepolygon.h"

NBShapePolygon::NBShapePolygon()
{
    vecs.push_back(b2Vec2(-1,-1));
    vecs.push_back(b2Vec2(-1,1));
    vecs.push_back(b2Vec2(1,-1));
    vecs.push_back(b2Vec2(1,1));
}

b2Shape *NBShapePolygon::createb2Shape()
{
    b2PolygonShape *s = new b2PolygonShape;
    s->Set(vecs.data(),vecs.size());
    return s;
}
