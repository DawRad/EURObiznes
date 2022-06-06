#include "ngplansza.h"
#include "ui_ngplansza.h"





NGPlansza::NGPlansza(CGame *wskGry, deque<CRysPole *> *pola, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NGPlansza)
{
    ui->setupUi(this);

    wskGry_ = wskGry;

    wskDeqPol_ = pola;

    // początkowe sprawdzenie cbRodzaj
    dostosujDoCBRodzaj(ui->cbRodzaj->currentText());

    // graphics view
    scene_ = new QGraphicsScene(this);
    ui->gvPola->setScene(scene_);
    ui->gvPola->setRenderHint(QPainter::Antialiasing);
    scene_->setBackgroundBrush(QPixmap(":/Zasoby/grafika/tla/drewno_5.jpg"));

    scene_->addItem(wskDeqPol_->front());
    ui->lbPoz->setText("Pozycja " + wskDeqPol_->at(0)->podajPozQStr());

    sceneKolor_ = new QGraphicsScene(this);
    ui->gvKolor->setScene(sceneKolor_);
    ui->gvKolor->setRenderHint(QPainter::Antialiasing);
    QString kolor = ui->cbKolor->currentText();
    dostosujKolor(kolor);

    setInputObjectsDisabled();
}





NGPlansza::~NGPlansza()
{
    // "odczepienie" rysunków od sceny
    removeItemsFromScene();

    delete scene_;
    delete sceneKolor_;

    delete ui;
}





int NGPlansza::odczytajKolor(const QString &kolor)
{
    if(kolor == "akwamaryna")
        return KOL_AKWAMAR;
    else if(kolor == "czerwony")
        return KOL_CZER;
    else if(kolor == "fioletowy")
        return KOL_FIOL;
    else if(kolor == "granatowy")
        return KOL_GRANAT;
    else if(kolor == "miętowy")
        return KOL_MIETA;
    else if(kolor == "oliwkowy")
        return KOL_OLIW;
    else if(kolor == "pomarańczowy")
        return KOL_POMAR;
    else
        return KOL_CZARNY;
}





void NGPlansza::dostosujDoCBRodzaj(const QString &arg1)
{
    if(arg1 == "Szansa")
    {
        ui->leNazwa->setEnabled(true);
        ui->leCena->setEnabled(false);
        ui->leCenaApart->setEnabled(false);
        ui->leCenaHot->setEnabled(false);
        ui->leCzynsz->setEnabled(false);
        ui->leHipoteka->setEnabled(false);

        ui->cbKolor->setEnabled(false);
    }
    else if(arg1 == "Kasa")
    {
        ui->leNazwa->setEnabled(true);
        ui->leCena->setEnabled(true);
        ui->leCenaApart->setEnabled(false);
        ui->leCenaHot->setEnabled(false);
        ui->leCzynsz->setEnabled(false);
        ui->leHipoteka->setEnabled(false);

        ui->cbKolor->setEnabled(false);

        ui->lbKwota->clear();
        ui->lbKwota->setText("Kwota:");
    }
    else if(arg1 == "Standardowe")
    {
        ui->leNazwa->setEnabled(true);
        ui->leCena->setEnabled(true);
        ui->leCenaApart->setEnabled(true);
        ui->leCenaHot->setEnabled(true);
        ui->leCzynsz->setEnabled(true);
        ui->leHipoteka->setEnabled(true);

        ui->cbKolor->setEnabled(true);

        //ui->lbKwota->clear();
        ui->lbKwota->setText("Cena:");
    }
    else if(arg1 == "Specjalne")
    {
        ui->leNazwa->setEnabled(true);
        ui->leCena->setEnabled(true);
        ui->leCenaApart->setEnabled(false);
        ui->leCenaHot->setEnabled(false);
        ui->leCzynsz->setEnabled(true);
        ui->leHipoteka->setEnabled(true);

        ui->cbKolor->setEnabled(false);

        //ui->lbKwota->clear();
        ui->lbKwota->setText("Cena:");
    }
    else if(arg1 == "Ekstra")
    {
        ui->leNazwa->setEnabled(true);
        ui->leCena->setEnabled(true);
        ui->leCenaApart->setEnabled(false);
        ui->leCenaHot->setEnabled(false);
        ui->leCzynsz->setEnabled(true);
        ui->leHipoteka->setEnabled(true);

        ui->cbKolor->setEnabled(false);

        //ui->lbKwota->clear();
        ui->lbKwota->setText("Cena:");
    }
}





void NGPlansza::dostosujKolor(const QString &arg1)
{
    ui->gvKolor->setBackgroundBrush(QBrush(CRys::colorIntToQCol(odczytajKolor(arg1))));
}





void NGPlansza::setInputObjectsEnabled()
{
    ui->cbRodzaj->setEnabled(true);
    ui->leNazwa->setEnabled(true);
    ui->leCena->setEnabled(true);
    ui->leCzynsz->setEnabled(true);
    ui->leHipoteka->setEnabled(true);
    ui->cbKolor->setEnabled(true);
    ui->leCenaApart->setEnabled(true);
    ui->leCenaHot->setEnabled(true);
    ui->pbDodPole->setEnabled(true);
}





