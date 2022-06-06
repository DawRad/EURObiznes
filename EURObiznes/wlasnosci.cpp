#include "wlasnosci.h"
#include "ui_wlasnosci.h"





Wlasnosci::Wlasnosci(CGame *wskGry,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wlasnosci)
{
    ui->setupUi(this);

    // przypisanie wskaźnika gry
    wskGry_ = wskGry;

    // pobieranie danych pol gracza
    danePolGracza_ = wskGry_->podajDanePolGracza();

    // gv i scena
    scene_ = new QGraphicsScene(this);
    ui->gvPrzeglad->setScene(scene_);
    ui->gvPrzeglad->setRenderHint(QPainter::Antialiasing);

    if(danePolGracza_.size() == 0)
    {
        //
        ui->pbNast->setEnabled(false);
        ui->pbPoprz->setEnabled(false);
        ui->pbZastaw->setEnabled(false);
        ui->pbWykup->setEnabled(false);

        scene_->addText("Nie posiadasz jeszcze żadnych pól");
    }
    else
    {
        // tworzenie rysunków pól gracza
        rysunkiPol_ = CAdministratorCRys::utworzKolejkePol(danePolGracza_);

        // definicje iteratorów
        itPol_ = rysunkiPol_.begin();
        itDanychPol_ = danePolGracza_.begin();
        scene_->addItem(*itPol_);
        ui->lblInfo->setText("Pozycja " + QString::number(itDanychPol_->poz) + ": ");
    }
}





Wlasnosci::~Wlasnosci()
{
    CAdministratorCRys::wyczyscDequeCRysPole(&rysunkiPol_);

    delete scene_;

    delete ui;
}





void Wlasnosci::on_pbPoprz_clicked()
{
    scene_->removeItem(*itPol_);
    if(itPol_ == rysunkiPol_.begin())
        itPol_ = rysunkiPol_.end();

    itPol_--;       

    scene_->addItem(*itPol_);
    ui->lblInfo->setText("Pozycja " + QString::number(itDanychPol_->poz) + ": ");
}





void Wlasnosci::on_pbNast_clicked()
{
    scene_->removeItem(*itPol_);

    itPol_++;
    if(itPol_ == rysunkiPol_.end())
        itPol_ = rysunkiPol_.begin();

    scene_->addItem(*itPol_);
    ui->lblInfo->setText("Pozycja " + QString::number(itDanychPol_->poz) + ": ");
}

