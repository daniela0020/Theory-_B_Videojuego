#include "resorte.h"



double resorte::getVelocidad() const
{
    return velocidad;
}


resorte::resorte()
{

}

resorte::resorte(float posx, float posy,float ancho, float alto, float k)
{

    this->posx=posx;

    this->posy=posy;

    this->ancho=ancho;

    this->alto=alto;

    this->k=k;

    setPos(posx,posy);

    alpha=-(B/(2*Masa));

    W=sqrt(((k/Masa)-pow(alpha,2)));


}
QRectF resorte::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void resorte::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawRect(boundingRect());
}

void resorte::actualizarValores()
{
    expo+=alpha*dt;
    angu+=W*dt;
}

void resorte::activarMovimiento()
{
    timer = new QTimer();

    timer->start(10);

    connect(timer,&QTimer::timeout,this,&resorte::actualizarPosicion);

}

void resorte::actualizarPosicion()
{
    float oldPosy=posy;
    posy+=sin(angu);
    velocidad+=W*cos(angu);
    alto+=(oldPosy-posy);
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
