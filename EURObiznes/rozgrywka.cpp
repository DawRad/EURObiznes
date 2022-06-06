#include "rozgrywka.h"
#include "ui_rozgrywka.h"





Rozgrywka::Rozgrywka(CGame *wskGry, deque<CRysPole *> *wskDeqPol, deque<CRysPionek *> *wskPionkow, bool *wskEndGame, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rozgrywka)
{
    ui->setupUi(this);       

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // tworzenie pól tej klasy

    timerPrime_ = new QTimer(this);
    timerInfo_ = new QTimer(this);

    wyzwalacz_ = new CNadawca();

    info_ = new CRysInfo();
    info_->setPos(INFO_SCENE_POS);


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // ustawianie wartości początkowych pól tej klasy
    wymiarA_ = 110;
    wymiarB_ = 176;
    wymiarPlanszy_ = 902;

    wskGry_ = wskGry;

    wskDeqPol_ = wskDeqPol;

    wskEndGame_ = wskEndGame;

    // przygotowuje parametry pól do wyrysowania, ale najpierw zapewnia, że pole o pozycji 0 jest na
    // początku kolejki
    CAdministratorCRys::przesunPolePozZeroNaPocz(wskDeqPol_);
    przygotujPolaDoRysowania();

    wskPionki_ = wskPionkow;
    int *size = new int;


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // tworzenie grafiki
    scenePlansza_ = new QGraphicsScene(this);
    ui->gvPlansza->setScene(scenePlansza_);
    ui->gvPlansza->setRenderHint(QPainter::Antialiasing);
    ui->gvPlansza->setResizeAnchor(QGraphicsView::AnchorViewCenter);

    scenePanelGracza_ = new QGraphicsScene(this);
    ui->gvPanelGracza->setScene(scenePanelGracza_);
    ui->gvPanelGracza->setRenderHint(QPainter::Antialiasing);

    // tła
//    QImage *image = new QImage(":/Zasoby/grafika/tla/tablica.jpg");
//    *image = image->scaled(ui->gvPanelGracza->size());
//    QBrush *brush = new QBrush(*image);

    ui->gvPanelGracza->setBackgroundBrush(QBrush(Q_KOL_TLO_PANEL_GR));

    scenePlansza_->setBackgroundBrush(QPixmap(":/Zasoby/grafika/tla/drewno_5.jpg"));
//    delete image;
//    delete brush;


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // ustawianie stanów początkowych przycisków
    ui->pbKup->setEnabled(false);
    ui->pbNastRunda->setEnabled(false);


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // rysowanie pól    
    *size = wskDeqPol_->size();

    for(int i = 0; i < *size; i++)
        scenePlansza_->addItem(wskDeqPol_->at(i));

    // pionki
    *size = wskPionki_->size();
    for(int i = 0; i < *size; i++)
    {
        wskPionki_->at(i)->setWskWyzw(wyzwalacz_);
        wskPionki_->at(i)->setTimer(timerPrime_);
        wskPionki_->at(i)->setPos(wskDeqPol_->at(0)->pos());
        wskPionki_->at(i)->setSize(QSizeF(0.35 * wymiarA_, 0.35 * wymiarA_));
        scenePlansza_->addItem(wskPionki_->at(i));
    }

    delete size;

    // kostki
    kostki_ = new deque<CRysKostki *>;
    for(int i = 0; i < 2; i++)
    {
        kostki_->push_front(new CRysKostki(QPoint(-0.25 * wymiarA_, -0.25 * wymiarA_), QSizeF(0.5 * wymiarA_, 0.5 * wymiarA_), timerPrime_,
                                           wyzwalacz_));
    }

    kostki_->at(0)->setPos(QPoint(0 - wymiarA_ / 4 - 10, 200));
    kostki_->at(0)->setPrimaryDice(true);           // pierwsza kostka ma wysyłać sygnał rzutWykonany()
    scenePlansza_->addItem(kostki_->at(0));

    kostki_->at(1)->setPos(QPoint(0 + wymiarA_ / 4 + 10, 200));
    scenePlansza_->addItem(kostki_->at(1));

    // panel gracza
    QSizeF *pGrSize = new QSizeF(0.98 * ui->gvPanelGracza->size().width(), 0.98 * ui->gvPanelGracza->size().height());
    SDnPionka *dnPionka = new SDnPionka;
    *dnPionka = wskPionki_->at(0)->podajSwojeSkladniki();
    dnPionka->size = WYM_PIONA_PAN_GR;
    dnPionka->topLeft = TOPLEFT_PIONA_PAN_GR;
    panelGracza_ = new CRysPanelGracza(QPoint(-(pGrSize->width()) / 2, -(pGrSize->height()) / 2), *pGrSize, *dnPionka, wskGry_->podajDaneGracza());
    scenePanelGracza_->addItem(panelGracza_);

    delete pGrSize;
    delete dnPionka;


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // łączenie wszelkiego rodzaju sygnałów i slotów
    connect(timerPrime_, &QTimer::timeout, scenePlansza_, &QGraphicsScene::advance);
    connect(timerInfo_, SIGNAL(timeout()), this, SLOT(usunInfo()));
    connect(wyzwalacz_, SIGNAL(rzutWykonany()), this, SLOT(rzutWykonany()));
    connect(wyzwalacz_, SIGNAL(pionSiePoruszyl(int,int)), this, SLOT(nastRuchPiona(int,int)));
    connect(wyzwalacz_, SIGNAL(pionDotarl()), this, SLOT(pionNaCelu()));
    connect(this, SIGNAL(zacznijTureGracza()), this, SLOT(turaGracza()));
}





