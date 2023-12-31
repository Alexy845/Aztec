#include "threadtableau.h"

#include <QDebug>
#include <QGlobal.h>
#include <QTime>
#include "threadgeneratorresolve.h"

ThreadTableau::ThreadTableau(QObject *parent) : QThread(parent) {}

int ThreadTableau::forme[9][9] = {
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

int ThreadTableau::quelleForme(int l, int c)
{
    return ThreadTableau::forme[l][c];
}

bool ThreadTableau::canPlaceGenValue(int l, int c, int value, QList<QList<int> > plateau)
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

/*const QList<QList<int> > ThreadTableau::genTableau()
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
    }*/
    /*int current_l = 0;
    int current_c = 0;
    int pass_l = 0;
    int pass_c = 0;

    //srand(time(0));
    while (true) {
        //int value = nTable[current_l][current_c]+1;
        QList<int> vl = {1,2,3,4,5,6,7,8,9};
        vl.removeAll(nTable[current_l][current_c]);
        int index = rand() % ((vl.size() + 0) - 0) + 0;
        int value = vl[index];
        vl.removeAll(value);
        while(!canPlaceGenValue(current_l, current_c, value, nTable)){
            if(vl.size() != 0/*value != 9*//*){
                int index = rand() % ((vl.size() + 0) - 0) + 0;
                value = vl[index];
                vl.removeAll(value);
            }else {
                value = 10;
            }
        }
        if(value>9){
            nTable[current_l][current_c] = 0;
            if(current_c == 0){
                current_l = pass_l;
                qDebug() << nTable[current_l];
                pass_l--;
            }
            current_c = pass_c;
            if(current_c == 0){
                pass_c = 8;
            }else{
                pass_c--;
            }
        }else {
            nTable[current_l][current_c] = value;
            if (current_c == 8){
                if(current_l ==8){
                    break;
                }
                pass_l = current_l;
                qDebug() << nTable[current_l];
                current_l++;
                pass_c = current_c;
                current_c = 0;
            }else{
                pass_c = current_c;
                current_c++;
            }
        }*/
        //qDebug() << nTable[0] << "\n" << nTable[1] << "\n" << nTable[2] << "\n" << nTable[3] << "\n" << nTable[4] << "\n" << nTable[5] << "\n" << nTable[6] << "\n" << nTable[7] << "\n" << nTable[8] << "\n";

    /*}*/

    /*qDebug() << nTable[0] << "\n" << nTable[1] << "\n" << nTable[2] << "\n" << nTable[3] << "\n" << nTable[4] << "\n" << nTable[5] << "\n" << nTable[6] << "\n" << nTable[7] << "\n" << nTable[8] << "\n";
    return nTable;
}*/

const QList<QList<int> > ThreadTableau::genAztec(QList<QList<int> > plateau)
{
    QList<QList<int>> Aztec = plateau;

    for(int l=0; l<9; l++){
        for(int c=0; c<9; c++){
            Aztec[l][c] = 0;
            //qDebug() << Aztec[0] << "\n" << Aztec[1] << "\n" << Aztec[2] << "\n" << Aztec[3] << "\n" << Aztec[4] << "\n" << Aztec[5] << "\n" << Aztec[6] << "\n" << Aztec[7] << "\n" << Aztec[8] << "\n";
            for(int value = 1; value<10; value++){
                if(value != plateau[l][c]){
                    if(canResolveAztecWith(Aztec, value, l, c)){
                        Aztec[l][c] = plateau[l][c];
                        //qDebug() << l << c << value;
                        value = 10;
                    }else {
                    }
                }
            }
        }
    }

    qDebug() << Aztec[0] << "\n" << Aztec[1] << "\n" << Aztec[2] << "\n" << Aztec[3] << "\n" << Aztec[4] << "\n" << Aztec[5] << "\n" << Aztec[6] << "\n" << Aztec[7] << "\n" << Aztec[8] << "\n";
    return Aztec;
}

bool ThreadTableau::canResolveAztecWith(QList<QList<int> > plateau, int value, int ol, int oc)
{

    QList<QList<int>> resAztec = {
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
    if(!canPlaceGenValue(ol,oc,value,plateau)) {
        return false;
    }
    resAztec[ol][oc] = value;
    for(int l=0; l<9; l++){
        for(int c=0; c<9; c++){
            //qDebug() << l << c;
            if(plateau[l][c] != 0){
                resAztec[l][c] = plateau[l][c];
            }else {
                int v = resAztec[l][c]+1;
                while(!canPlaceGenValue(l,c,v,plateau) || !canPlaceGenValue(l,c,v,resAztec)){
                    v++;
                    if(v>9){
                        v=0;
                    }
                }
                if(v == 0){
                    bool loop = true;
                    while(loop){
                        if(l==0 && c== 0){
                            return false;
                        }
                        l = c == 0 ? l-1:l;
                        c = c == 0 ? 8:c+1;
                        if(plateau[l][c] == 0 && !(ol == l && oc == c)){
                            loop = false;
                        }
                    }
                }else {
                    resAztec[l][c] = v;
                }
            }
        }
    }

    return true;
}

void ThreadTableau::run()
{

    /*QTime time = QTime::currentTime();
    srand((uint)time.msec());*/
   /* for(int i = 0; i<100; i++){
        qDebug() << rand() % ((9 + 1) - 1) + 1;
    }*/

    QList<QList<int>> t ={{1, 2, 3, 4, 5, 6, 7, 8, 9},
     {3, 4, 5, 1, 8, 9, 2, 6, 7},
     {4, 6, 7, 9, 2, 1, 3, 5, 8},
     {2, 1, 8, 5, 7, 3, 4, 9, 6},
     {7, 3, 6, 2, 9, 8, 5, 1, 4},
     {5, 8, 2, 6, 1, 4, 9, 7, 3},
     {9, 5, 1, 3, 6, 7, 8, 4, 2},
     {8, 9, 4, 7, 3, 5, 6, 2, 1},
     {6, 7, 9, 8, 4, 2, 1, 3, 5},};
    //genAztec(genTableau());
/*
    ThreadGeneratorResolve th = new ThreadGeneratorResolve;
    th.start();
    ThreadGeneratorResolve th2 = new ThreadGeneratorResolve;
    th2.start();
    ThreadGeneratorResolve th3 = new ThreadGeneratorResolve;
    th3.start();
    ThreadGeneratorResolve th4 = new ThreadGeneratorResolve;
    th4.start();

    ThreadGeneratorResolve th5 = new ThreadGeneratorResolve;
    th5.start();
    ThreadGeneratorResolve th6 = new ThreadGeneratorResolve;
    th6.start();
    ThreadGeneratorResolve th7 = new ThreadGeneratorResolve;
    th7.start();
    ThreadGeneratorResolve th8 = new ThreadGeneratorResolve;
    th8.start();


    ThreadGeneratorResolve th9 = new ThreadGeneratorResolve;
    th9.start();
    ThreadGeneratorResolve th10 = new ThreadGeneratorResolve;
    th10.start();
    ThreadGeneratorResolve th11 = new ThreadGeneratorResolve;
    th11.start();
    ThreadGeneratorResolve th12 = new ThreadGeneratorResolve;
    th12.start();

    ThreadGeneratorResolve th13 = new ThreadGeneratorResolve;
    th13.start();
    ThreadGeneratorResolve th14 = new ThreadGeneratorResolve;
    th14.start();
    ThreadGeneratorResolve th15 = new ThreadGeneratorResolve;
    th15.start();
    ThreadGeneratorResolve th16 = new ThreadGeneratorResolve;
    th16.start();
    while(true){
    }
*/
    //qDebug() << "finis";
}
