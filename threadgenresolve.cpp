#include "threadgenresolve.h"

#include <QDebug>
#include <QGlobal.h>
#include <QTime>

ThreadGenResolve::ThreadGenResolve(QObject *parent) : QThread(parent) {}

int ThreadGenResolve::forme[9][9] = {
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

int ThreadGenResolve::quelleForme(int l, int c)
{
    return ThreadGenResolve::forme[l][c];
}

bool ThreadGenResolve::canPlaceGenValue(int l, int c, int value, QList<QList<int> > plateau)
{
    if (value == 0 || value == 10){
        return true;
    }
    // Check ligne colonne
    for(int i=0; i<9;i++) {
        if(plateau[l][i] == value){
            return false;
        }
        if(plateau[i][c] == value){
            return false;
        }
    }

    // Check in forme
    int ncasecheck = 0;

    for(int i =0; i<9; i++){
        for(int j=0; j<9; j++){
            if (quelleForme(i,j) == quelleForme(l,c)){
                ncasecheck++;
                if(plateau[i][j] == value){
                    return false;
                }
                if(ncasecheck == 9){
                    return true;
                }
            }
        }
    }
    return true;
}


void ThreadGenResolve::run()
{
    QTime time = QTime::currentTime();
    srand((uint)time.msec());
    qDebug() << genTableau();

}

const QList<QList<int> > ThreadGenResolve::genTableau()
{
    QList<QList<int>> nTable = {
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

    while(true){
        nTable = {
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
        for(int l = 0; l<9; l++){
            for(int c = 0; c<9; c++){
                int value = rand() % ((9 + 1) - 1) + 1;
                if(canPlaceGenValue(l, c, value, nTable)){
                    nTable[l][c] = value;
                    //qDebug() << nTable[0] << "\n" << nTable[1] << "\n" << nTable[2] << "\n" << nTable[3] << "\n" << nTable[4] << "\n" << nTable[5] << "\n" << nTable[6] << "\n" << nTable[7] << "\n" << nTable[8] << "\n";
                }else {
                    //qDebug() << value;
                    l = 10;
                    c = 10;
                }
            }
        }
    }

    //qDebug() << nTable[0] << "\n" << nTable[1] << "\n" << nTable[2] << "\n" << nTable[3] << "\n" << nTable[4] << "\n" << nTable[5] << "\n" << nTable[6] << "\n" << nTable[7] << "\n" << nTable[8] << "\n";
    return nTable;
}
