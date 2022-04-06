#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<QGraphicsItem>
#include<QPainter>
#include<QObject>

#define Masa 100.0

class personaje:public QGraphicsItem,public QObject
{

public:
     double posx, posy;
     double ancho,alto;
     personaje();
     personaje(double posx,double posy,double ancho,double alto);
     QRectF boundingRect() const;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
     void MoveRight(double velocidad);
     void MoveLeft(double velocidad);
     void MoveUp(double velocidad);
     void MoveDown(double velocidad);


};

#endif // PERSONAJE_H
