#include "mainwindow.h"
#include "plansza.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>



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
    komorka** komorki = new komorka*[8];
    for(int i = 0; i < 8;i++){
        komorki[i] = new komorka[8];
    }
    for(int i = 0; i <8;i++){
        for(int j = 0; j <8;j++){
            komorki[i][j].SetStatusKomorki(false);
        }
    }
    komorki[2][2].SetStatusKomorki(true);
    komorki[2][3].SetStatusKomorki(true);
    komorki[2][4].SetStatusKomorki(true);
    komorki[3][2].SetStatusKomorki(true);
    komorki[4][3].SetStatusKomorki(true);




    plansza nowa(8,8);
    MainWindow w;
    w.set_plansza(&nowa);
    nowa.SetKomorki(komorki);
    w.show();
    return a.exec();
}
