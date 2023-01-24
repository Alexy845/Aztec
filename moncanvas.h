#ifndef MONCANVAS_H
#define MONCANVAS_H

#include <QWidget>
#include "plateau.h"

class MonCanvas : public QWidget
{
    Q_OBJECT
private:
    QImage *fond;
    Plateau *m_plateau=nullptr;
    QPointF changeCoo(QPointF p);
    int margex = 20, margeY = 40, deltaX = 55, deltaY = 55;
public:
    explicit MonCanvas(QWidget *parent = nullptr);
    void setPlateau(Plateau *newPlateau);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
signals:

};

#endif // MONCANVAS_H
