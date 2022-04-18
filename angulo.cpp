#include "angulo.h"
#include <QFont>

Angulo::Angulo()
{
    angulo = 0;
    setPlainText(QString("Ángulo: ") +QString::number(angulo));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));

}

void Angulo::SumAngulo()
{
    angulo += 10;
    setPlainText(QString("Ángulo: ") +QString::number(angulo));

}

void Angulo::ResAngulo()
{
    angulo -= 10;
    setPlainText(QString("Ángulo: ") +QString::number(angulo));

}

