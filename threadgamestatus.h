#ifndef THREADGAMESTATUS_H
#define THREADGAMESTATUS_H

#include <QThread>
#include "plateau.h"

class ThreadGameStatus : public QThread
{
   private:
    Plateau *pl;
public:
    ThreadGameStatus(QObject *parent=0, Plateau *p);
    void run();
};

#endif // THREADGAMESTATUS_H
