#ifndef CRYSEMITER_H
#define CRYSEMITER_H

#include "Rysunki_h/crys.h"
#include "Rysunki_h/cnadawca.h"





/**
 * @brief Klasa graficzna
 */
class CRysEmiter : public CRys
{
protected:
    CNadawca *nadawca_;

public:
    CRysEmiter();
    CRysEmiter(QPoint topLeft, QSizeF size, string imieNad = "brak", qreal rot = 0);
    virtual ~CRysEmiter();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override = 0;
    virtual QPainterPath shape() const override = 0;

    QObject *podajNadawce();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override = 0;
};

#endif // CRYSEMITER_H
