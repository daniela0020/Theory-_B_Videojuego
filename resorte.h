#ifndef RESORTE_H
#define RESORTE_H




#include<objetodinamico.h>
#include<QMetaType>
#define B 20.0


class resorte:public objetoDinamico
{
    float k=0,W=0,angu=0,velocidad=0,dT = 0.1;
    int counterTime=0;
    bool activado=false;
    QPixmap *pixmap;

public:

    resorte();
    resorte(float posx, float posy,float k);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) ;
    void actualizarValores();
    void activarMovimiento();
    void cambiarForma();

    float getVelocidad() const;
    bool getActivado() const ;
    void setActivado(bool newActivado);




    void setCounterColision(int newCounterColision);


signals:
public slots:

    void actualizarPosicion();
    void sprint();

};

#endif // RESORTE_H
