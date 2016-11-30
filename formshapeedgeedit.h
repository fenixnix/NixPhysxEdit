#ifndef FORMSHAPEEDGEEDIT_H
#define FORMSHAPEEDGEEDIT_H

#include <QWidget>
#include <QInputDialog>

namespace Ui {
class FormShapeEdgeEdit;
}

class FormShapeEdgeEdit : public QWidget
{
    Q_OBJECT

public:
    explicit FormShapeEdgeEdit(QWidget *parent = 0);
    ~FormShapeEdgeEdit();

private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::FormShapeEdgeEdit *ui;
};

#endif // FORMSHAPEEDGEEDIT_H
