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
void objetoDinamico::MoveRight()
{
    this->posx+=velocidadPaso;
    setPos(posx,posy);
}

void objetoDinamico::MoveLeft()
{
    this->posx-=velocidadPaso;

    setPos(posx,posy);
}

void objetoDinamico::MoveUp()
{
    this->posy-=velocidadPaso;

    setPos(posx,posy);
}

void objetoDinamico::MoveDown()
{
    this->posy+=velocidadPaso;

    setPos(posx,posy);
}


void objetoDinamico::actualizarPosicion()
{

}

