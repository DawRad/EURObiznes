#include "Logika_h/cplansza.h"





CPlansza::CPlansza()
{

}

CPlansza::~CPlansza()
{
    CPlansza::usunKarty();
    CPlansza::usunKartyUzyte();
    CPlansza::usunPola();

    karty_.clear();
    kartyUzyte_.clear();
    pola_.clear();
    regiony_.clear();
}

// -----> funkcja CHYBA dokończona...
void CPlansza::wczytajDaneZPliku_pola(deque<string> &daneZPliku)
{
    int size = daneZPliku.size();
    int actIndex = 0, hEndIndex = 0;
    string content;
    SParsedElem actElem;

    while(actIndex < size)
    {
        actElem = parseElem(daneZPliku.at(actIndex));

        if(actElem.header == "pole")
        {
            hEndIndex = parseBound(daneZPliku, actElem.header, actIndex);
            actIndex++;

            actElem = parseElem(daneZPliku.at(actIndex));
            content = parseHeadCont(daneZPliku.at(actIndex), actElem.pocz);

            switch (changePoleRodz(content))
            {
                case 0:
                    utworzCPoleSpecZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                case 1:
                    utworzCPoleStndZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                case 2:
                    utworzCPoleEkstraZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                case 3:
                    utworzCPoleDoWiezieniaZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                case 4:
                    utworzCPoleKasaZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                case 5:
                    utworzCPoleSzansaZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                case 6:
                    utworzCPoleZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                default:
                    return;
            }
        }

        else if (actElem.header == "/pola_dane")
            return;

        actIndex = hEndIndex;
        actIndex++;
    }
}

void CPlansza::wczytajDaneZPliku_karty(deque<string> &daneZPliku)
{
    int size = daneZPliku.size();
    int actIndex = 0, hEndIndex = 0;
    string content;
    SParsedElem actElem;

    while(actIndex < size)
    {
        actElem = parseElem(daneZPliku.at(actIndex));

        if(actElem.header == "karta")
        {
            hEndIndex = parseBound(daneZPliku, actElem.header, actIndex);
            actIndex++;

            actElem = parseElem(daneZPliku.at(actIndex));
            content = parseHeadCont(daneZPliku.at(actIndex), actElem.pocz);

            switch (kartaRodzToInt(content))
            {
                case 0:
                    utworzCKartaKwotyZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                case 1:
                    utworzCKartaRuchuZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                case 2:
                    utworzCKartaWiezieniaZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                case 3:
                    utworzCKartaWolnoscZPliku(daneZPliku, actIndex, hEndIndex);
                    break;

                default:
                    return;
            }
        }

        else if (actElem.header == "/karty_dane")
            return;

        actIndex = hEndIndex;
        actIndex++;
    }
}

void CPlansza::sortujListePol()
{
    deque<CPole*> tmpList;
    CPole *tmpCPole;
    int minPozVal;
    int minPoz;
    int size = pola_.size();

    for(int i = 0; i < size; i++)
    {
        minPozVal = pola_.at(i)->podajDaneInt(0);
        minPoz = i;

        for(int j = i + 1; j < size; j++)
        {
            if(pola_.at(j)->podajDaneInt(0) < minPozVal)
            {
                minPozVal = pola_.at(j)->podajDaneInt(0);
                minPoz = j;
            }
        }

        tmpCPole = pola_.at(i);
        pola_.at(i) = pola_.at(minPoz);
        pola_.at(minPoz) = tmpCPole;
    }
}




void CPlansza::dodajPole(int rodz, SDnPoczPola dane)
{
    switch(rodz)
    {
    case 0:                                         // klasa CPoleSpec
        pola_.push_back(new CPoleSpec(dane));
        break;
    case 1:                                         // klasa CPoleStnd
        pola_.push_back(new CPoleStnd(dane));
        break;
    case 2:                                         // klasa CPoleEkstra
        pola_.push_back(new CPoleEkstra(dane));
        break;
    case 3:                                         // klasa CPoleDoWiezienia
        pola_.push_back(new CPoleDoWiezienia(dane));
        break;
    case 4:                                         // klasa CPoleKasa
        pola_.push_back(new CPoleKasa(dane));
        break;
    case 5:                                         // klasa CPoleSzansa
        pola_.push_back(new CPoleSzansa(dane));
        break;
    case 6:                                         // klasa CPole
        pola_.push_back(new CPole(dane));
        break;
    }
}





