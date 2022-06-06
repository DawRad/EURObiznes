QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Logika_src/cczlowiek.cpp \
    Logika_src/cgame.cpp \
    Logika_src/cgracz.cpp \
    Logika_src/ckarta.cpp \
    Logika_src/ckartakwoty.cpp \
    Logika_src/ckartaruchu.cpp \
    Logika_src/ckartawiezienia.cpp \
    Logika_src/ckartawolnosc.cpp \
    Logika_src/ckomputer.cpp \
    Logika_src/cplansza.cpp \
    Logika_src/cpole.cpp \
    Logika_src/cpoledowiezienia.cpp \
    Logika_src/cpoleekstra.cpp \
    Logika_src/cpolekasa.cpp \
    Logika_src/cpolespec.cpp \
    Logika_src/cpolestnd.cpp \
    Logika_src/cpoleszansa.cpp \
    Rysunki_src/cnadawca.cpp \
    Rysunki_src/crys.cpp \
    Rysunki_src/crysemiter.cpp \
    Rysunki_src/crysinfo.cpp \
    Rysunki_src/cryskostki.cpp \
    Rysunki_src/cryspanelgracza.cpp \
    Rysunki_src/cryspionek.cpp \
    Rysunki_src/cryspole.cpp \
    Rysunki_src/cryspole_pplusw.cpp \
    Rysunki_src/cryspoleobraz.cpp \
    Rysunki_src/cryspolespec.cpp \
    Rysunki_src/cryspolestart.cpp \
    Rysunki_src/cryspolestnd.cpp \
    Rysunki_src/cryspoleszansa.cpp \
    Rysunki_src/crysprzycisk.cpp \
    Rysunki_src/crysprzyciskimg.cpp \
    Rysunki_src/crysrog.cpp \
    Rysunki_src/cwspskalowaniaimg.cpp \
    cadministratorcrys.cpp \
    main.cpp \
    mainwindow.cpp \
    nggracze.cpp \
    ngogolne.cpp \
    ngplansza.cpp \
    rozgrywka.cpp \
    wlasnosci.cpp

HEADERS += \
    Consts.h \
    Logika_h/Stale.h \
    Logika_h/Struktury.h \
    Logika_h/cczlowiek.h \
    Logika_h/cgame.h \
    Logika_h/cgracz.h \
    Logika_h/ckarta.h \
    Logika_h/ckartakwoty.h \
    Logika_h/ckartaruchu.h \
    Logika_h/ckartawiezienia.h \
    Logika_h/ckartawolnosc.h \
    Logika_h/ckomputer.h \
    Logika_h/cplansza.h \
    Logika_h/cpole.h \
    Logika_h/cpoledowiezienia.h \
    Logika_h/cpoleekstra.h \
    Logika_h/cpolekasa.h \
    Logika_h/cpolespec.h \
    Logika_h/cpolestnd.h \
    Logika_h/cpoleszansa.h \
    Rysunki_h/Consts_Qt.h \
    Rysunki_h/Structs_Qt.h \
    Rysunki_h/cnadawca.h \
    Rysunki_h/crys.h \
    Rysunki_h/crysemiter.h \
    Rysunki_h/crysinfo.h \
    Rysunki_h/cryskostki.h \
    Rysunki_h/cryspanelgracza.h \
    Rysunki_h/cryspionek.h \
    Rysunki_h/cryspole.h \
    Rysunki_h/cryspole_pplusw.h \
    Rysunki_h/cryspoleobraz.h \
    Rysunki_h/cryspolespec.h \
    Rysunki_h/cryspolestart.h \
    Rysunki_h/cryspolestnd.h \
    Rysunki_h/cryspoleszansa.h \
    Rysunki_h/crysprzycisk.h \
    Rysunki_h/crysprzyciskimg.h \
    Rysunki_h/crysrog.h \
    Rysunki_h/cwspskalowaniaimg.h \
    cadministratorcrys.h \
    mainwindow.h \
    nggracze.h \
    ngogolne.h \
    ngplansza.h \
    rozgrywka.h \
    wlasnosci.h

FORMS += \
    mainwindow.ui \
    nggracze.ui \
    ngogolne.ui \
    ngplansza.ui \
    rozgrywka.ui \
    wlasnosci.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Zasoby.qrc
