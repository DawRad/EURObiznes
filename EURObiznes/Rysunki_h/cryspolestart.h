#ifndef CRYSPOLESTART_H
#define CRYSPOLESTART_H

#include "Rysunki_h/cryspoleobraz.h"






/**
 * @brief Klasa graficzna
 */
class CRysPoleStart : public CRysPoleObraz
{
    QString napis_1_;
    QString napis_2_;

public:
    CRysPoleStart();
    CRysPoleStart(QPoint topLeft, QSizeF size, int poz, QString napis[], QString path, CWspSkalowaniaImg skalaImg = SKALA_IMG_START, qreal rot = 0);
    ~CRysPoleStart();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void aktualKwote(int kwota, QString waluta);
};

#endif // CRYSPOLESTART_H
