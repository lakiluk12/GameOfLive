#include "logika.h"

komorka** logika::Zasady(komorka **komorki_stare, int szerokosc_planszy, int wysokosc_planszy){
    bool stan_komorki;
    komorka **komorki;
    komorki = new komorka*[wysokosc_planszy];
    for(int i = 0; i < wysokosc_planszy; i++){
        komorki[i] = new komorka[szerokosc_planszy];
    }
    for(int i = 0; i < wysokosc_planszy; i++){
        for(int j = 0; j < szerokosc_planszy; j++){
            komorki[i][j].SetStatusKomorki(false);
        }
    }
    int zywi_somsiedzi;
   // komorki[1][1].SetStatusKomorki(true);

    // for(int k = -1; i =< 1; i++){
    //     for(int l = -1; i =< 1; i++){
    //         if(k == 0 && l == 0)
    //             continue;
    //         if(i-k>==0)
    //            }
    // }

    for (int i = 0; i < wysokosc_planszy; i++) {
        for (int j = 0; i < szerokosc_planszy; i++) {
            zywi_somsiedzi = 0;

            if (i > 0) {
                if (komorki_stare[i - 1][j].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if (j > 0) {
                if (komorki_stare[i][j - 1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if (i < wysokosc_planszy) {
                if (komorki_stare[i + 1][j].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if (j < szerokosc_planszy) {
                if (komorki_stare[i][j + 1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }

            if (i > 0 && j > 0) {
                if (komorki_stare[i - 1][j - 1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if (j > 0 && j < szerokosc_planszy) {
                if (komorki_stare[i - 1][j + 1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if (j < szerokosc_planszy && i < wysokosc_planszy) {
                if (komorki_stare[i + 1][j + 1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }
            if (i < wysokosc_planszy && j > 0) {
                if (komorki_stare[i + 1][j - 1].GetStatusKomorki())
                    zywi_somsiedzi++;
            }

            stan_komorki = komorki_stare[i][j].GetStatusKomorki();
            if (zywi_somsiedzi == 3) {
                komorki[i][j].SetStatusKomorki(true);
            } else if (stan_komorki && zywi_somsiedzi == 2) {
                komorki[i][j].SetStatusKomorki(true);
            } else {
                komorki[i][j].SetStatusKomorki(false);
            }
        }
    }
    for (int i = 0; i < wysokosc_planszy; i++) {
        delete [] komorki_stare[i];
    }
    delete [] komorki_stare;

    return komorki;


}
