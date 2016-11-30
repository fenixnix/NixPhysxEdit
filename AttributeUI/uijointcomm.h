#ifndef UIJOINTCOMM_H
#define UIJOINTCOMM_H

#include <QWidget>
#include <QtWidgets/QDialogButtonBox>

class UIJointComm : public QWidget
{
    Q_OBJECT
public:
    explicit UIJointComm(QWidget *parent = 0);
    virtual void pushOK();
signals:

public slots:

private:
    QDialogButtonBox *buttonBox;

private slots:
    void onPushOK();
};

#endif // UIJOINTCOMM_H
