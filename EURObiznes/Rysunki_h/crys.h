#ifndef CRYS_H
#define CRYS_H

//#include <iostream>
#include <cmath>

#include <QtMath>

#include "Consts.h"
#include "Rysunki_h/Structs_Qt.h"

using std::string;






/**
 * @brief Klasa graficzna
 */
class CRys : public QGraphicsItem
{
protected:
    QPoint topLeft_;
    QSizeF size_;
    qreal rotation_;

public:
    CRys();
    CRys(QPoint topLeft, QSizeF size, qreal rotS = 0);
    virtual ~CRys();

    QRectF boundingRect() const override;    
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override = 0;
    virtual QPainterPath shape() const override = 0;

    // * * * * * * * * * * * * * * *
    // metody do ustawiania atrybutów
    void setTopLeft(QPoint topLeft);

    virtual void setSize(QSizeF size);

    /**
     * \brief Funkcja wirtualna na wypadek, gdyby od pola size_ zależały inne parametry
     *
     */
    virtual void setSizeWithOtherDimUpdate(QSizeF size);

    void setRotation(qreal rot);



    /**
     * @param rot - rotacja w stopniach. Wartość rotacji jest większa od zera, gdy rotacja jest przeprowadzana przeciwnie do ruchu wskazówek
     * zegara
     */
    static QPoint mapToRot(QPoint point, qreal rot);

    static QPointF mapToRot(QPointF pointF, qreal rot);

    static QRectF mapToRot(QRectF rect, qreal rot);

    /**
     * \brief Funkcja zamieniająca atrybut kolor z typu int na typ QColor
     */
    static QColor colorIntToQCol(int color);

};

#endif // CRYS_H
