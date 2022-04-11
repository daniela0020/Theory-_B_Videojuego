#include "enemigovolador.h"

enemigoVolador::enemigoVolador()
{

}

enemigoVolador::enemigoVolador(float posx, float posy)
{
    this->posx=posx;
    this->posy=posy;
    this->ancho=25;
    this->alto=25;


    this->k=300;

    setPos(posx,posy);

    W=(k/Masa);

    timer = new QTimer();

    timer->start(100);

    connect(timer,&QTimer::timeout,this,&enemigoVolador::actualizarPosicion);

}

QRectF enemigoVolador::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void enemigoVolador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

void enemigoVolador::actualizarPosicion()
{
    posx+=5*sin(angu);
    setPos(posx,posy);
    angu+=W*dT;
}


