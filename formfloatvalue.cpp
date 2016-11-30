#include "formfloatvalue.h"
#include "ui_formfloatvalue.h"

FormFloatValue::FormFloatValue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFloatValue)
{
    ui->setupUi(this);
}

FormFloatValue::~FormFloatValue()
{
    delete ui;
}
