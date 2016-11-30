#ifndef FORMFILTER_H
#define FORMFILTER_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QDebug>

namespace Ui {
class FormFilter;
}

class FormFilter : public QWidget
{
    Q_OBJECT

public:
    explicit FormFilter(QWidget *parent = 0);
    ~FormFilter();
    b2Filter get();
    void set(b2Filter f);
signals:
    void valueChanged();
private slots:
    void elementValueChanged();
private:
    Ui::FormFilter *ui;
    b2Filter filter;
};

#endif // FORMFILTER_H
