#include "nbqgeditshape.h"

NBQGEditShape::NBQGEditShape()
{

}

void NBQGEditShape::draw()
{
    NBBody* body = obj->toFixture()->parent->toBody();
    widget->glPushMatrix();
    widget->glTranslatef(body->def.position.x,body->def.position.y,0);
    widget->glRotatef(body->def.angle*180.0f/M_PI,0,0,1);
    ShapeEditPainter(widget).draw((b2Shape*)obj->toFixture()->def.shape);
    widget->glPopMatrix();
}
