#include "bomba.h"


void Bomba::setDerecha(bool newDerecha)
{
    derecha = newDerecha;
}

Bomba::Bomba(float x,float y):objetoDinamico(x,y,25,25)
{
    velocidadx = 0;

    velocidady = 0;

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Bomba::actualizarPosicion);

}
QRectF Bomba::boundingRect() const
{
      return QRect(-ancho, -alto, ancho, alto);
}

void Bomba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}
void Bomba::VelocidadInicial()
{
    velocidadx=velocidad*cos(ang);
    velocidady=velocidad*sin(ang)-GR*dt;
    velocidad=sqrt((velocidadx*velocidadx)+(velocidady*velocidady));
    ang=atan2(velocidady,velocidadx);
}

void Bomba::actualizarPosicion()
{
    if(derecha){
        posx = posx + (velocidadx*dt);
        posy -= (velocidady*dt) - (0.5*GR*dt*dt);

    }
    else{
        posx -= (velocidadx*dt);
        posy -= (velocidady*dt) - (0.5*GR*dt*dt);
    }

    setPos(posx,posy);
    VelocidadInicial();

}
void Bomba::activarMovimiento(float ang)
{
    this->ang = ang*(PI/180);
    VelocidadInicial();
    timer->start(10);

}
