#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "ajout.h"
#include "list_ordinateur.h"
#include "modif_supp.h"





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    Ajout *ajout ;
    List_ordinateur*list_ordinateur;
    modif_supp*modif_supp;

};
#endif // MAINWINDOW_H
