#ifndef LABELEDSPINBOX_H
#define LABELEDSPINBOX_H

#include <QWidget>

namespace Ui {
class labeledSpinBox;
}

class LabeledSpinBox : public QWidget
{
    Q_OBJECT

public:
    explicit LabeledSpinBox(QWidget *parent = 0);
    ~LabeledSpinBox();
    void setText(QString str);
    void set(double v);
    double get();
signals:
    void finishEdit();

private slots:
    void on_doubleSpinBox_editingFinished();

private:
    Ui::labeledSpinBox *ui;
};

#endif // LABELEDSPINBOX_H
