#ifndef PLANSZA_H
#define PLANSZA_H

#include "logika.h"

class plansza
{
private:
    int wysokosc;
    int szerokosc;
    komorka **komorki;
    int generacja;
    logika *logika_planszy;
public:
    plansza(int zadana_wysokosc, int zadana_szerokosc, int zasieg = 1);
    void SetWysokosc(int nowa);
    void SetSzerokosc(int nowa);
    int GetWysokosc();
    int GetSzerokosc();
    void KolejnaGeneracja();
    komorka** GetKomorki();
    void NewKomorki();
    void SetKomorki(komorka** nowa_plansza);
};

#endif // PLANSZA_H
