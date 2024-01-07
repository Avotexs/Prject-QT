#include "ajout.h"
#include "ui_ajout.h"


Ajout::Ajout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ajout)
{
    ui->setupUi(this);
    DB_Connection =QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("C:/Users/abder/Documents/ajout/Gestion_des_ordinateures/ajoueordinateur.db");

    if(DB_Connection.open())
    {

        qDebug() << "Database connected";
    }
    else    {
        qDebug() << "Database is Not connected";
        qDebug() << "error"<<DB_Connection.lastError();

    }


}

Ajout::~Ajout()
{
    delete ui;
}

void Ajout::on_pushButton_clicked()
{
    hide();
}


void Ajout::on_pushButton_ajout_clicked()
{
    if (!DB_Connection.isOpen())
    {
        qDebug() << " Database not open!";
        return;
    }

    QString ID = ui->lineEdit->text();
    QString numeroSerie = ui->lineEdit_2->text();
    QString Couleur = ui->lineEdit_3->text();
    QString Processeur = ui->lineEdit_4->text();
    QString status = ui->comboBox->currentText();
    QString departementAttribue = ui->comboBox_2->currentText();

    // Check if any of the fields are empty
    if (ID.isEmpty() || numeroSerie.isEmpty() || Couleur.isEmpty() || Processeur.isEmpty())
    {
        QMessageBox::critical(this, "Error", "veuillez remplir tous les champs");
        return;
    }

    // Check if ID and numeroSerie are unique
    QSqlQuery checkQuery(DB_Connection);
    checkQuery.prepare("SELECT ID, numeroSerie FROM ordinateur WHERE ID = :ID OR numeroSerie = :numeroSerie");
    checkQuery.bindValue(":ID", ID);
    checkQuery.bindValue(":numeroSerie", numeroSerie);

    if (checkQuery.exec() && checkQuery.next())
    {
        QMessageBox::critical(this, "Error", "ID ou numeroSerie existant. veuillez entrer un valeur unique.");
        return;
    }

    QSqlDatabase::database().transaction();
    QSqlQuery QueryInsetData(DB_Connection);
    QueryInsetData.prepare("INSERT INTO ordinateur (ID, numeroSerie, Couleur, Processeur, status,departementAttribue) VALUES (:ID, :numeroSerie, :Couleur, :Processeur, :status, :departementAttribue)");
    QueryInsetData.bindValue(":ID", ID);
    QueryInsetData.bindValue(":numeroSerie", numeroSerie);
    QueryInsetData.bindValue(":Couleur", Couleur);
    QueryInsetData.bindValue(":Processeur", Processeur);
    QueryInsetData.bindValue(":status", status);
    QueryInsetData.bindValue(":departementAttribue", departementAttribue);

    if (QueryInsetData.exec())
    {
        QMessageBox::information(this, "Success", "Ordinateur ajouté avec succès!");
        qDebug() << "ordinateur ajouté--";
    }
    else
    {
        QMessageBox::critical(this, "Error", "Error AJOUT: " + QueryInsetData.lastError().text());
        qDebug() << "erreur ajout--";
        qDebug() << "Error" << QueryInsetData.lastError().text();
    }

    QSqlDatabase::database().commit();
}

