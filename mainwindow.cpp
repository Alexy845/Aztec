#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"
#include "plateau.h"


#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), timer (new QTimer)
{
    ui->setupUi(this);

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

void MainWindow::on_page_victoire_customContextMenuRequested(const QPoint &pos)
{

}




