#ifndef OBJETODINAMICO_H
#define OBJETODINAMICO_H

#include<QTimer>
#include<QObject>
#include<QGraphicsItem>
#include<QPainter>

#define Masa 100.0
class objetoDinamico:public QObject,public QGraphicsItem
{
public:
    //atributos publicos para su facil empleo en la herencia
    double posx=0,posy=0;

    int ancho=0,alto=0,filas=0, columnas=0;


    QTimer *timer;
    //constructuroes
    objetoDinamico();
    objetoDinamico(double posx,double posy,int ancho,int alto);

    //metodos
    void MoveRight(double pixeles);
    void MoveLeft(double pixeles);
    void MoveUp(double pixeles);
    void MoveDown(double pixeles);
    double getPosx() ;
    void setPosx(double newPosx);
    double getPosy() ;
    void setPosy(double newPosy);

    //Metodos abstractos

    virtual QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

signals:
public slots:

    //slot abstracto

    virtual void sprint();
    virtual void actualizarPosicion();


};

#endif // OBJETODINAMICO_H
