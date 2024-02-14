#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "plansza.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set_qtablewiget();
    void set_plansza(plansza *nowa_plansza);
    void aktualizacja_planszy();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    plansza *m_plansza;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
