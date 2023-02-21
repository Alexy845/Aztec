#include "rldialogue.h"
#include "ui_rldialogue.h"

#define Path_to_DB "C:\Mes Dossiers\Ynov Campus\Cours\POO\ProjetGroupe\final_project_poo\database\db.sq3"

RLDialogue::RLDialogue(QWidget *parent)
    :QDialog(parent), ui(new Ui::RLDialogue)
{
    ui->setupUi(this);


}
