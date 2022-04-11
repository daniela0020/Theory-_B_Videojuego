#include "objetomovcircular.h"

ObjetoMovCircular::ObjetoMovCircular(int k,int h)
{
    angulo = 0;
    distancia = 125;
    radio=12;
    this->h = h;
    this->k = k;
    ancho = 10;
    alto = 10;
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&ObjetoMovCircular::actualizarPosicion);
    timer->start(100);
}

QRectF ObjetoMovCircular::boundingRect() const
{
      return QRect(-radio/2, -radio/2, radio*2, radio*2);
}

void ObjetoMovCircular::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

void ObjetoMovCircular::actualizarPosicion()
{ 
    posx = (distancia*cos(angulo)) + h;
    posy = (distancia*sin(angulo)) + k;
    angulo+=Wa*dt;
    setPos(posx,posy);
}
