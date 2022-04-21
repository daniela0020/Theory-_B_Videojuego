#include "enemigo.h"

Enemigo::Enemigo(float posx, float posy):objetoDinamico(posx,posy,25,25)
{

    this->k=300;

    W=(k/Masa);

    pixmap=new QPixmap(":/imagenes/Enemigo.png");

    timer = new QTimer();

    timer->start(100);

    connect(timer,&QTimer::timeout,this,&Enemigo::actualizarPosicion);

}
void Enemigo::actualizarPosicion()
{
    posx+=5*sin(angu);
    setPos(posx,posy);
    angu+=W*dT;
}
QRectF Enemigo::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}
void Enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-25,-25,*pixmap,columnas,filas,25,25);

}
