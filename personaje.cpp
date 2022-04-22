#include "personaje.h"

personaje::personaje()
{

}

personaje::personaje(double posx,double posy, double ancho, double alto)
{
    this->posx=posx;

    this->posy=posy;

    this->ancho=ancho;

    this->alto=alto;

    setPos(posx,posy);
}

QRectF personaje::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawRect(boundingRect());
}

void personaje::actualizarPosicion()
{

}

void personaje::sprint()
{

}

