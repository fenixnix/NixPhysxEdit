#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Box2D/Box2D.h"
#include "globaltimer.h"
#include "dialogvec2input.h"
#include "obj/nbdatamnger.h"
#include "formshapechainedit.h"
#include "formshapeedgeedit.h"
#include "dialogshapecircleedit.h"
#include "dialogshapepolygonedit.h"
#include "b2objfactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    B2Physx::the()->init();
    B2Physx::the()->setDraw(&draw);
    B2Physx::the()->setGravity();
    draw.setDrawPtr(ui->openGLWidget);
    QObject::connect(&simTimer,&QTimer::timeout,this,&MainWindow::step);
    currentRID.clear();

    curWidget = nullptr;
    nullWidget = nullptr;
    nullWidget = new QWidget(this);
    nullWidget->setMaximumWidth(0);
    curWidget = nullWidget;
    ui->horizontalLayout->addWidget(curWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::step()
{
    //GlobalTimer::update();
    B2Physx::the()->step(0.04);
    this->update();
}

void MainWindow::setWorldBox(float w, float h)
{
    B2Physx::the()->createWorldBaseObj();
    float whalf = w/2;
    float hhalf = h/2;
    B2Physx::the()->createBlockWall(-whalf,-hhalf,-whalf,hhalf);
    B2Physx::the()->createBlockWall(-whalf,hhalf,whalf,hhalf);
    B2Physx::the()->createBlockWall(whalf,hhalf,whalf,-hhalf);
    B2Physx::the()->createBlockWall(whalf,-hhalf,-whalf,-hhalf);
}

void MainWindow::changeCurrentWidget(QWidget *widget)
{
    curWidget->hide();
    ui->horizontalLayout->removeWidget(curWidget);
    ui->horizontalLayout->addWidget(widget);
    curWidget = widget;
    curWidget->show();
}

void MainWindow::editShape(b2Shape *s)
{
    int type = s->GetType();
    if(type == b2Shape::e_circle){
        DialogShapeCircleEdit edit;
        edit.set(s);
        edit.exec();
    }
    if(type == b2Shape::e_polygon){
        DialogShapePolygonEdit edit;
        edit.set(s);
        edit.exec();
    }
    //    if(type == b2Shape::e_edge){
    //        FormShapeEdgeEdit* edit = new FormShapeEdgeEdit();
    //        edit->show();
    //    }
    //    if(type == b2Shape::e_chain){
    //        FormShapeChainEdit* edit = new FormShapeChainEdit();
    //        edit->show();
    //    }
}

void MainWindow::updateShapeList()
{
    ui->listWidget_Shape->clear();
    ui->listWidget_Shape->addItems(NBDataMnger::the()->getShapeList());
}

void MainWindow::updateBodyList()
{
    ui->listWidget_RigidBodys->clear();
    ui->listWidget_RigidBodys->addItems(NBDataMnger::the()->layer.getBodyList());
}

void MainWindow::updateFixtureList(QString bodyID)
{
    ui->listWidget_Fixtures->clear();
    ui->listWidget_Fixtures->addItems(NBDataMnger::the()->layer.getFixtureList(bodyID));
}

void MainWindow::updateJointList()
{
    ui->listWidget_Joint->clear();
    ui->listWidget_Joint->addItems(NBDataMnger::the()->layer.getJointList());
}

void MainWindow::updateAllList()
{
    updateShapeList();
    updateJointList();
    updateBodyList();
    updateFixtureList("");
}

void MainWindow::updateAtt(NBObject *obj)
{
    QString type = obj->getType();
    if(type == "body"){
        formBody.setBody(obj->toBody());
        changeCurrentWidget(&formBody);
    }
    if(type == "joint"){
        NBJoint* joint = obj->toJoint();
        QString jointType = QString::fromStdString(joint->getJointType());
        if(jointType == "distance"){
            formJointDistance.setJoint(joint->toJointDistance());
            changeCurrentWidget(&formJointDistance);
        }
        if(jointType == "revolute"){
            formJointRevolute.setJoint(joint->toJointRevolute());
            changeCurrentWidget(&formJointRevolute);
        }
        if(jointType == "prismatic"){
            //uiJointComm.setJoint(joint->toJointRevolute());
            changeCurrentWidget(&uiJointComm);
        }
        qDebug()<<__FUNCTION__<<__LINE__<<jointType<<"!!!";
    }
    if(type == "fixture"){
        formFixture.setFixture(obj->toFixture());
        changeCurrentWidget(&formFixture);
    }
    update();//!!!可以删除
}

void MainWindow::addNewJoint(QString jointType)
{
    QString id = QInputDialog::getText(this,"Joint","ID");
    NBJoint* obj = NBDataMnger::the()->layer.newDefJoint(id.toStdString(),jointType);
    updateJointList();
    updateAtt(obj);
    ui->openGLWidget->setEditNBObject(obj);
}

void MainWindow::on_actionAdd_triggered()
{
    QString id = QInputDialog::getText(this,"RigidBody","ID");
    NBBody* body = new NBBody(id);
    NBDataMnger::the()->layer.addBody(body);

    updateBodyList();
    currentRID = id;
    ui->openGLWidget->setEditNBObject(body);
}

void MainWindow::on_actionWorld_Box_triggered()
{

}

void MainWindow::on_actionRun_triggered()
{
    setWorldBox(20,20);
    ui->openGLWidget->setDrawLayer(false);
    simTimer.start(40);
}

void MainWindow::expendB2Fixture(QString rid, QString fid)
{

}

void MainWindow::on_listWidget_RigidBodys_clicked(const QModelIndex &index)
{
    currentRID = index.data().toString();
    updateFixtureList(currentRID);
    NBBody* body = NBDataMnger::the()->layer.getNBBody(currentRID)->toBody();
    updateAtt(body);
    ui->openGLWidget->setEditNBObject(body);
}

void MainWindow::on_actionGravity_triggered()
{
    DialogVec2Input *dlg = new DialogVec2Input;
    dlg->exec();
    b2Vec2 g = b2Vec2(dlg->getX(),dlg->getY());
    B2Physx::the()->setGravity(g);
    delete dlg;
}

void MainWindow::on_actionStop_triggered()
{
    ui->openGLWidget->setDrawLayer(true);
    simTimer.stop();
    B2Physx::the()->destroyAll();
}

void MainWindow::on_actionCircle_triggered()
{
    DialogShapeCircleEdit edit;
    edit.exec();
}

void MainWindow::on_actionPolygon_triggered()
{
    DialogShapePolygonEdit edit;
    edit.exec();
}

void MainWindow::on_actionChain_triggered()
{
    FormShapeChainEdit* edit = new FormShapeChainEdit();
    edit->show();
}

void MainWindow::on_actionEdge_triggered()
{
    FormShapeEdgeEdit* edit = new FormShapeEdgeEdit();
    edit->show();
}

void MainWindow::on_listWidget_Shape_clicked(const QModelIndex &index)
{
    qDebug()<<NBDataMnger::the()->getShapeList();
    ui->listWidget_Shape->clear();
    ui->listWidget_Shape->addItems(NBDataMnger::the()->getShapeList());
}

void MainWindow::on_listWidget_Shape_viewportEntered()
{
    qDebug()<<__FUNCTION__<<NBDataMnger::the()->getShapeList();
    ui->listWidget_Shape->clear();
    ui->listWidget_Shape->addItems(NBDataMnger::the()->getShapeList());
}

void MainWindow::on_actionNew_triggered()
{
    QString ridBodyID = currentRID;
    if(ridBodyID.size()==0){
        return;
    }
    QStringList shapeList = NBDataMnger::the()->getShapeList();
    if(shapeList.empty()){
        qDebug()<<"no shape!!!";
        return;
    }
    QString id = QInputDialog::getText(this,"Fixture","ID",QLineEdit::Normal,"shape");
    NBBody* body = NBDataMnger::the()->layer.getNBBody(ridBodyID)->toBody();
    qDebug()<<__FUNCTION__<<__LINE__<<body<<body->id;
    NBFixture* fixture = new NBFixture(body,id);
    QString shapeID;
    shapeID = QInputDialog::getItem(this,"Shape List","Shape",shapeList,0,false);
    fixture->def.shape = NBDataMnger::the()->getShape(shapeID)->Clone(&allo);
    NBDataMnger::the()->layer.addFixture(fixture);
    updateFixtureList(ridBodyID);
    updateAtt(fixture);
}

void MainWindow::on_listWidget_RigidBodys_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* item = ui->listWidget_RigidBodys->itemAt(pos);
    qDebug()<<__FUNCTION__<<pos;
    if(item){
        QMenu* popMenu = new QMenu(this);
        popMenu->addAction(tr("Add Fixture"));
        popMenu->addAction(tr("delete"));
        QAction* action = popMenu->exec(QCursor::pos());
        qDebug()<<__FUNCTION__<<__LINE__<< action->text();
        if(action->text() == "Add Fixture"){
            on_actionNew_triggered();
        }
        if(action->text() == "delete"){
            NBDataMnger::the()->layer.delBody(item->text());
        }
        updateBodyList();
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName();
    NBDataMnger::the()->save(fileName);
}

void MainWindow::on_actionDistance_triggered()
{
    addNewJoint("distance");
}

void MainWindow::on_actionRevolute_triggered()
{
    addNewJoint("revolute");
}

void MainWindow::on_actionPrismatic_triggered()
{
    addNewJoint("prismatic");
}

void MainWindow::on_actionPulley_triggered()
{
    b2PulleyJointDef def;
    b2Vec2 groundAnchorA;

    /// The second ground anchor in world coordinates. This point never moves.
    b2Vec2 groundAnchorB;

    /// The local anchor point relative to bodyA's origin.
    b2Vec2 localAnchorA;

    /// The local anchor point relative to bodyB's origin.
    b2Vec2 localAnchorB;

    /// The a reference length for the segment attached to bodyA.
    float32 lengthA;

    /// The a reference length for the segment attached to bodyB.
    float32 lengthB;

    /// The pulley ratio, used to simulate a block-and-tackle.
    float32 ratio;

}

void MainWindow::on_actionGear_triggered()
{
    //!!!!!!!!!!!!!!!!!
    b2GearJointDef def;
    /// The first revolute/prismatic joint attached to the gear joint.
    b2Joint* joint1;

    /// The second revolute/prismatic joint attached to the gear joint.
    b2Joint* joint2;

    /// The gear ratio.
    /// @see b2GearJoint for explanation.
    float32 ratio;

}

void MainWindow::on_listWidget_Joint_clicked(const QModelIndex &index)
{
    QString jointID = index.data().toString();
    NBJoint* obj =(NBJointDistance*)(NBDataMnger::the()->layer.getNBJoint(jointID.toStdString()));
    if(obj==nullptr){
        return;
    }
    ui->openGLWidget->setEditNBObject(obj);
    updateJointList();
    updateAtt(obj);
}

void MainWindow::on_actionCreate_Unit_triggered()
{
    NBDataMnger::the()->layer.create(B2Physx::the()->world);
}

void MainWindow::on_actionExport_Unit_triggered()
{
    QString fileName = QFileDialog::getSaveFileName();
    NBDataMnger::the()->layer.write(fileName);
}

void MainWindow::on_actionImport_Unit_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();
    NBDataMnger::the()->layer.read(fileName);
    updateAllList();
}

