#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <box2dqtdraw.h>
#include <b2physx.h>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>

#include "formrigidbody.h"
#include "formfixture.h"
#include "formjointdistance.h"
#include "formjointrevolute.h"
#include "AttributeUI/uijointprismatic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void step();
    void setWorldBox(float w, float h);
    void setWorldGround(float w, float h);
    void changeCurrentWidget(QWidget* widget);
    void editShape(b2Shape *s);

    void updateShapeList();
    void updateBodyList();
    void updateFixtureList(QString bodyID);
    void updateJointList();
    void updateAllList();

    void updateAtt(NBObject* obj);
    void refreshAtt();

    NBBody *addNewBody(QString id);
    NBFixture *addNewFixture(QString id, QString shapeID);
    void addNewJoint(QString id, QString jointType);
    void inputIDtoAddNewJoint(QString jointType);
    NBBody *getCurrentBody();

    QString genAutoName(QString baseName,QStringList existNameList);

private slots:
    void on_actionAdd_triggered();
    void on_actionWorld_Box_triggered();
    void on_actionRun_triggered();
    void on_listWidget_RigidBodys_clicked(const QModelIndex &index);
    void on_actionGravity_triggered();
    void on_actionStop_triggered();
    void on_actionCircle_triggered();
    void on_listWidget_Shape_clicked(const QModelIndex &index);
    void on_listWidget_Shape_viewportEntered();
    void on_actionPolygon_triggered();
    void on_actionNew_triggered();
    void on_actionSave_triggered();
    void on_actionChain_triggered();
    void on_actionEdge_triggered();
    void on_actionDistance_triggered();
    void on_actionRevolute_triggered();
    void on_actionPrismatic_triggered();
    void on_actionPulley_triggered();
    void on_actionGear_triggered();
    void on_listWidget_Joint_clicked(const QModelIndex &index);
    void on_actionCreate_Unit_triggered();
    void on_actionExport_Unit_triggered();
    void on_actionImport_Unit_triggered();
    void on_listWidget_Fixtures_clicked(const QModelIndex &index);
    void on_actionCircle_Object_triggered();
    void on_actionSquare_Object_triggered();

    void on_listWidget_RigidBodys_customContextMenuRequested(const QPoint &pos);
    void on_listWidget_Joint_customContextMenuRequested(const QPoint &pos);
    void on_listWidget_Shape_customContextMenuRequested(const QPoint &pos);
    void on_listWidget_Fixtures_customContextMenuRequested(const QPoint &pos);

    void on_actionClear_triggered();

private:
    Ui::MainWindow *ui;
    QString currentRID;
    Box2DQtDraw draw;
    QTimer simTimer;

    QWidget* curWidget;
    QWidget* nullWidget;
    FormRigidBody formBody;
    FormFixture formFixture;
    FormJointDistance formJointDistance;
    FormJointRevolute formJointRevolute;
    UIJointPrismatic uiJointPrismatic;
};

#endif // MAINWINDOW_H
