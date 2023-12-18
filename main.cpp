#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

class komorka{
private:
    bool status_komorki;
public:
    void SetStatusKomorki(bool status){
        status_komorki = status;
    }
    bool GetStatusKomorki(){
        return status_komorki;
    }
};

class logika{
private:
    int wysokosc_planszy;
    int szerokosc_planszy;
    int zasieg;
public:
    logika(int ZadanyZasieg = 1):zasieg(ZadanyZasieg)
    {}
    komorka** Zasady(komorka **komorki){
        return komorki;
    }

};

class plansza{
private:
    int wysokosc;
    int szerokosc;
    komorka **komorki;
    int generacja;
    logika *logika_planszy;
public:
    plansza(int ZadanaWysokosc, int ZadanaSzerokosc, int zasieg = 1):generacja(0){
        if(zasieg > 0){
            logika_planszy = new logika(zasieg);
        }
        komorki = new komorka*[ZadanaWysokosc];
        for(int i = 0; i < ZadanaWysokosc;i++){
            komorki[i] = new komorka[ZadanaSzerokosc];
        }
    }
    int GetWysokosc(){
        return wysokosc;
    }
    int GetSzerokosc(){
        return szerokosc;
    }
    void KolejnaGeneracja(){
        komorki = logika_planszy->Zasady(komorki);
        generacja++;
    }
    komorka** OdswierzPlansze(){
        return komorki;
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
