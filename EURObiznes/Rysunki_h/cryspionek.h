#ifndef CRYSPIONEK_H
#define CRYSPIONEK_H

#include "Rysunki_h/crys.h"
#include "Rysunki_h/cnadawca.h"






/**
 * @brief Klasa graficzna
 */
class CRysPionek : public CRys
{
protected:        
    int shape_;
    int innerShape_;
    QColor kolor_;
    QColor innerKolor_;

    QTimer *sceneTimer_;
    CNadawca *wskWyzwalacza_;               // wskaźnik wyzwalacza z okna z planszą

    /// środek kolejnego pola w układzie obiektu tej klasy
    QPointF startPoz_;
    QPointF nastPoz_;

    // parametry ruchu
    int aktPozPola_;            // reprezentuje nr pozycji pola na planszy, na którym aktualnie znajduje się pionek
    int finPozPola_;            // reprezentuje nr pozycji pola na planszy, na które pionek ma się ostatecznie udać

    int krok_;
    int krokiDoZrob_;
    double dx_;

        /// pozwolenie na ruch
    bool moveToken_;

    /// parametry toru ruchu
    static double parA_;

public:
    CRysPionek();
    CRysPionek(QPoint topLeft, QSizeF size, int shape, int innerShape, int kolor, qreal rot = 0);

    /**
     * \brief Konstruktor z myślą o panelu gracza.
     *
     */
    CRysPionek(SDnPionka dane);

    ~CRysPionek();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    virtual QPainterPath shape() const override;

    SDnPionka podajSwojeSkladniki();

    void setShape(int shape);
    void setInnerShape(int innerShape);

    void setKolor(int kolor);
    void setTimer(QTimer *timer);
    void setWskWyzw(CNadawca *wskWyzw);

    // punkt pCelu ma być w układzie sceny
    void ustawParamRuchu(QPointF start, QPointF pCelu);
    void ustawParamRuchu(int kroki, QPointF start, QPointF pCelu);
    void ustawParamRuchu(int kroki, QPointF start, QPointF pCelu, int finPozPola);

    /**
     * /brief Do użycia w przypadku, gdy pion zmienił pozycję nie w wyniku
     * rzutu kośćmi.
     *
     */
    void zmienAktPoz(int aktPoz);

    static int innKolFromKol(int kolor);

protected:
    void advance(int step) override;

    void drawShape(QPainter *painter);
    void drawInnerShape(QPainter *painter);

    void drawInnerShapeBow(QPainter *painter);
    void drawInnerShapeThreeSquares(QPainter *painter);
    void drawInnerShapeFourCircles(QPainter *painter);
    void drawInnerShapeSquare8(QPainter *painter);
    void drawInnerShapeSemicircles(QPainter *painter);
    void drawInnerShapeSmallerGreater(QPainter *painter);


    // poruszanie na planszy
    void poziomoWLewo();
    void poziomoWPrawo();
    void pionowoWGore();
    void pionowoWDol();
};

#endif // CRYSPIONEK_H
