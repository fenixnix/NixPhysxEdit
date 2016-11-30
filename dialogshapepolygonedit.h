#ifndef DIALOGSHAPEPOLYGONEDIT_H
#define DIALOGSHAPEPOLYGONEDIT_H

#include <DialogShape.h>
#include <Box2D/Box2D.h>

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

private:
    Ui::DialogShapePolygonEdit *ui;
    b2PolygonShape *shape;
};

#endif // DIALOGSHAPEPOLYGONEDIT_H
