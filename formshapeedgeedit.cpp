#include "formshapeedgeedit.h"
#include "ui_formshapeedgeedit.h"
#include "obj/nbdatamnger.h"

FormShapeEdgeEdit::FormShapeEdgeEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormShapeEdgeEdit)
{
    ui->setupUi(this);
}

FormShapeEdgeEdit::~FormShapeEdgeEdit()
{
    delete ui;
}

void FormShapeEdgeEdit::on_pushButton_OK_clicked()
{
    QString id;
    id = QInputDialog::getText(this,"Shape","ID");
    NBDataMnger::the()->addShape(id,ui->openGLWidget->createShape());
    this->close();
    delete this;
}
