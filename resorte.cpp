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

resorte::resorte(float posx, float posy, float k):objetoDinamico(posx,posy,30,35)
{

    this->k=k;

    equilibrio=posy;

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

    timer->start(20);

    connect(timer,&QTimer::timeout,this,&resorte::actualizarPosicion);

}

void resorte::cambiarForma()
{

}

void resorte::actualizarPosicion()
{
    float oldPosy=posy;
    posy+=sin(angu);
    alto+=(oldPosy-posy);
    setPos(posx,posy);
    actualizarValores();

    counterTime++;

    if(counterTime>1000){
        posy=equilibrio;
        setPos(posx,posy);
        activado=false;
        timer->stop();
        counterTime=0;
    }
}

void resorte::sprint()
{

}

