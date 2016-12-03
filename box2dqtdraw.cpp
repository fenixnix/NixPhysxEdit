#include "box2dqtdraw.h"
#include <iostream>

using namespace std;

Box2DQtDraw::Box2DQtDraw()
{

}

void Box2DQtDraw::setDrawPtr(NQOpenGL2DWidget *w)
{
    gl = w;
}

void Box2DQtDraw::DrawLine(b2Vec2 a, b2Vec2 b)
{
    gl->drawLine(a.x,a.y,b.x,b.y);
}

void Box2DQtDraw::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
    //cout<<__FUNCTION__<<endl;
    gl->glColor4f(color.r,color.g,color.b,color.a);
    gl->glBegin(GL_LINE_LOOP);
    for(int i = 0;i<vertexCount;i++){
        gl->glVertex2f(vertices[i].x,vertices[i].y);
    }
    gl->glEnd();
}

void Box2DQtDraw::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
    //cout<<__FUNCTION__<<endl;
    gl->glColor4f(color.r,color.g,color.b,color.a);
    gl->glBegin(GL_TRIANGLE_FAN);
    for(int i = 0;i<vertexCount;i++){
        gl->glVertex2f(vertices[i].x,vertices[i].y);
    }
    gl->glEnd();
}

void Box2DQtDraw::DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color)
{
    gl->glColor4f(color.r,color.g,color.b,color.a);
    gl->drawCircle(center.x,center.y,radius,GL_LINE_LOOP);
}

void Box2DQtDraw::DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color)
{
    gl->glColor4f(color.r,color.g,color.b,color.a);
    gl->drawCircle(center.x,center.y,radius,GL_TRIANGLE_FAN);
}

void Box2DQtDraw::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color)
{
    //cout<<__FUNCTION__<<endl;
    gl->glColor4f(color.r,color.g,color.b,color.a);
    gl->glBegin(GL_LINES);
    gl->glVertex2f(p1.x,p1.y);
    gl->glVertex2f(p2.x,p2.y);
    gl->glEnd();
}

void Box2DQtDraw::DrawTransform(const b2Transform &xf)
{
    //cout<<__FUNCTION__<<endl;
    gl->glColor4f(1,1,1,0.5);
    gl->drawLine(xf.p.x,xf.p.y,xf.p.x+xf.q.c,xf.p.y+xf.q.s);
}

void Box2DQtDraw::drawBody(NQOpenGL2DWidget *gl, b2BodyDef *body)
{
    gl->glColor4f(0,0.5,0,0.5);
    float size = gl->getWorldPixelSize();
    gl->drawRect(body->position.x,body->position.y,size,size);
    b2Rot rot(body->angle);
    gl->drawCircle(body->position.x+rot.c*size*5,body->position.y+rot.s*size*5,size,GL_LINE_LOOP);
}


#include "obj/nbjointdistance.h"
#include "obj/nbjointrevolute.h"
#include "obj/nbjointprismatic.h"
void Box2DQtDraw::drawJoint(NQOpenGL2DWidget *gl, NBJoint *joint)
{
    gl->glColor4f(0.5,0,0,0.5);
    float size = gl->getWorldPixelSize();
    if(joint->getJointType() == e_distanceJoint){
        NBJointDistance* j = joint->toJointDistance();
        gl->drawCircle(j->anchorA.x,j->anchorA.y,size,GL_LINE_LOOP);
        gl->drawRect(j->anchorB.x,j->anchorB.y,size,size);
        gl->drawLine(j->anchorA.x,j->anchorA.y,j->anchorB.x,j->anchorB.y);
    }
    if(joint->getJointType() == e_revoluteJoint){
        NBJointRevolute* j = joint->toJointRevolute();
        gl->drawCircle(j->anchor.x,j->anchor.y,size,GL_LINE_LOOP);
    }
    if(joint->getJointType() == e_prismaticJoint){
        NBJointPrismatic* j = joint->toJointPrismatic();
        gl->drawCircle(j->anchor.x,j->anchor.y,size,GL_LINE_LOOP);
        gl->drawRect(j->axis.x,j->axis.y,size,size);
        gl->drawLine(j->anchor.x,j->anchor.y,j->axis.x,j->axis.y);
    }
}

void Box2DQtDraw::drawFixture(NQOpenGL2DWidget *gl, b2FixtureDef *fixture)
{
    if(fixture->shape->GetType() == b2Shape::e_polygon){
        drawPolygonShape(gl,(b2PolygonShape*)fixture->shape);
    }
    if(fixture->shape->GetType() == b2Shape::e_circle){
        drawCircleShape(gl,(b2CircleShape*)fixture->shape);
    }
    if(fixture->shape->GetType() == b2Shape::e_chain){
        drawChainShape(gl,(b2ChainShape*)fixture->shape);
    }
    if(fixture->shape->GetType() == b2Shape::e_edge){
        drawEdgeShape(gl,(b2EdgeShape*)fixture->shape);
    }
}

void Box2DQtDraw::drawCircleShape(NQOpenGL2DWidget *gl, b2CircleShape *shape)
{
    gl->glColor4f(0,0.5,0,0.5);
    gl->drawCircle(shape->m_p.x,shape->m_p.y,shape->m_radius,GL_TRIANGLE_FAN);
}

void Box2DQtDraw::drawPolygonShape(NQOpenGL2DWidget *gl, b2PolygonShape *shape)
{
    gl->glColor4f(0,0.5,0,0.5);
    gl->glBegin(GL_TRIANGLE_FAN);
    for(int i = 0;i<shape->GetVertexCount();i++){
        gl->glVertex2f(shape->GetVertex(i).x,shape->GetVertex(i).y);
    }
    gl->glEnd();
}

void Box2DQtDraw::drawEdgeShape(NQOpenGL2DWidget *gl, b2EdgeShape *shape)
{
    gl->glColor4f(0,0.5,0,0.5);
    gl->glBegin(GL_LINES);
    gl->glVertex2f(shape->m_vertex1.x,shape->m_vertex1.y);
    gl->glVertex2f(shape->m_vertex2.x,shape->m_vertex2.y);
    gl->glEnd();
}

void Box2DQtDraw::drawChainShape(NQOpenGL2DWidget *gl, b2ChainShape *shape)
{
    gl->glColor4f(0,0.5,0,0.5);
    gl->glBegin(GL_LINE_STRIP);
    for(int i = 0;i<shape->GetChildCount();i++){
        b2EdgeShape es;
        shape->GetChildEdge(&es,i);
        gl->glVertex2f(es.m_vertex1.x,es.m_vertex1.y);
    }
    b2EdgeShape es;
    shape->GetChildEdge(&es,shape->GetChildCount()-1);
    gl->glVertex2f(es.m_vertex2.x,es.m_vertex2.y);
    gl->glEnd();
}
