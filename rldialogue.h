#ifndef RLDIALOGUE_H
#define RLDIALOGUE_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class RLDialogue; }
QT_END_NAMESPACE

class RLDialogue : public QDialog
{
    Q_OBJECT
public:
    RLDialogue(QWidget *parent = nullptr);
    ~RLDialogue();
private:
    Ui::RLDialogue *ui;
    QSqlDatabase myDB;
};

#endif // RLDIALOGUE_H
