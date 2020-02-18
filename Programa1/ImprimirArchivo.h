#ifndef IMPRIMIRARCHIVO_H
#define IMPRIMIRARCHIVO_H
#include <iostream>
#include <iomanip>
using namespace std;

class ImprimirArchivo{

    protected:
        string sNombreArchivo;
        int iLineasBlancas;
        int iLineasComentarios;
        int iLineasCodigo;
        int iLineasTotales;

    public:
        //Constructores
        inline ImprimirArchivo(){
            sNombreArchivo = "";
            iLineasCodigo = 0;
            iLineasComentarios = 0;
            iLineasBlancas = 0;
            iLineasTotales = iLineasCodigo + iLineasComentarios + iLineasBlancas;
        }

        inline ImprimirArchivo(string sNombre, int iLinBlancas, int iLinCom, int iLinCod, int iLinTotal){
            sNombreArchivo = sNombre;
            iLineasBlancas = iLinBlancas;
            iLineasComentarios = iLinCom;
            iLineasCodigo = iLinCod;
            iLineasTotales = iLinTotal;
        }

        // Getters y Setters
        //Setters
        inline void setNombreArchivo(string sNombre){
            sNombreArchivo = sNombre;
        }

        inline void setLineasBlancas(int iLinBlancas){
            iLineasBlancas = iLinBlancas;
        }

        inline void setLineasComentarios(int iLinCom){
            iLineasComentarios = iLinCom;
        }

        inline void setLineasCodigo(int iLinCod){
            iLineasCodigo = iLinCod;
        }

        //Getters
        inline string getNombreArchivo(){
            return sNombreArchivo;
        }

        inline int getLineasBlancas(){
            return iLineasBlancas;
        }

        inline int getLineasComentarios(){
            return iLineasComentarios;
        }

        inline int getLineasCodigo(){
            return iLineasCodigo;
        }

        inline int getLineasTotales(){
            return iLineasCodigo + iLineasComentarios + iLineasBlancas;
        }

        //Funcion para imprimir resultados
        inline void ImprimirResultados(){
            if( getLineasTotales() > 1){
              cout << "Nombre del archivo: " << getNombreArchivo() << endl;
              cout << "----------------------------------------------------" << endl;
              cout << "Cantidad de lineas en blanco: "<< setfill('0') << setw(2) << getLineasBlancas() << endl;
              cout << "Cantidad de lineas con comentarios: " << setfill('0') << setw(2) << getLineasComentarios() << endl;
              cout << "Cantidad de lineas con codigo: " << setfill('0') << setw(2) << getLineasCodigo() << endl;
              cout << "----------------------------------------------------" << endl;
              cout << "Cantidad total de lineas: " << setfill('0') << setw(2) << getLineasTotales() << endl;
            } else {
              cout << "!Archivo vacio, fin del programa!" << endl;
            }
        }




};

#endif //   IMPRIMIRARCHIVO_H