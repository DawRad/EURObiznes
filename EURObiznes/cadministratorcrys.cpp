#include "cadministratorcrys.h"





CAdministratorCRys::CAdministratorCRys()
{

}





void CAdministratorCRys::przesunPolePozZeroNaPocz(deque<CRysPole *> *pola)
{
    // szukanie pola o pozycji 0
    int index = 0;
    int size = pola->size();

    for(int i = 0; i < size; i++)
        if(pola->at(i)->podajPozInt() == 0)
        {
            index = i;
            break;
        }

    if(abs(size - index) <= index)
    {
        while(pola->at(0)->podajPozInt() != 0)
            dequeCRysPolePrzod(pola);
    }
    else
    {
        while(pola->at(0)->podajPozInt() != 0)
            dequeCRysPoleTyl(pola);
    }
}





void CAdministratorCRys::aktualPensjeNaStart(deque<CRysPole *> *pola, int kwota, QString waluta)
{
    for(deque<CRysPole *>::iterator it = pola->begin(); it != pola->end(); it++)
        if((*it)->podajPozInt() == P_START)
        {
            CRysPoleStart *tmp = dynamic_cast<CRysPoleStart *>(*it);
            if(tmp != NULL)
                tmp->aktualKwote(kwota, waluta);

            break;
        }
}





void CAdministratorCRys::dequeIntPrzod(deque<int> &kolejka)
{
    int tmp = kolejka.at(0);
    kolejka.pop_front();
    kolejka.push_back(tmp);
}





void CAdministratorCRys::dequeIntTyl(deque<int> &kolejka)
{
    int tmp = kolejka.back();
    kolejka.pop_back();
    kolejka.push_front(tmp);
}





void CAdministratorCRys::dequeCRysPionekPrzod(deque<CRysPionek *> *pionki)
{
    CRysPionek *tmpPion = pionki->at(0);
    pionki->pop_front();
    pionki->push_back(tmpPion);
}





void CAdministratorCRys::dequeCRysPionekTyl(deque<CRysPionek *> *pionki)
{
    CRysPionek *tmpPion = pionki->back();
    pionki->pop_back();
    pionki->push_front(tmpPion);
}





void CAdministratorCRys::dequeCRysPolePrzod(deque<CRysPole *> *pola)
{
    CRysPole *tmpPole = pola->at(0);
    pola->pop_front();
    pola->push_back(tmpPole);
}





void CAdministratorCRys::dequeCRysPoleTyl(deque<CRysPole *> *pola)
{
    CRysPole *tmpPole = pola->back();
    pola->pop_back();
    pola->push_front(tmpPole);
}





void CAdministratorCRys::wyczyscDequeCRysPole(deque<CRysPole *> *deqPol)
{
    for(deque<CRysPole *>::iterator it; it != deqPol->end(); it++)
        delete *it;

    deqPol->clear();
}




CRysPoleStnd *CAdministratorCRys::utworzRysPolaStndZDnPol(const SDnPola &dane)
{
    return new CRysPoleStnd(TOPLEFT_POLA_ZWYKL_WYBOR, WYM_POLA_ZWYKL_WYBOR,
                            dane.poz, QString::fromStdString(dane.atrybuty.at(0).data),
                            ":/Zasoby/grafika/ikony_pol/poz_" + QString::fromStdString(to_string(dane.poz)) + ".png",
                            QString::fromStdString(dane.atrybuty.at(1).data),
                            std::stoi(dane.atrybuty.at(5).data));
}





CRysPoleSpec *CAdministratorCRys::utworzRysPolaSpecZDnPol(const SDnPola &dane)
{
    return new CRysPoleSpec(TOPLEFT_POLA_ZWYKL_WYBOR,
                            WYM_POLA_ZWYKL_WYBOR,
                            dane.poz,
                            QString::fromStdString(dane.atrybuty.at(0).data),
                            ":/Zasoby/grafika/ikony_pol/poz_" + QString::fromStdString(to_string(dane.poz)) + ".png",
                            QString::fromStdString(dane.atrybuty.at(1).data));
}





CRysPoleSzansa *CAdministratorCRys::utworzRysPolaSzansaZDnPol(const SDnPola &dane)
{
    return new CRysPoleSzansa(TOPLEFT_POLA_ZWYKL_WYBOR,
                              WYM_POLA_ZWYKL_WYBOR,
                              dane.poz,
                              QString::fromStdString(dane.atrybuty.at(0).data),
                              ":/Zasoby/grafika/ikony_pol/pytajnik.png");
}





CRysPoleSzansa *CAdministratorCRys::utworzRysPolaKasaZDnPol(const SDnPola &dane)
{
    return new CRysPoleSzansa(TOPLEFT_POLA_ZWYKL_WYBOR,
                              WYM_POLA_ZWYKL_WYBOR,
                              dane.poz,
                              QString::fromStdString(dane.atrybuty.at(0).data),
                              ":/Zasoby/grafika/ikony_pol/skarbiec.png");
}





