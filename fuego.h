#ifndef FUEGO_H
#define FUEGO_H


#include <QGraphicsPixmapItem>
#include<QPainter>
#include<objetodinamico.h>

class fuego:public objetoDinamico
{

public:
    fuego();

    fuego(float posx,float posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QList<fuego*> creacionExplosion(float posx, float poxy);
    QImage *imagen;

};

#endif // FUEGO_H
