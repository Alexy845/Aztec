#include "dialog.h"
#include "ui_dialog.h"


#define Path_to_DB "D:/Ynov B1/POO VILLEDON/LoginForm/SQLite/db.sqlite"

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
            ui->lblResult_2->setText("[+]Connected to Database File :)");

        }
    }else{
        ui->lblResult->setText("[!]Database File doesnot exist : (");
        ui->lblResult_2->setText("[!]Database File doesnot exist : (");

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
    qDebug() << "ici";
    QString Username, Password;
    Username = ui->txtUser->text();
    Password = ui->txtPass->text();

    if(!myDB.isOpen()){
            qDebug() << "No connection to db :( ";
            return;
    }

    QSqlQuery qry;
    if(qry.exec("SELECT Username, Password, Role FROM Users WHERE Username='" + Username +
                "' AND Password='" + Password + "'"))
    {
        qDebug() <<"bonjour";
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


void Dialog::on_btnRegister_clicked()
{
    QString Username, Password,ConfirmPassword;
    Username = ui->txtUserRegister->text();
    Password = ui->txtPassRegister->text();
    ConfirmPassword = ui->txtConfirmPass->text();

    if(!myDB.isOpen()){
            qDebug() << "No connection to db :( ";
            return;
    }

    QSqlQuery qry;
    if(qry.exec("SELECT Username, Password, ConfirmPassword, Role FROM Users WHERE Username=\'" + Username +
                "\' AND Password=\'" + Password + "\'" + "\' AND ConfirmPassword=\'" + ConfirmPassword))
    {
        if(qry.next())
        {
            ui->lblResult_2->setText("[+]Valid Username and Password and ConfirmPassword");
            QString msg = "Username = " + qry.value(0).toString() + " \n" +
                          "Password = " + qry.value(1).toString() + " \n" +
                          "ConfirmPassword = " + qry.value(2).toString() + " \n" +
                          "Role = " + qry.value(3).toString();

            QMessageBox::warning(this, "Register was successful", msg);
        }else{
            ui->lblResult_2->setText("[-]Wrong Password or ConfirmPassword. :( ");


        }
    }
}



