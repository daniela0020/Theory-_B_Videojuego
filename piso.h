#ifndef PISO_H
#define PISO_H


#include<QGraphicsItem>
#include<QPainter>
#include<QObject>

class piso: public QObject, public QGraphicsItem
{
    int posx,posy,ancho,alto;
public:
    piso();
    piso(int posx,int posy, int ancho, int alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getPosx() ;
    int getPosy() ;
};

#endif // PISO_H
