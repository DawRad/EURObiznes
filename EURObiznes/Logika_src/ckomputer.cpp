#include "Logika_h/ckomputer.h"

CKomputer::CKomputer(SDnGracza _dane) : CGracz(_dane)
{    
    id_ = _dane.id;
    nick_ = _dane.nick;
    portfel_ = _dane.portfel;
}

CKomputer::~CKomputer()
{

}

string CKomputer::przedstawSie()
{
    return "komp";
}

SWynAkcji CKomputer::rzucKoscmi()
{
    SWynAkcji tmp;

    srand(time(NULL));

    tmp.y1 = rand() % 6 + 1;
    tmp.y2 = rand() % 6 + 1;

    return tmp;
}

int CKomputer::decyduj(int stan, int kwota, int lbPol)
{
    // działanie, gdy pole nie ma właściciela
    if (stan == 0)
    {
        double tmp = kwota / portfel_ - (lbPol / 100) * 5;
        if (tmp < 0.18)
        {
            return 1;
        }

        else return 0;
    }

    // działanie, gdy komputer jest właścicielem pola
     else if (stan == 2)
    {
        if (kwota / portfel_ < 0.14) return 1;
        else return 0;
    }

    // działanie, gdy komputer jest właścicielem, ale pole jest zastawione
    else if (stan == 3)
    {
        if (kwota / portfel_ < 0.5) return 1;
        else return 0;
    }

    // -----> tu też trzeba się zastanowić nad wyjątkiem
    else return -777;
}
