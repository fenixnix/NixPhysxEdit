#ifndef DIALOGSHAPECIRCLEEDIT_H
#define DIALOGSHAPECIRCLEEDIT_H

#include <dialogshape.h>
#include <Box2D/Box2D.h>

namespace Ui {
class DialogShapeCircleEdit;
}

class DialogShapeCircleEdit : public DlgShape
{
    Q_OBJECT

public:
    explicit DialogShapeCircleEdit(QWidget *parent = 0);
    ~DialogShapeCircleEdit();
    void set(b2Shape* s);

public slots:
    void widgetValueChanged();

private slots:

    void on_x_valueChanged(double arg1);

    void on_y_valueChanged(double arg1);

    void on_radius_valueChanged(double arg1);

    void on_openGLWidget_frameSwapped();

    void on_buttonBox_accepted();

private:
    Ui::DialogShapeCircleEdit *ui;
    b2CircleShape *shape;
};

#endif // DIALOGSHAPECIRCLEEDIT_H
