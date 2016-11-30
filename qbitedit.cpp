#include "qbitedit.h"
#include <QGridLayout>
#include <QDebug>

QBitEdit::QBitEdit(QWidget *parent) : QWidget(parent)
{
    value = 0;
    size = 16;
    col = 8;
    QGridLayout *layout = new QGridLayout(this);
    for(int r = 0;r<size/col;r++){
        for(int c= 0;c<col;c++){
            QCheckBox* bit = new QCheckBox(this);
            QObject::connect(bit,&QCheckBox::stateChanged,this,&QBitEdit::bitChanged);
            layout->addWidget(bit,r,c,1,1);
            bits.append(bit);
        }
    }
    value2UI();
}

int QBitEdit::getValue()
{
    ui2Value();
    return value;
}

void QBitEdit::setValue(int v)
{
    //qDebug()<<__FUNCTION__<<__LINE__<<v;
    value = v;
    value2UI();
}

void QBitEdit::ui2Value()
{
    int v = 0;
    for(int i = bits.size()-1;i>=0;i--){
        v = v<<1;
        if(bits[i]->checkState()){
            v+=1;
        }
    }
    value = v;
}

void QBitEdit::value2UI()
{
    int v = 1;
    for(int i = 0;i<bits.size();i++){
        bits[i]->setChecked(v&value);
        v = v<<1;
    }
}

void QBitEdit::bitChanged()
{
    //qDebug()<<__FUNCTION__<<__LINE__;
    emit valueChanged();
}
