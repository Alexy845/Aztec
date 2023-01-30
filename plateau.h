#ifndef PLATEAU_H
#define PLATEAU_H

#include "piece.h"
#include <QList>

class Plateau
{
private:
    Piece m_plateau[9][9];
    Piece m_completionplateau[9][9];
    int m_remaining_live;
    static int forme[9][9];
    QList<int> m_selectCase;
public:
    Plateau();
    const QList<QList<int>> genTableau();
    int getDefaultValeur(int l, int c);
    int getValeur(int l, int c);
    int quelleForme(int l, int c);
    const QList<int> &getSelectCase() const;
    void setSelectCase(const QList<int> &newSelectCase);
    void setValue(int l, int c, int value);
    bool canPlaceValue(int l, int c, int value);
    bool canPlaceGenValue(int l, int c, int value, QList<QList<int>> plateau);
    int getRemaining_live() const;
    void uncreaseRemaining_live();
    void checkVictoryDefeat();
};

#endif // PLATEAU_H
