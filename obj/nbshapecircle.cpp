#include "nbshapecircle.h"

NBShapeCircle::NBShapeCircle()
{
    vecs.push_back(b2Vec2(0,0));
    radius = 1.0f;
}

b2Shape *NBShapeCircle::createb2Shape()
{
    b2CircleShape *s = new b2CircleShape;
    s->m_p = vecs[0];
    s->m_radius = radius;
    return s;
}
