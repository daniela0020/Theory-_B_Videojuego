#ifndef OBJETOESTATICO_H
#define OBJETOESTATICO_H

#include<QObject>
#include<QGraphicsItem>
#include<QPainter>

class objetoEstatico:public QObject,public QGraphicsItem
{
    float posx=0,posy=0,alto=0,ancho=0;


public:
    objetoEstatico();
    objetoEstatico(float posx,float posy,float ancho,float alto);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // OBJETOESTATICO_H
