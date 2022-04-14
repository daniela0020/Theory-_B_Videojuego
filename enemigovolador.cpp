#include "enemigovolador.h"

enemigoVolador::enemigoVolador(float posx, float posy):Enemigo(posx, posy)
{

}

<<<<<<< HEAD
=======

>>>>>>> 8d7a53ce2a97f33380614d25e9257f773b663413
void enemigoVolador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}


