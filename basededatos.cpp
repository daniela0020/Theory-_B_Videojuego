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
                posicion[contador]=utilidades::conversionStrInt(leido);
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


void baseDeDatos::getBolasFuego(string fileName, QList<ObjetoMovCircular*> &objects)
{
    ifstream reader;
    reader.open(fileName);
    string leido;
    int posicion[3],contador=0;

        if(!reader.fail()){

            while(!reader.eof()){

                reader>>leido;
                posicion[contador]=utilidades::conversionStrInt(leido);
                contador++;

                if(contador==3){
                    objects.append(new ObjetoMovCircular(posicion[0],posicion[1],posicion[2]));
                    posicion[0]=0;posicion[1]=0;posicion[2]=0;
                    contador=0;
                }
            }
        }

        reader.close();
}

void baseDeDatos::getEnemigos(string fileName, QList<Enemigo *> &objects)
{
    ifstream reader;
    reader.open(fileName);
    string leido;
    int posicion[2],contador=0;

        if(!reader.fail()){

            while(!reader.eof()){

                reader>>leido;
                posicion[contador]=utilidades::conversionStrInt(leido);
                contador++;

                if(contador==2 ){
                    objects.append(new Enemigo(posicion[0],posicion[1]));
                    posicion[0]=0;posicion[1]=0;
                    contador=0;
                }
            }
        }

        reader.close();
}

void baseDeDatos::getResortes(string fileName, QList<resorte *> &objects)
{
    ifstream reader;
    reader.open(fileName);
    string leido;
    int posicion[3],contador=0;

        if(!reader.fail()){

            while(!reader.eof()){

                reader>>leido;
                posicion[contador]=utilidades::conversionStrInt(leido);
                contador++;

                if(contador==3){
                    objects.append(new resorte(posicion[0],posicion[1],posicion[2]));
                    posicion[0]=0;posicion[1]=0;posicion[2]=0;
                    contador=0;
                }
            }
        }

        reader.close();
}

