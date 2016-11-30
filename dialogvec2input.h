#ifndef DIALOGVEC2INPUT_H
#define DIALOGVEC2INPUT_H

#include <QDialog>

namespace Ui {
class DialogVec2Input;
}

class DialogVec2Input : public QDialog
{
    Q_OBJECT

public:
    explicit DialogVec2Input(QWidget *parent = 0);
    ~DialogVec2Input();
    double getX();
    double getY();
private:
    Ui::DialogVec2Input *ui;
};

#endif // DIALOGVEC2INPUT_H