void CPlansza::ustawPensjeStart(int pensja)
{
    pensjaStart_ = pensja;
}





void CPlansza::zamienNaCPoleSzansa(SDnPoczPola dane)
{
    delete pola_.at(dane.poz);
    pola_.at(dane.poz) = new CPoleSzansa(dane);
}





void CPlansza::zamienNaCPoleSpec(SDnPoczPola dane)
{
    delete pola_.at(dane.poz);
    pola_.at(dane.poz) = new CPoleSpec(dane);
}





void CPlansza::zamienNaCPoleStnd(SDnPoczPola dane)
{
    delete pola_.at(dane.poz);
    pola_.at(dane.poz) = new CPoleStnd(dane);
}





void CPlansza::zamienNaCPoleEkstra(SDnPoczPola dane)
{
    delete pola_.at(dane.poz);
    pola_.at(dane.poz) = new CPoleEkstra(dane);
}





void CPlansza::zamienNaCPoleKasa(SDnPoczPola dane)
{
    delete pola_.at(dane.poz);
    pola_.at(dane.poz) = new CPoleKasa(dane);
}





SWynAkcji CPlansza::identPole(CGracz *gracz, int parPoz)
{
    return pola_.at(parPoz)->akcja(gracz);
}





deque<SDnPola> CPlansza::zbierzDnPol()
{
    int size = pola_.size();
    deque<SDnPola> wynik;

    for(int i = 0; i < size; i++)
        wynik.push_back(pola_.at(i)->podajDane());

    return wynik;
}





SDnPola CPlansza::zbierzDnPola(int poz)
{
    return pola_.at(poz)->podajDane();
}





deque<SDnPola> CPlansza::zbierzDnPol(CGracz *gracz)
{
    deque<SDnPola> wynik;
    int size = pola_.size();
    SWynAkcji tmpAkcja;

    for(int i = 0; i < size; i++)
    {
        tmpAkcja = pola_.at(i)->akcja(gracz);
        if((tmpAkcja.y1 == 0 || tmpAkcja.y1 == 1 || tmpAkcja.y1 == 2) && (tmpAkcja.y2 == 2 || tmpAkcja.y2 == 3))
            wynik.push_back(pola_.at(i)->podajDane());
    }

    return wynik;
}





deque<SDnPola> CPlansza::zbierzDnPolNiezast(CGracz *gracz)
{
    deque<SDnPola> wynik;
    int size = pola_.size();
    SWynAkcji tmpAkcja;

    for(int i = 0; i < size; i++)
    {
        tmpAkcja = pola_.at(i)->akcja(gracz);
        if((tmpAkcja.y1 == 0 || tmpAkcja.y1 == 1 || tmpAkcja.y1 == 2) && tmpAkcja.y2 == 2)
            wynik.push_back(pola_.at(i)->podajDane());
    }

    return wynik;
}





deque<SDnPola> CPlansza::zbierzDnPolZast(CGracz *gracz)
{
    deque<SDnPola> wynik;
    int size = pola_.size();
    SWynAkcji tmpAkcja;

    for(int i = 0; i < size; i++)
    {
        tmpAkcja = pola_.at(i)->akcja(gracz);
        if((tmpAkcja.y1 == 0 || tmpAkcja.y1 == 1 || tmpAkcja.y1 == 2) && tmpAkcja.y2 == 3)
            wynik.push_back(pola_.at(i)->podajDane());
    }

    return wynik;
}





CGracz* CPlansza::ktoMaPole(int parPoz)
{
    CPoleSpec *tmpPoleSpec;

    tmpPoleSpec = dynamic_cast<CPoleSpec *>(pola_.at(parPoz));

    if(tmpPoleSpec != NULL)
    {
        return tmpPoleSpec->podajWlasciciela();
    }
    else
    {
        // (...)-----> możliwe, że tu trzeba będzie dać wyjątek
        return NULL;
    }

}





int CPlansza::podajPensje()
{
    return pensjaStart_;
}





int CPlansza::podajCenePola(int poz)
{
    return pola_.at(poz)->podajDaneInt(1);
}





