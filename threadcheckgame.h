#ifndef THREADCHECKGAME_H
#define THREADCHECKGAME_H

#include "plateau.h"

#include <QThread>

class ThreadCheckGame : public QThread
{
private:
    Plateau *p;
public:
    ThreadCheckGame(QObject *parent=nullptr, Plateau *p=nullptr);
    void run();
    Plateau *getP() const;
    void setP(Plateau *newP);
};
#endif // THREADCHECKGAME_H
