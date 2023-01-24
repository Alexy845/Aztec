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
    int margex = 52, margeY = 63, deltaX = 92, deltaY = 93;
public:
    explicit MonCanvas(QWidget *parent = nullptr);
    void setPlateau(Plateau *newPlateau);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
signals:

};

#endif // MONCANVAS_H
