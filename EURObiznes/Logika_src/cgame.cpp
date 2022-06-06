#include "Logika_h/cgame.h"





CGame::CGame()
{
    plansza_ = new CPlansza;
}





CGame::~CGame()
{
    delete lbGraczy_;
    delete kwotaPocz_;

    // czyszczenie kolejek
    CGame::usunGraczy();
    CGame::usunPrzegranych();

    gracze_.clear();
    przegrani_.clear();

    delete plansza_;
}





// -----> Czy to potrzebne?
void CGame::utworzGre(int lbGraczy, int kwotaPocz, int pensja)
{
    plansza_->ustawPensjeStart(pensja);

    lbGraczy_ = new int;
    kwotaPocz_ = new int;

    *lbGraczy_ = lbGraczy;
    *kwotaPocz_ = kwotaPocz;
}





void CGame::utworzGre(int kwotaPocz, int pensja)
{
    plansza_->ustawPensjeStart(pensja);
    *kwotaPocz_ = kwotaPocz;
}





void CGame::wczytajPolaZPliku(string nazPli)
{
    ifstream plik(nazPli.c_str());
    deque<string> daneZPliku;
    string tmp;

    // <----------> Wczytywanie danych z pliku <---------->
    if(plik.is_open())
    {
        while (!plik.eof())
        {
            getline(plik, tmp);
            daneZPliku.push_back(tmp);
        }
    }
    else
    {
        // -----> możliwe, że tu też przyda się wyjątek
    }

    plik.close();
    // <----------> Koniec wczytywania <---------->

    plansza_->wczytajDaneZPliku_pola(daneZPliku);
}





void CGame::wczytajPolaZPliku(deque<string> &daneZPliku)
{
    plansza_->wczytajDaneZPliku_pola(daneZPliku);
}





void CGame::wczytajKartyZPliku(deque<std::string> &daneZPliku)
{
    plansza_->wczytajDaneZPliku_karty(daneZPliku);
}





void CGame::utworzCz(SDnGracza dane)
{
    dane.portfel = *kwotaPocz_;
    dane.id = gracze_.size();
    gracze_.push_back(new CCzlowiek(dane));
}





void CGame::utworzKomp(SDnGracza dane)
{
    gracze_.push_back(new CKomputer(dane));
}





void CGame::aktualDnPocz(int kwotaPocz, int pensja)
{
    utworzGre(kwotaPocz, pensja);

    int size = gracze_.size();

    if(size != 0)
        for(int i = 0; i < size; i++)
            gracze_.at(i)->ustawPortfel(*kwotaPocz_);
}





void CGame::utworzKolejke()
{
    int size = gracze_.size();
    int randIndex = 0;
    CGracz *tmpCGracz;

    // jeśli będzie tylko jeden element w liście gracze_, nie nastąpi mieszanie
    if(size > 1)
    {
        for(int i = 0; i < (size - 1); i++)
        {
            srand(time(NULL));
            randIndex = rand() % (size - i) + i;

            tmpCGracz = gracze_.at(i);
            gracze_.at(i) = gracze_.at(randIndex);
            gracze_.at(randIndex) = tmpCGracz;
        }
    }
}





bool CGame::wypelnienieKolejkiGraczy()
{
    if((int)gracze_.size() == *lbGraczy_)
        return true;
    else
        return false;
}





void CGame::nowePole(int rodz, SDnPoczPola dane)
{
    switch (rodz)
    {
    case 0:
        plansza_->zamienNaCPoleSpec(dane);
        break;

    case 1:
        plansza_->zamienNaCPoleStnd(dane);
        break;

    case 2:
        plansza_->zamienNaCPoleEkstra(dane);
        break;

    case 4:
        plansza_->zamienNaCPoleKasa(dane);
        break;

    case 5:
        plansza_->zamienNaCPoleSzansa(dane);
        break;

    default:
        return;
    }
}





void CGame::nastepny()
{
    CGracz *tmpCGracz;

    tmpCGracz = gracze_.at(0);
    gracze_.pop_front();
    gracze_.push_back(tmpCGracz);
}





string CGame::identGracza()
{
    return gracze_.at(0)->przedstawSie();
}





string CGame::identGracza(int parId)
{
    int size = gracze_.size();
    int licz = 0;

    do
    {
        if(gracze_.at(licz)->podajId() == parId)
        {
            return gracze_.at(licz)->przedstawSie();
        }

        licz++;

    }   while(licz < size);

    return "ERROR!";
}





bool CGame::czyOstatniGrajacy()
{
    if((int)gracze_.size() < 2)
        return true;
    else
        return false;
}





bool CGame::czyPierwszyZKolejki()
{
    if(gracze_.at(0)->podajId() == 0)
        return true;
    else
        return false;
}





bool CGame::czyUwieziony()
{
    SWynAkcji tmp = podajPozGracza();

    if(tmp.y1 == P_WIEZIENIE)
        return true;
    else
        return false;
}





bool CGame::czyGraczMaKartyWolnosc()
{
    if(gracze_.at(0)->podajLbKartWolnosc() > 0)
        return true;
    else
        return false;
}





