#include "personajeprincipal.h"

PersonajePrincipal::PersonajePrincipal(float x, float y)
{
    float posicionx = x;
    float posiciony = y;
    float velocidadx = 0;
    float velocidady = 0;
    //float aceleracionx;
    //float aceleraciony;
    //float dt;
    int ancho = 50;
    int alto = 50;
    int vidas = 3;

    setPos(posicionx,posiciony);
}

void PersonajePrincipal::MoveRight()
{
    this->posicionx+=velocidadPaso;
    filas=0;
    setPos(posicionx,posiciony);
}

void PersonajePrincipal::MoveLeft()
{
    this->posicionx-=velocidadPaso;
    filas=39;
    setPos(posicionx,posiciony);
}

QRectF PersonajePrincipal::boundingRect() const
{
    return QRect(-ancho/2, -alto/2, ancho, alto);
}

void PersonajePrincipal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Hay que cambiar esto cuando tengamos el sprite
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

void PersonajePrincipal::actualizarSalto(float velInicial)
{
    velocidadx = velInicial * cos(ang);
    velocidady = velInicial * sin(ang);

    posicionx = posicionx + (velocidadx*dt);
    posiciony = posiciony + (velocidady*dt) - (0.5*GR*(dt*dt));

}

void PersonajePrincipal::actualizarImagen()
{

}