int CPlansza::wartoscNieruchomosciGracza(CGracz *wlasciciel)
{
    int wynik = 0;
    int size = pola_.size();
    SWynAkcji tmpAkcja;

    for(int i = 0; i < size; i++)
    {
        tmpAkcja = pola_.at(i)->akcja(wlasciciel);
        if((tmpAkcja.y1 == 0 || tmpAkcja.y1 == 1 || tmpAkcja.y1 == 2) && tmpAkcja.y2 == 2)          // warunek ---> pole jest klasy CPoleSpec lub CPoleStnd lub CPoleEkstra i nie jest zastawione, a właścicielem jest wlasciciel
            wynik += pola_.at(i)->podajDaneInt(1);
    }

    return wynik;
}





int CPlansza::potencjalZastawuGracza(CGracz *wlasciciel)
{
    int wynik = 0;
    int size = pola_.size();
    SWynAkcji tmpAkcja;

    for(int i = 0; i < size; i++)
    {
        tmpAkcja = pola_.at(i)->akcja(wlasciciel);
        if((tmpAkcja.y1 == 0 || tmpAkcja.y1 == 1 || tmpAkcja.y1 == 2) && tmpAkcja.y2 == 2)          // warunek ---> pole jest klasy CPoleSpec lub CPoleStnd lub CPoleEkstra i nie jest zastawione, a właścicielem jest wlasciciel
            wynik += pola_.at(i)->podajDaneInt(4);
    }

    return wynik;
}





SDnKarty CPlansza::losowanieKarty()
{
    srand(time(NULL));

    int nrKarty = rand() % 6 + 1;

    return karty_.at(nrKarty)->akcja();
}





void CPlansza::tasowanieKart()
{
    CKarta *tmpCKarta;
    int size = karty_.size();
    int randIndex = 0;

    // gdy w liście kart będzie tylko 1 element, tasowanie nie zostanie wykonane
    if(size > 1)
    {
        for(int i = 0; i < (size - 1); i++)
        {
            srand(time(NULL));
            randIndex = rand() % (size - i) + i;

            tmpCKarta = karty_.at(i);
            karty_.at(i) = karty_.at(randIndex);
            karty_.at(randIndex) = tmpCKarta;
        }
    }
}





void CPlansza::kupowaniePola(CGracz *kupiec, int parPoz)
{
    CPoleSpec *tmpSpec;

    tmpSpec = dynamic_cast<CPoleSpec *>(pola_.at(parPoz));

    if(tmpSpec != NULL)
    {
        tmpSpec->sprzedawanie(kupiec);
    }
    else
    {
        // -----> możliwe, że tu trzeba będzie dać wyjątek
    }
}





int CPlansza::daneIntPola(int parPoz, int opt)
{
    return pola_.at(parPoz)->podajDaneInt(opt);
}





void CPlansza::zabuduj(int poz)
{
    CPoleStnd *tmpStnd;

    tmpStnd = dynamic_cast<CPoleStnd *>(pola_.at(poz));

    if(tmpStnd != NULL)
    {
        tmpStnd->buduj();
    }
    else
    {
        // -----> możliwe, że tu trzeba będzie dać wyjątek
    }
}





int CPlansza::zastaw(int poz)
{
    CPoleSpec *tmpSpec;

    tmpSpec = dynamic_cast<CPoleSpec *>(pola_.at(poz));

    if(tmpSpec != NULL)
    {
        return tmpSpec->zastawianie();
    }
    else
    {
        // -----> możliwe, że tu trzeba będzie dać wyjątek
        return 0;
    }
}





void CPlansza::wykup(int poz)
{
    CPoleSpec *tmpSpec;

    tmpSpec = dynamic_cast<CPoleSpec *>(pola_.at(poz));

    if(tmpSpec != NULL)
    {
        tmpSpec->wykupowanie();
    }
    else
    {
        // -----> możliwe, że tu trzeba będzie dać wyjątek
    }
}





int CPlansza::ustalKolejnaPozWKolejce(int aktPoz, int rozmKolejki)
{
    int wynik;

    wynik = aktPoz + 1;
    if((rozmKolejki - 1) - wynik  < 0)
        wynik -= rozmKolejki;

    return wynik;
}





int CPlansza::changePoleRodz(string rodz)
{
    if(rodz == "CPoleSpec") return 0;

    else if(rodz == "CPoleStnd") return 1;

    else if(rodz == "CPoleEkstra") return 2;

    else if(rodz == "CPoleDoWiezienia") return 3;

    else if(rodz == "CPoleKasa") return 4;

    else if(rodz == "CPoleSzansa") return 5;

    else if(rodz == "CPole") return 6;

    else return -1;
}





