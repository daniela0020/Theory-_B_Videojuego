#include "personaje.h"

float personaje::getMasa() const
{
    return masa;
}

float personaje::getPosx() const
{
    return posx;
}

void personaje::setPosx(float newPosx)
{
    posx = newPosx;
}

float personaje::getPosy() const
{
    return posy;
}

void personaje::setPosy(float newPosy)
{
    posy = newPosy;
}

personaje::personaje()
{

}

personaje::personaje(float posx, float posy)
{
    this->posx=posx;

    this->posy=posy;

    setPos(posx,posy);

    ancho=34;alto=34;

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

void personaje::MoveRight()
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void personaje::MoveLeft()
{
    this->posx-=velocidad;

    setPos(posx,posy);
}

void personaje::MoveUp()
{
    this->posy-=velocidad;

    setPos(posx,posy);
}

void personaje::MoveDown()
{
    this->posy+=velocidad;

    setPos(posx,posy);
}
