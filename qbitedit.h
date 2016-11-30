#ifndef QBITEDIT_H
#define QBITEDIT_H

#include <QWidget>
#include <QCheckBox>

class QBitEdit : public QWidget
{
    Q_OBJECT
public:
    explicit QBitEdit(QWidget *parent = 0);
    int getValue();
    void setValue(int v);
    void ui2Value();
    void value2UI();

signals:
    void valueChanged();

private slots:
    void bitChanged();

private:
    int size;
    int col;
    int value;
    QVector<QCheckBox* > bits;
};

#endif // QBITEDIT_H
