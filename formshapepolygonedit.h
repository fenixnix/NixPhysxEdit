#ifndef FORMSHAPEPOLYGONEDIT_H
#define FORMSHAPEPOLYGONEDIT_H

#include <QWidget>
#include <QInputDialog>

namespace Ui {
class FormShapePolygonEdit;
}

class FormShapePolygonEdit : public QWidget
{
    Q_OBJECT

public:
    explicit FormShapePolygonEdit(QWidget *parent = 0);
    ~FormShapePolygonEdit();

private slots:
    void on_pushButton_OK_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

private:
    Ui::FormShapePolygonEdit *ui;
};

#endif // FORMSHAPEPOLYGONEDIT_H
