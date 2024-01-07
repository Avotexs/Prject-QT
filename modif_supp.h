#ifndef MODIF_SUPP_H
#define MODIF_SUPP_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include<QFileInfo>
#include <QMessageBox>

namespace Ui {
class modif_supp;
}

class modif_supp : public QMainWindow
{
    Q_OBJECT

public:
    explicit modif_supp(QWidget *parent = nullptr);
    ~modif_supp();

private slots:
    void on_pushButton_modif_clicked();



    void on_pushButton_supp_clicked();



    void on_pushButton_show_clicked();
     void onTableWidgetSelectionChanged();

private:
    Ui::modif_supp *ui;
    QSqlDatabase DB_Connection;


};



#endif // MODIF_SUPP_H
