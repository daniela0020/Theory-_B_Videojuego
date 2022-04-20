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

    void getPartida(QString usuario,short int &mapa, float &posx, float &posy, short int& tiempo, short int &vidas);
    void setPartida(QString usuario, QString contrasena, int mapa, float posx, float posy, short int tiempo, short int vidas );
    void getStaticObjects(string fileName, QList<objetoEstatico*> &objects);
    bool verificarDatos(QString dato);
    bool verificarContrasena(QString usuario,QString contrasena);
    void getBolasFuego(string fileName, QList<ObjetoMovCircular*> &objects);
    void getEnemigos(string fileName, QList<Enemigo*> &objects);
    void getResortes(string fileName, QList<resorte*> &objects);



};

#endif // BASEDEDATOS_H
