#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include "Rysunki_h/cryspolespec.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);        

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // tworzenie pól tej klasy
    gra_ = new CGame();

    pionki_ = new deque<CRysPionek *>;

    pola_ = new deque<CRysPole *>;

    waluta_ = "PLN";

    zegarmistrzSwiatla_ = new QTimer;

    // początkowe ustawienie flag okna
    oknoOgolneCrtd_ = false;
    oknoGraczCrtd_ = false;
    oknoPlanszyCrtd_ = false;
    oknoRozgrywkiCrtd_ = false;

    endGame_ = new bool;
    *endGame_ = false;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // wczytywanie danych początkowych

    // dane pól z pliku
    deque<string> *danePol = pobierzDanePolZPliku(":/Zasoby/Pliki_z_danymi/Pola_nFormat.txt");
    gra_->wczytajPolaZPliku(*danePol);

    danePol->clear();
    delete danePol;

    // dane kart z pliku
    deque<string> *daneKart = pobierzDanePolZPliku(":/Zasoby/Pliki_z_danymi/Karty.txt");
    gra_->wczytajKartyZPliku(*daneKart);

    daneKart->clear();
    delete daneKart;

    // tworzenie rysunków pól wczytanych z pliku
    deque<SDnPola> *danePolDoRys = new deque<SDnPola>;
    *danePolDoRys = gra_->podajDanePol();
    utworzRysPol(danePolDoRys);

    danePolDoRys->clear();
    delete danePolDoRys;
}




MainWindow::~MainWindow()
{
    delete gra_;
    delete zegarmistrzSwiatla_;
    delete endGame_;

    delete nowaGraOgolne_;
    delete oknoGraczy_;
    delete oknoPlanszy_;
    delete oknoRozgrywki_;

    // usuwanie deques
    czyszczenieDeques();
    pionki_->clear();
    pola_->clear();

    delete pionki_;
    delete pola_;

    delete ui;
}





void MainWindow::utworzRysPol(deque<SDnPola> *danePol)
{
    int size = danePol->size();

    for(int i = 0; i < size; i++)
    {
        // tworzenie rysunku pola specjalnego lub ekstra
        if(danePol->at(i).rodz == 0 || danePol->at(i).rodz ==2)
            pola_->push_back(CAdministratorCRys::utworzRysPolaSpecZDnPol(danePol->at(i)));

        // tworzenie rysunku pola standardowego
        else if(danePol->at(i).rodz == 1)
            pola_->push_back(CAdministratorCRys::utworzRysPolaStndZDnPol(danePol->at(i)));

        // tworzenie rysunku pola "IDŹ DO WIĘZIENIA"
        else if(danePol->at(i).rodz == 3)
        {
            QString napis2 = "";
            pola_->push_back(CAdministratorCRys::utworzRysPola_PplusW_ZDnPol(danePol->at(i), napis2));
        }

        // tworzenie rysunku pola szansa
        else if(danePol->at(i).rodz == 5)
            pola_->push_back(CAdministratorCRys::utworzRysPolaSzansaZDnPol(danePol->at(i)));

        // tworzenie rysunku pola "PARKING"
        else if(danePol->at(i).rodz == 6 && danePol->at(i).poz == 12)
        {
            QString napis2 = "PARKING";
            pola_->push_back(CAdministratorCRys::utworzRysPola_PplusW_ZDnPol(danePol->at(i), napis2));
        }

        // tworzenie rysunku pola "START"
        else if(danePol->at(i).rodz == 4 && danePol->at(i).poz == 0)
            pola_->push_back(CAdministratorCRys::utworzRysPolaStartZDnPol(danePol->at(i), waluta_));

        // tworzenie rysunku pola kasa nie będącego polem "START"
        else if(danePol->at(i).rodz == 4 && danePol->at(i).poz != 0)
            pola_->push_back(CAdministratorCRys::utworzRysPolaKasaZDnPol(danePol->at(i)));

        // tworzenie rysunku pola "ODWIEDZINY"
        else if (danePol->at(i).poz == 6)
            pola_->push_back(CAdministratorCRys::utworzRysPolaRogZDnPol(danePol->at(i)));

        // tworzenie rysunku pola "WIĘZIENIE"
        else if(danePol->at(i).poz == 24)
            pola_->push_back(CAdministratorCRys::utworzRysPolaObrazZDnPol(danePol->at(i)));

        // tworzenie rysunku pola ERROR - na wszelki wypadek
        else
            pola_->push_back(CAdministratorCRys::utworzRysPolaZErroremZDnPol(danePol->at(i)));
    }
}





