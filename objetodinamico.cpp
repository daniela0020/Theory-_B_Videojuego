#include "objetodinamico.h"

float objetoDinamico::getPosx()
{
    return posx;
}

void objetoDinamico::setPosx(float newPosx)
{
    posx = newPosx;
}

float objetoDinamico::getPosy()
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

void objetoDinamico::actualizarPosicion()
{

}

