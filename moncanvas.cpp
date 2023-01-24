#include "moncanvas.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>

void MonCanvas::setPlateau(Plateau *newPlateau)
{
    m_plateau = newPlateau;
    setFocusPolicy( Qt::StrongFocus );
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
                int v = m_plateau->getDefaultValeur(l, c);
                int nv = m_plateau->getValeur(l, c);
                if(v!=0) {
                    painter.setPen(Qt::black);
                    painter.drawText(changeCoo(QPointF(c, l)), QString::number(v));
                } else if (nv != 0){
                    painter.setPen(Qt::gray);
                    painter.drawText(changeCoo(QPointF(c, l)), QString::number(nv));
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
    m_plateau->setSelectCase({l,c});
    qDebug() << m_plateau->getSelectCase();
}

void MonCanvas::keyPressEvent(QKeyEvent *event)
{
    if  (event->key() == Qt::Key_1){
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 1);
        repaint();
    }
    else if (event->key() == Qt::Key_2){
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 2);
        repaint();
    }
    else if (event->key() == Qt::Key_3){
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 3);
        repaint();
    }
    else if (event->key() == Qt::Key_4){
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 4);
        repaint();
    }
    else if (event->key() == Qt::Key_5){
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 5);
        repaint();
    }
    else if (event->key() == Qt::Key_6){
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 6);
        repaint();
    }
    else if (event->key() == Qt::Key_7){
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 7);
        repaint();
    }
    else if (event->key() == Qt::Key_8){
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 8);
        repaint();
    }
    else if (event->key() == Qt::Key_9){
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 9);
        repaint();
    }
}
