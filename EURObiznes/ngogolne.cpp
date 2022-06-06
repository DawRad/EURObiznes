#include "ngogolne.h"
#include "ui_ngogolne.h"





NGOgolne::NGOgolne(CGame *gra, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NGOgolne)
{
    ui->setupUi(this);

    wskGry_ = gra;    
}





NGOgolne::~NGOgolne()
{    
    delete ui;
}





void NGOgolne::on_pbWstecz_clicked()
{    
    emit wstecz();
}





void NGOgolne::on_pbDalej_clicked()
{                
    if(ui->cbLbGraczy->isEnabled())
    {
        wskGry_->utworzGre(ui->cbLbGraczy->currentText().toInt(), ui->leKwStartowa->text().toInt(), ui->lePensja->text().toInt());
        ui->cbLbGraczy->setEnabled(false);
    }
    else
        wskGry_->aktualDnPocz(ui->leKwStartowa->text().toInt(), ui->lePensja->text().toInt());

    emit dalej(ui->lePensja->text().toInt());
}
