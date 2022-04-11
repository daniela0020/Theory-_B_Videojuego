#include "objetodinamico.h"

double objetoDinamico::getPosx()
{
    return posx;
}

void objetoDinamico::setPosx(float newPosx)
{
    posx = newPosx;
}

double objetoDinamico::getPosy()
{
    return posy;
}

void objetoDinamico::setPosy(float newPosy)
{
    posy = newPosy;
}





void objetoDinamico::sprint()
{

}



objetoDinamico::objetoDinamico()
{

}


objetoDinamico::objetoDinamico(float posx,float posy,int ancho,int alto)

{
    this->posx=posx;

    this->posy=posy;

    this->ancho=ancho;

    this->alto=alto;

    setPos(posx,posy);

}
void objetoDinamico::MoveRight(float velocidad)
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void objetoDinamico::MoveLeft(float velocidad)
{
    this->posx-=velocidad;

    setPos(posx,posy);
}

void objetoDinamico::MoveUp(float velocidad)
{
    this->posy-=velocidad;

    setPos(posx,posy);
}

void objetoDinamico::MoveDown(float velocidad)
{
    this->posy+=velocidad;

    setPos(posx,posy);
}

QRectF objetoDinamico::boundingRect() const
{
      return QRect();
}
void objetoDinamico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void objetoDinamico::actualizarPosicion()
{

}

