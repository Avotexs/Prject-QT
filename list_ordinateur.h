#ifndef LIST_ORDINATEUR_H
#define LIST_ORDINATEUR_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include<QFileInfo>
#include <QMessageBox>

namespace Ui {
class List_ordinateur;
}

class List_ordinateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit List_ordinateur(QWidget *parent = nullptr);
    ~List_ordinateur();

private slots:
    void on_pushButton_load_clicked();

    void on_pushButton_load_2_clicked();

private:
    Ui::List_ordinateur *ui;
    QSqlDatabase DB_Connection;
};

#endif // LIST_ORDINATEUR_H
