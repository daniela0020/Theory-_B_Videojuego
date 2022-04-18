#include "vidas.h"
#include <QFont>

Vidas::Vidas()
{
    vidas = 3;
    setPlainText(QString("Vidas: ") +QString::number(vidas));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));

}
unsigned short Vidas::getVidas()
{
    return vidas;
}

void Vidas::decrease()
{
    vidas --;
    setPlainText(QString("Vidas: ") +QString::number(vidas));

}
