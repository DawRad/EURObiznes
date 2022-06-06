#include "Rysunki_h/crysemiter.h"





CRysEmiter::CRysEmiter()
{
    nadawca_ = new CNadawca();
}





CRysEmiter::CRysEmiter(QPoint topLeft, QSizeF size, string imieNad, qreal rot) : CRys(topLeft, size, rot)
{
    delete nadawca_;

    nadawca_ = new CNadawca(imieNad);
}





CRysEmiter::~CRysEmiter()
{
    delete nadawca_;
}






QObject *CRysEmiter::podajNadawce()
{
    return nadawca_;
}
