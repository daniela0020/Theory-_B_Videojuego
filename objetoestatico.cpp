#include "objetoestatico.h"

float objetoEstatico::getPosy() const
{
    return posy;
}

void objetoEstatico::setPosy(float newPosy)
{
    posy = newPosy;
}

float objetoEstatico::getPosx() const
{
    return posx;
}

void objetoEstatico::setPosx(float newPosx)
{
    posx = newPosx;
}

objetoEstatico::objetoEstatico()
{

}

objetoEstatico::objetoEstatico(float posx, float posy, float ancho, float alto)
{
    this->posx=posx;
    this->posy=posy;
    this->ancho=ancho;
    this->alto=alto;
    setPos(posx,posy);
}

QRectF objetoEstatico::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}
void objetoEstatico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    painter->drawRect(boundingRect());
}
