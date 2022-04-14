#include "basededatos.h"




void baseDeDatos::getStaticObjects(string fileName, QList<objetoEstatico *> &objects)
{
    ifstream reader;

    reader.open(fileName);
    string leido;
    int posicion[4],contador=0;

        if(!reader.fail()){

            while(!reader.eof()){

                reader>>leido;
                posicion[contador]=utilidades::conversionStr2Int(leido);
                contador++;

                if(contador==4){
                    objects.append(new objetoEstatico(posicion[0],posicion[1],posicion[2],posicion[3]));
                    posicion[0]=0;posicion[1]=0;posicion[2]=0;posicion[3]=0;
                    contador=0;
                }
            }
        }

    reader.close();
}