deque<string> *MainWindow::pobierzDanePolZPliku(QString nazPli)
{
    QFile file(nazPli);
    deque<string> *wynik = new deque<string>;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //ui->lwKomunikat->addItem("Błąd pliku");
    }

    else
    {
        QTextStream in(&file);
        QString tmp;

        tmp = in.readLine();

        while (!tmp.isNull() && !in.atEnd())
        {
            wynik->push_back(tmp.toStdString());
            tmp = in.readLine();
        }
    }


    file.close();
    return wynik;
}






void MainWindow::czyszczenieDeques()
{
    // czyszczenie deque pionków
    int size = pionki_->size();

    for(int i = 0; i < size; i++)
        delete  pionki_->at(i);

    // czyszczenie deque rysunków pól
    size = pola_->size();

    for(int i = 0; i < size; i++)
        delete pola_->at(i);
}





void MainWindow::on_pbNowaGra_clicked()
{   
    if(!oknoOgolneCrtd_)
    {
        nowaGraOgolne_ = new NGOgolne(gra_, this);
        connect(nowaGraOgolne_, SIGNAL(wstecz()), this, SLOT(pokazSie()));
        connect(nowaGraOgolne_, SIGNAL(dalej(int)), this, SLOT(oknoOgolneDalej(int)));
        oknoOgolneCrtd_ = true;
    }

    this->hide();
    nowaGraOgolne_->show();
}




void MainWindow::pokazSie()
{
    nowaGraOgolne_->hide();
    this->show();
}




void MainWindow::oknoOgolneDalej(int kwota)
{
    if(!oknoGraczCrtd_)
    {
        oknoGraczy_ = new NGGracze(gra_, pionki_, this);
        connect(oknoGraczy_, SIGNAL(wstecz()), this, SLOT(oknoGraczyWstecz()));
        connect(oknoGraczy_, SIGNAL(dalej()), this, SLOT(oknoGraczyDalej()));
        oknoGraczCrtd_ = true;
    }

    CAdministratorCRys::aktualPensjeNaStart(pola_, kwota, waluta_);
    nowaGraOgolne_->hide();
    oknoGraczy_->show();
}




void MainWindow::oknoGraczyWstecz()
{
    oknoGraczy_->hide();
    nowaGraOgolne_->show();
}





void MainWindow::oknoGraczyDalej()
{
    if(!oknoPlanszyCrtd_)
    {
        oknoPlanszy_ = new NGPlansza(gra_, pola_, this);
        connect(oknoPlanszy_, SIGNAL(dalej()), this, SLOT(oknoPlanszyGraj()));
        oknoPlanszyCrtd_ = true;
    }

    oknoGraczy_->hide();
    oknoPlanszy_->show();
}





void MainWindow::oknoPlanszyGraj()
{
    if(!oknoRozgrywkiCrtd_)
    {
        oknoRozgrywki_ = new Rozgrywka(gra_, pola_, pionki_, endGame_, this);
        connect(oknoRozgrywki_, SIGNAL(destroyed()), this, SLOT(deleteLater()));
        oknoRozgrywkiCrtd_ = true;
    }

    delete oknoPlanszy_;
    oknoPlanszyCrtd_ = false;

    delete oknoGraczy_;
    oknoGraczCrtd_ = false;

    delete nowaGraOgolne_;
    oknoOgolneCrtd_ = false;

    oknoRozgrywki_->show();
}

