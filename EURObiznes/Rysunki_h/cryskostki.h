#ifndef CRYSKOSTKI_H
#define CRYSKOSTKI_H

#include "Rysunki_h/cryspoleobraz.h"
#include "Rysunki_h/cnadawca.h"






/**
 * @brief Klasa graficzna
 */
class CRysKostki : public CRysPoleObraz
{
protected:
    int faza_;
    bool moveToken_;
    bool primaryDice_;
    QString oczka_;
    QTimer *timer_;

    /// wskaźnik CNadawca z okna rozgrywki
    CNadawca *wskWyzwalacza_;


public:
    CRysKostki();
    CRysKostki(QPoint topLeft, QSizeF size, QTimer *timer, CNadawca *wskNadawcy, int poz = -1, QString napis = "",
               QString imgPath = ":/Zasoby/grafika/inne_elementy/oczko_0.png", CWspSkalowaniaImg skalaImg = SKALA_KOSTKI, qreal rot = 0);
    ~CRysKostki();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void ustawOczka(QString oczka);
    void ustawOczka(int oczka);

    /**
     *  \brief Metoda ustala, która kostka wysyła sygnał rzutWykonany()
     *
     * Jeśli state == false - kostka nie wysyła, jeśli state == true - wysyła.
     * Należy dbać, aby podczas gry tylko jedna z używanych kostek miała wartość pola
     * primaryDice_ == true (domyślnie podczas tworzenia wszystkie instancje tej klasy mają wartość false).
     */
    void setPrimaryDice(bool state);

    void drawMyUpdatedImage(QPainter *painter, QRectF rect);


protected:
    void advance(int step) override;
};

#endif // CRYSKOSTKI_H
