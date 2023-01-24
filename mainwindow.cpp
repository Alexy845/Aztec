#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plateau.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Plateau *p = new Plateau();
    ui->canvas->setPlateau(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}

