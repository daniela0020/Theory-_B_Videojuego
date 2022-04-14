#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include<string>
#include<fstream>
#include<utilidades.h>
#include<QMetaType>
using namespace std;




class baseDeDatos
{
public:

    void getPartida();
    void setPartida();
    template<typename T>
    void getStaticObjects(string fileName,string tipo, QList<T*> objects){

        ifstream reader;

        reader.open(fileName);
        string leido;
        int posicion[4],contador=0;

        if(tipo=="muro"){
            if(!reader.fail()){

                while(!reader.eof()){

                    reader>>leido;
                    posicion[contador]=utilidades::conversionStr2Int(leido);
                    contador++;

                    if(contador==3){
                        objects.append(new T[posicion[0],posicion[1],posicion[2]]);
                        posicion[0]=0;posicion[1]=0;posicion[2]=0;
                        contador=0;
                    }
                }
            }
        }
        else{
            if(!reader.fail()){

                while(!reader.eof()){

                    reader>>leido;
                    posicion[contador]=utilidades::conversionStr2Int(leido);
                    contador++;

                    if(contador==4){
                        objects.append(new T(posicion[0],posicion[1],posicion[2],posicion[3]));
                        posicion[0]=0;posicion[1]=0;posicion[2]=0;posicion[3]=0;
                        contador=0;
                    }
                }
            }
        }
        reader.close();

    }


};

#endif // BASEDEDATOS_H
