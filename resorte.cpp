#include "resorte.h"



double resorte::getVelocidad() const
{
    return velocidad;
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
    timer = new QTimer();

    timer->start(10);

    connect(timer,&QTimer::timeout,this,&resorte::actualizarPosicion);

}

void resorte::cambiarForma()
{
     float oldPosy=posy;
     alto+=(oldPosy-posy);
}

void resorte::actualizarPosicion()
{

    posy+=sin(angu);
    velocidad+=W*cos(angu);
    cambiarForma();
    setPos(posx,posy);
    actualizarValores();

    counterTime++;
    if(counterTime>1000){
        timer->deleteLater();
        counterTime=0;

    }
}

void resorte::sprint()
{

}
