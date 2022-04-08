#ifndef PERSONAJE_H
#define PERSONAJE_H
#include<objetodinamico.h>




class personaje:public objetoDinamico
{

public:
     personaje();
     personaje(double posx,double posy,double ancho,double alto);
     QRectF boundingRect() const;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
     void actualizarPosicion();
     void sprint();

};

#endif // PERSONAJE_H
