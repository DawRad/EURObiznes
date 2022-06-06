#ifndef CONSTS_QT_H
#define CONSTS_QT_H

#include <QtWidgets>
#include "Rysunki_h/cwspskalowaniaimg.h"
//using QtWidgets::;

// kolory-Qt
const QColor Q_KOL_TLO_PANEL_GR(74, 48, 11);
const QColor Q_KOL_POLA_BAZA(189, 180, 123);
const QColor Q_KOL_ROG(199, 150, 97);
const QColor Q_KOL_PRZYCISKI1(135, 175, 230);
const QColor Q_KOL_PRZYCISKI1_DISAB(170, 190, 220);
const QColor Q_KOL_PRZYCISKI2(145, 240, 215);
const QColor Q_KOL_PRZYCISKI2_DISAB(175, 210, 200);

// wymiary
const QSizeF WYM_PIONA_WYBOR(100, 100);
const QSizeF WYM_PIONA_PLANSZA(20, 20);
const QSizeF WYM_PIONA_PAN_GR(80, 80);

const QSizeF WYM_POLA_ZWYKL_WYBOR(150, 240);
const QSizeF WYM_POLA_ZWYKL_PLANSZA(100, 160);

    /// pole kwadratowe w rogu planszy
const QSizeF WYM_POLA_NARKW_WYBOR(240, 240);
const QSizeF WYM_POLA_NARKW_PLANSZA(160, 160);

    /// pole z informacjami
const QSizeF WYM_POLA_INFO(400, 250);

    ///kostka - obraz
const QSize WYM_KOSTKI(0.25 * 110, 0.25 * 110);

    /// pole Stnd - obraz
    const QSize WYM_IMG_STND_WYBOR(0.9 * WYM_POLA_ZWYKL_WYBOR.width(), 0.35 * WYM_POLA_ZWYKL_WYBOR.height());
    const QSize WYM_IMG_STND_PLANSZA(0.9 * WYM_POLA_ZWYKL_PLANSZA.width(), 0.35 * WYM_POLA_ZWYKL_PLANSZA.height());

    /// pole "Szansa" - obraz
const QSize WYM_IMG_SZANSA_WYB(0.9 * WYM_POLA_ZWYKL_WYBOR.width(), 0.9 * WYM_POLA_ZWYKL_WYBOR.height());
const QSize WYM_IMG_SZANSA_PLANSZA(0.9 * WYM_POLA_ZWYKL_PLANSZA.width(), 0.9 * WYM_POLA_ZWYKL_PLANSZA.height());

    /// pole "róg


// współczynniki wymiarów obrazów
const CWspSkalowaniaImg SKALA_IMG_STND(0.9, 0.35);
const CWspSkalowaniaImg SKALA_IMG_SZANSA(0.9, 0.9);
const CWspSkalowaniaImg SKALA_KOSTKI(1, 1);
const CWspSkalowaniaImg SKALA_IMG_PPLUSW(0.4, 0.4);
const CWspSkalowaniaImg SKALA_IMG_START(0.9375, 0.3);


// punkty topLeft
const QPoint TOPLEFT_PIONA_WYBOR(-50, -50);
const QPoint TOPLEFT_PIONA_PLANSZA(-10, -10);
const QPoint TOPLEFT_PIONA_PAN_GR(-40, -40);

const QPoint TOPLEFT_POLA_ZWYKL_WYBOR(-75, -120);
const QPoint TOPLEFT_POLA_ZWYKL_PLANSZA(-50, -80);

    /// pole kwadratowe w rogu planszy
const QPoint TOPLEFT_POLA_NARKW_WYBOR(-120, -120);
const QPoint TOPLEFT_POLA_NARKW_PLANSZA(-80, -80);

    /// pole z informacjami
const QPoint TOPLEFT_POLE_INFO(-200, -125);

// pozycja pola info na planszy
const QPoint INFO_SCENE_POS(0, -100);

#endif // CONSTS_QT_H
