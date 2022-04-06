#include "resorte.h"



resorte::resorte()
{

}

resorte::resorte(double posx, double posy,double ancho, double alto, double k)
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

void resorte::calcularPosicion()
{
    posy+=exp(expo)*sin(angu);
    setPos(posx,posy);
    this->actualizarValores();
}
void resorte::actualizarValores()
{
    expo+=alpha*dt;
    angu+=W*dt;
}

void resorte::activarMovimiento()
{
    time = new QTimer();

    time->start(10);

    connect(time,&QTimer::timeout,this,&resorte::calcularPosicion);
}
