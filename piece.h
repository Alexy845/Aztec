#ifndef PIECE_H
#define PIECE_H

#include <QString>

class Piece
{
private:
    int m_valeur;
    bool m_possibles[9];
public:
    Piece(int valeur=0);
    void setValeur(int newValeur);
    int getValeur() const;
    int comptePossibles() const;
    void setPasPossible(int i);
    void resteTIlUn();
    QString toString();
};

#endif // PIECE_H
