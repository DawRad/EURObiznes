#include "Logika_h/cpolespec.h"

CPoleSpec::CPoleSpec()
{
    stan_ = 0;
    wlasciciel_ = NULL;
}

CPoleSpec::CPoleSpec(SDnPoczPola _dane)
{
    pozycja_ = _dane.poz;
    nazwa_ = _dane.nazwa;
    cena_ = _dane.kwota;
    stan_ = 0;
    czynsz_ = _dane.czynsz;
    hipoteka_ = _dane.hipoteka;
    wlasciciel_ = NULL;
}

CPoleSpec::~CPoleSpec()
{

}

/* @return
 * y1 = 0 (zawsze dla tej klasy)
 *
 * y2:
 * == 0 -----> gdy pole nie ma właściciela
 * == 1 -----> gdy pole ma właściciela, ale gracz stający nim NIE jest
 * == 2 -----> gdy pole ma właściciela i jest nim gracz stający
 * == 3 -----> gdy pole jest zastawione i właścicielem jest gracz stający
 * == 4 -----> gdy pole jest zastawione i właścicielem NIE jest gracz stający
 */
SWynAkcji CPoleSpec::akcja(CGracz *gracz)
{
    SWynAkcji tmp;

    tmp.y1 = 0;

    // pole nie ma właściciela - tmp.y2 = 0
    if (stan_ == 0)
    {
        tmp.y2 = 0;
    }

    // pole ma właściciela
    else if (stan_ == 1)
    {
        // akcja, gdy gracz nie jest właścicielem - musi zapłacić czynsz
        if (gracz != wlasciciel_)
        {
            int k = wlasciciel_->podajLbPol(1);             /// k jest liczbą posiadanych przez właściciela pól CPoleSpec

            wlasciciel_->aktualPortfel(czynsz_ * k);
            gracz->aktualPortfel((-1) * (czynsz_ * k));

            tmp.y2 = 1;
        }

        // gdy gracz jest właścicielem, funkcja przekazuje o tym informację (tmp.y2 == 2)
        else
        {          
            tmp.y2 = 2;
        }
    }

    // gdy pole jest zastawione, to funkcja informuje o tym oraz czy gracz jest właścicielem (tmp.y2 == 3) czy nie (tmp.y2 == 4)
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

void CPoleSpec::wpiszDane(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
    cena_ = dane.kwota;
    stan_ = 0;
    czynsz_ = dane.czynsz;
    hipoteka_ = dane.hipoteka;
    wlasciciel_ = NULL;
}

int CPoleSpec::podajDaneInt(int opt)
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

    default:
        return pozycja_;
    }
}

SDnPola CPoleSpec::podajDane()
{
    SDnPola wynik;

    wynik.rodz = 0;

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

    // -----> zastanowić się, czy nie trzeba tu dodać właściciela (nicku)

    return wynik;
}



void CPoleSpec::sprzedawanie(CGracz *kupiec)
{
    wlasciciel_ = kupiec;
    wlasciciel_->aktualPortfel(-cena_);
    wlasciciel_->kupPole(0);
    stan_ = 1;
}





CGracz *CPoleSpec::podajWlasciciela()
{
    return wlasciciel_;
}



int CPoleSpec::zastawianie()
{
    wlasciciel_->aktualPortfel(hipoteka_);
    stan_ = 2;   
}

void CPoleSpec::wykupowanie()
{
    stan_ = 1;

    // !!! Sprawdź później !!! :
    // - nie wiem, czy nie trzeba też tu uwzględnić operacji na portfelu właściciela
}
