#ifndef CRYSPOLESZANSA_H
#define CRYSPOLESZANSA_H

#include "Rysunki_h/cryspoleobraz.h"






/**
 * @brief Klasa graficzna
 */
class CRysPoleSzansa : public CRysPoleObraz
{
public:
    CRysPoleSzansa();
    CRysPoleSzansa(QPoint topLeft, QSizeF size, int poz, QString napis, QString path, CWspSkalowaniaImg skalaImg = SKALA_IMG_SZANSA, qreal rot = 0);
    ~CRysPoleSzansa();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // CRYSPOLESZANSA_H
