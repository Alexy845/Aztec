#ifndef PLATEAU_H
#define PLATEAU_H

#include "piece.h"

class Plateau
{
private:
    Piece m_plateau[9][9];
    static int forme[9][9];
public:
    Plateau();
    int getValeur(int l, int c);
    int quelleForme(int l, int c);
};

#endif // PLATEAU_H
