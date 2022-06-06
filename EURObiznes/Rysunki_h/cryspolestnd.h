#ifndef CRYSPOLESTND_H
#define CRYSPOLESTND_H

#include "Rysunki_h/cryspoleobraz.h"






/**
 * @brief Klasa graficzna
 */
class CRysPoleStnd : public CRysPoleObraz
{
protected:
    QString cena_;
    int kolor_;

public:
    CRysPoleStnd();
    CRysPoleStnd(QPoint topLeft, QSizeF size, int poz, QString napis, QString path, QString cena, int kolor = 6, CWspSkalowaniaImg skalaImg = SKALA_IMG_STND, qreal rot = 0);
    virtual ~CRysPoleStnd();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

};

#endif // CRYSPOLESTND_H
