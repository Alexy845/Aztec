#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnClear_clicked();

    void on_btnClear_3_clicked();

    void on_btnLogin_clicked();

private:
    Ui::Dialog *ui;

    QSqlDatabase myDB;
};
#endif // DIALOG_H
