#include "personajeprincipal.h"

void PersonajePrincipal::setDireccion(bool isDerecha)
{
    direccion = isDerecha;
}
bool PersonajePrincipal::getDireccion(){
    return direccion;
}

bool PersonajePrincipal::getParabolico() const
{
    return parabolico;
}

void PersonajePrincipal::setParabolico(bool newParabolico)
{
    parabolico = newParabolico;
}

bool PersonajePrincipal::getSaltando() const
{
    return saltando;
}

void PersonajePrincipal::setSaltando(bool newSaltando)
{
    saltando = newSaltando;
}

int PersonajePrincipal::getVidas() const
{
    return vidas;
}

void PersonajePrincipal::setVidas(int newVidas)
{
    vidas = newVidas;
}

bool PersonajePrincipal::getSubiendo() const
{
    return subiendo;
}

void PersonajePrincipal::setSubiendo(bool newSubiendo)
{
    subiendo = newSubiendo;
}

PersonajePrincipal::PersonajePrincipal(float x, float y):objetoDinamico(x,y,30,50)
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
    painter->setBrush(Qt::green);
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
    if(parabolico){
        if(direccion){
            posx = posx + (velocidadx*Dt);
            posy -= (velocidady*Dt) - (0.5*GR*Dt*Dt);

        }else{
            posx -= (velocidadx*Dt);
            posy -= (velocidady*Dt) - (0.5*GR*Dt*Dt);
        }
        if(posy<alturaMax){
            subiendo=false;
        }
    }
    else{
        ang=0;
        posy -= 15*(velocidady*Dt) - (0.5*GR*Dt*Dt);

    }

    setPos(posx,posy);
    VelocidadInicial();

}

void PersonajePrincipal::activarSalto(double ang,float velocidad)
{
    if(!saltando){
        this->ang = ang*(PI/180);
        this->velocidad=velocidad;
        VelocidadInicial();
        timer->start(10);
        saltando=true;
        subiendo=true;
    }

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


