#include "formrigidbody.h"
#include "ui_formrigidbody.h"
#define _USE_MATH_DEFINES
#include <math.h>

FormRigidBody::FormRigidBody(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRigidBody)
{
    ui->setupUi(this);
    def = nullptr;
}

FormRigidBody::~FormRigidBody()
{
    delete ui;
}

void FormRigidBody::setBody(NBBody *body)
{
    def = body;
    upload();
}

void FormRigidBody::upload()
{
    if(!def){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    ui->type->setCurrentIndex(def->def.type);
    ui->x->setValue(def->def.position.x);
    ui->y->setValue(def->def.position.y);
    ui->angle->setValue(def->def.angle);
    ui->linearDamping->setValue(def->def.linearDamping);
    ui->angularDamping->setValue(def->def.angularDamping);
    ui->allowSleep->setChecked(def->def.allowSleep);
    ui->awake->setChecked(def->def.awake);
    ui->fixedRotation->setChecked(def->def.fixedRotation);
    ui->active->setChecked(def->def.active);
    ui->gravityScale->setValue(def->def.gravityScale);
}

void FormRigidBody::download()
{
    if(!def){
        qDebug()<<__FUNCTION__<<__LINE__;
        return;
    }
    def->def.type = ((b2BodyType)ui->type->currentIndex());
    def->def.position.x = ui->x->value();
    def->def.position.y = ui->y->value();
    def->def.angle = ui->angle->value()*M_PI/180;
    def->def.linearDamping = ui->linearDamping->value();
    def->def.angularDamping = ui->angularDamping->value();
    def->def.allowSleep = ui->allowSleep->checkState();
    def->def.awake = ui->awake->checkState();
    def->def.fixedRotation = ui->fixedRotation->checkState();
    def->def.bullet = ui->bullet->checkState();
    def->def.active = ui->active->checkState();
    def->def.gravityScale = ui->gravityScale->value();
}

void FormRigidBody::on_pushButton_OK_clicked()
{
    download();
}
