#ifndef FORMSHAPECIRCLEEDIT_H
#define FORMSHAPECIRCLEEDIT_H

#include <QWidget>
#include <QInputDialog>

namespace Ui {
class FormShapeCircleEdit;
}

class FormShapeCircleEdit : public QWidget
{
    Q_OBJECT

public:
    explicit FormShapeCircleEdit(QWidget *parent = 0);
    ~FormShapeCircleEdit();
    QString shapeDefID;
private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::FormShapeCircleEdit *ui;
};

#endif // FORMSHAPECIRCLEEDIT_H
