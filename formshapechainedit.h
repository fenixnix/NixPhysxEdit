#ifndef FORMSHAPECHAINEDIT_H
#define FORMSHAPECHAINEDIT_H

#include <QWidget>
#include <QInputDialog>

namespace Ui {
class FormShapeChainEdit;
}

class FormShapeChainEdit : public QWidget
{
    Q_OBJECT

public:
    explicit FormShapeChainEdit(QWidget *parent = 0);
    ~FormShapeChainEdit();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_OK_clicked();

private:
    Ui::FormShapeChainEdit *ui;
};

#endif // FORMSHAPECHAINEDIT_H
