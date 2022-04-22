#include "tiempo.h"
#include <QFont>

void Tiempo::setTiempo(unsigned short newTiempo)
{
    tiempo = newTiempo;
}

Tiempo::Tiempo()
{
    tiempo = 120;
    setPlainText(QString("Tiempo: ") +QString::number(tiempo));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Tiempo::decrease);
    timer->start(1000);

}

unsigned short Tiempo::getTiempo()
{
    return tiempo;
}

void Tiempo::decrease()
{
    tiempo --;
    setPlainText(QString("Tiempo: ") +QString::number(tiempo));
    if (tiempo<=0){
        timer->stop();
    }

}