string CPlansza::poleRodzToStr(int rodz)
{
    switch (rodz)
    {
    case 0:
        return "CPoleSpec";

    case 1:
        return "CPoleStnd";

    case 2:
        return "CPoleEkstra";

    case 3:
        return "CPoleDoWiezienia";

    case 4:
        return "CPoleKasa";

    case 5:
        return "CPoleSzansa";

    case 6:
        return "CPole";

    default:
        return "CPole Widmo!!!";
    }
}





int CPlansza::kartaRodzToInt(string rodzaj)
{
    if(rodzaj == "CKartaKwoty")
        return 0;
    else if(rodzaj == "CKartaRuchu")
        return 1;
    else if(rodzaj == "CKartaWiezienia")
        return 2;
    else if(rodzaj == "CKartaWolnosc")
        return 3;
    else
        return -1;
}





void CPlansza::usunKarty()
{
    int licz = karty_.size();

    for(int i = 0; i < licz; i++)
    {
        CKarta *tmp = karty_.at(i);
        delete tmp;
    }
}





void CPlansza::usunKartyUzyte()
{
    int licz = kartyUzyte_.size();

    for(int i = 0; i < licz; i++)
    {
        CKarta *tmp = kartyUzyte_.at(i);
        delete tmp;
    }
}





void CPlansza::usunPola()
{
    int licz = pola_.size();

    for(int i = 0; i < licz; i++)
    {
        CPole *tmp = pola_.at(i);
        delete tmp;
    }
}





void CPlansza::utworzCPoleZPliku(deque<string> &daneZPliku, int start, int end)
{
    SDnPoczPola tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.nazwa = "! ERROR !";
    tmp.poz = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = changePoleHeader(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
        case 0:
            tmp.nazwa = tmpAct;
            break;

        case 1:
            tmp.poz = stoi(tmpAct);
            break;

        default:
            break;
        }
        start++;
    }

    CPole *finalRes = new CPole(tmp);
    pola_.push_back(finalRes);
}





void CPlansza::utworzCPoleSpecZPliku(deque<string> &daneZPliku, int start, int end)
{
    SDnPoczPola tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.nazwa = "! ERROR !";
    tmp.poz = -1;
    tmp.kwota = -1;
    tmp.czynsz = -1;
    tmp.hipoteka = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = changePoleHeader(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
        case 0:
            tmp.nazwa = tmpAct;
            break;

        case 1:
            tmp.poz = stoi(tmpAct);
            break;

        case 2:
            tmp.kwota = stoi(tmpAct);
            break;

        case 3:
            tmp.czynsz = stoi(tmpAct);
            break;

        case 4:
            tmp.hipoteka = stoi(tmpAct);
            break;

        default:
            break;
        }
        start++;
    }

    CPoleSpec *finalRes = new CPoleSpec(tmp);
    CPole *ptr = finalRes;
    pola_.push_back(ptr);
}





void CPlansza::utworzCPoleStndZPliku(deque<string> &daneZPliku, int start, int end)
{
    SDnPoczPola tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.nazwa = "! ERROR !";
    tmp.poz = -1;
    tmp.kwota = -1;
    tmp.czynsz = -1;
    tmp.hipoteka = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = changePoleHeader(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
        case 0:
            tmp.nazwa = tmpAct;
            break;

        case 1:
            tmp.poz = stoi(tmpAct);
            break;

        case 2:
            tmp.kwota = stoi(tmpAct);
            break;

        case 3:
            tmp.czynsz = stoi(tmpAct);
            break;

        case 4:
            tmp.hipoteka = stoi(tmpAct);
            break;

        case 5:
            tmp.kolor = stoi(tmpAct);
            break;              

        case 6:
            tmp.cenaAp = stoi(tmpAct);
            break;

        case 7:
            tmp.cenaHot = stoi(tmpAct);
            break;

        default:
            break;
        }
        start++;
    }

    CPoleStnd *finalRes = new CPoleStnd(tmp);
    CPole *ptr = finalRes;
    pola_.push_back(ptr);
}





void CPlansza::utworzCPoleEkstraZPliku(deque<string> &daneZPliku, int start, int end)
{
    SDnPoczPola tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.nazwa = "! ERROR !";
    tmp.poz = -1;
    tmp.kwota = -1;
    tmp.czynsz = -1;
    tmp.hipoteka = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = changePoleHeader(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
        case 0:
            tmp.nazwa = tmpAct;
            break;

        case 1:
            tmp.poz = stoi(tmpAct);
            break;

        case 2:
            tmp.kwota = stoi(tmpAct);
            break;

        case 3:
            tmp.czynsz = stoi(tmpAct);
            break;

        case 4:
            tmp.hipoteka = stoi(tmpAct);
            break;

        default:
            break;
        }
        start++;
    }

    CPoleEkstra *finalRes = new CPoleEkstra(tmp);
    CPole *ptr = finalRes;
    pola_.push_back(ptr);
}





