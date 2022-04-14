#include "resorte.h"



float resorte::getVelocidad() const
{
    return velocidad;
}

bool resorte::getActivado() const
{
    return activado;
}

void resorte::setActivado(bool newActivado)
{
    activado = newActivado;
}

resorte::resorte()
{

}

resorte::resorte(float posx, float posy, float k)
{

    this->posx=posx;

    this->posy=posy;

    ancho=20;

    alto=50;

    this->k=k;

    setPos(posx,posy);

    W=(k/Masa);

    timer = new QTimer();

}

QRectF resorte::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto) ;
}

void resorte::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawRect(boundingRect());
}

void resorte::actualizarValores()
{
     angu+=W*dT;
}

void resorte::activarMovimiento()
{
    activado=true;

    timer->start(10);

    connect(timer,&QTimer::timeout,this,&resorte::actualizarPosicion);

}

void resorte::cambiarForma()
{

}

void resorte::actualizarPosicion()
{
    float oldPosy=posy;
    posy+=sin(angu);
    velocidad=30*abs(W*cos(angu));

    alto+=(oldPosy-posy);
    setPos(posx,posy);
    actualizarValores();

    counterTime++;
    if(counterTime>500){
        activado=false;
        timer->stop();
        counterTime=0;

    }
}

void resorte::sprint()
{

}
