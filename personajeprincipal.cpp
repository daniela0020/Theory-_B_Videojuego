#include "personajeprincipal.h"

PersonajePrincipal::PersonajePrincipal(float x, float y)
{
    posx = x;
    posy = y;
    velocidadx = 0;
    velocidady = 0;
    velInicialX = 0;
    velInicialY = 4;
    //float aceleracionx;
    //float aceleraciony;
    ancho = 25;
    alto = 25;
    vidas = 3;

    timer = new QTimer(this);
    //connect(time,SIGNAL(timeout()), this, SLOT(actualizarSalto()));
    connect(timer,&QTimer::timeout,this,&PersonajePrincipal::actualizarSalto);
    setPos(posx,posy);
}

QRectF PersonajePrincipal::boundingRect() const
{
      return QRect(-ancho, -alto, ancho, alto);//return QRect(-ancho/2, -alto/2, ancho, alto);
}

void PersonajePrincipal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Hay que cambiar esto cuando tengamos el sprite
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

void PersonajePrincipal::setAng(float newAng)
{
    ang = newAng;
}

void PersonajePrincipal::VelocidadInicial()
{
    //velInicialX = velocidadPaso * cos(angulo);
    //velInicialY = velocidadPaso * sin(angulo);
    //velocidady = velInicialY;
    velocidadx=velocidadPaso*cos(ang);
    velocidady=velocidadPaso*sin(ang)-GR*dt;
    velocidadPaso=sqrt((velocidadx*velocidadx)+(velocidady*velocidady));
    ang=atan2(velocidady,velocidadx);
}

void PersonajePrincipal::actualizarSalto()
{

    //velocidadx = velInicialX;
    //velocidady = velocidady + (GR*dt);

    posx = posx + (velocidadx*dt);
    posy -= (velocidady*dt) - (0.5*GR*(dt*dt));

    setPos(posx,posy);
    VelocidadInicial();
/*
    if(posy < 310){
        timer->stop();
        posy = 310;
    }
*/

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