void CPlansza::utworzCPoleKasaZPliku(deque<string> &daneZPliku, int start, int end)
{
    SDnPoczPola tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.nazwa = "! ERROR !";
    tmp.poz = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = changePoleHeader(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
            case 0:
                tmp.nazwa = tmpAct;
                break;

            case 1:
                tmp.poz = stoi(tmpAct);
                break;

            case 8:
                tmp.kwota = stoi(tmpAct);
                break;

            default:
                break;
        }
        start++;
    }

    CPoleKasa *finalRes = new CPoleKasa(tmp);
    CPole *ptr = finalRes;
    pola_.push_back(ptr);
}





void CPlansza::utworzCPoleSzansaZPliku(deque<string> &daneZPliku, int start, int end)
{
    SDnPoczPola tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.nazwa = "! ERROR !";
    tmp.poz = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = changePoleHeader(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
            case 0:
                tmp.nazwa = tmpAct;
                break;

            case 1:
                tmp.poz = stoi(tmpAct);
                break;

            default:
                break;
        }
        start++;
    }

    CPoleSzansa *finalRes = new CPoleSzansa(tmp);
    CPole *ptr = finalRes;
    pola_.push_back(ptr);
}





void CPlansza::utworzCPoleDoWiezieniaZPliku(deque<string> &daneZPliku, int start, int end)
{
    SDnPoczPola tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.nazwa = "! ERROR !";
    tmp.poz = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = changePoleHeader(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
            case 0:
                tmp.nazwa = tmpAct;
                break;

            case 1:
                tmp.poz = stoi(tmpAct);
                break;

            default:
                break;
        }
        start++;
    }

    CPoleDoWiezienia *finalRes = new CPoleDoWiezienia(tmp);
    CPole *ptr = finalRes;
    pola_.push_back(ptr);
}





void CPlansza::utworzCKartaWolnoscZPliku(deque<std::string> &daneZPliku, int start, int end)
{
    SDnKarty tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.tresc = "! ERROR !";
    tmp.nr = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = kartaHeaderToInt(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
            case 0:
                tmp.nr = stoi(tmpAct);
                break;

            case 1:
                tmp.tresc = tmpAct;
                break;

            default:
                break;
        }
        start++;
    }

    CKartaWolnosc *finalRes = new CKartaWolnosc(tmp);
    CKarta *ptr = finalRes;
    karty_.push_back(ptr);
}





void CPlansza::utworzCKartaKwotyZPliku(deque<std::string> &daneZPliku, int start, int end)
{
    SDnKarty tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.tresc = "! ERROR !";
    tmp.nr = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = kartaHeaderToInt(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
            case 0:
                tmp.nr = stoi(tmpAct);
                break;

            case 1:
                tmp.tresc = tmpAct;
                break;

            case 2:
                tmp.wartosc = stoi(tmpAct);

            default:
                break;
        }
        start++;
    }

    CKartaKwoty *finalRes = new CKartaKwoty(tmp);
    CKarta *ptr = finalRes;
    karty_.push_back(ptr);
}





void CPlansza::utworzCKartaRuchuZPliku(deque<std::string> &daneZPliku, int start, int end)
{
    SDnKarty tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.tresc = "! ERROR !";
    tmp.nr = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = kartaHeaderToInt(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
            case 0:
                tmp.nr = stoi(tmpAct);
                break;

            case 1:
                tmp.tresc = tmpAct;
                break;

            case 3:
                tmp.wartosc = stoi(tmpAct);

            default:
                break;
        }
        start++;
    }

    CKartaRuchu *finalRes = new CKartaRuchu(tmp);
    CKarta *ptr = finalRes;
    karty_.push_back(ptr);
}





