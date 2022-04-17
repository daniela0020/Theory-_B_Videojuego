#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include<string>
#include<fstream>
#include<utilidades.h>
#include<resorte.h>
#include<objetoestatico.h>
#include<objetomovcircular.h>
#include<enemigo.h>

using namespace std;




class baseDeDatos
{
public:

    void getPartida();
    void setPartida();
    void getStaticObjects(string fileName, QList<objetoEstatico*> &objects);
    void getBolasFuego(string fileName, QList<ObjetoMovCircular*> &objects);
    void getEnemigos(string fileName, QList<Enemigo*> &objects);
    void getResortes(string fileName, QList<resorte*> &objects);


};


#endif // BASEDEDATOS_H
