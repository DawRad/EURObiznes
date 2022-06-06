#ifndef NGOGOLNE_H
#define NGOGOLNE_H

#include <QDialog>

#include "cadministratorcrys.h"





namespace Ui {
class NGOgolne;
}


/**
 * @brief Klasa graficzna - okno ustawień ogólnych
 */
class NGOgolne : public QDialog
{
    Q_OBJECT

public:
    explicit NGOgolne(CGame *gra, QWidget *parent = nullptr);
    ~NGOgolne();

signals:
    void wstecz();
    void dalej(int kwota);

private slots:
    void on_pbWstecz_clicked();

    void on_pbDalej_clicked();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // moje sloty    

private:
    Ui::NGOgolne *ui;   

    CGame *wskGry_;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // flagi okna
    bool childWindowCreated_;

};

#endif // NGOGOLNE_H
