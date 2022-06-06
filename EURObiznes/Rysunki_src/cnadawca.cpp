#include "Rysunki_h/cnadawca.h"





CNadawca::CNadawca(string imie, QObject *parent) : QObject(parent)
{
    imie_ = imie;
}





CNadawca::~CNadawca()
{

}





void CNadawca::emitPressedSig()
{
    emit wasPressed();
}





void CNadawca::emitRzutWykonany()
{
    emit rzutWykonany();
}





void CNadawca::emitPionSiePoruszyl(int aktPozPola, int nastPozPola)
{
    emit pionSiePoruszyl(aktPozPola, nastPozPola);
}





void CNadawca::emitPionDotarl()
{
    emit pionDotarl();
}





void CNadawca::ustawImie(string imie)
{
    imie_ = imie;
}
