#include "personajeprincipal.h"


void PersonajePrincipal::setVelocidadInicial(float newVelocidadInicial)
{
    velocidadInicial = newVelocidadInicial;
}

float PersonajePrincipal::getVelocidadInicial()
{
    return velocidadInicial;
}

void PersonajePrincipal::setDireccion(bool newDireccion)
{
    direccion = newDireccion;
}

void PersonajePrincipal::setParabolico(bool newParabolico)
{
    parabolico = newParabolico;
}

bool PersonajePrincipal::getParabolico() const
{
    return parabolico;
}

void PersonajePrincipal::setSaltando(bool newSaltando)
{
    saltando = newSaltando;
}

bool PersonajePrincipal::getSaltando() const
{
    return saltando;
}

PersonajePrincipal::PersonajePrincipal(double x, double y)
{
    posx = x;
    posy = y;
    velocidadx = 0;
    velocidady = 0;
    ancho = 40;
    alto = 60;
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
    painter->setBrush(Qt::green);
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
    if(parabolico){
        if(direccion){
            posx = posx + (velocidadx*Dt);
            posy -= (velocidady*Dt) - (0.5*GR*Dt*Dt);

        }else{
            posx -= (velocidadx*Dt);
            posy -= (velocidady*Dt) - (0.5*GR*Dt*Dt);
        }
    }else{//ecuaciones para caida libre
        velocidadx=0;
        ang=0;
        posy -= 10*(velocidady*Dt) - (0.5*GR*Dt*Dt);
    }


    setPos(posx,posy);
    VelocidadInicial();

}

void PersonajePrincipal::activarSalto(double ang)
{
    if(!saltando){//garantizo que no pueda saltar mientras esté en caida libre
        this->ang = ang*(PI/180);
        velocidadInicial=(velocidadInicial<50 || velocidadInicial>70)?50:velocidadInicial;
        VelocidadInicial();
        timer->start(10);
        saltando=true;
    }

}


