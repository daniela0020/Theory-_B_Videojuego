#include "basededatos.h"

void baseDeDatos::getPartida(QString usuario, short int &mapa, float &posx, float &posy, short int &tiempo, short int &vidas)
{
    ifstream reader;
    reader.open("Partida.txt");
    string leido;
    int contador=0;
    if(!reader.fail()){

        while(!reader.eof()){

            contador++;
            if (contador == 1){
                reader>>leido;
                if(leido == usuario.toStdString()){
                    reader>>leido;
                    reader>>leido;
                    mapa = utilidades::conversionStrShortInt(leido);
                    reader>>leido;
                    posx = utilidades::conversionStr2float(leido);
                    reader>>leido;
                    posy = utilidades::conversionStr2float(leido);
                    reader>>leido;
                    tiempo = utilidades::conversionStrShortInt(leido);
                    reader>>leido;
                    vidas = utilidades::conversionStrShortInt(leido);

                    break;
                }
            }
            else if(contador == 8){
                contador = 0;
            }
            else {
                reader>>leido;
            }


        }
    }

    reader.close();
}

void baseDeDatos::setPartida(QString usuario, QString contrasena, int mapa, float posx, float posy, short int tiempo, short int vidas)
{
    ofstream writer1,writer2;
    ifstream reader;
    string textoleido;


    if(!verificarDatos(usuario)){
        writer1.open("Partida.txt",ios::app);
        writer1<<usuario.toStdString()<<" ";
        writer1<<contrasena.toStdString()<<" ";
        writer1<<mapa<<" ";
        writer1<<posx<<" ";
        writer1<<posy<<" ";
        writer1<<tiempo<<" ";
        writer1<<vidas<<" ";
        writer1<<endl;
        writer1.close();
    }else{
        reader.open("Partida.txt");
        writer2.open("temp.txt",ios::app);
        while(!reader.eof()){
            reader>>textoleido;
            if(textoleido!=""){
                if(textoleido==usuario.toStdString()){
                    writer2<<usuario.toStdString()<<" ";
                    writer2<<contrasena.toStdString()<<" ";
                    reader>>textoleido;
                    writer2<<mapa<<" ";
                    reader>>textoleido;
                    writer2<<posx<<" ";
                    reader>>textoleido;
                    writer2<<posy<<" ";
                    reader>>textoleido;
                    writer2<<tiempo<<" ";
                    reader>>textoleido;
                    writer2<<vidas<<" ";
                    reader>>textoleido;
                    textoleido="";
                    writer2<<endl;
                }
                else{
                    writer2<<textoleido<<" ";//user
                    reader>>textoleido;
                    writer2<<textoleido<<" ";//pass
                    reader>>textoleido;
                    writer2<<textoleido<<" ";//mapa
                    reader>>textoleido;
                    writer2<<textoleido<<" ";//posx
                    reader>>textoleido;
                    writer2<<textoleido<<" ";//pasy
                    reader>>textoleido;
                    writer2<<textoleido<<" ";//tiempo
                    reader>>textoleido;
                    writer2<<textoleido<<" ";//vidas
                    textoleido="";
                    writer2<<endl;
                }

            }
        }
        writer2.close();
        reader.close();
        remove("Partida.txt");
        rename("temp.txt","Partida.txt");
    }



}

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

bool baseDeDatos::verificarDatos(QString dato)
{
    ifstream reader;
    reader.open("Partida.txt");
    string leido;
    int contador=0;
    bool esta=false;

    if(!reader.fail()){

        while(!reader.eof()){

            contador++;
            if (contador == 1){
                reader>>leido;
                if(leido == dato.toStdString()){
                    esta = true;
                    break;
                }
            }
            else if(contador == 8){
                contador = 0;
            }
            else {
                reader>>leido;
            }


        }
    }

    reader.close();
    return esta;

}

bool baseDeDatos::verificarContrasena(QString usuario, QString contrasena)
{
    bool bandera=false;
    short int con=0;
    string textoleido;
    ifstream lector;
    lector.open("Partida.txt");
    while(!lector.eof())
    {
        con++;
        if (con == 1){
            lector>>textoleido;//lectura de usuario
            if(textoleido==usuario.toStdString())
            {
                lector>>textoleido;//leo contraseña
                if(textoleido==contrasena.toStdString())
                {
                    bandera = true;
                    break;
                }

            }

        }
        else if(con == 8){
            con = 0;
        }
        else {
            lector>>textoleido;
        }

    }

    lector.close();
    return bandera;
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


