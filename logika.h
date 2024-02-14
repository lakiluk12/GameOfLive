#ifndef LOGIKA_H
#define LOGIKA_H

#include "komorka.h"
class logika
{
private:
    int zasieg;
public:
    logika(int zadany_zasieg = 1):zasieg(zadany_zasieg)
    {}
    komorka** Zasady(komorka **komorki_stare, int szerokosc_planszy, int wysokosc_planszy);

};

#endif // LOGIKA_H
