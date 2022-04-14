#include "enemigoterrestre.h"

enemigoTerrestre::enemigoTerrestre(float posx, float posy):Enemigo(posx, posy)
{

}
void enemigoTerrestre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}
