#include "piece.h"
#include <QTextStream>


void Piece::setValeur(int newValeur)
{
    m_valeur = newValeur;
}

int Piece::getValeur() const
{
    return m_valeur;
}

int Piece::comptePossibles() const
{
    if(m_valeur != 0) {
        return 0;
    } else {
        int cpt = 0;
        for(int i=0;i<10;i++) {
            if(m_possibles[i]) {
                cpt++;
            }
        }
        return cpt;
    }
}

void Piece::setPasPossible(int i)
{
    if(m_valeur==0) {
        m_possibles[i] = false;
        resteTIlUn();
    }
}

void Piece::resteTIlUn()
{
    if(comptePossibles()==1) {
        int i;
        for(i=1;i<10;i++) {
            if(m_possibles[i] == true)
                break;
        }
        setValeur(i);
    }
}

QString Piece::toString()
{
    if(m_valeur!=0) {
        return QString::asprintf("La pièce a la valeur %d.", m_valeur);
    } else {
        QString res;
        QTextStream buf(&res);
        buf<<"Valeur Indéterminée ("<<comptePossibles()<<" possibles) [";
        for(int i=1;i<10;i++) {
            buf<<i<<":"<<m_possibles[i]<<(i<9?", ":"");
        }
        buf<<"]";
        return res;
    }
}

Piece::Piece(int valeur):m_valeur(valeur)
{
    if(valeur == 0) {
        for(int i=1;i<10;i++) {
            m_possibles[i] = true;
        }
    }
}
