#include "nggracze.h"
#include "ui_nggracze.h"

NGGracze::NGGracze(CGame *gra, deque<CRysPionek *> *pionki, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NGGracze)
{
    ui->setupUi(this);

    wskGry_ = gra;

    pionki_ = pionki;

    // wypelnienie opcji do wyboru
    ksztalty_.push_back(0);
    ksztalty_.push_back(1);

    symbole_.push_back(0);
    symbole_.push_back(1);
    symbole_.push_back(2);
    symbole_.push_back(3);

    koloryPionow_.push_back(KOL_CZER);
    koloryPionow_.push_back(KOL_NIEB);
    koloryPionow_.push_back(KOL_ZIEL);
    koloryPionow_.push_back(KOL_ZOLTY);
    koloryPionow_.push_back(KOL_ROZ);

    // QGraphicsView
    scene_ = new QGraphicsScene(this);

    //ui->gvPionek = new QGraphicsView(this);
    ui->gvPionek->setScene(scene_);
    ui->gvPionek->setRenderHint(QPainter::Antialiasing);

    pionki_->push_back(new CRysPionek(TOPLEFT_PIONA_WYBOR, WYM_PIONA_WYBOR, ksztalty_.at(0), symbole_.at(0), koloryPionow_.at(0)));
    wskAktPionu_ = pionki_->at(0);

    scene_->addItem(pionki_->at(0));
}

NGGracze::~NGGracze()
{
    // "odczepienie" stworzonych pionków od sceny
    removingItemsFromScene();

    // usuwanie sceny
    delete scene_;

    // czyszczenie deques
    ksztalty_.clear();
    symbole_.clear();
    koloryPionow_.clear();
    koloryUzyte_.clear();

    delete ui;
}





void NGGracze::removingItemsFromScene()
{
    /*
    int size = pionki_->size();

    for(int i = 0; i < size; i++)
        scene_->removeItem(pionki_->at(i));

    */

    QList<QGraphicsItem *> sceneItems = scene_->items();
    int size = sceneItems.size();
    for(int i = 0; i < size; i++)
        scene_->removeItem(sceneItems.at(i));
}





void NGGracze::dequeIntPrzod(deque<int> &kolejka)
{
    int tmp = kolejka.at(0);
    kolejka.pop_front();
    kolejka.push_back(tmp);
}





void NGGracze::dequeIntTyl(deque<int> &kolejka)
{
    int tmp = kolejka.back();
    kolejka.pop_back();
    kolejka.push_front(tmp);
}





void NGGracze::dequeCRysPionekPrzod(deque<CRysPionek *> &pionki)
{
    CRysPionek *tmp = pionki.at(0);
    pionki.pop_front();
    pionki.push_back(tmp);
}





void NGGracze::dequeCRysPionekTyl(deque<CRysPionek *> &pionki)
{
    CRysPionek *tmp = pionki.back();
    pionki.pop_back();
    pionki.push_front(tmp);
}





void NGGracze::on_pbOknoWstecz_clicked()
{    
    emit wstecz();
}





void NGGracze::on_pbDodGr_clicked()
{
    if(ui->cbRodzaj->currentIndex() == 0)
    {
        SDnGracza dane;
        dane.nick = ui->leNick->text().toStdString();

        wskGry_->utworzCz(dane);

        int tmp = koloryPionow_.at(0);
        koloryPionow_.pop_front();
        koloryUzyte_.push_front(tmp);                

        if(wskGry_->wypelnienieKolejkiGraczy())
        {
            ui->pbDodGr->setEnabled(false);
            ui->pbDalej_4->setEnabled(true);

        }
        else
        {
            pionki_->push_back(new CRysPionek(TOPLEFT_PIONA_WYBOR, WYM_PIONA_WYBOR, ksztalty_.at(0), symbole_.at(0), koloryPionow_.at(0)));
            wskAktPionu_ = pionki_->back();
            scene_->removeItem(*(pionki_->crbegin() + 1));
            scene_->addItem(pionki_->back());
            ui->leNick->clear();
        }
    }
    else
    {
        //
    }    
}





void NGGracze::on_pbDalej_clicked()
{
    int tmp = ksztalty_.at(0);
    ksztalty_.pop_front();
    ksztalty_.push_back(tmp);

    pionki_->back()->setShape(ksztalty_.at(0));
    pionki_->back()->update();
}





void NGGracze::on_pbWstecz_clicked()
{
    int tmp = ksztalty_.back();
    ksztalty_.pop_back();
    ksztalty_.push_front(tmp);

    pionki_->back()->setShape(ksztalty_.at(0));
    pionki_->back()->update();
}





void NGGracze::on_pbDalej_2_clicked()
{
    int tmp = symbole_.at(0);
    symbole_.pop_front();
    symbole_.push_back(tmp);

    pionki_->back()->setInnerShape(symbole_.at(0));
    pionki_->back()->update();
}





void NGGracze::on_pbWstecz_2_clicked()
{
    int tmp = symbole_.back();
    symbole_.pop_back();
    symbole_.push_front(tmp);

    pionki_->back()->setInnerShape(symbole_.at(0));
    pionki_->back()->update();
}





void NGGracze::on_pbDalej_3_clicked()
{
    int tmp = koloryPionow_.at(0);
    koloryPionow_.pop_front();
    koloryPionow_.push_back(tmp);

    pionki_->back()->setKolor(koloryPionow_.at(0));
    pionki_->back()->update();
}





void NGGracze::on_pbWstecz_3_clicked()
{
    int tmp = koloryPionow_.back();
    koloryPionow_.pop_back();
    koloryPionow_.push_front(tmp);

    pionki_->back()->setKolor(koloryPionow_.at(0));
    pionki_->back()->update();
}





void NGGracze::on_pbDalej_4_clicked()
{
    emit dalej();
}

