#include "formfilter.h"
#include "ui_formfilter.h"

FormFilter::FormFilter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFilter)
{
    ui->setupUi(this);
    QObject::connect(ui->category,&QBitEdit::valueChanged,this,&FormFilter::elementValueChanged);
    QObject::connect(ui->mask,&QBitEdit::valueChanged,this,&FormFilter::elementValueChanged);
    QObject::connect(ui->groupIndex,&QSpinBox::editingFinished,this,&FormFilter::elementValueChanged);
}

FormFilter::~FormFilter()
{
    delete ui;
}

b2Filter FormFilter::get()
{
    filter.categoryBits = ui->category->getValue();
    filter.maskBits = ui->mask->getValue();
    filter.groupIndex = ui->groupIndex->value();
    return filter;
}

void FormFilter::set(b2Filter f)
{
    filter = f;
    ui->category->setValue(filter.categoryBits);
    ui->mask->setValue(filter.maskBits);
    ui->groupIndex->setValue(filter.groupIndex);
}

void FormFilter::elementValueChanged()
{
    //qDebug()<<__FUNCTION__<<__LINE__;
    emit valueChanged();
}
