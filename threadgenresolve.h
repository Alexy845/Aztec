#ifndef THREADGENRESOLVE_H
#define THREADGENRESOLVE_H

#include <QThread>

class ThreadGenResolve : public QThread
{
private:
    static int forme[9][9];
public:
    ThreadGenResolve(QObject *parent=0);
    int quelleForme(int l, int c);
    bool canPlaceGenValue(int l, int c, int value, QList<QList<int>> plateau);
    const QList<QList<int>> genTableau();
    void run();
};

#endif // THREADGENRESOLVE_H
