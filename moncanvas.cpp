#include "moncanvas.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

void MonCanvas::setPlateau(Plateau *newPlateau)
{
    m_plateau = newPlateau;
}

QPointF MonCanvas::changeCoo(QPointF p)
{

    return QPointF(p.x()*deltaX+margex, p.y()*deltaY+margeY);
}

MonCanvas::MonCanvas(QWidget *parent)
    : QWidget{parent}
{
    fond = new QImage(":/images/grille.png");
}

void MonCanvas::paintEvent(QPaintEvent *)
{
    if(m_plateau != nullptr) {
        QPainter painter(this);
        painter.drawImage(0, 0, *fond);
        QFont *police = new QFont("Arial", 40, QFont::Bold);
        painter.setFont(*police);
        for(int l=0;l<9; l++) {
            for(int c=0;c<9;c++) {
                int v = m_plateau->getValeur(l, c);
                if(v!=0) {
                    //qDebug() <<"Ligne "<<l<<", colonne "<<c<<" : valeur "<<v;
                    painter.drawText(changeCoo(QPointF(c, l)), QString::number(v));
                }
            }
        }
    }
}

/*
 * colonnes : 22, 111, 204
 * lignes : 10, 100, 190
 *
 */

void MonCanvas::mousePressEvent(QMouseEvent *event)
{
    int c = (event->position().x()-22)/90;
    int l = (event->position().y()-10)/90;
    qDebug() <<"Ligne "<<l<<", colonne "<<c<<", forme "<<m_plateau->quelleForme(l, c);
}
