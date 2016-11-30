#include "dialogvec2input.h"
#include "ui_dialogvec2input.h"

DialogVec2Input::DialogVec2Input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogVec2Input)
{
    ui->setupUi(this);
}

DialogVec2Input::~DialogVec2Input()
{
    delete ui;
}

double DialogVec2Input::getX()
{
    return ui->doubleSpinBox_X->value();
}

double DialogVec2Input::getY()
{
    return ui->doubleSpinBox_Y->value();
}
