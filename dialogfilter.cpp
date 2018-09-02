#include "dialogfilter.h"
#include "ui_dialogfilter.h"

DialogFilter::DialogFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFilter)
{
    ui->setupUi(this);
}

DialogFilter::~DialogFilter()
{
    delete ui;
}

b2Filter DialogFilter::get()
{
    return ui->widget->get();
}
