#include "plansza.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

plansza::plansza(int zadana_wysokosc, int zadana_szerokosc, int zasieg):generacja(0){
    if(zadana_wysokosc <= 0 || zadana_szerokosc <= 0){
        zadana_szerokosc = 8;
        zadana_wysokosc = 8;
    }
    if(zasieg <= 0){
        zasieg = 1;
    }
    logika_planszy = new logika(zasieg);

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
    komorki = logika_planszy->Zasady(komorki, szerokosc, wysokosc);
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

void plansza::ClearPlansza(){
    for(int i = 0; i < wysokosc; i++){
        for(int j = 0; j < szerokosc; j++){
            komorki[i][j].SetStatusKomorki(false);
        }
    }
}
int plansza::GetGeneracja(){
    return generacja;
}
void plansza::LosujStan(){
    std::srand( time( NULL ) );
    for(int i = 0; i < wysokosc; i++){
        for(int j = 0; j < szerokosc; j++){
            if(std::rand()%100<=20)
            komorki[i][j].SetStatusKomorki(true);
        }
    }
}
