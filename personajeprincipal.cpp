#include "personajeprincipal.h"

void PersonajePrincipal::setDireccion(bool isDerecha)
{
    direccion = isDerecha;
}
bool PersonajePrincipal::getDireccion(){
    return direccion;
}

void PersonajePrincipal::setVelocidad(float newVelocidad)
{
    velocidad += newVelocidad;
}

float PersonajePrincipal::getVelocidad() const
{
    return velocidad;
}

PersonajePrincipal::PersonajePrincipal(float x, float y):objetoDinamico(x,y,25,25)
{
    velocidadx = 0;
    velocidady = 0;
    vidas = 3;
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
    velocidadx=velocidad*cos(ang);
    velocidady=velocidad*sin(ang)-GR*Dt;
    velocidad=sqrt((velocidadx*velocidadx)+(velocidady*velocidady));
    ang=atan2(velocidady,velocidadx);
}

void PersonajePrincipal::actualizarPosicion()
{
    if(direccion){
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

void PersonajePrincipal::MoveRight(float velocidad)
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void PersonajePrincipal::MoveLeft(float velocidad)
{
    this->posx-=velocidad;

    setPos(posx,posy);
}

void PersonajePrincipal::MoveUp(float velocidad)
{
    this->posy-=velocidad;

    setPos(posx,posy);
}

void PersonajePrincipal::MoveDown(float velocidad)
{
    this->posy+=velocidad;

    setPos(posx,posy);
}





