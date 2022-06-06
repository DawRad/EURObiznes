#ifndef CRYSPOLESPEC_H
#define CRYSPOLESPEC_H

#include "Rysunki_h/cryspolestnd.h"






/**
 * @brief Klasa graficzna
 */
class CRysPoleSpec : public CRysPoleStnd
{
public:
    CRysPoleSpec();
    CRysPoleSpec(QPoint topLeft, QSizeF size, int poz, QString napis, QString path, QString cena, int kolor = 6, CWspSkalowaniaImg skalaImg = SKALA_IMG_STND, qreal rot = 0);
    ~CRysPoleSpec();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // CRYSPOLESPEC_H
