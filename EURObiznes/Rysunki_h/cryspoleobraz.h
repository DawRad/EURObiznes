#ifndef CRYSPOLEOBRAZ_H
#define CRYSPOLEOBRAZ_H

#include "Rysunki_h/cryspole.h"






/**
 * @brief Klasa graficzna
 */
class CRysPoleObraz : public CRysPole
{
protected:
    QString imagePath_;
    QImage *image_;
    CWspSkalowaniaImg skalaImg_;

public:
    CRysPoleObraz();
    CRysPoleObraz(QPoint topLeft, QSizeF size, int poz, QString napis, QString path, CWspSkalowaniaImg skalaImg = SKALA_KOSTKI, qreal rot = 0);
    virtual ~CRysPoleObraz();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void setSize(QSizeF size) override;

    void drawMyImage(QPainter *painter,QRectF rect);
};

#endif // CRYSPOLEOBRAZ_H
