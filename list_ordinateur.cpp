#include "list_ordinateur.h"
#include "ui_list_ordinateur.h"

List_ordinateur::List_ordinateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::List_ordinateur)
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

List_ordinateur::~List_ordinateur()
{
    delete ui;
}
//tous
void List_ordinateur::on_pushButton_load_clicked()
{
    if (!DB_Connection.isOpen())
    {
        qDebug() << " Database not open!";
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DB_Connection);

    query.prepare("SELECT * FROM ordinateur");

    if (query.exec())
    {
        model->setQuery(query);
        ui->tableView->setModel(model);



        qDebug() << "List afficher";
    }
    else
    {
        qDebug() << "erreur List";

    }
    DB_Connection.close();
}



