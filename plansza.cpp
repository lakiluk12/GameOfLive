#include "plansza.h"

plansza::plansza(int zadana_wysokosc, int zadana_szerokosc, int zasieg):generacja(0){
    if(zadana_wysokosc <= 0 || zadana_szerokosc <= 0){
        zadana_szerokosc = 8;
        zadana_wysokosc = 8;
    }
    if(zasieg <= 0){
        zasieg = 1;
    }
    logika_planszy = new logika(zasieg, wysokosc, szerokosc);

}
void plansza::SetWysokosc(int nowa){
    wysokosc = nowa;
}
void plansza::SetSzerokosc(int nowa){
    szerokosc = nowa;
}
int plansza::GetWysokosc(){
    return wysokosc;
}
int plansza::GetSzerokosc(){
    return szerokosc;
}
void plansza::KolejnaGeneracja(){
    komorki = logika_planszy->Zasady(komorki);
    generacja++;
}
komorka** plansza::GetKomorki(){
    return komorki;
}
void plansza::NewKomorki(){
    komorki = new komorka*[wysokosc];
    for(int i = 0; i < wysokosc;i++){
        komorki[i] = new komorka[szerokosc];
    }
}
void plansza::SetKomorki(komorka** nowa_plansza){
    komorki = nowa_plansza;
}
