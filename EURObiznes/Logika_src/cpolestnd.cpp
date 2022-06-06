#include "Logika_h/cpolestnd.h"

CPoleStnd::CPoleStnd()
{    
    stan_ = 0;
    czynsz_ = 0;
    lbApartam_ = 0;
    lbHoteli_ = 0;
    wlasciciel_ = NULL;
}

CPoleStnd::CPoleStnd(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
    cena_ = dane.kwota;
    stan_ = 0;
    hipoteka_ = dane.hipoteka;    

    czynsz_ = dane.czynsz;

    kolor_ = dane.kolor;
    lbApartam_ = 0;
    lbHoteli_ = 0;
    cenaApartam_ = dane.cenaAp;
    cenaHotelu_ = dane.cenaHot;

    wlasciciel_ = NULL;
}

CPoleStnd::~CPoleStnd()
{

}

/*
 *
 * @return
 * y1 = 1 (zawsze dla tej klasy)
 *
 * y2:
 * = 0 -----> gdy pole nie ma właściciela
 * = 1 -----> gdy pole ma właściciela, ale gracz stający nim nie jest
 * = 2 -----> gdy pole ma właściciela i jest nim gracz stający
 * = 3 -----> gdy pole jest zastawione i właścicielem jest gracz stający
 * = 4 -----> gdy pole jest zastawione i właścicielem NIE jest gracz stający
 */
SWynAkcji CPoleStnd::akcja(CGracz *gracz)
{
    SWynAkcji tmp;

    tmp.y1 = 1;

    if (stan_ == 0)
    {        
        tmp.y2 = 0;
    }

    else if (stan_ == 1)
    {
        // akcja, gdy gracz nie jest właścicielem - musi zapłacić czynsz
        if (gracz != wlasciciel_)
        {
            wlasciciel_->aktualPortfel(czynsz_ * (1 + lbApartam_ + lbHoteli_));
            gracz->aktualPortfel(-czynsz_ * (1 + lbApartam_ + lbHoteli_));

            tmp.y2 = 1;
        }

        // gdy gracz jest właścicielem, funkcja przekazuje informację także o tym, jaki to rodzaj pola (tmp.y2 == 1 ---> CPoleStnd)
        else
        {            
            tmp.y2 = 2;
        }
    }

    // gdy pole jest zastawione, to funkcja informuje o tym (tmp.y1 == 2) oraz czy gracz jest właścicielem (tmp.y2 == 1) lub nie (tmp.y2 == -1)
    else if (stan_ == 2)
    {        
        if (wlasciciel_ == gracz) tmp.y2 = 3;
        else tmp.y2 = 4;
    }

    // ERROR
    else
    {     
        tmp.y2 = -777;
    }

    return tmp;
}

int CPoleStnd::podajDaneInt(int opt)
{
    switch(opt)
    {
    case 0:
        return pozycja_;
        break;

    case 1:
        return cena_;
        break;

    case 2:
        return stan_;
        break;

    case 3:
        return czynsz_;
        break;

    case 4:
        return hipoteka_;
        break;

    case 5:
        return kolor_;
        break;

    case 6:
        return lbApartam_;
        break;

    case 7:
        return lbHoteli_;
        break;

    case 8:
        return cenaApartam_;
        break;

    case 9:
        return cenaHotelu_;
        break;

    default:
        return pozycja_;
    }
}

SDnPola CPoleStnd::podajDane()
{
    SDnPola wynik;

    wynik.rodz = 1;

    wynik.poz = pozycja_;

    SHeadAndData tmp;
    tmp.header = "Nazwa";
    tmp.data = nazwa_;
    wynik.atrybuty.push_back(tmp);

    tmp.header = "Cena";
    tmp.data = to_string(cena_);
    wynik.atrybuty.push_back(tmp);

    tmp.header = "Stan";
    tmp.data = to_string(stan_);
    wynik.atrybuty.push_back(tmp);

    tmp.header = "Czynsz";
    tmp.data = to_string(czynsz_);
    wynik.atrybuty.push_back(tmp);

    tmp.header = "Hipoteka";
    tmp.data = to_string(hipoteka_);
    wynik.atrybuty.push_back(tmp);

    // (...)-----> zastanowić się, czy nie trzeba tu dodać właściciela (nicku)

    tmp.header = "Kolor";
    tmp.data = to_string(kolor_);
    wynik.atrybuty.push_back(tmp);

    tmp.header = "Cena apartamentu";
    tmp.data = to_string(cenaApartam_);
    wynik.atrybuty.push_back(tmp);

    tmp.header = "Cena hotelu";
    tmp.data = to_string(cenaHotelu_);
    wynik.atrybuty.push_back(tmp);

    return wynik;
}





void CPoleStnd::sprzedawanie(CGracz *kupiec)
{
    wlasciciel_ = kupiec;
    wlasciciel_->aktualPortfel(-cena_);
    stan_ = 1;
}





void CPoleStnd::wpiszDane(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
    cena_ = dane.kwota;
    stan_ = 0;
    hipoteka_ = dane.hipoteka;

    czynsz_ = dane.czynsz;

    kolor_ = dane.kolor;
    lbApartam_ = 0;
    lbHoteli_ = 0;
    cenaApartam_ = dane.cenaAp;
    cenaHotelu_ = dane.cenaHot;

    wlasciciel_ = NULL;
}





void CPoleStnd::aktualCzynsz()
{
    if (lbHoteli_ == 1) czynsz_ = czynsz_ + czynsz_;
    else czynsz_ = czynsz_ * lbApartam_;
}





void CPoleStnd::buduj()
{
    if (lbApartam_ < 4)
    {
        lbApartam_++;
        wlasciciel_->aktualPortfel(-cenaApartam_);
    }
    else
    {
        wlasciciel_->aktualPortfel(-cenaHotelu_);
        lbHoteli_++;
    }
}
