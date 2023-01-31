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


        QColor violet = QColor(74,57,88);
        painter.setPen(violet);
        violet.setAlphaF( 0.2 );
        painter.setBrush(violet);
        int y = m_plateau->getSelectCase()[0]*55+74;
        int x = m_plateau->getSelectCase()[1]*55+292;
        painter.drawRect(QRect(x,y,55,55));

        QFont *police = new QFont("Arial", 20, QFont::Bold);
        painter.setFont(*police);
        for(int l=0;l<9; l++) {
            for(int c=0;c<9;c++) {
                int v = m_plateau->getDefaultValeur(l, c);
                int nv = m_plateau->getValeur(l, c);
                if(v!=0) {
                    painter.setPen(QColor(46,35,56));
                    painter.drawText(changeCoo(QPointF(c, l)), QString::number(v));
                } else if (nv != 0){
                    painter.setPen(nv >= 10 ? Qt::red:QColor(178,163,153));
                    painter.drawText(changeCoo(QPointF(c, l)), QString::number(nv >= 10 ? nv/10:nv));
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
    if(event->position().x() > 292 && event->position().x() < 787 && event->position().y() > 74 && event->position().y() < 569){
        int c = (event->position().x()-292)/55;
        int l = (event->position().y()-74)/55;
        qDebug() << event->position().x() << event->position().y();
        m_plateau->setSelectCase({l,c});
        repaint();
    }
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
    else{
        m_plateau->setValue(m_plateau->getSelectCase()[0], m_plateau->getSelectCase()[1], 0);
        repaint();
    }
}
