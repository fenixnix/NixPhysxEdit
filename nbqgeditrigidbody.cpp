#include "nbqgeditrigidbody.h"
#include "obj/nbbody.h"

NBQGEditRigidBody::NBQGEditRigidBody()
{
    selArr.push_back(false);
    selRotArr.push_back(false);
}

void NBQGEditRigidBody::click(float x, float y)
{
    b2BodyDef* def = &((NBBody*)(obj))->def;
    float size = widget->getWorldPixelSize();
    if(def){
        if(widget->CheckPointSelect(QPointF(def->position.x,def->position.y),QPointF(x,y))){
            selArr[0] = true;
            return;
        }
        b2Vec2 v = B2Physx::angle2Vec(def->angle,size*5);
        if(widget->CheckPointSelect(QPointF(def->position.x+v.x,def->position.y+v.y),QPointF(x,y))){
            selRotArr[0] = true;
            return;
        }
    }
}

void NBQGEditRigidBody::move(float x, float y)
{
    b2BodyDef* def = &((NBBody*)(obj))->def;
    if(def){
        if(selArr[0]){
            def->position.x = x;
            def->position.y = y;
            widget->update();
        }
        if(selRotArr[0]){
            b2Vec2 v = b2Vec2(x,y) - def->position;
            def->angle = B2Physx::vec2Angle(v);
            widget->update();
        }
    }
}

void NBQGEditRigidBody::draw()
{
    widget->glColor4f(1,1,0,1);
    b2BodyDef* def = &((NBBody*)(obj))->def;
    float x = def->position.x;
    float y = def->position.y;
    float size = widget->getWorldPixelSize();
    widget->drawRect(x,y,size,size);
    b2Vec2 v = B2Physx::angle2Vec(def->angle,size*5);
    widget->drawCircle(x+v.x,y+v.y,size,GL_LINE_LOOP);
}

void NBQGEditRigidBody::rel()
{
    NBQGEdit::rel();
    for(int i = 0;i<selRotArr.size();i++){
        selRotArr[i] = false;
    }
}
