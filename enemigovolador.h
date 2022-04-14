#ifndef ENEMIGOVOLADOR_H
#define ENEMIGOVOLADOR_H

#include<enemigo.h>

class enemigoVolador:public Enemigo
{

public:
    enemigoVolador(float posx,float posy);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // ENEMIGOVOLADOR_H
