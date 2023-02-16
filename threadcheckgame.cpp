#include "threadcheckgame.h"
#include <QDebug>

Plateau *ThreadCheckGame::getP() const
{
    return p;
}

void ThreadCheckGame::setP(Plateau *newP)
{
    p = newP;
}

ThreadCheckGame::ThreadCheckGame(QObject *parent, Plateau *p)
{
    this->p = p;
}

void ThreadCheckGame::run()
{
    /*while(p->checkVictoryDefeat() != 1 && p->checkVictoryDefeat() != 2){
    }*/
    qDebug() << "Partie Finis";
}
