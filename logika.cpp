#include "logika.h"

komorka** logika::Zasady(komorka **komorki_stare){
    bool stan_komorki;
    komorka **komorki;
    komorki = new komorka*[wysokosc_planszy];
    for(int i = 0; i < wysokosc_planszy; i++){
        komorki[i] = new komorka[szerokosc_planszy];
    }
    int zywi_somsiedzi;
    bool szerokosc_min, wysokosc_min, szerokosc_max, wysokosc_max;

    for(int i = 0; i < wysokosc_planszy; i++){
        zywi_somsiedzi = 0;
        for(int j = 0; i< szerokosc_planszy; i++){
            stan_komorki = komorki_stare[i][j].GetStatusKomorki();
            if(i > 0){
                if(komorki_stare[i-1][j].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if(j > 0){
                if(komorki_stare[i][j-1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if(i < wysokosc_planszy){
                if(komorki_stare[i+1][j].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if(j < szerokosc_planszy){
                if(komorki_stare[i][j+1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }


            if(i > 0 && j > 0){
                if(komorki_stare[i-1][j-1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if(j > 0 && j < szerokosc_planszy){
                if(komorki_stare[i-1][j+1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if(j < szerokosc_planszy && i < wysokosc_planszy){
                if(komorki_stare[i+1][j+1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if(i < wysokosc_planszy && j > 0){
                if(komorki_stare[i+1][j-1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }

            if(zywi_somsiedzi == 3){
                komorki[i][j].SetStatusKomorki(true);
            }else if(stan_komorki && zywi_somsiedzi == 2){
                komorki[i][j].SetStatusKomorki(true);
            }else{
                komorki[i][j].SetStatusKomorki(false);
            }
        }
    }
    for(int i = 0; i < wysokosc_planszy; i++){
        delete [] komorki_stare[i];
    }
    delete [] komorki_stare;

    return komorki;


}
