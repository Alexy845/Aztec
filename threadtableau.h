#ifndef THREADTABLEAU_H
#define THREADTABLEAU_H

#include <QThread>


class ThreadTableau : public QThread
{
private:
    static int forme[9][9];
public:
    ThreadTableau(QObject *parent=0);
    int quelleForme(int l, int c);
    bool canPlaceGenValue(int l, int c, int value, QList<QList<int>> plateau);
    const QList<QList<int>> genTableau();
    const QList<QList<int>> genAztec(QList<QList<int>> plateau);
    bool canResolveAztecWith(QList<QList<int>> plateau, int value, int l, int c);
    void run();
};

#endif // THREADTABLEAU_H
