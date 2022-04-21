#include "fuego.h"

fuego::fuego()
{

}

fuego::fuego(float posx, float posy):objetoDinamico(posx,posy,20,20)
{
    imagen=new QImage(":/imagenes/fire.png");
}

QRectF fuego::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}
void fuego::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

   painter->drawImage(boundingRect(),*imagen);

}


QList<fuego*> fuego::creacionExplosion(float posx, float posy)
{
    QList<fuego *> fuegos;
    fuegos.append(new fuego(posx-20,posy));
    fuegos.append(new fuego(posx,posy));
    fuegos.append(new fuego(posx+20,posy));
    fuegos.append(new fuego(posx,posy-20));
    fuegos.append(new fuego(posx,posy+20));
    return fuegos;
}
