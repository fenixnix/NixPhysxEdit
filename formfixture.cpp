#include "formfixture.h"
#include "ui_formfixture.h"
#include "dialogshapecircleedit.h"
#include "dialogshapepolygonedit.h"

FormFixture::FormFixture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFixture)
{
    ui->setupUi(this);
}

FormFixture::~FormFixture()
{
    delete ui;
}

void FormFixture::setFixture(NBFixture *f)
{
    def = f;
    qDebug()<<__FUNCTION__<<__LINE__<<f->def.density;
    upload();
}

void FormFixture::upload()
{
    ui->friction->setValue(def->def.friction);
    ui->restitiution->setValue(def->def.restitution);
    ui->density->setValue(def->def.density);
    ui->isSencor->setChecked(def->def.isSensor);
    ui->filter->set(def->def.filter);
}

void FormFixture::download()
{
    def->def.friction = ui->friction->value();
    def->def.restitution = ui->restitiution->value();
    def->def.density = ui->density->value();
    def->def.isSensor = ui->isSencor->checkState();
    def->def.filter = ui->filter->get();
}

void FormFixture::on_buttonBox_accepted()
{
    download();
}

void FormFixture::on_pushButton_Shape_clicked()
{
    if(def->def.shape->GetType() == b2Shape::e_circle){
        DialogShapeCircleEdit edit;
        edit.set((b2Shape*)def->def.shape);
        edit.exec();
    }
    if(def->def.shape->GetType() == b2Shape::e_polygon){
        DialogShapePolygonEdit edit;
        edit.set((b2Shape*)def->def.shape);
        edit.exec();
    }
}
