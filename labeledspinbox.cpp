#include "labeledspinbox.h"
#include "ui_labeledspinbox.h"

LabeledSpinBox::LabeledSpinBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labeledSpinBox)
{
    ui->setupUi(this);
}

LabeledSpinBox::~LabeledSpinBox()
{
    delete ui;
}

void LabeledSpinBox::setText(QString str)
{
    ui->label->setText(str);
}

void LabeledSpinBox::set(double v)
{
    ui->doubleSpinBox->setValue(v);
}

double LabeledSpinBox::get()
{
    return ui->doubleSpinBox->value();
}

void LabeledSpinBox::on_doubleSpinBox_editingFinished()
{
    emit finishEdit();
}
