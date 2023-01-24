#include "mainwindow.h"

#include <QApplication>

#include "qstd.h"
using namespace qstd;
#include "piece.h"

void testePiece() {
    cout<<"Test de Pièces...\n";
    Piece p1;
    cout <<p1.toString()<<"\n";
    p1.setPasPossible(1);
    cout <<p1.toString()<<"\n";
    p1.setPasPossible(2);
    p1.setPasPossible(3);
    p1.setPasPossible(4);
    p1.setPasPossible(5);
    p1.setPasPossible(6);
    p1.setPasPossible(7);
    p1.setPasPossible(8);
    cout <<p1.toString()<<"\n";
}

int main(int argc, char *argv[])
{
    //testePiece();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
