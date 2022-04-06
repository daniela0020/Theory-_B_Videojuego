#include "personajeprincipal.h"

PersonajePrincipal::PersonajePrincipal(float x, float y)
{
    posicionx = x;
    posiciony = y;
    velocidadx = 0;
    velocidady = 0;
    velInicialX = 0;
    velInicialY = 4;
    //float aceleracionx;
    //float aceleraciony;
    ancho = 25;
    alto = 25;
    vidas = 3;

    time = new QTimer(this);
    //connect(time,SIGNAL(timeout()), this, SLOT(actualizarSalto()));
    connect(time,&QTimer::timeout,this,&PersonajePrincipal::actualizarSalto);
    setPos(posicionx,posiciony);
}

float PersonajePrincipal::getPosx() const
{
    return posicionx;
}
/*
void PersonajePrincipal::setPosx(float newPosx)
{
    posicionx = newPosx;
}
*/
float PersonajePrincipal::getPosy() const
{
    return posiciony;
}

void PersonajePrincipal::setPosy(float newPosy)
{
    posiciony = newPosy;
}


void PersonajePrincipal::MoveRight()
{
    this->posicionx+=velocidadPaso;
    //filas=0;
    setPos(posicionx,posiciony);
}

void PersonajePrincipal::MoveLeft()
{
    this->posicionx-=velocidadPaso;
    //filas=39;
    setPos(posicionx,posiciony);
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

void PersonajePrincipal::VelocidadInicial(int angulo)
{
    velInicialX = velocidadPaso * cos(angulo);
    velInicialY = velocidadPaso * sin(angulo);
    velocidady = velInicialY;
}

void PersonajePrincipal::actualizarSalto()
{

    velocidadx = velInicialX;
    velocidady = velocidady + (GR*dt);

    posicionx = posicionx + (velocidadx*dt);
    posiciony = posiciony + (velocidady*dt) - (0.5*GR*(dt*dt));

    setPos(posicionx,posiciony);

    if(posiciony < 310){
        time->stop();
        posiciony = 310;
    }


}

void PersonajePrincipal::activarMovimiento()
{

    time->start(10);

}

void PersonajePrincipal::actualizarImagen()
{

}

