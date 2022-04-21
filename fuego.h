#ifndef FUEGO_H
#define FUEGO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include<QPainter>
#include<QTimer>
#include<objetodinamico.h>

class fuego:public objetoDinamico
{

public:
    fuego();

    fuego(float posx,float posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QList<fuego*> creacionExplosion(int posx, int poxy);
    QPixmap *pixmap;
    QImage *imagen;

};

#endif // FUEGO_H

