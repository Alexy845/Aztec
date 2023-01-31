#ifndef THREADGENERATORRESOLVE_H
#define THREADGENERATORRESOLVE_H

#include <QThread>


class ThreadGeneratorResolve : public QThread
{
private:
    static int forme[9][9];
public:
    ThreadGeneratorResolve(QObject *parent=0);
    int quelleForme(int l, int c);
    bool canPlaceGenValue(int l, int c, int value, QList<QList<int>> plateau);
    const QList<QList<int>> genTableau();
    void run();
};

#endif // THREADGENERATORRESOLVE_H
