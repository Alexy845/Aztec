#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void action_timer();
    void stopTimer();
    void startGame();
    void changePage(int index);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_n1_clicked();
    void on_pushButton_n2_clicked();
    void on_pushButton_n3_clicked();
    void on_pushButton_n4_clicked();
    void on_pushButton_n5_clicked();
    void on_pushButton_n6_clicked();
    void on_pushButton_n7_clicked();
    void on_pushButton_n8_clicked();
    void on_pushButton_n9_clicked();

    void on_page_victoire_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
};
#endif // MAINWINDOW_H
