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
    def2 = body;
    def = &body->def;
    upload();
}

void FormRigidBody::setB2Body(b2BodyDef *bodyDef)
{
    qDebug()<<__FUNCTION__;
    def = bodyDef;
    upload();
}

void FormRigidBody::upload()
{
    ui->type->setCurrentIndex(def->type);
    ui->x->setValue(def->position.x);
    ui->y->setValue(def->position.y);
    ui->angle->setValue(def->angle);
    ui->linearDamping->setValue(def->linearDamping);
    ui->angularDamping->setValue(def->angularDamping);
    ui->allowSleep->setChecked(def->allowSleep);
    ui->awake->setChecked(def->awake);
    ui->fixedRotation->setChecked(def->fixedRotation);
    ui->active->setChecked(def->active);
    ui->gravityScale->setValue(def->gravityScale);
}

void FormRigidBody::download()
{
    def->type = ((b2BodyType)ui->type->currentIndex());
    def->position.x = ui->x->value();
    def->position.y = ui->y->value();
    def->angle = ui->angle->value()*M_PI/180;
    def->linearDamping = ui->linearDamping->value();
    def->angularDamping = ui->angularDamping->value();
    def->allowSleep = ui->allowSleep->checkState();
    def->awake = ui->awake->checkState();
    def->fixedRotation = ui->fixedRotation->checkState();
    def->bullet = ui->bullet->checkState();
    def->active = ui->active->checkState();
    def->gravityScale = ui->gravityScale->value();
}

void FormRigidBody::on_pushButton_OK_clicked()
{
    download();
}
