#include "formshapecircleedit.h"
#include "ui_formshapecircleedit.h"
#include "Box2D/Box2D.h"
#include "obj/nbdatamnger.h"

FormShapeCircleEdit::FormShapeCircleEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormShapeCircleEdit)
{
    ui->setupUi(this);
}

FormShapeCircleEdit::~FormShapeCircleEdit()
{
    delete ui;
}

void FormShapeCircleEdit::on_pushButton_OK_clicked()
{
//    QString id;
//    id = QInputDialog::getText(this,"Shape","ID");
//    NBDataMnger::the()->createShape(id,ui->openGLWidget->createShape());
//    this->close();
//    delete this;
}
