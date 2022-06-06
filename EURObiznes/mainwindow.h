#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "Logika_h/cgame.h"

// okna poboczne
#include "ngogolne.h"
#include "nggracze.h"
#include "ngplansza.h"
#include "rozgrywka.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



/**
 * @brief Klasa graficzna - okno główne
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * \brief Tworzy rysunki pól na podstawie kolejki danych pobranych z pola gra_
     */
    void utworzRysPol(deque<SDnPola> *danePol);


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
    // wczytywanie danych
    deque<string> *pobierzDanePolZPliku(QString nazPli);

    // metody do destruktora
    void czyszczenieDeques();


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private slots:
    void on_pbNowaGra_clicked();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // moje sloty

    void pokazSie();

    void oknoOgolneDalej(int kwota);

    void oknoGraczyWstecz();

    void oknoGraczyDalej();

    void oknoPlanszyGraj();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
    Ui::MainWindow *ui;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // okna poboczne

    NGOgolne *nowaGraOgolne_;

    NGGracze *oknoGraczy_;

    NGPlansza *oknoPlanszy_;

    Rozgrywka *oknoRozgrywki_;

    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // gra

    CGame *gra_;

    QString waluta_;

    QTimer *zegarmistrzSwiatla_;

    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // grafika

    deque<CRysPionek *> *pionki_;

    deque<CRysPole *> *pola_;

    // * * * * * * * * * *
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // flagi okna
    bool oknoOgolneCrtd_;           // czy utworzone nowaGraOgolne_
    bool oknoGraczCrtd_;            // czy utworzone okno graczy
    bool oknoPlanszyCrtd_;          // czy utworzone okno planszy
    bool oknoRozgrywkiCrtd_;          // czy utworzone okno rozgrywki

    bool *endGame_;                  // czy upłynął czas rozgrywki

};
#endif // MAINWINDOW_H
