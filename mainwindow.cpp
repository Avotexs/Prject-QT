#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    ajout = new class Ajout(this);
    ajout->show();
}


void MainWindow::on_pushButton_2_clicked()
{

    list_ordinateur= new class List_ordinateur(this);
    list_ordinateur->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    modif_supp=new class modif_supp(this);
    modif_supp->show();
}


void MainWindow::on_pushButton_9_clicked()
{
    hide();
}