void CPlansza::utworzCKartaWiezieniaZPliku(deque<std::string> &daneZPliku, int start, int end)
{
    SDnKarty tmp;
    string tmpAct;
    SParsedElem tmpActElem;
    int selector = 0;

    tmp.tresc = "! ERROR !";
    tmp.nr = -1;

    tmpActElem = parseElem(daneZPliku.at(start));


    // Założenie: start wskazuje na element typu string z nagłówkiem "rodz" lub "atr"
    if(tmpActElem.header == "atr")
    {
        end = parseBound(daneZPliku, "atr", start);
        start++;
    }

    else
    {
        start++;
        end = parseBound(daneZPliku, "atr", start);
        start ++;
    }

    while(start < end)
    {
        tmpActElem = parseElem(daneZPliku.at(start));

        selector = kartaHeaderToInt(tmpActElem.header);

        tmpAct = parseHeadCont(daneZPliku.at(start), tmpActElem.pocz);

        switch (selector)
        {
            case 0:
                tmp.nr = stoi(tmpAct);
                break;

            case 1:
                tmp.tresc = tmpAct;
                break;

            default:
                break;
        }
        start++;
    }

    CKartaWiezienia *finalRes = new CKartaWiezienia(tmp);
    CKarta *ptr = finalRes;
    karty_.push_back(ptr);
}





int CPlansza::changePoleHeader(string header)
{
    if(header == "nazwa_")
        return 0;
    else if(header == "pozycja_")
        return 1;
    else if(header == "cena_")
        return 2;
    else if(header == "czynsz_")
        return 3;
    else if(header == "hipoteka_")
        return 4;
    else if(header == "kolor_")
        return 5;      
    else if(header == "cenaApartam_")
        return 6;
    else if(header == "cenaHotelu_")
        return 7;
    else if(header == "kwota_")
        return 8;
    else
        return -1;
}





int CPlansza::kartaHeaderToInt(std::string header)
{
    if(header == "nr_")
        return 0;
    else if(header == "tresc_")
        return 1;
    else if(header == "kwota_")
        return 2;
    else if(header == "nowaPoz_")
        return 3;
    else
        return -1;
}





int CPlansza::parseBound(deque<string> &trescPliku, string nazwaNag, int start)
{
    nazwaNag = "/" + nazwaNag;
    int size = trescPliku.size(), wynik = start;
    string tmpAct;

    for(int i = start; i < size; i++)
    {
        tmpAct = parseElem(trescPliku.at(i)).header;

        if(tmpAct == (nazwaNag))
        {
            wynik = i;
            break;
        }
    }

    return wynik;
}





string CPlansza::parseHeadCont(string strumien, int start)
{
    SWynAkcji wynik;
    int index_1 = 0;
    int size = strumien.size();

    if(strumien[start] != '>')
    {
        while(strumien[start] == ' ' && start < size)
            start += 1;

        wynik.y1 = start;
        index_1 = znajdzZn('<', start, strumien);
        wynik.y2 = index_1 - 1;

        return strumien.substr(wynik.y1, wynik.y2 - wynik.y1 + 1);
    }
    else
    {
        start++;
        while(strumien[start] == ' ' && start < size)
            start += 1;

        wynik.y1 = start;
        index_1 = znajdzZn('<', start, strumien);
        wynik.y2 = index_1 - 1;

        return strumien.substr(wynik.y1, wynik.y2 - wynik.y1 + 1);
    }
}





SParsedElem CPlansza::parseElem(string& daneStr)
{
    SParsedElem wynElem;
    string tmpAct;
    int index = 0, index_1 = 0, size;

    size = daneStr.size();

    wynElem.pocz = 0;

    // sytuacja, gdy strumien danych zaczyna się znakiem '<'
    if(daneStr[0] == '<')
    {
         //wynElem.pocz = index_0 = daneStrIndex;        
        index = 1;

        // poszukiwanie wartości nagłówka danych
        index = CPlansza::znajdzZn('>', index, daneStr);

        tmpAct = daneStr.substr(1, index - 1);
        wynElem.header = tmpAct;

        if((index + 1) < size)
        {
            wynElem.pocz = index + 1;
        }
    }
    // sytuacja, gdy '<' nie jest pierwszym znakiem
    else
    {
        index = znajdzZn('<', index, daneStr);
        index_1 = znajdzZn('>', index, daneStr);

        tmpAct = daneStr.substr(index + 1, index_1 - index - 1);
        wynElem.header = tmpAct;

        if((index_1 +1) < size)
            wynElem.pocz = index_1 + 1;
    }

    return wynElem;
}

int CPlansza::znajdzZn(char parZn, int indexStart, string& strumien)
{
    int size = strumien.size();

    while(strumien[indexStart] != parZn && indexStart < size)
        indexStart++;

    return indexStart;
}
