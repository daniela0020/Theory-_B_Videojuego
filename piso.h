#ifndef PISO_H
#define PISO_H


#include<personaje.h>

class piso:public personaje
{

public:
    piso();
    piso(double posx,double posy, double ancho, double alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PISO_H