void MainWindow::on_treeWidget_Layer_clicked(const QModelIndex &index)
{
    QTreeWidgetItem item;
}

void MainWindow::on_listWidget_Fixtures_clicked(const QModelIndex &index)
{
    currentFID = ui->listWidget_Fixtures->currentItem()->text();
    NBFixture* obj = NBDataMnger::the()->layer.getNBFixture(currentRID,currentFID)->toFixture();
    if(!obj){
        return;
    }
    updateFixtureList(currentRID);
    updateAtt(obj);
    ui->openGLWidget->setEditNBObject(obj);
}

void MainWindow::on_listWidget_Joint_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* item = ui->listWidget_Joint->itemAt(pos);
    if(item){
        QMenu* popMenu = new QMenu(this);
        popMenu->addAction(tr("delete"));
        QAction* action = popMenu->exec(QCursor::pos());
        qDebug()<<__FUNCTION__<<__LINE__<< action->text();
        if(action->text() == "delete"){
            NBDataMnger::the()->layer.delJoint(item->text().toStdString());
        }
        updateJointList();
    }
}

void MainWindow::on_listWidget_Shape_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* item = ui->listWidget_Shape->itemAt(pos);
    if(item){
        QMenu* popMenu = new QMenu(this);
        popMenu->addAction("edit");
        popMenu->addAction("delete");
        QAction* action = popMenu->exec(QCursor::pos());
        if(!action){
            return;
        }
        if(action->text() == "edit"){
            b2Shape* shape = NBDataMnger::the()->getShape(item->text());
            editShape(shape);
        }
        if(action->text() == "delete"){
            NBDataMnger::the()->delShape(item->text());
            updateFixtureList(currentRID);
        }
    }
}

void MainWindow::on_actionTest_read_triggered()
{
    ///test code
    B2ObjFactory::the()->setWorld(B2Physx::the()->world);
    B2ObjFactory::the()->loadUnitFromFile("test","walker.xml");
    B2ObjFactory::the()->createUnitImp("test",b2Transform(b2Vec2(5,0),b2Rot(1)));
    this->update();
}