void NGPlansza::setInputObjectsDisabled()
{
    ui->cbRodzaj->setEnabled(false);
    ui->leNazwa->setEnabled(false);
    ui->leCena->setEnabled(false);
    ui->leCzynsz->setEnabled(false);
    ui->leHipoteka->setEnabled(false);
    ui->cbKolor->setEnabled(false);
    ui->leCenaApart->setEnabled(false);
    ui->leCenaHot->setEnabled(false);
    ui->pbDodPole->setEnabled(false);
}





void NGPlansza::removeItemsFromScene()
{
    QList<QGraphicsItem *> items = scene_->items();

    for(int i = 0; i < items.size(); i++)
        scene_->removeItem(items.at(i));
}





void NGPlansza::on_cbRodzaj_currentTextChanged(const QString &arg1)
{
    dostosujDoCBRodzaj(arg1);
}





void NGPlansza::on_pbDodPole_clicked()
{
    SDnPoczPola dane;
    dane.poz = wskDeqPol_->at(0)->podajPozInt();
    dane.nazwa = ui->leNazwa->text().toStdString();
    if(ui->cbRodzaj->currentText() == "Szansa")
    {
        // tworzenie pola Szansa                
        wskGry_->nowePole(5, dane);
        CAdministratorCRys::zamienNaCRysPolaSzansa(wskDeqPol_, wskGry_->podajDanePola(dane.poz), scene_);
    }
    else if(ui->cbRodzaj->currentText() == "Kasa")
    {
        // tworzenie pola Kasa
        dane.kwota = ui->leCena->text().toInt();
        wskGry_->nowePole(4, dane);
        CAdministratorCRys::zamienNaCRysPolaKasa(wskDeqPol_, wskGry_->podajDanePola(dane.poz), scene_);
    }
    else if(ui->cbRodzaj->currentText() == "Standardowe")
    {
        // tworzenie pola Standardowego
        dane.kwota = ui->leCena->text().toInt();
        dane.czynsz = ui->leCzynsz->text().toInt();
        dane.hipoteka = ui->leHipoteka->text().toInt();
        dane.kolor = odczytajKolor(ui->cbKolor->currentText());
        dane.cenaAp = ui->leCenaApart->text().toInt();
        dane.cenaHot = ui->leCenaHot->text().toInt();
        wskGry_->nowePole(1, dane);
        CAdministratorCRys::zamienNaCRysPolaStnd(wskDeqPol_, wskGry_->podajDanePola(dane.poz), scene_);
    }
    else if(ui->cbRodzaj->currentText() == "Specjalne")
    {
        // tworzenie pola specjalnego
    }
    else if(ui->cbRodzaj->currentText() == "Ekstra")
    {
        // tworzenie pola ekstra
    }

    scene_->addItem(wskDeqPol_->at(0));
}



void NGPlansza::on_pbWstecz_clicked()
{
    CRysPole *tmpPole = wskDeqPol_->back();
    wskDeqPol_->pop_back();
    wskDeqPol_->push_front(tmpPole);   

    QString poz = wskDeqPol_->at(0)->podajPozQStr();
    if(poz == "0" || poz =="6" || poz == "12" || poz =="18" || poz =="24")
    {
        setInputObjectsDisabled();
    }
    else
    {
        ui->cbRodzaj->setEnabled(true);
        ui->pbDodPole->setEnabled(true);
        dostosujDoCBRodzaj(ui->cbRodzaj->currentText());
    }
    scene_->removeItem(wskDeqPol_->at(1));
    scene_->addItem(wskDeqPol_->at(0));
    ui->lbPoz->setText("Pozycja " + poz);
}




void NGPlansza::on_pbDalej_clicked()
{
    CRysPole *tmpPole = wskDeqPol_->front();
    wskDeqPol_->pop_front();
    wskDeqPol_->push_back(tmpPole);

    QString poz = wskDeqPol_->at(0)->podajPozQStr();
    if(poz == "0" || poz =="6" || poz == "12" || poz =="18" || poz =="24")
    {
        setInputObjectsDisabled();
    }
    else
    {
        ui->cbRodzaj->setEnabled(true);
        ui->pbDodPole->setEnabled(true);
        dostosujDoCBRodzaj(ui->cbRodzaj->currentText());
    }

    scene_->removeItem(wskDeqPol_->back());
    scene_->addItem(wskDeqPol_->at(0));

    ui->lbPoz->setText("Pozycja " + wskDeqPol_->at(0)->podajPozQStr());
}





void NGPlansza::on_pbGraj_clicked()
{
    emit dalej();
}





void NGPlansza::on_cbKolor_currentTextChanged(const QString &arg1)
{
    dostosujKolor(arg1);
}

