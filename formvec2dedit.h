#ifndef FORMVEC2DEDIT_H
#define FORMVEC2DEDIT_H

#include <QWidget>

namespace Ui {
class FormVec2DEdit;
}

class FormVec2DEdit : public QWidget
{
    Q_OBJECT

public:
    explicit FormVec2DEdit(QWidget *parent = 0);
    ~FormVec2DEdit();
    void set(QPointF p);
    QPointF get();

private slots:
    void on_y_valueChanged(double arg1);

    void on_x_valueChanged(double arg1);

signals:
    void valueChanged();

private:
    Ui::FormVec2DEdit *ui;
};

#endif // FORMVEC2DEDIT_H
