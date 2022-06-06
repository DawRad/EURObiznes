#ifndef STRUCTS_QT_H
#define STRUCTS_QT_H

#include "Consts_Qt.h"





/**
 * @brief Struktura graficzna
 *
 * Przechowuje dane pionka potrzebne do utworzenia obiektu tej
 * klasy.
 */
struct SDnPionka
{
    QPoint topLeft;
    QSizeF size;
    int shape;
    int innerShape;
    QColor kolor;
    QColor innerKolor;
    qreal rot;
};


#endif // STRUCTS_QT_H