Rozgrywka::~Rozgrywka()
{
    delete timerPrime_;
    delete timerInfo_;

    // usuwanie deques
    czyszczenieDeques();
    kostki_->clear();
    delete kostki_;

    delete oknoWlasnosci_;
    delete panelGracza_;
    delete info_;
    delete scenePlansza_;
    delete scenePanelGracza_;



    delete ui;
}





void Rozgrywka::przygotujPolaDoRysowania()
{
    int size = wskDeqPol_->size();

    ustawWymiaryPol(size);
    ustawPozPol(size);
}





void Rozgrywka::ustawPozPol(int size)
{
    QPoint polePos(wymiarPlanszy_ / 2 - wymiarB_ / 2, wymiarPlanszy_ / 2 - wymiarB_ / 2);

    for(int i = 0; i < size; i++)
    {
        // pozycja pola "START"
        if(i == 0)
        {
            wskDeqPol_->at(i)->setPos(polePos);
            polePos.setX(polePos.x() - wymiarB_ / 2 - wymiarA_ / 2);
        }

        else if(i > 0 && i < 6)
        {
            wskDeqPol_->at(i)->setPos(polePos);
            polePos.setX(polePos.x() - wymiarA_);
        }

        // pozycja pola "WIĘZIENIE"/"ODWIEDZINY"
        else if(i == 6)
        {
            polePos.setX(polePos.x() - (wymiarB_ / 2 - wymiarA_ / 2));
            wskDeqPol_->at(i)->setPos(polePos);
            polePos.setY(polePos.y() - wymiarB_ / 2 - wymiarA_ / 2);
        }

        else if(i > 6 && i < 12)
        {
            wskDeqPol_->at(i)->setPos(polePos);
            wskDeqPol_->at(i)->setRotation(90);
            polePos.setY(polePos.y() - wymiarA_);
        }

        // pozycja pola "PARKING"
        else if(i == 12)
        {
            polePos.setY(polePos.y() - (wymiarB_ / 2 - wymiarA_ / 2));
            wskDeqPol_->at(i)->setPos(polePos);
            polePos.setX(polePos.x() + wymiarB_ / 2 + wymiarA_ / 2);
        }

        else if(i > 12 && i < 18)
        {
            wskDeqPol_->at(i)->setPos(polePos);
            polePos.setX(polePos.x() + wymiarA_);
        }

        // pozycja pola "IDŹ DO WIĘZIENIA"
        else if(i == 18)
        {
            polePos.setX(polePos.x() + (wymiarB_ / 2 - wymiarA_ / 2));
            wskDeqPol_->at(i)->setPos(polePos);
            polePos.setY(polePos.y() + wymiarB_ / 2 + wymiarA_ / 2);
        }

        else if(i > 18 && i < 24)
        {
            wskDeqPol_->at(i)->setPos(polePos);
            wskDeqPol_->at(i)->setRotation(-90);
            polePos.setY(polePos.y() + wymiarA_);
        }

        // pozycja pola "WIĘZIENIE"
        else
        {
            polePos.setX(-wymiarPlanszy_ / 2 + 0.25 * wymiarB_ + 0.5 * 0.75 * wymiarB_);
            polePos.setY(wymiarPlanszy_ / 2 - 0.25 * wymiarB_ - 0.5 * 0.75 * wymiarB_);
            wskDeqPol_->at(i)->setPos(polePos);
        }
    }
}





