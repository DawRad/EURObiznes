#include "Rysunki_h/crysprzyciskimg.h"





CRysPrzyciskImg::CRysPrzyciskImg()
{

}





CRysPrzyciskImg::CRysPrzyciskImg(QPoint topLeft, QSizeF size, QString nazwa, int shape, QString paths[], string imieNad, qreal rot) : CRysPrzycisk(topLeft, size, nazwa,
                                                                                                                                                   shape, imieNad, rot)
{
    path_ = paths[0];
    pathDisab_ = paths[1];
}





CRysPrzyciskImg::~CRysPrzyciskImg()
{

}





void CRysPrzyciskImg::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->isEnabled())
    {

        drawShape(painter);
    }

    else
    {
        drawShape(painter);
    }
}
