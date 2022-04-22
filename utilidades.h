#ifndef UTILIDADES_H
#define UTILIDADES_H

#include<string>
#include<QString>
using namespace std;

class utilidades
{
public:
    utilidades();
    static int contadorDigitos(string numero);
    static float conversionStr2float(string numero);
    static int conversionStrInt(string numero);
    static QString conversionInt2Str(int numero);
    static short int conversionStrShortInt(string numero);
};
#endif // UTILIDADES_H
