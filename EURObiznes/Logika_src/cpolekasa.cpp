#include "Logika_h/cpolekasa.h"

CPoleKasa::CPoleKasa()
{

}

CPoleKasa::CPoleKasa(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
    kwota_ = dane.kwota;
}

CPoleKasa::~CPoleKasa()
{

}

SWynAkcji CPoleKasa::akcja(CGracz *gracz)
{
    SWynAkcji wynik;

    wynik.y1 = 4;
    wynik.y2 = kwota_;

    return wynik;
}

int CPoleKasa::podajDaneInt(int opt)
{
    switch(opt)
    {
    case 0:
        return pozycja_;
        break;

    case 1:
        return kwota_;
        break;

    default:
        return pozycja_;
    }
}

SDnPola CPoleKasa::podajDane()
{
    SDnPola wynik;

    wynik.rodz = 4;

    wynik.poz = pozycja_;

    SHeadAndData tmp;
    tmp.header = "Nazwa";
    tmp.data = nazwa_;
    wynik.atrybuty.push_back(tmp);

    tmp.header = "Kwota";
    tmp.data = to_string(kwota_);
    wynik.atrybuty.push_back(tmp);

    return wynik;
}

void CPoleKasa::wpiszDane(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
    kwota_ = dane.kwota;
}

void CPoleKasa::ustawKwote(int wartosc)
{
    kwota_ = wartosc;
}
