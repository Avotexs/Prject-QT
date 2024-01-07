#ifndef AJOUT_H
#define AJOUT_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include<QFileInfo>
#include <QMessageBox>

namespace Ui {
class Ajout;
}

class Ajout : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ajout(QWidget *parent = nullptr);
    ~Ajout();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_ajout_clicked();

private:
    Ui::Ajout *ui;
    QSqlDatabase DB_Connection;
};

#endif // AJOUT_H

