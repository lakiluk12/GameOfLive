#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <cstdlib>
#include <ctime>

class komorka
{
private:
    bool status_komorki;

public:
    void SetStatusKomorki(bool status) { status_komorki = status; }
    bool GetStatusKomorki() { return status_komorki; }
};

class logika
{
private:
    int wysokosc_planszy;
    int szerokosc_planszy;
    int szansa;

public:
    logika( int zadana_wysokosc = 8, int zadana_szerokosc = 8, int zadana_szansa = 20)
        : wysokosc_planszy(zadana_wysokosc), szerokosc_planszy(zadana_szerokosc), szansa(zadana_szansa)
    {}
    komorka **Zasady(komorka **komorki_stare)
    {
        bool stan_komorki;
        komorka **komorki;
        komorki = new komorka *[wysokosc_planszy];
        for (int i = 0; i < wysokosc_planszy; i++) {
            komorki[i] = new komorka[szerokosc_planszy];
        }
        int zywi_somsiedzi;

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
            delete[] komorki_stare[i];
        }
        delete[] komorki_stare;

        return komorki;
    }
    komorka** LosujPlansze(){
        srand(time(NULL));
        komorka **komorki;
        komorki = new komorka *[wysokosc_planszy];
        for (int i = 0; i < wysokosc_planszy; i++) {
            komorki[i] = new komorka[szerokosc_planszy];
        }

        for(int i = 0; i < wysokosc_planszy; i++){
            for(int j = 0; j < szerokosc_planszy; j++){
                if(szansa >= (std::rand()%101))
                    komorki[i][j].SetStatusKomorki(true);
            }
        }
    }
};

class plansza
{
private:
    int wysokosc;
    int szerokosc;
    komorka **komorki;
    int generacja;
    logika *logika_planszy;

public:
    plansza(int zadana_wysokosc, int zadana_szerokosc, int zasieg = 1)
        : generacja(0)
    {
        if (zadana_wysokosc <= 0 || zadana_szerokosc <= 0) {
            zadana_szerokosc = 8;
            zadana_wysokosc = 8;
        }
        if (zasieg <= 0) {
            zasieg = 1;
        }
        logika_planszy = new logika(wysokosc, szerokosc);
        komorki = new komorka *[zadana_wysokosc];
        for (int i = 0; i < zadana_wysokosc; i++) {
            komorki[i] = new komorka[zadana_szerokosc];
        }
    }
    int GetWysokosc() { return wysokosc; }
    int GetSzerokosc() { return szerokosc; }
    void KolejnaGeneracja()
    {
        komorki = logika_planszy->Zasady(komorki);
        generacja++;
    }
    komorka **GetPlansza() { return komorki; }
    void StanLosowy(){
        komorki = logika_planszy->LosujPlansze();
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "GraWZycie_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
