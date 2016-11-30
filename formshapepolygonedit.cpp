#include "formshapepolygonedit.h"
#include "ui_formshapepolygonedit.h"
#include "obj/nbdatamnger.h"

FormShapePolygonEdit::FormShapePolygonEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormShapePolygonEdit)
{
    ui->setupUi(this);
}

FormShapePolygonEdit::~FormShapePolygonEdit()
{
    delete ui;
}

void FormShapePolygonEdit::on_pushButton_OK_clicked()
{
//    QString id;
//    id = QInputDialog::getText(this,"Shape","ID");
//    NBDataMnger::the()->createShape(id,ui->openGLWidget->createShape());
//    this->close();
//    delete this;
}

void FormShapePolygonEdit::on_pushButton_add_clicked()
{
    ui->openGLWidget->addPoint();
}

void FormShapePolygonEdit::on_pushButton_del_clicked()
{
    ui->openGLWidget->delPoint();
}
