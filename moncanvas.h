#ifndef MONCANVAS_H
#define MONCANVAS_H

#include <QWidget>
#include "plateau.h"
#include "mainwindow.h"

class MonCanvas : public QWidget
{
    Q_OBJECT
private:
    MainWindow *mainwindow;
    QImage *fond;
    Plateau *m_plateau=nullptr;
    QPointF changeCoo(QPointF p);
    int margex = 312, margeY = 110, deltaX = 55, deltaY = 55;
public:
    MonCanvas(QWidget *parent = nullptr);
    void setPlateau(Plateau *newPlateau);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void setMainwindow(MainWindow *newMainwindow);

signals:

};

#endif // MONCANVAS_H
