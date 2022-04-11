#include "personajeprincipal.h"

void PersonajePrincipal::setDerecha(bool newDerecha)
{
    derecha = newDerecha;
}




void PersonajePrincipal::setVelocidadInicial(float newVelocidadInicial)
{
    velocidadInicial = newVelocidadInicial;
}

float PersonajePrincipal::getVelocidadInicial()
{
    return velocidadInicial;
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
    setPos(posx,posy);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&PersonajePrincipal::actualizarPosicion);

}

QRectF PersonajePrincipal::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto) ;
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
    velocidadx=velocidadInicial*cos(ang);
    velocidady=velocidadInicial*sin(ang)-GR*Dt;
    velocidadInicial=sqrt((velocidadx*velocidadx)+(velocidady*velocidady));
    ang=atan2(velocidady,velocidadx);
}

void PersonajePrincipal::actualizarPosicion()
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



}

void PersonajePrincipal::activarSalto(double ang)
{
    this->ang = ang*(PI/180);
    VelocidadInicial();
    timer->start(10);

}

void PersonajePrincipal::actualizarImagen()
{

}

