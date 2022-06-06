#include "Logika_h/cpole.h"

CPole::CPole()
{

}





CPole::CPole(SDnPoczPola _dane)
{
    nazwa_ = _dane.nazwa;
    pozycja_ = _dane.poz;
}





CPole::~CPole()
{

}





SWynAkcji CPole::akcja(CGracz *gracz)
{
    SWynAkcji wynik;

    wynik.y1 = 6;
    wynik.y2 = pozycja_;

    return wynik;
}





void CPole::wpiszDane(SDnPoczPola _dane)
{
    nazwa_ = _dane.nazwa;
    pozycja_ = _dane.poz;
}





int CPole::podajDaneInt(int opt)
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





SDnPola CPole::podajDane()
{
    SDnPola wynik;

    wynik.rodz = 6;

    wynik.poz = pozycja_;

    SHeadAndData tmp;
    tmp.header = "Nazwa";
    tmp.data = nazwa_;
    wynik.atrybuty.push_back(tmp);

    return wynik;
}





string CPole::podajNazwe()
{
    return nazwa_;
}





string CPole::kolorToStr(int kolor)
{
    switch (kolor)
    {
    case KOL_CZER:
        return "czerwony";
        break;

    case KOL_ZIEL:
        return "zielony";
        break;

    case KOL_NIEB:
        return "niebieski";

    case KOL_AKWAMAR:
        return "akwamaryna";

    case KOL_FIOL:
        return "fioletowy";

    case KOL_CZARNY:
        return "czarny";

    case KOL_POMAR:
        return "pomarańczowy";

    case KOL_OLIW:
        return "oliwkowy";

    case KOL_ROZ:
        return "różowy";

    case KOL_ZOLTY:
        return "żółty";

    default:
        return "oktaryna";
    }
}
