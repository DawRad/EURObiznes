#ifndef CRYSPRZYCISKIMG_H
#define CRYSPRZYCISKIMG_H

#include "Rysunki_h/crysprzycisk.h"






/**
 * @brief Klasa graficzna
 */
class CRysPrzyciskImg : public CRysPrzycisk
{
protected:
    QString path_;
    QString pathDisab_;

public:
    CRysPrzyciskImg();
    CRysPrzyciskImg(QPoint topLeft, QSizeF size, QString nazwa, int shape, QString paths[], string imieNad = "brak", qreal rot = 0);
    ~CRysPrzyciskImg();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // CRYSPRZYCISKIMG_H
