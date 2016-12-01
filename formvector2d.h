#ifndef FORMVECTOR2D_H
#define FORMVECTOR2D_H

#include <QWidget>
#include <QVector2D>
#include <Box2d/Box2D.h>

namespace Ui {
class FormVector2D;
}

class FormVector2D : public QWidget
{
    Q_OBJECT

public:
    explicit FormVector2D(QWidget *parent = 0);
    void setText(QString str);
    ~FormVector2D();
    void setb2(QVector2D vector);
    QVector2D get();
    void setb2(b2Vec2 vec);
    b2Vec2 getb2();
signals:
    void finishEdit();

private:
    void onXYfinishEdit();

private:
    Ui::FormVector2D *ui;
};

#endif // FORMVECTOR2D_H
