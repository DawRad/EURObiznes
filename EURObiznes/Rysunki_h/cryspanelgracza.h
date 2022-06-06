#ifndef CRYSPANELGRACZA_H
#define CRYSPANELGRACZA_H

#include "crys.h"

#include "cadministratorcrys.h"





/**
 * @brief Klasa graficzna
 */
class CRysPanelGracza : public CRys
{
protected:
    bool crtdMark_;

    CRysPionek *pionek_;
    QString rodzGracza_;
    QString nick_;
    QString portfel_;
    QString lbKartWolnosc_;
    QString imgPath_;

public:
    CRysPanelGracza();
    CRysPanelGracza(QPoint topLeft, QSizeF size, SDnPionka danePionka, SDnGracza daneGr, QString imgPath = ":/Zasoby/grafika/tla/tablica.jpg", qreal rot = 0);
    ~CRysPanelGracza();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    virtual QPainterPath shape() const override;

    void aktualizujPanel(SDnPionka danePionka, string rodzGracza, string nick, int portfel, int lbKart);
    void aktualizujPanel(SDnPionka danePionka, SDnGracza daneGr);
    void aktualNapisPortfel(int portfel);
    void aktualNapislbKartWolnosc(int lbKart);
    void graczUzylKartyWolnosc();

    static QString odkodujRodzGracza(string rodzGracza);
};

#endif // CRYSPANELGRACZA_H
