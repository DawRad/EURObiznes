#include "Logika_h/cczlowiek.h"

CCzlowiek::CCzlowiek(SDnGracza _dane) : CGracz(_dane)
{ 
    id_ = _dane.id;
    nick_ = _dane.nick;
    portfel_ = _dane.portfel;

    for(int i = 0; i < _dane.lbKolorow; i++)
        lbPolKol_.push_back(0);
}

CCzlowiek::~CCzlowiek()
{

}

string CCzlowiek::przedstawSie()
{
    return "cz";
}

SWynAkcji CCzlowiek::rzucKoscmi()
{
    SWynAkcji tmp;

    srand(time(NULL));

    tmp.y1 = rand() % 6 + 1;
    tmp.y2 = rand() % 6 + 1;

    kostka_.y1 = tmp.y1;
    kostka_.y2 = tmp.y2;

    if(aktPoz_ == P_WIEZIENIE)
    {
        // gracz jest w więzieniu, nie może się poruszyć
        // trzeba sprawdzić, czy wyrzucił dublet
        if (tmp.y1 == tmp.y2)
        {
            nastPoz_ = P_ODWIEDZINY;
        }
    }
    else
    {
        int suma = tmp.y1 + tmp.y2;
        nastPoz_ = aktPoz_ + suma;
        if((P_WIEZIENIE - 1) - nastPoz_ < 0)
            nastPoz_ = nastPoz_ - P_WIEZIENIE;
    }

    return tmp;
}

int CCzlowiek::decyduj(int stan, int kwota, int lbPol)
{
    return -777;
}
