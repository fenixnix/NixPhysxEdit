#include "dialogshapepolygonedit.h"
#include "ui_dialogshapepolygonedit.h"

DialogShapePolygonEdit::DialogShapePolygonEdit(QWidget *parent) :
    DlgShape(parent),
    ui(new Ui::DialogShapePolygonEdit)
{
    ui->setupUi(this);
}

DialogShapePolygonEdit::~DialogShapePolygonEdit()
{
    delete ui;
}

void DialogShapePolygonEdit::set(b2Shape *s)
{
    shape = (b2PolygonShape*)s;
    ui->openGLWidget->set(shape);
}

void DialogShapePolygonEdit::widgetValueChanged()
{

}
