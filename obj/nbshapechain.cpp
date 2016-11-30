#include "nbshapechain.h"

NBShapeChain::NBShapeChain()
{

}

b2Shape *NBShapeChain::createb2Shape()
{
    b2ChainShape *s = new b2ChainShape;
    s->CreateChain(vecs.data(),vecs.size());
    return s;
}
