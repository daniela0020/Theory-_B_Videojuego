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

PersonajePrincipal::PersonajePrincipal(float x, float y):objetoDinamico(x,y,30,50)
{
    velocidadx = 0;
    velocidady = 0;
    timer = new QTimer(this);
    timer2= new QTimer(this);
    pixmap=new QPixmap(":/imagenes/Personaje.png");
    columnas = 0;
    filas = 0;
    timer2->start(100);
    connect(timer,&QTimer::timeout,this,&PersonajePrincipal::actualizarPosicion);
    connect(timer2,&QTimer::timeout,this,&PersonajePrincipal::sprint);


}

QRectF PersonajePrincipal::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto) ;
}


void PersonajePrincipal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(-30,-50,*pixmap,columnas,filas,30,50);
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
    VelocidadInicial();
    if(parabolico){
          if(direccion){
              filas = 100;
              posx = posx + (velocidadx*Dt);
              posy -= (velocidady*Dt) - (0.5*GR*Dt*Dt);

          }else{
              filas = 150;
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

void PersonajePrincipal::sprint()
{
    columnas+=30;
    if(columnas>=90){
        columnas=0;
    }


}

void PersonajePrincipal::activarSalto(float ang, float velocidad)
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
    filas = 0;
    setPos(posx,posy);
}

void PersonajePrincipal::MoveLeft(float velocidad)
{
    this->posx-=velocidad;
    filas = 49;
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

bool PersonajePrincipal::getSubiendo() const
{
    return subiendo;
}

void PersonajePrincipal::establecerPosicion(float posx, float posy)
{
    this->posx=posx;
    this->posy=posy;
    setPos(posx,posy);
}





