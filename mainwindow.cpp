#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->OknoGry->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_qtablewiget(){
    komorka** komorki = m_plansza->GetKomorki();
    int szerokosc = m_plansza->GetSzerokosc();
    int wysokosc = m_plansza->GetWysokosc();
    ui->tableWidget->setColumnCount(szerokosc);
    ui->tableWidget->setRowCount(wysokosc);

    int wysokosc_okna =  ui->tableWidget->geometry().height();
    int szerokosc_okna = ui->tableWidget->geometry().width();

    int szerokosc_komorki = (szerokosc_okna+4)/m_plansza->GetSzerokosc();
    int wysokosc_komorki = (wysokosc_okna+4)/m_plansza->GetWysokosc();

    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(szerokosc_komorki);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(wysokosc_komorki);

}
void MainWindow::set_plansza(plansza *nowa_plansza){
    m_plansza = nowa_plansza;
}

void MainWindow::kolejna_generacja(){
    int szerokosc = m_plansza->GetSzerokosc();
    int wysokosc = m_plansza->GetWysokosc();
     komorka** komorki = m_plansza->GetKomorki();

    for (int i = 0; i < szerokosc; ++i) {
        for (int j = 0; j < wysokosc; ++j) {
            if(komorki[i][j].GetStatusKomorki()){
                ui->tableWidget->setItem(i, j, new QTableWidgetItem);
                ui->tableWidget->item(i,j)->setBackground(Qt::black);
            }
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->logo->setVisible(false);
    ui->menu->setVisible(false);
    ui->OknoGry->setVisible(true);

    int wysokosc, szerokosc;

    szerokosc = ui->szerokosc->value();
    wysokosc = ui->wysokosc->value();
    m_plansza->SetSzerokosc(szerokosc);
    m_plansza->SetWysokosc(wysokosc);

    set_qtablewiget();
    kolejna_generacja();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->logo->setVisible(true);
    ui->menu->setVisible(true);
    ui->OknoGry->setVisible(false);

}


void MainWindow::on_pushButton_3_clicked()
{

}

