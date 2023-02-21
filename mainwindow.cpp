#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"
#include "plateau.h"

#define Path_to_DB "C:/Mes Dossiers/Ynov Campus/Cours/POO/ProjetGroupe/final_project_poo/database/db.sq3"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), timer (new QTimer)
{
    ui->setupUi(this);
    changePage(0);
    setCurrentID(0);

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if(checkFile.isFile())
    {
        if(myDB.open())
        {
            qDebug() << "Database Connected";
        }
    }else{
        qDebug() << "Database not Connected";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::action_timer()
{
    timerCount++;
    int min = timerCount/60;
    int sec = timerCount%60;
    QString te = (min >= 10 ? "":"0") + QString::number(min) + ":" + (sec >= 10 ? "":"0") + QString::number(sec);
    ui->Digital_clock->display(te);
}

void MainWindow::stopTimer()
{
    qDebug() << "Timer stop";
    timer->stop();
}

void MainWindow::startGame()
{
    Plateau *p = new Plateau();
    ui->canvas->setPlateau(p);
    ui->canvas->setMainwindow(this);
    timerCount = 0;
    timer->start(1000);
    connect(timer ,&QTimer::timeout, this, &MainWindow::action_timer);
}

void MainWindow::changePage(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::endGame(int ve)
{
    changePage(ve);
    stopTimer();
}

void MainWindow::registerAccount(QString username, QString Password, QString ConfirmPassword)
{
    qDebug() << "Register actions";
    if(!myDB.isOpen()){
        qDebug() << "Database not Connected";
        return;
    }

    if(Password != ConfirmPassword){
        qDebug() << "Password and Confirmpassword didn't match !";
        return;
    }

    QSqlQuery qry;

    if(qry.exec("SELECT * FROM Users WHERE Username='" + username +"'")){
        if(qry.next()){
            qDebug() << "User already exist";
            return;
        }else {
            qry.exec("INSERT INTO Users(Username, Password) values ('" + username + "', '" + Password + "')");
            qDebug() << "User created";
            setCurrentID(qry.exec("SELECT id FROM Users WHERE Username='" + username + "'"));
            ui->l_user->setText(username);
            changePage(0);
            return;
        }
    }

}

void MainWindow::loginAccount(QString username, QString Password)
{
    qDebug() << "Login actions";
    if(!myDB.isOpen()){
        qDebug() << "Database not Connected";
        return;
    }

    QSqlQuery qry;
    if(qry.exec("SELECT * FROM Users WHERE Username='" + username + "' AND Password='" + Password + "'")){
        if(qry.next()){
            qDebug() << "Hello " << username << " you'r now connected";
            setCurrentID(qry.exec("SELECT id FROM Users WHERE Username='" + username + "'"));
            ui->l_user->setText(username);
            changePage(0);
            return;
        }else {
            qDebug() << "Wrong password";
            return;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    stopTimer();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    startGame();

}

void MainWindow::on_pushButton_n1_clicked()
{
    ui->canvas->keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_1, Qt::NoModifier));

}

void MainWindow::on_pushButton_n2_clicked()
{
    ui->canvas->keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_2, Qt::NoModifier));

}

void MainWindow::on_pushButton_n3_clicked()
{
    ui->canvas->keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_3, Qt::NoModifier));

}

void MainWindow::on_pushButton_n4_clicked()
{
    ui->canvas->keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_4, Qt::NoModifier));

}

void MainWindow::on_pushButton_n5_clicked()
{
    ui->canvas->keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_5, Qt::NoModifier));

}

void MainWindow::on_pushButton_n6_clicked()
{
    ui->canvas->keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_6, Qt::NoModifier));

}

void MainWindow::on_pushButton_n7_clicked()
{
    ui->canvas->keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_7, Qt::NoModifier));

}

void MainWindow::on_pushButton_n8_clicked()
{
    ui->canvas->keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_8, Qt::NoModifier));

}

void MainWindow::on_pushButton_n9_clicked()
{
    ui->canvas->keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_9, Qt::NoModifier));

}

void MainWindow::on_cr_btn_clicked()
{
    if(ui->l_title->text() == "Login"){
        loginAccount(ui->EDT_Username->toPlainText(), ui->EDT_Pass->toPlainText());
    } else {
        registerAccount(ui->EDT_Username->toPlainText(), ui->EDT_Pass->toPlainText(), ui->EDT_ConfPass->toPlainText());
    }
}

void MainWindow::on_connection_btn_clicked()
{
    changePage(3);
}

void MainWindow::on_l_action_clicked()
{
    if(ui->l_title->text() == "Login"){
        ui->l_title->setText("Register");
        ui->EDT_ConfPass->setVisible(true);
        ui->l_action->setText("Use it");
        ui->l_quest->setText("Already have an account ? ");
        ui->cr_btn->setText("Register");
    } else {
        ui->l_title->setText("Login");
        ui->EDT_ConfPass->setVisible(false);
        ui->EDT_ConfPass->clear();
        ui->l_action->setText("Create one");
        ui->l_quest->setText("No account ? ");
        ui->cr_btn->setText("Login");
    }
}

void MainWindow::on_page_victoire_customContextMenuRequested(const QPoint &pos)
{

}

int MainWindow::getCurrentID() const
{
    return currentID;
}

void MainWindow::setCurrentID(int newCurrentID)
{
    currentID = newCurrentID;
}




