#ifndef RESORTE_H
#define RESORTE_H




#include<objetodinamico.h>
#include<QMetaType>
#include<piso.h>

#define B 20.0
#define dT 1


class resorte:public objetoDinamico
{
    float k=0,W=0,angu=0,velocidad=0;
    int counterTime=0;
    bool activado=false;


public:

    resorte();
    resorte(float posx, float posy,float k);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) ;
    void actualizarValores();
    void activarMovimiento();
    void cambiarForma();

    double getVelocidad() const;




    void setCounterColision(int newCounterColision);

    bool getActivado() const;
    void setActivado(bool newActivado);

signals:
public slots:

    void actualizarPosicion();
    void sprint();

};

#endif // RESORTE_H
