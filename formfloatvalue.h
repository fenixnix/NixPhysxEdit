#ifndef FORMFLOATVALUE_H
#define FORMFLOATVALUE_H

#include <QWidget>

namespace Ui {
class FormFloatValue;
}

class FormFloatValue : public QWidget
{
    Q_OBJECT

public:
    explicit FormFloatValue(QWidget *parent = 0);
    ~FormFloatValue();

private:
    Ui::FormFloatValue *ui;
};

#endif // FORMFLOATVALUE_H
