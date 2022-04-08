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


    template<typename T>
    void getStaticObjects(string fileName,QList<T*> object){
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
                    object.append(new T(posicion[0],posicion[1],posicion[2],posicion[3]));
                    posicion[0]=0;posicion[1]=0;posicion[2]=0;posicion[3]=0;
                    contador=0;
                }
            }
        }
        reader.close();
    }
    //void getStaticObjects(string fileName,QList<T>);//bonus time- floor - airblocks - coins
    //template<typename T>
    //void getDinamicObjects(string fileName,QList<T*> object);//fireballs - springs - enemies
    void getPartida();
    void setPartida();

};

#endif // BASEDEDATOS_H
