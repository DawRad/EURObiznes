#ifndef CRYSINFO_H
#define CRYSINFO_H

#include "Rysunki_h/crys.h"
#include "cadministratorcrys.h"







/**
 * @brief Klasa graficzna
 */
class CRysInfo : public CRys
{
protected:
    QString imgPath_;
    QString text_;

public:
    CRysInfo(QPoint topLeft = TOPLEFT_POLE_INFO, QSizeF size = WYM_POLA_INFO, QString imgPath = ":/Zasoby/grafika/tla/pergamin.png", qreal rot = 0);
    ~CRysInfo();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    virtual QPainterPath shape() const override;

    void ustawText(string tresc);
};

#endif // CRYSINFO_H
