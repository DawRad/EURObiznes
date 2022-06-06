#ifndef CNADAWCA_H
#define CNADAWCA_H

//#include <iostream>

#include <QObject>

using std::string;





/**
 * @brief Klasa graficzna
 */
class CNadawca : public QObject
{
    Q_OBJECT

    std::string imie_;

public:
    explicit CNadawca(string imie = "N_i", QObject *parent = nullptr);
    ~CNadawca();

    void emitPressedSig();

    void emitRzutWykonany();

    /**
     * \brief Odpowiada za emisję sygnału pionSiePoruszyl(int).
     *
     * Parametr wskazuje na pozycję na planszy pola, na które pion ma się poruszyć
     * w następnej kolejności.
     * Z założenia metoda ma być wywoływana w metodzie advance(int step) pionka, po przejściu
     * na kolejne pole, pod warunkiem, że pionek musi iść dalej.
     */
    void emitPionSiePoruszyl(int aktPozPola, int nastPozPola);

    void emitPionDotarl();

    void ustawImie(string imie);

signals:
    void wasPressed();
    void rzutWykonany();    
    void pionSiePoruszyl(int,int);
    void pionDotarl();

};

#endif // CNADAWCA_H
