#include "dialog.h"
#include "ui_dialog.h"


#define Path_to_DB "D:/Ynov B1/POO VILLEDON/LoginForm/SQLite/accounts.sq3"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if(checkFile.isFile())
    {
        if(myDB.open())
        {
            ui->lblResult->setText("[+]Connected to Database File :)");

        }
    }else{
        ui->lblResult->setText("[!]Database File doesnot exist : (");

    }
}

Dialog::~Dialog()
{
    delete ui;
    qDebug() << "Closing the connection to Database file on exit.";
    myDB.close();
}


void Dialog::on_btnClear_clicked()
{
    ui->txtPass->setText("");
    ui->txtUser->setText("");

}


void Dialog::on_btnClear_3_clicked()
{
    ui->txtPassRegister->setText("");
    ui->txtConfirmPass->setText("");
    ui->txtUserRegister->setText("");

}


void Dialog::on_btnLogin_clicked()
{
    QString Username, Password;
    Username = ui->txtUser->text();
    Password = ui->txtPass->text();

    if(!myDB.isOpen()){
            qDebug() << "No connection to db :( ";
            return;
    }

    QSqlQuery qry;
    if(qry.exec("SELECT Username, Password, Role FROM Users WHERE Username=\'" + Username +
                "\' AND Password=\'" + Password + "\'"))
    {
        if(qry.next())
        {
            ui->lblResult->setText("[+]Valid Username and Password");
            QString msg = "Username = " + qry.value(0).toString() + " \n" +
                          "Password = " + qry.value(1).toString() + " \n" +
                          "Role = " + qry.value(2).toString();

            QMessageBox::warning(this, "Login was successful", msg);
        }else{
            ui->lblResult->setText("[-]Wrong Username or Password. :( ");


        }
    }
}

