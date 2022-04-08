#ifndef BOMBA_H
#define BOMBA_H
#define GR 9.8
#define dt 0.1

class Bomba
{
    float velocidadx;
    float velocidady;
    float velocidadPaso = 30;
public:
    Bomba();

    void VelocidadInicial();
    void activarMovimiento(double angulo);
};

#endif // BOMBA_H
