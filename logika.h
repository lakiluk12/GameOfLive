#ifndef LOGIKA_H
#define LOGIKA_H

#include "komorka.h"
class logika
{
private:
    int wysokosc_planszy;
    int szerokosc_planszy;
    int zasieg;
public:
    logika(int zadany_zasieg = 1, int zadana_wysokosc = 1, int zadana_szerokosc = 1):zasieg(zadany_zasieg)
    {}
    komorka** Zasady(komorka **komorki_stare);

};

#endif // LOGIKA_H
