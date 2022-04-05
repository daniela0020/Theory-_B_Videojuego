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
    static int conversionStr2Int(string numero);
    static QString conversionInt2Str(int numero);
};
#endif // UTILIDADES_H
