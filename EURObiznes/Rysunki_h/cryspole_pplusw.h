#ifndef CRYSPOLE_PPLUSW_H
#define CRYSPOLE_PPLUSW_H

#include "Rysunki_h/cryspoleobraz.h"





/**
 * @brief Klasa graficzna
 */
class CRysPole_PplusW : public CRysPoleObraz
{
protected:
    QString napis_1_;

public:
    CRysPole_PplusW();
    CRysPole_PplusW(QPoint topLeft, QSizeF size, int poz, QString napis [], QString path, CWspSkalowaniaImg skalaImg = SKALA_IMG_PPLUSW, qreal rot = 0);
    ~CRysPole_PplusW();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // CRYSPOLE_PPLUSW_H
