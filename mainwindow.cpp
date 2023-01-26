#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plateau.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), timer (new QTimer)
{
    ui->setupUi(this);
    Plateau *p = new Plateau();
    ui->canvas->setPlateau(p);

    timer->start(1000);
    connect(timer ,&QTimer::timeout, this, &MainWindow::action_timer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::action_timer()
{
    static int compteur=0;
    compteur++;
    int min = compteur/60;
    int sec = compteur%60;
    QString te = QString::number(min) + (min >= 10 ? "":"0") + ":" + (sec >= 10 ? "":"0") + QString::number(sec);
    ui->Digital_clock->display(te);
}