void Rozgrywka::ustawWymiaryPol(int size)
{
    for(int i = 0; i < size; i++)
    {
        if(i == 0 || i == 12 || i == 18)
            wskDeqPol_->at(i)->setSize(QSizeF(wymiarB_, wymiarB_));

        else if(i == 6)
            wskDeqPol_->at(i)->setSizeWithOtherDimUpdate(QSizeF(wymiarB_, wymiarB_));

        else if(i == 24)
            wskDeqPol_->at(i)->setSize(QSizeF(0.75 * wymiarB_, 0.75 * wymiarB_));

        else
            wskDeqPol_->at(i)->setSize(QSizeF(wymiarA_, wymiarB_));
    }
}





void Rozgrywka::akcjaKartyKwoty(SDnKarty dane)
{
    if(dane.wartosc >= 0)
    {
        wskGry_->graczZarabia(dane.wartosc);        
    }
    else
    {
        // gracza nie stać na zapłatę kwoty
    }
    timerInfo_->start(CZAS_WYSW);
}





void Rozgrywka::akcjaKartyRuchu(SDnKarty dane)
{
    wskGry_->graczZmieniaPole(dane.wartosc);
    wskPionki_->at(0)->setPos(wskDeqPol_->at(wskGry_->podajPozGracza().y2)->pos());
    wskPionki_->at(0)->update();
    timerInfo_->start(CZAS_WYSW);

}





void Rozgrywka::akcjaKartyWiezienia()
{
    wskGry_->aresztuj();
    wskPionki_->at(0)->setPos(wskDeqPol_->at(wskGry_->podajPozGracza().y1)->pos());
    wskPionki_->at(0)->update();
    timerInfo_->start(CZAS_WYSW);
}





void Rozgrywka::akcjaKartyWolnosc()
{
    timerInfo_->start(CZAS_WYSW);
}





void Rozgrywka::czyszczenieDeques()
{
    int size = kostki_->size();

    for(int i = 0; i < size; i++)
        delete kostki_->at(i);
}





void Rozgrywka::on_pbNastRunda_clicked()
{    
    // pierwszy krok w kolejnej turze: zaktualizowanie kolejek graczy i rysunków
    wskGry_->nastepny();
    CAdministratorCRys::dequeCRysPionekPrzod(wskPionki_);
    panelGracza_->aktualizujPanel(wskPionki_->at(0)->podajSwojeSkladniki(), wskGry_->podajDaneGracza());
    panelGracza_->update();

    // drugi krok: sprawdzenie czy nie kończy się rozgrywka
    if(wskGry_->czyOstatniGrajacy())
    {
        // pozostał ostatni gracz, koniec gry
    }
    else
    {
        // są jeszcze inni gracze w grze
        if(wskGry_->czyPierwszyZKolejki())
        {
            // gracz pierwszy w kolejce, trzeba sprawdzić, czy nie upłynął czas rozgrywki
            if(*wskEndGame_)
            {
                // koniec gry
            }
            else
            {
                ui->pbNastRunda->setEnabled(false);
                ui->pbKostki->setEnabled(true);
                // gra trwa dalej, trzeba sprawdzić, czy gracz nie jest w więzieniu
                // emit zacznijTureGracza();
            }
        }
        else
        {
            // gra trwa dalej
            ui->pbNastRunda->setEnabled(false);
            ui->pbKostki->setEnabled(true);
        }
    }
}





void Rozgrywka::actionWyjscieClicked()
{

}





void Rozgrywka::rzutWykonany()
{   
    SWynAkcji tmp = wskGry_->podajPozGracza();
    if(wskGry_->czyUwieziony())
    {
        // gracz jest w więzieniu, trzeba sprawdzić, czy wyrzucił dublet
        if(tmp.y2 == P_ODWIEDZINY)
        {
            wskPionki_->at(0)->setPos(wskDeqPol_->at(P_ODWIEDZINY)->pos());
            wskPionki_->at(0)->update();
            wskGry_->uwolnij();
        }
        else if(wskGry_->czyGraczMaKartyWolnosc())
        {
            // jeśli nie wyrzucił dubletu, to sprawdzenie, czy może użyć karty "Wolność"
            ui->pbUwolnij->setEnabled(true);
        }
        ui->pbNastRunda->setEnabled(true);
    }
    else
    {
        if(tmp.y2 < tmp.y1)
        {
            // gracz przeszedł przez start, pobiera pensję
            wskGry_->graczPobieraPensje();
            panelGracza_->aktualNapisPortfel(wskGry_->podajKontoGr());
        }

        int nastPoz = CPlansza::ustalKolejnaPozWKolejce(tmp.y1, (int)wskDeqPol_->size() - 1);
        wskPionki_->at(0)->ustawParamRuchu(LB_KROKOW, wskDeqPol_->at(tmp.y1)->pos(), wskDeqPol_->at(nastPoz)->pos(), tmp.y2);

        timerPrime_->start(TIMER_INTERVAL);
    }
}





