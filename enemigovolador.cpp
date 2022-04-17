#include "enemigovolador.h"

enemigoVolador::enemigoVolador(float posx, float posy):Enemigo(posx, posy)
{

}

void enemigoVolador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}


