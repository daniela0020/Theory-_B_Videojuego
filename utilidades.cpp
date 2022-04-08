#include "utilidades.h"

utilidades::utilidades()
{

}

int utilidades::contadorDigitos(string numero)
{
    int digitos=0;

    for(int i=0;i<numero.length();i++){
        digitos=(numero.at(i)!='-')?digitos+=1:digitos;
    }

    return digitos;
}

int utilidades::conversionStr2Int(string numero)
{
    int multi=1,char2int=0,signo=1;

    for(int i=0;i<contadorDigitos(numero)-1;++i)
    {
        multi*=10;
    }

    for(int i=0;i<numero.length();++i){

        if(numero.at(i)!='-'){
            char2int+=(numero.at(i)-48)*multi;
            multi/=10;
        }else{
            signo=-1;
        }

    }

    return char2int*signo;
}

QString utilidades::conversionInt2Str(int numero)
{
    return QString::number(numero);
}
