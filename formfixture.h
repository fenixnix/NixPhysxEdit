#ifndef FORMFIXTURE_H
#define FORMFIXTURE_H

#include <QWidget>
#include "obj/nbfixture.h"

namespace Ui {
class FormFixture;
}

class FormFixture : public QWidget
{
    Q_OBJECT

public:
    explicit FormFixture(QWidget *parent = 0);
    ~FormFixture();
    void setFixture(NBFixture* f);
    void upload();
    void download();

private slots:

    void on_buttonBox_accepted();

    void on_pushButton_Shape_clicked();

private:
    Ui::FormFixture *ui;
    NBFixture* def;
};

#endif // FORMFIXTURE_H
