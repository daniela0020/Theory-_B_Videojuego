#ifndef ENEMIGOTERRESTRE_H
#define ENEMIGOTERRESTRE_H
#include<enemigo.h>

class enemigoTerrestre:public Enemigo
{
public:
    enemigoTerrestre(float posx,float posy);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // ENEMIGOTERRESTRE_H
