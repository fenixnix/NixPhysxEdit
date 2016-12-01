#ifndef BOX2DQTDRAW_H
#define BOX2DQTDRAW_H

#include "Box2D/Box2D.h"
#include "mainglwidget.h"

class Box2DQtDraw : public b2Draw
{
public:
    Box2DQtDraw();
    void setDrawPtr(NQOpenGL2DWidget* w);

    void DrawLine(b2Vec2 a, b2Vec2 b);

    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
    void DrawTransform(const b2Transform& xf);

    void static drawBody(NQOpenGL2DWidget *gl, b2BodyDef *body);
    void static drawJoint(NQOpenGL2DWidget *gl, NBJoint *joint);
    void static drawFixture(NQOpenGL2DWidget* gl, b2FixtureDef* fixture);
    void static drawCircleShape(NQOpenGL2DWidget* gl, b2CircleShape* shape);
    void static drawPolygonShape(NQOpenGL2DWidget* gl,b2PolygonShape* shape);
    void static drawEdgeShape(NQOpenGL2DWidget* gl,b2EdgeShape* shape);
    void static drawChainShape(NQOpenGL2DWidget* gl,b2ChainShape* shape);
private:
    NQOpenGL2DWidget* gl;
};

#endif // BOX2DQTDRAW_H
