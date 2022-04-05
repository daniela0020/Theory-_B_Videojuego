#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include<string>
#include<fstream>
#include<utilidades.h>
#include<QMetaType>
using namespace std;
template<typename T>



class baseDeDatos
{
public:



    void getStaticObjects(string fileName,QList<T*> object);
    //void getStaticObjects(string fileName,QList<T>);//bonus time- floor - airblocks - coins
    void getDinamicObjects(string fileName,QList<T*> object);//fireballs - springs - enemies
    void getPartida();
    void setPartida();

};

#endif // BASEDEDATOS_H
