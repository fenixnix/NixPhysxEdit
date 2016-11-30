#include "nbshapeedge.h"

NBShapeEdge::NBShapeEdge()
{
    vecs.push_back(b2Vec2(-1,0));
    vecs.push_back(b2Vec2(1,0));
}

b2Shape *NBShapeEdge::createb2Shape()
{
    b2EdgeShape *s = new b2EdgeShape;
    s->m_vertex1 = vecs[0];
    s->m_vertex2 = vecs[1];
    return s;
}
