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

resorte::resorte(float posx, float posy, float k):objetoDinamico(posx,posy,20,30)
{

    this->k=k;

    W=(k/Masa);

    pixmap=new QPixmap(":/imagenes/Resorte.png");

    timer = new QTimer();

}

QRectF resorte::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto) ;
}

void resorte::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-20,-30,*pixmap,columnas,filas,20,30);

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
    if (counterTime<250){
        filas=0;
    }
    if (counterTime>=250){
        filas = 30;
    }
    columnas+=20;
    if(columnas>=80){
        columnas=0;
    }

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

