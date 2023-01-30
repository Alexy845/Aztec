#include "dialog.h"
#include "ui_dialog.h"

#define path_to_DB
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
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

