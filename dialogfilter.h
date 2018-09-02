#ifndef DIALOGFILTER_H
#define DIALOGFILTER_H

#include <QDialog>
#include <Box2D/Box2D.h>

namespace Ui {
class DialogFilter;
}

class DialogFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFilter(QWidget *parent = 0);
    ~DialogFilter();
    b2Filter get();
private slots:

private:
    Ui::DialogFilter *ui;
};

#endif // DIALOGFILTER_H