void Rozgrywka::nastRuchPiona(int aktPozPola, int nastPozPola)
{
    wskPionki_->at(0)->ustawParamRuchu(LB_KROKOW, wskDeqPol_->at(aktPozPola)->pos(), wskDeqPol_->at(nastPozPola)->pos());

    timerPrime_->start(TIMER_INTERVAL);
}




void Rozgrywka::pionNaCelu()
{        
    if(wskGry_->czyUwieziony())
    {
        // gracz jest uwięziony, nie może nic zrobić
        ui->pbNastRunda->setEnabled(true);
    }
    else
    {
        // gracz jest wolny, może podjąć akcje w zależności od pola, na które stanął
        panelGracza_->update();
        SWynAkcji idPola = wskGry_->graczStajeNaPolu();
        if((idPola.y1 == 0 || idPola.y1 == 1 || idPola.y1 ==2) && idPola.y2 == 0)
        {
            // pole bezpańskie, można kupować
            if(wskGry_->czyGraczaStacNaZakupPola())
            {
                ui->pbNastRunda->setEnabled(true);
                ui->pbKup->setEnabled(true);
            }
            else
            {
                // gracza nie stać na zakup
                ui->pbNastRunda->setEnabled(true);
            }
        }
        else if((idPola.y1 == 0 || idPola.y1 == 1 || idPola.y1 ==2) && idPola.y2 == 1)
        {
            // pole jest własnością innego gracza
            panelGracza_->aktualNapisPortfel(wskGry_->podajKontoGr());
            panelGracza_->update();
            ui->pbNastRunda->setEnabled(true);
        }
        else if(((idPola.y1 == 0 || idPola.y1 == 2) && idPola.y2 == 2) || ((idPola.y1 == 0 || idPola.y1 == 1 || idPola.y1 ==2) && idPola.y2 == 4) || idPola.y1 == 6)
        {
            // gracz nie może nic zrobić
            ui->pbNastRunda->setEnabled(true);
        }
        else if(idPola.y1 == 5)
        {
            // gracz stanął na polu "Szansa"
            aktKarta_ = wskGry_->graczLosujeKarte();
            info_->ustawText(aktKarta_.tresc);
            scenePlansza_->addItem(info_);
            switch (aktKarta_.rodzaj) {
            case 0:
                akcjaKartyKwoty(aktKarta_);
                break;

            case 1:
                akcjaKartyRuchu(aktKarta_);
                break;

            case 2:
                akcjaKartyWiezienia();
                break;

            case 3:
                akcjaKartyWolnosc();
                break;

            default:
                break;
            }                     
        }
        else
        {
            ui->pbNastRunda->setEnabled(true);
        }
    }
}





void Rozgrywka::turaGracza()
{

}





void Rozgrywka::usunInfo()
{
    scenePlansza_->removeItem(info_);
    timerInfo_->stop();
    ui->pbNastRunda->setEnabled(true);
    switch (aktKarta_.rodzaj)
    {
    case 0:
        panelGracza_->aktualNapisPortfel(wskGry_->podajKontoGr());
        break;

    case 1:
        pionNaCelu();
        wskPionki_->at(0)->zmienAktPoz(wskGry_->podajPozGracza().y1);
        break;

    case 2:
        break;

    case 3:
        panelGracza_->aktualNapislbKartWolnosc(wskGry_->podajLbKartWolnosc());
        break;

    default:
        return;
    }

    // w każdym przypadku, na końcu należy zaktualizować panel gracza
    panelGracza_->update();
}





void Rozgrywka::on_pbKostki_clicked()
{            
    SWynAkcji rzut = wskGry_->graczRzuca();

    kostki_->at(0)->ustawOczka(rzut.y1);
    kostki_->at(1)->ustawOczka(rzut.y2);

    timerPrime_->start(500);
    ui->pbKostki->setEnabled(false);
}






void Rozgrywka::on_pbUwolnij_clicked()
{
    wskGry_->graczUzywaKartyWolnosc();

    // poniższa metoda sama zmienia wartość liczby kart
    // "Wolność" gracza wyświetlanych na panelu, a także
    // aktualizuje rysunek na scenie
    panelGracza_->graczUzylKartyWolnosc();

    ui->pbUwolnij->setEnabled(false);
}


void Rozgrywka::on_pbKup_clicked()
{
    wskGry_->graczKupuje();
    panelGracza_->aktualNapisPortfel(wskGry_->podajKontoGr());
    panelGracza_->update();
    ui->pbKup->setEnabled(false);
}


void Rozgrywka::on_pbWlasnosci_clicked()
{
    oknoWlasnosci_ = new Wlasnosci(wskGry_, this);
    oknoWlasnosci_->show();
}

