#include "piso.h"

piso::piso()
{

}

piso::piso(int posx, int posy, int ancho, int alto)
{
    this->ancho=ancho;
    this->alto=alto;
    this->posx=posx;
    this->posy=posy;

}
QRectF piso::boundingRect() const
{
    return QRectF(-posx,-posy,ancho,alto);
}

void piso::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