CRysPoleStart *CAdministratorCRys::utworzRysPolaStartZDnPol(const SDnPola &dane, QString &waluta)
{
    QString napisy[3];
    napisy[0] = "Przechodząc przez";
    napisy[1] = QString::fromStdString(dane.atrybuty.at(0).data);
    napisy[2] = "pobierz " + QString::fromStdString(dane.atrybuty.at(1).data) + " " + waluta;

    return new CRysPoleStart(TOPLEFT_POLA_NARKW_WYBOR,
                             WYM_POLA_NARKW_WYBOR,
                             dane.poz,
                             napisy,
                             ":/Zasoby/grafika/ikony_pol/poz_" + QString::fromStdString(to_string(dane.poz)) + ".png");
}





CRysPole_PplusW *CAdministratorCRys::utworzRysPola_PplusW_ZDnPol(const SDnPola &dane, QString &napis2)
{
    QString napisy[2];
    napisy[0] = QString::fromStdString(dane.atrybuty.at(0).data);
    napisy[1] = napis2;

    return new CRysPole_PplusW(TOPLEFT_POLA_NARKW_WYBOR,
                               WYM_POLA_NARKW_WYBOR,
                               dane.poz,
                               napisy,
                               ":/Zasoby/grafika/ikony_pol/poz_" + QString::fromStdString(to_string(dane.poz)) + ".png");
}





CRysRog *CAdministratorCRys::utworzRysPolaRogZDnPol(const SDnPola &dane)
{
    return new CRysRog(TOPLEFT_POLA_NARKW_WYBOR,
                       WYM_POLA_NARKW_WYBOR,
                       dane.poz,
                       QString::fromStdString(dane.atrybuty.at(0).data),
                       QString::fromStdString(dane.atrybuty.at(0).data));
}





CRysPoleObraz *CAdministratorCRys::utworzRysPolaObrazZDnPol(const SDnPola &dane)
{
    return new CRysPoleObraz(TOPLEFT_POLA_ZWYKL_WYBOR,
                              WYM_POLA_ZWYKL_WYBOR,
                              dane.poz,
                              QString::fromStdString(dane.atrybuty.at(0).data),
                              ":/Zasoby/grafika/ikony_pol/poz_" + QString::fromStdString(to_string(dane.poz)) + ".png");
}





CRysPoleSzansa *CAdministratorCRys::utworzRysPolaZErroremZDnPol(const SDnPola &dane)
{
    return new CRysPoleSzansa(TOPLEFT_POLA_ZWYKL_WYBOR,
                              WYM_POLA_ZWYKL_WYBOR,
                              dane.poz,
                              QString::fromStdString(dane.atrybuty.at(0).data),
                              ":/Zasoby/grafika/ikony_pol/error.png");
}





deque<CRysPole *> CAdministratorCRys::utworzKolejkePol(deque<SDnPola> &danePol)
{
    deque<CRysPole *> wyn;

    for(deque<SDnPola>::iterator it = danePol.begin(); it != danePol.end(); it++)
    {
        switch(it->rodz)
        {
        case 0:
            wyn.push_back(utworzRysPolaSpecZDnPol(*it));
            break;

        case 1:
            wyn.push_back(utworzRysPolaStndZDnPol(*it));
            break;

        case 2:
            wyn.push_back(utworzRysPolaSpecZDnPol(*it));
            break;

        case 3:
            wyn.push_back(utworzRysPolaObrazZDnPol(*it));
            break;

        case 4:
            wyn.push_back(utworzRysPolaKasaZDnPol(*it));
            break;

        case 5:
            wyn.push_back(utworzRysPolaSzansaZDnPol(*it));
            break;

        case 6:
            {
                QString napis;
                if(it->poz == P_PARKING)
                {
                    napis = "PARKING";
                    wyn.push_back(utworzRysPola_PplusW_ZDnPol(*it, napis));
                }
                else if(it->poz == P_DO_WIEZ)
                {
                    napis = "";
                    wyn.push_back(utworzRysPola_PplusW_ZDnPol(*it, napis));
                }
            };
            break;

        default:
            break;
        }
    }

    return wyn;
}





void CAdministratorCRys::zamienNaCRysPolaStnd(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene)
{
    CRysPole *tmp = deqPol->at(0);
    deqPol->at(0) = utworzRysPolaStndZDnPol(dane);

    scene->removeItem(tmp);
    delete tmp;
}





void CAdministratorCRys::zamienNaCRysPolaSpec(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene)
{
    CRysPole *tmp = deqPol->at(0);
    deqPol->at(0) = utworzRysPolaSpecZDnPol(dane);

    scene->removeItem(tmp);
    delete tmp;
}





void CAdministratorCRys::zamienNaCRysPolaEkstra(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene)
{
    CRysPole *tmp = deqPol->at(0);
    deqPol->at(0) = utworzRysPolaSpecZDnPol(dane);

    scene->removeItem(tmp);
    delete tmp;
}





void CAdministratorCRys::zamienNaCRysPolaSzansa(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene)
{
    CRysPole *tmp = deqPol->at(0);
    deqPol->at(0) = utworzRysPolaSzansaZDnPol(dane);

    scene->removeItem(tmp);
    delete tmp;
}





void CAdministratorCRys::zamienNaCRysPolaKasa(deque<CRysPole *> *deqPol, const SDnPola &dane, QGraphicsScene *scene)
{
    CRysPole *tmp = deqPol->at(0);
    deqPol->at(0) = utworzRysPolaKasaZDnPol(dane);

    scene->removeItem(tmp);
    delete tmp;
}




