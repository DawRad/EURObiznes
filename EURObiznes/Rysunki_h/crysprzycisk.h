#ifndef CRYSPRZYCISK_H
#define CRYSPRZYCISK_H

#include "Rysunki_h/crysemiter.h"





/**
 * @brief Klasa graficzna
 */
class CRysPrzycisk : public CRysEmiter
{
protected:

    /* 0 ---> rect
     * 1 ---> ellipse
     */
    int shape_;

    QString nazwa_;

public:
    CRysPrzycisk();
    CRysPrzycisk(QPoint topLeft, QSizeF size, QString nazwa, int shape, string imieNad = "brak", qreal rot = 0);
    virtual ~CRysPrzycisk();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    virtual QPainterPath shape() const override;



protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void drawShape(QPainter *painter);
};

#endif // CRYSPRZYCISK_H
