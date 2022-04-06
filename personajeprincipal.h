#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H
#include <QPainter>
#include <QGraphicsItem>
#include <QTimer>
#include <math.h>
#define MASA 70
#define GR -9.8
#define dt 0.1

class PersonajePrincipal:public QObject, public QGraphicsItem
{

private:
    float posicionx;
    float posiciony;
    float velocidadx;
    float velocidady;
    float velInicialX;
    float velInicialY;
    //float aceleracionx;
    //float aceleraciony;
    float velocidadPaso = 30;
    //float dt;
    int ancho;
    int alto;
    int vidas;
    QTimer *time;
    int filas=0, columnas=0;
public:
    PersonajePrincipal(float x, float y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void MoveRight();
    void MoveLeft();

    void setPosy(float newPosx);

    void setPosx(float newPosy);

    float getPosx() const;

    float ang = 45;

    float getPosy() const;

    void actualizarImagen();

    void activarMovimiento();

    void VelocidadInicial(int angulo);

public slots:

    void actualizarSalto();


};

#endif // PERSONAJEPRINCIPAL_H
