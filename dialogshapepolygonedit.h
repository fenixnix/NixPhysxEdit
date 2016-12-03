#ifndef DIALOGSHAPEPOLYGONEDIT_H
#define DIALOGSHAPEPOLYGONEDIT_H

#include <DialogShape.h>
#include <Box2D/Box2D.h>
#include "nbshapepolygonglwidget.h"

namespace Ui {
class DialogShapePolygonEdit;
}

class DialogShapePolygonEdit : public DlgShape
{
    Q_OBJECT

public:
    explicit DialogShapePolygonEdit(QWidget *parent = 0);
    ~DialogShapePolygonEdit();
    void set(b2Shape* s);

public slots:
    void widgetValueChanged();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::DialogShapePolygonEdit *ui;
    NBShapePolygonGLWidget *getWidget();
};

#endif // DIALOGSHAPEPOLYGONEDIT_H
