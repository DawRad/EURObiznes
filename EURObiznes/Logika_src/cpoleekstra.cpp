#include "Logika_h/cpoleekstra.h"

CPoleEkstra::CPoleEkstra()
{
    stan_ = 0;
    wlasciciel_ = NULL;
}

CPoleEkstra::CPoleEkstra(SDnPoczPola dane)
{
    pozycja_ = dane.poz;
    nazwa_ = dane.nazwa;
    cena_ = dane.kwota;
    stan_ = 0;
    czynsz_ = dane.czynsz;
    hipoteka_ = dane.hipoteka;
    wlasciciel_ = NULL;
}

CPoleEkstra::~CPoleEkstra()
{

}

/* @return
 * y1 = 2 (zawsze dla tej klasy)
 *
 * y2:
 * = 0 -----> gdy pole nie ma właściciela
 * = 1 -----> gdy pole ma właściciela, ale gracz stający nim nie jest
 * = 2 -----> gdy pole ma właściciela i jest nim gracz stający
 * = 3 -----> gdy pole jest zastawione i właścicielem jest gracz stający
 * = 4 -----> gdy pole jest zastawione i właścicielem NIE jest gracz stający
 */
SWynAkcji CPoleEkstra::akcja(CGracz *gracz)
{
    SWynAkcji wynik;

    wynik.y1 = 2;

    // pole nie ma właściciela
    if(stan_ == 0)
    {        
        wynik.y2 = 0;
    }

    // pole ma właściciela
    else if(stan_ == 1)
    {
        /* sytuacja, gdy inny gracz jest właścicielem - ten, który stanął musi zapłacić czynsz
         * wtedy akcja zwraca y2 == 1 (gracz musiał zapłacić czynsz)
         * gracz musi zapłacić czynsz pomnożony przez wartość wyrzuconych oczek
         */
        if(gracz != wlasciciel_)
        {
            int k = wlasciciel_->podajLbPol(2);
            int l = gracz->podajSumeOczekKostki();

            // gdy właściciel posiada 1 pole CPoleEkstra
            if(k == 1)
            {
                gracz->aktualPortfel((-1) * 0.5 * czynsz_ * l);
                wlasciciel_->aktualPortfel(0.5 * czynsz_ * l);
            }

            // gdy właściciel posiada 1 pole CPoleEkstra
            else
            {
                gracz->aktualPortfel((-1) * 1 * czynsz_ * l);
                wlasciciel_->aktualPortfel(1 * czynsz_ * l);
            }

            wynik.y2 = 1;
        }

        /* sytuacja, gdy gracz jest właścicielem
         * wtedy akcja zwraca y2 == 2
         */
        else
        {           
            wynik.y2 = 2;
        }
    }

    // gdy pole jest zastawione, to funkcja informuje o tym czy gracz jest właścicielem (tmp.y2 == 3) lub nie (tmp.y2 == 4)
    else if(stan_ == 2)
    {
        if(gracz == wlasciciel_)
        {           
            wynik.y2 = 3;
        }

        else
        {          
            wynik.y2 = 4;
        }
    }

    // ERROR
    else
    {      
        wynik.y2 = -777;
    }

    return wynik;
}

int CPoleEkstra::podajDaneInt(int opt)
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

SDnPola CPoleEkstra::podajDane()
{
    SDnPola wynik;

    wynik.rodz = 2;

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





void CPoleEkstra::sprzedawanie(CGracz *kupiec)
{
    wlasciciel_ = kupiec;
    wlasciciel_->aktualPortfel(-cena_);
    wlasciciel_->kupPole(2);
    stan_ = 1;
}





void CPoleEkstra::wpiszDane(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
    cena_ = dane.kwota;
    stan_ = 0;
    czynsz_ = dane.czynsz;
    hipoteka_ = dane.hipoteka;
    wlasciciel_ = NULL;
}
