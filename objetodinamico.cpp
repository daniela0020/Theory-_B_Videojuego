#include "objetodinamico.h"

double objetoDinamico::getPosx()
{
    return posx;
}

void objetoDinamico::setPosx(double newPosx)
{
    posx = newPosx;
}

double objetoDinamico::getPosy()
{
    return posy;
}

void objetoDinamico::setPosy(double newPosy)
{
    posy = newPosy;
}

QRectF objetoDinamico::boundingRect() const
{
    return QRectF();
}

void objetoDinamico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void objetoDinamico::sprint()
{

}

void objetoDinamico::actualizarPosicion()
{

}

objetoDinamico::objetoDinamico()
{

}

objetoDinamico::objetoDinamico(double posx,double posy,int ancho,int alto)
{
    this->posx=posx;

    this->posy=posy;

    this->ancho=ancho;

    this->alto=alto;

    setPos(posx,posy);

}
void objetoDinamico::MoveRight(double velocidad)
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void objetoDinamico::MoveLeft(double velocidad)
{
    this->posx-=velocidad;

    setPos(posx,posy);
}

void objetoDinamico::MoveUp(double velocidad)
{
    this->posy-=velocidad;

    setPos(posx,posy);
}

void objetoDinamico::MoveDown(double velocidad)
{
    this->posy+=velocidad;

    setPos(posx,posy);
}