bool CGame::czyGraczaStacNaZakupPola()
{
    if(gracze_.at(0)->podajStanKonta() >= plansza_->podajCenePola(gracze_.at(0)->podajAktPoz()))
        return true;
    else
        return false;
}





bool CGame::czyGraczaStacNaCzynsz()
{
    if(gracze_.at(0)->podajStanKonta() >= plansza_->daneIntPola(gracze_.at(0)->podajAktPoz(), 3))
        return true;
    else
        return false;
}





bool CGame::czyGraczaStacNaZaplate(int kwota)
{
    if(gracze_.at(0)->podajStanKonta() >= kwota)
        return true;
    else
        return false;
}





// -----> Czy to potrzebne?
SWynAkcji CGame::graczStajeNaPolu()
{                
    gracze_.at(0)->aktualPozycje();
    return plansza_->identPole(gracze_.at(0), gracze_.at(0)->podajAktPoz());
}





SWynAkcji CGame::graczStajeNaPolu(int poz)
{
    return plansza_->identPole(gracze_.at(0), poz);
}





void CGame::graczZmieniaPole(int lbKrokow)
{
    gracze_.at(0)->ruch(lbKrokow);
    gracze_.at(0)->aktualPozycje();
}





int CGame::graczDecyduje(SWynAkcji wynik, int poz, int kolor)
{
    // parametr opt == 1 w metodzie daneIntPola wskazuje, że zwraca ona wartość ceny pola na pozycji poz
    return gracze_.at(0)->decyduj(wynik.y2, plansza_->daneIntPola(poz, 1), gracze_.at(0)->podajLbPolKol(kolor));
}





SWynAkcji CGame::graczRzuca()
{        
    return gracze_.at(0)->rzucKoscmi();
}





void CGame::graczKupuje()
{
    plansza_->kupowaniePola(gracze_.at(0), gracze_.at(0)->podajAktPoz());
}





void CGame::graczBuduje(int poz)
{
    plansza_->zabuduj(poz);
}





void CGame::graczZastawia(int poz)
{
    plansza_->zastaw(poz);
}





void CGame::graczWykupuje(int poz)
{
    plansza_->wykup(poz);
}





void CGame::graczPlaciCzynsz()
{
    int czynsz = plansza_->daneIntPola(gracze_.at(0)->podajAktPoz(), 3);
    gracze_.at(0)->aktualPortfel(-czynsz);
    plansza_->ktoMaPole(gracze_.at(0)->podajAktPoz())->aktualPortfel(czynsz);
}





void CGame::graczZarabia(int kwota)
{
    gracze_.at(0)->aktualPortfel(kwota);
}





void CGame::graczPobieraPensje()
{
    gracze_.at(0)->aktualPortfel(plansza_->podajPensje());
}





SDnKarty CGame::graczLosujeKarte()
{
    SDnKarty karta = plansza_->losowanieKarty();

    if(karta.rodzaj == 3)
        gracze_.at(0)->dodajKarteWolnosc();

    return karta;
}





void CGame::graczUzywaKartyWolnosc()
{
    gracze_.at(0)->uzyjWolnosc();
}





void CGame::aresztuj()
{
    gracze_.at(0)->idzDoWiezienia();
}





void CGame::uwolnij()
{
    gracze_.at(0)->wyjdzZWiezienia();
}





bool CGame::sprawdzPortfel()
{
    if(gracze_.at(0)->podajStanKonta() >= 0)
        return true;
    else
        return false;;
}





bool CGame::sprawdzPortfel(int kwota)
{
    if(gracze_.at(0)->podajStanKonta() >= kwota)
        return true;
    else
        return false;
}





int CGame::podajKwotePocz()
{
    return *kwotaPocz_;
}





int CGame::podAktLbGraczy()
{
    return gracze_.size();
}





string CGame::podajWlascicielaPola(int poz)
{
    return plansza_->ktoMaPole(poz)->podajNick();
}





int CGame::podajKontoGr()
{
    return gracze_.at(0)->podajStanKonta();
}





int CGame::podajLbKartWolnosc()
{
    return gracze_.at(0)->podajLbKartWolnosc();
}





SWynAkcji CGame::podajPozGracza()
{
    return gracze_.at(0)->podajPoz();
}





SDnGracza CGame::podajDaneGracza()
{
    return gracze_.at(0)->podajDane();
}





deque<SDnPola> CGame::podajDanePol()
{
    return plansza_->zbierzDnPol();
}





deque<SDnPola> CGame::podajDanePolGracza()
{
    return plansza_->zbierzDnPol(gracze_.at(0));
}





SDnPola CGame::podajDanePola(int poz)
{
    return plansza_->zbierzDnPola(poz);
}





void CGame::usunGraczy()
{
    int licz = gracze_.size();

    for(int i = 0; i < licz; i++)
    {
        delete gracze_.at(i);
    }
}





void CGame::usunPrzegranych()
{
    int licz = przegrani_.size();

    for(int i = 0; i < licz; i++)
    {
        delete przegrani_.at(i);
    }
}
