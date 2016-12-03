#include "nqopengl2dwidget.h"
#define _USE_MATH_DEFINES
#include "math.h"

const float viewZNear = 1.0f;
const float viewZFar = -1.0f;

NQOpenGL2DWidget::NQOpenGL2DWidget(QWidget *parent):QOpenGLWidget(parent)
{
    bgColor = Qt::black;
    viewMov = false;
    camPos.setZ(10);
    this->setMouseTracking(true);
}

void NQOpenGL2DWidget::updateViewPort()
{
    glLoadIdentity();
    float ratio = (float)this->height()/(float)this->width();
    float whalf = camPos.z();
    float hhalf = camPos.z()*ratio;
    glOrtho(camPos.x() - whalf,
            camPos.x() + whalf,
            camPos.y() - hhalf,
            camPos.y() + hhalf,
            viewZNear,viewZFar);
    glViewport(0,0,this->width(),this->height());
}

void NQOpenGL2DWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(bgColor.redF(),bgColor.greenF(),bgColor.blueF(),bgColor.alphaF());
    glMatrixMode(GL_PROJECTION);
    updateViewPort();
}

void NQOpenGL2DWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    updateViewPort();
    drawGroundGrid();
    draw(this);
    glFlush();
}

void NQOpenGL2DWidget::draw(NQOpenGL2DWidget *d)
{

}

void NQOpenGL2DWidget::click(float x, float y)
{

}

void NQOpenGL2DWidget::move(float x, float y)
{

}

void NQOpenGL2DWidget::rel()
{

}

void NQOpenGL2DWidget::drawCircle(float x, float y, float r, int type)
{
    //cout<<__FUNCTION__<<endl;
    const float k_segments = 32.0f;
    const float k_increment = 2.0f * M_PI / k_segments;
    float sinInc = sinf(k_increment);
    float cosInc = cosf(k_increment);
    QVector2D r1(1.0f, 0.0f);
    QVector2D v1 = QVector2D(x,y) + r * r1;
    glBegin(type);
    for (int i = 0; i < k_segments; ++i)
    {
        QVector2D r2(cosInc * r1.x() - sinInc * r1.y(),sinInc * r1.x() + cosInc * r1.y());
        QVector2D v2 = QVector2D(x,y) + r * r2;
        glVertex2f(v1.x(),v1.y());
        r1 = r2;
        v1 = v2;
    }
    glEnd();
}

void NQOpenGL2DWidget::drawRect(float x, float y, float w, float h)
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(x-w/2,y-h/2);
    glVertex2f(x-w/2,y+h/2);
    glVertex2f(x+w/2,y+h/2);
    glVertex2f(x+w/2,y-h/2);
    glEnd();
}

void NQOpenGL2DWidget::drawLine(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

void NQOpenGL2DWidget::drawGroundGrid()
{
    glColor4f(0,0.2,0,0.2);
    for(int i = -10;i<=10;i++)
    {
        glBegin(GL_LINES);
        glVertex3d(i,-10,0);
        glVertex3d(i,10,0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3d(-10,i,0);
        glVertex3d(10,i,0);
        glEnd();
    }
    glColor4f(0,1,1,0.2);
    glBegin(GL_LINES);
    glVertex3d(10,0,0);
    glVertex3d(-10,0,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(0,10,0);
    glVertex3d(0,-10,0);
    glEnd();
}

QPointF NQOpenGL2DWidget::ScreenLoc2WorldLoc(QPointF loc)
{
    QPointF worldLoc;
    float ratio = (float)this->height()/(float)this->width();
    float whalf = camPos.z();
    float hhalf = camPos.z()*ratio;
    float orgX = camPos.x() - whalf;
    float difX = (loc.x()/(float)this->width())*whalf*2;
    float orgY = camPos.y() + hhalf;
    float difY = (-loc.y()/(float)this->height())*hhalf*2;
    worldLoc.setX(orgX+difX);
    worldLoc.setY(orgY+difY);
    return worldLoc;
}

bool NQOpenGL2DWidget::CheckPointSelect(QPointF selectPoint, QPointF mouseLoc)
{
    float selectRectSize = getWorldPixelSize();
    if(
            (abs(selectPoint.x() - mouseLoc.x())<=selectRectSize)&&
            (abs(selectPoint.y() - mouseLoc.y())<=selectRectSize)
            ){
        return true;
    }
    return false;
}

float NQOpenGL2DWidget::getWorldPixelSize(int mul)
{
    return (camPos.z()*2/this->width())*mul;
}

void NQOpenGL2DWidget::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<__FUNCTION__;
    if(event->key() == Qt::Key_A){
        camPos.setX(camPos.x() - camPos.z()/10);
    }
    if(event->key() == Qt::Key_D){
        camPos.setX(camPos.x() + camPos.z()/10);
    }
    if(event->key() == Qt::Key_W){
        camPos.setY(camPos.y() + camPos.z()/10);
    }
    if(event->key() == Qt::Key_S){
        camPos.setY(camPos.y() - camPos.z()/10);
    }
    update();
}

void NQOpenGL2DWidget::keyReleaseEvent(QKeyEvent *event)
{

}

void NQOpenGL2DWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MidButton){
        qDebug()<<__FUNCTION__<<endl;
        mouseProPos = event->localPos();
        viewMov = true;
        camPos.setX(worldPos.x());
        camPos.setY(worldPos.y());
        camProPos.setX(camPos.x());
        camProPos.setY(camPos.y());
        update();
    }
    click(worldPos.x(),worldPos.y());
}

void NQOpenGL2DWidget::mouseReleaseEvent(QMouseEvent *event)
{
    viewMov = false;
    rel();
    emit finishEdit();
}

void NQOpenGL2DWidget::mouseMoveEvent(QMouseEvent *event)
{
    mousePos = event->localPos();
    worldPos = ScreenLoc2WorldLoc(mousePos);
    if(viewMov){
        QPointF mouseDif = mousePos - mouseProPos;
        //qDebug()<<mouseDif<<camProPos<<worldDif;
        camPos.setX(camProPos.x() - mouseDif.x()*getWorldPixelSize(1));
        camPos.setY(camProPos.y() + mouseDif.y()*getWorldPixelSize(1));
        update();
    }
    move(worldPos.x(),worldPos.y());
}

void NQOpenGL2DWidget::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0){
        camPos.setZ(camPos.z()*1.1f);
    }else{
        camPos.setZ(camPos.z()*0.9f);
    }
    update();
}
