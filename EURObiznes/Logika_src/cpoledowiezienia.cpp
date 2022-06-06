#include "Logika_h/cpoledowiezienia.h"

CPoleDoWiezienia::CPoleDoWiezienia()
{

}

CPoleDoWiezienia::CPoleDoWiezienia(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
}

CPoleDoWiezienia::~CPoleDoWiezienia()
{

}

SWynAkcji CPoleDoWiezienia::akcja(CGracz *gracz)
{
    SWynAkcji wynik;

    wynik.y1 = 3;
    wynik.y2 = 3;

    return wynik;
}

int CPoleDoWiezienia::podajDaneInt(int opt)
{
    switch(opt)
    {
    case 0:
        return pozycja_;
        break;

    default:
        return pozycja_;
    }
}

SDnPola CPoleDoWiezienia::podajDane()
{
    SDnPola wynik;

    wynik.rodz = 3;

    wynik.poz = pozycja_;

    SHeadAndData tmp;
    tmp.header = "Nazwa";
    tmp.data = nazwa_;
    wynik.atrybuty.push_back(tmp);

    return wynik;
}

void CPoleDoWiezienia::wpiszDane(SDnPoczPola dane)
{
    nazwa_ = dane.nazwa;
    pozycja_ = dane.poz;
}
