#ifndef CRYSROG_H
#define CRYSROG_H

#include <cmath>

#include "Rysunki_h/cryspole.h"






/**
 * @brief Klasa graficzna
 */
class CRysRog : public CRysPole
{
protected:
    QPolygon polygon_;
    QString napis_1_;

public:
    /**
     *
     * Polygon jest wprowadzany ręcznie.
     */
    CRysRog(QPoint topLeft, QSizeF size, int poz, QString napis, QPolygon polygon, QString napis_1, qreal rot = 0);

    /**
     *
     * Polygon określony automatycznie wg parametrów w konstruktorze
     */
    CRysRog(QPoint topLeft, QSizeF size, int poz, QString napis, QString napis_1, qreal rot = 0);

    ~CRysRog();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    virtual QPainterPath shape() const override;

    virtual void setSizeWithOtherDimUpdate(QSizeF size) override;
};

#endif // CRYSROG_H
