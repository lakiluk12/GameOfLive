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
        for (int j = 0; j < szerokosc_planszy; j++) {
            zywi_somsiedzi = 0;

            for(int k = -1; k < 2;k++){
                for(int l = -1; l < 2;l++){
                    if((i+k) >= 0 && (i+k) < wysokosc_planszy
                        && (j+l) >= 0 && (j+l) < szerokosc_planszy
                        && (l+k) != 0){
                        if(komorki_stare[i+k][j+l].GetStatusKomorki())
                            zywi_somsiedzi++;
                    }
                }
            }
            // if (i > 0) {
            //     if (komorki_stare[i - 1][j].GetStatusKomorki())
            //         zywi_somsiedzi++;
            // }
            // if (j > 0) {
            //     if (komorki_stare[i][j - 1].GetStatusKomorki())
            //         zywi_somsiedzi++;
            // }
            // if (i < wysokosc_planszy-1) {
            //     if (komorki_stare[i + 1][j].GetStatusKomorki())
            //         zywi_somsiedzi++;
            // }
            // if (j < szerokosc_planszy) {
            //     if (komorki_stare[i][j + 1].GetStatusKomorki())
            //         zywi_somsiedzi++;
            // }

            // if (i > 0 && j > 0) {
            //     if (komorki_stare[i - 1][j - 1].GetStatusKomorki())
            //         zywi_somsiedzi++;
            // }
            // if (i > 0 && j < szerokosc_planszy) {
            //     if (komorki_stare[i - 1][j + 1].GetStatusKomorki())
            //         zywi_somsiedzi++;
            // }
            // if (j < szerokosc_planszy-1 && i < wysokosc_planszy-1) {
            //     if (komorki_stare[i + 1][j + 1].GetStatusKomorki())
            //         zywi_somsiedzi++;
            // }
            // if (i < wysokosc_planszy-1 && j > 0) {
            //     if (komorki_stare[i + 1][j - 1].GetStatusKomorki())
            //         zywi_somsiedzi++;
            // }

            //zywi_somsiedzi = 3;

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
