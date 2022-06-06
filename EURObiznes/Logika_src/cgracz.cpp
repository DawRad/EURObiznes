#include "Logika_h/cgracz.h"





CGracz::CGracz()
{
    aktPoz_ = P_START;
    lbPolSpec_ = 0;
    lbPolEkstra_ = 0;
    lbKartWolnosc_ = 0;
}





CGracz::CGracz(SDnGracza parDane)
{
    aktPoz_ = P_START;
    lbPolSpec_ = 0;
    lbPolEkstra_ = 0;
    lbKartWolnosc_ = 0;

    for(int i = 0; i < parDane.lbKolorow; i++)
        lbPolKol_.push_back(0);
}





CGracz::~CGracz()
{

}





void CGracz::ruch(int poz)
{
    nastPoz_ = aktPoz_ + poz;
    if((P_WIEZIENIE - 1) - nastPoz_ < 0)
    {
        // gracz przechodzi przez pole "START" do przodu
        nastPoz_ = nastPoz_ - P_WIEZIENIE;
    }
    else if(nastPoz_ < 0)
    {
        // gracz przechodzi przez pole "START" do tyłu
        nastPoz_ = nastPoz_ + P_WIEZIENIE;
    }
}





int CGracz::dodajPole(SWynAkcji opt)
{
    if(opt.y1 == 0)
    {
        lbPolSpec_ += 1;

        return lbPolSpec_;
    }

    else if(opt.y1 == 1)
    {
        switch(opt.y2)
        {
            case 0:
            lbPolKol_[0] += 1;
            break;

            case 1:
            lbPolKol_[1] += 1;
            break;

            case 2:
            lbPolKol_[2] += 1;
            break;

            case 3:
            lbPolKol_[3] += 1;
            break;

            case 4:
            lbPolKol_[4] += 1;
            break;

            case 5:
            lbPolKol_[5] += 1;
            break;

            case 6:
            lbPolKol_[6] += 1;
            break;

            case 7:
            lbPolKol_[7] += 1;
            break;
        }

        return lbPolKol_[opt.y2];
    }

    else if (opt.y1 == 2)
    {
        lbPolEkstra_ += 1;
        return lbPolEkstra_;
    }

    else
    {
        return -777;
    }
}





void CGracz::dodajKarteWolnosc()
{
    lbKartWolnosc_++;
}





SDnGracza CGracz::podajDane()
{
    SDnGracza wynik;

    wynik.id = id_;
    wynik.rodz = przedstawSie();
    wynik.nick = nick_;
    wynik.portfel = portfel_;
    wynik.lbKartWolnosc = lbKartWolnosc_;

    return wynik;
}





int CGracz::podajId()
{
    return id_;
}





int CGracz::podajLbPol(int rodz)
{
    if(rodz == 1)
    {
        return lbPolSpec_;
    }
    else if(rodz == 2) return lbPolEkstra_;
    else return -777;
}





int CGracz::podajLbPolKol(int kolor)
{
    switch (kolor)
    {
        case 0: return lbPolKol_[0]; break;
        case 1: return lbPolKol_[1]; break;
        case 2: return lbPolKol_[2]; break;
        case 3: return lbPolKol_[3]; break;
        case 4: return lbPolKol_[4]; break;
        case 5: return lbPolKol_[5]; break;
        case 6: return lbPolKol_[6]; break;
        case 7: return lbPolKol_[7]; break;
        default: return -777; break;
    }
}





int CGracz::podajLbKartWolnosc()
{
    return lbKartWolnosc_;
}





int CGracz::podajStanKonta()
{
    return portfel_;
}





int CGracz::podajAktPoz()
{
    return aktPoz_;
}





int CGracz::podajNastPoz()
{
    return nastPoz_;
}





int CGracz::podajSumeOczekKostki()
{
    return (kostka_.y1 + kostka_.y2);
}





SWynAkcji CGracz::podajKostki()
{
    return kostka_;
}





SWynAkcji CGracz::podajPoz()
{
    SWynAkcji wyn;
    wyn.y1 = aktPoz_;
    wyn.y2 = nastPoz_;

    return wyn;
}





string CGracz::podajNick()
{
    return nick_;
}





void CGracz::ustawPortfel(int kwotaPocz)
{
    portfel_ = kwotaPocz;
}





void CGracz::aktualPortfel(int kwota)
{
    portfel_ += kwota;
}





void CGracz::kupPole(int rodz)
{
    switch (rodz)
    {
    case 0:
        lbPolSpec_++;
        break;

    case 2:
        lbPolEkstra_++;
        break;
    default:
        break;
    }
}





void CGracz::aktualPozycje()
{
    aktPoz_ = nastPoz_;
}





void CGracz::uzyjWolnosc()
{
    lbKartWolnosc_ -= 1;
    wyjdzZWiezienia();
}





void CGracz::idzDoWiezienia()
{
    aktPoz_ = P_WIEZIENIE;
    nastPoz_ = P_WIEZIENIE;
}





void CGracz::wyjdzZWiezienia()
{
    aktPoz_ = P_ODWIEDZINY;
    nastPoz_ = P_ODWIEDZINY;
}
