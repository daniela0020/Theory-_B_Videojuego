#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include<string>
#include<fstream>
#include<utilidades.h>
#include<objetoestatico.h>
#include<objetodinamico.h>

using namespace std;




class baseDeDatos
{
public:

    void getPartida();
    void setPartida();
    void getStaticObjects(string fileName, QList<objetoEstatico*> &objects);
    void getDinamicObjects(string fileName, QList<objetoDinamico*> &objects);


};


#endif // BASEDEDATOS_H
