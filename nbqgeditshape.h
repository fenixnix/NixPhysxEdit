#ifndef NBQGEDITSHAPE_H
#define NBQGEDITSHAPE_H

#include "nbqgedit.h"
#include "shapeeditpainter.h"
#include "obj/nbfixture.h"
#include "obj/nbbody.h"

class NBQGEditShape : public NBQGEdit
{
public:
    NBQGEditShape();
    void draw();
};

#endif // NBQGEDITSHAPE_H
