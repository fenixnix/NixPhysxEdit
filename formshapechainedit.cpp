#include "formshapechainedit.h"
#include "ui_formshapechainedit.h"
#include "obj/nbdatamnger.h"

FormShapeChainEdit::FormShapeChainEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormShapeChainEdit)
{
    ui->setupUi(this);
}

FormShapeChainEdit::~FormShapeChainEdit()
{
    delete ui;
}

void FormShapeChainEdit::on_pushButton_add_clicked()
{
    ui->openGLWidget->addPoint();
}

void FormShapeChainEdit::on_pushButton_del_clicked()
{
    ui->openGLWidget->delPoint();
}

void FormShapeChainEdit::on_pushButton_OK_clicked()
{
    QString id;
    id = QInputDialog::getText(this,"Shape","ID");
    NBDataMnger::the()->createShape(id,ui->openGLWidget->createShape());
    this->close();
    delete this;
}
