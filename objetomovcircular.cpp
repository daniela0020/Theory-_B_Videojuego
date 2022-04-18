#include "objetomovcircular.h"

ObjetoMovCircular::ObjetoMovCircular(float x,float y,float distancia)
{
    angulo = 0;
    this->distancia = distancia;
    radio=12;
    this->x = x;
    this->y = y;
    ancho = 10;
    alto = 10;
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&ObjetoMovCircular::actualizarPosicion);

    timer->start(100);

}

QRectF ObjetoMovCircular::boundingRect() const
{
    return QRectF(-radio/2, -radio/2, radio*2, radio*2) ;
}

void ObjetoMovCircular::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void ObjetoMovCircular::actualizarPosicion()

{ 
    posx = (distancia*cos(angulo)) + x;
    posy = (distancia*sin(angulo)) + y;
    angulo+=Wa*dt;
    setPos(posx,posy);
}
