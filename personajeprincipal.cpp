#include "personajeprincipal.h"

void PersonajePrincipal::setDerecha(bool newDerecha)
{
    derecha = newDerecha;
}

PersonajePrincipal::PersonajePrincipal(double x, double y)
{
    posx = x;
    posy = y;
    velocidadx = 0;
    velocidady = 0;
    ancho = 25;
    alto = 25;
    vidas = 3;

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&PersonajePrincipal::actualizarSalto);
    setPos(posx,posy);
}

QRectF PersonajePrincipal::boundingRect() const
{
      return QRect(-ancho, -alto, ancho, alto);
}

void PersonajePrincipal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

void PersonajePrincipal::setAng(float newAng)
{
    ang = newAng;
}

void PersonajePrincipal::VelocidadInicial()
{
    velocidadx=velocidadPaso*cos(ang);
    velocidady=velocidadPaso*sin(ang)-GR*Dt;
    velocidadPaso=sqrt((velocidadx*velocidadx)+(velocidady*velocidady));
    ang=atan2(velocidady,velocidadx);
}

void PersonajePrincipal::actualizarSalto()
{
    if(derecha){
        posx = posx + (velocidadx*Dt);
        posy -= (velocidady*Dt) - (0.5*GR*Dt*Dt);

    }else{
        posx -= (velocidadx*Dt);
        posy -= (velocidady*Dt) - (0.5*GR*Dt*Dt);
    }

    setPos(posx,posy);
    VelocidadInicial();
    if(colisionConMuro<>()){

    }


}

void PersonajePrincipal::activarSalto(double ang)
{
    this->ang = ang;
    VelocidadInicial();
    timer->start(10);

}

void PersonajePrincipal::actualizarImagen()
{

}

