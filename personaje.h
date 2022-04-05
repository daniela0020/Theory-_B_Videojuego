#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<QGraphicsItem>
#include<QPainter>
#include<QObject>


class personaje:public QGraphicsItem,public QObject
{
     float posx,posy,ancho,alto,velocidad=4,masa=100;
public:
     personaje();
     personaje(float posx,float posy);
     QRectF boundingRect() const;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
     void MoveRight();
     void MoveLeft();
     void MoveUp();
     void MoveDown();
     float getMasa() const;
     float getPosx() const;
     void setPosx(float newPosx);
     float getPosy() const;
     void setPosy(float newPosy);
};

#endif // PERSONAJE_H
