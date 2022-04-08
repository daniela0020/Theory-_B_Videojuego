#include "objetomovcircular.h"

ObjetoMovCircular::ObjetoMovCircular(int k,int h)
{
    angulo = 0;
    radio = 25;
    this->h = h;
    this->k = k;
    timer = new QTimer(this);
    //connect(time,SIGNAL(timeout()), this, SLOT(actualizarSalto()));
    connect(timer,&QTimer::timeout,this,&ObjetoMovCircular::actualizarPosicion);
    timer->start(10);
}

QRectF ObjetoMovCircular::boundingRect() const
{
      return QRect(-10, -10, 10, 10);
}

void ObjetoMovCircular::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Hay que cambiar esto cuando tengamos el sprite
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

void ObjetoMovCircular::actualizarPosicion()
{
    angulo = angulo + (W*dt);
    if (angulo>360){
        angulo = 0;
    }
    posx = (radio*cos(angulo)) + h;
    posy = (radio*sin(angulo)) + k;
    setPos(posx,posy);
}
