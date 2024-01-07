#include "modif_supp.h"
#include "ui_modif_supp.h"

modif_supp::modif_supp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modif_supp)
{
    ui->setupUi(this);
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("C:/Users/abder/Documents/ajout/Gestion_des_ordinateures/ajoueordinateur.db");

    if(DB_Connection.open())
    {
        qDebug() << "Database connected";
    }
    else
    {
        qDebug() << "Database is not connected";
        qDebug() << "Error" << DB_Connection.lastError();
    }
     connect(ui->tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(onTableWidgetSelectionChanged()));
}

modif_supp::~modif_supp()
{
    delete ui;
}

void modif_supp::on_pushButton_modif_clicked()
{
    if (!DB_Connection.isOpen())
    {
        qDebug() << " Database not open!";
        return;
    }
    QSqlDatabase::database().transaction();

    QString ID=ui->lineEdit->text();
    QString numeroSerie =ui->lineEdit_2->text();
    QString Couleur =ui->lineEdit_3->text();
    QString Processeur =ui->lineEdit_4->text();
    QString status =ui->comboBox->currentText();
    QString departementAttribue =ui->comboBox_2->currentText();

    QSqlQuery QueryUpdateData(DB_Connection);
    QueryUpdateData.prepare("UPDATE ordinateur SET numeroSerie=:numeroSerie, Couleur=:Couleur, Processeur=:Processeur, status=:status, departementAttribue=:departementAttribue WHERE ID=:ID");
    QueryUpdateData.bindValue(":ID",ID);
    QueryUpdateData.bindValue(":numeroSerie",numeroSerie);
    QueryUpdateData.bindValue(":Couleur",Couleur);
    QueryUpdateData.bindValue(":Processeur",Processeur);
    QueryUpdateData.bindValue(":status",status);
    QueryUpdateData.bindValue(":departementAttribue",departementAttribue);

    if(QueryUpdateData.exec()) {
        qDebug() << "ordinateur Modifier--";

    }else{

        qDebug() << "erreur modification--";
        qDebug() << "Error" << QueryUpdateData.lastError().text();
    }

    QSqlDatabase::database().commit();

}

void modif_supp::on_pushButton_supp_clicked()
{
    if (!DB_Connection.isOpen())
    {
        qDebug() << " Database not open!";
        return;
    }
    QString ID=ui->lineEdit->text();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryDeleteData(DB_Connection);
    QueryDeleteData.prepare("DELETE FROM ordinateur WHERE ID=:ID");
    QueryDeleteData.bindValue(":ID",ID);

    if(QueryDeleteData.exec()) {
        qDebug() << "ordinateur supprimer--";

    }else{
        qDebug() << "erreur suppretion--";
        qDebug() << "Error" << QueryDeleteData.lastError().text();
    }

    QSqlDatabase::database().commit();
}

void modif_supp::on_pushButton_show_clicked()
{

    if (!DB_Connection.isOpen())
    {
        qDebug() << " Database not open!";
        return;
    }
    QSqlDatabase::database().transaction();

    QSqlQuery QueryLoadData(DB_Connection);
    QueryLoadData.prepare("SELECT * FROM ordinateur");

    int NumberOfRowstodisplay=10;

    QueryLoadData.exec();
    ui->tableWidget->setRowCount(NumberOfRowstodisplay);
    qDebug() << "ordinateur load--";
    int RowNumber =0;
    while (QueryLoadData.next()) {
        ui->tableWidget->setItem(RowNumber,0, new QTableWidgetItem(QString(QueryLoadData.value("ID").toString())));
        ui->tableWidget->setItem(RowNumber,1, new QTableWidgetItem(QString(QueryLoadData.value("numeroSerie").toString())));
        ui->tableWidget->setItem(RowNumber,2, new QTableWidgetItem(QString(QueryLoadData.value("Couleur").toString())));
        ui->tableWidget->setItem(RowNumber,3, new QTableWidgetItem(QString(QueryLoadData.value("Processeur").toString())));
        ui->tableWidget->setItem(RowNumber,4, new QTableWidgetItem(QString(QueryLoadData.value("status").toString())));
        ui->tableWidget->setItem(RowNumber,5, new QTableWidgetItem(QString(QueryLoadData.value("departementAttribue").toString())));
        RowNumber=RowNumber+1;
    }

    QSqlDatabase::database().commit();
}
void modif_supp::onTableWidgetSelectionChanged()
{
    // Get the selected row
    int selectedRow = ui->tableWidget->currentRow();

    // Make sure a row is selected
    if (selectedRow >= 0) {
        // Retrieve data from the selected row
        QString ID = ui->tableWidget->item(selectedRow, 0)->text();
        QString numeroSerie = ui->tableWidget->item(selectedRow, 1)->text();
        QString Couleur = ui->tableWidget->item(selectedRow, 2)->text();
        QString Processeur = ui->tableWidget->item(selectedRow, 3)->text();
        QString status = ui->tableWidget->item(selectedRow, 4)->text();
        QString departementAttribue = ui->tableWidget->item(selectedRow, 5)->text();

        // Populate line edits with the retrieved data
        ui->lineEdit->setText(ID);
        ui->lineEdit_2->setText(numeroSerie);
        ui->lineEdit_3->setText(Couleur);
        ui->lineEdit_4->setText(Processeur);
        ui->comboBox->setCurrentText(status);
        ui->comboBox_2->setCurrentText(departementAttribue);
    }
}
