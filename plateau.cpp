#include "plateau.h"
#include "piece.h"

int Plateau::forme[9][9] = {
    {0, 0, 1, 1, 1, 1, 1, 2, 2},
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {3, 0, 0, 0, 1, 2, 2, 2, 5},
    {3, 3, 0, 4, 4, 4, 2, 5, 5},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {3, 3, 6, 4, 4, 4, 8, 5, 5},
    {3, 6, 6, 6, 7, 8, 8, 8, 5},
    {6, 6, 6, 7, 7, 7, 8, 8, 8},
    {6, 6, 7, 7, 7, 7, 7, 8, 8}
};

int Plateau::quelleForme(int l, int c)
{
    return Plateau::forme[l][c];
}

const QList<int> &Plateau::getSelectCase() const
{
    return m_selectCase;
}

void Plateau::setSelectCase(const QList<int> &newSelectCase)
{
    m_selectCase = newSelectCase;
}

void Plateau::setValue(int l, int c, int value)
{
    m_completionplateau[l][c].setValeur(value);
}

Plateau::Plateau()
{
    //m_plateau[0][0]
    int t[9][9] = {
        {5, 9, 8, 0, 7, 0, 0, 0 ,6},
        {0, 1, 0, 0, 5, 3, 0, 8, 7},
        {0, 0, 7, 8, 6, 0, 2, 0, 3},
        {0, 6, 0, 5, 4, 8, 9, 0, 0},
        {2, 5, 1, 3, 0, 6, 7, 4, 8},
        {0, 0, 9, 7, 1, 2, 0, 6, 0},
        {8, 0, 6, 0, 2, 5, 3, 0, 0},
        {3, 2, 0, 1, 8, 0, 0, 7, 0},
        {1, 0, 0, 0, 3, 0, 5, 9, 2}
    };
    int ct [9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    for(int l=0; l<9; l++) {
        for(int c=0; c<9; c++) {
            m_plateau[l][c].setValeur(t[l][c]);
            m_completionplateau[l][c].setValeur(ct[l][c]);
        }
    }
    setSelectCase({0,0});
}

int Plateau::getDefaultValeur(int l, int c)
{
    return m_plateau[l][c].getValeur();
}

int Plateau::getValeur(int l, int c)
{
    return m_completionplateau[l][c].getValeur();
}
