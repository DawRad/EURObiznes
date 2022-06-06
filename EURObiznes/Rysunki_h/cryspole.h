#ifndef CRYSPOLE_H
#define CRYSPOLE_H

#include "Rysunki_h/crys.h"






/**
 * @brief Klasa graficzna
 */
class CRysPole : public CRys
{
protected:
    int poz_;
    QString napis_;

public:
    CRysPole();
    CRysPole(QPoint topLeft, QSizeF size, int poz, QString napis, qreal rot = 0);
    ~CRysPole();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    virtual QPainterPath shape() const override;

    QString podajPozQStr();
    int podajPozInt();
};

#endif // CRYSPOLE_H
