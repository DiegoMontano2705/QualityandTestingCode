/*
    Descripción del programa: Programa que lee un archivo el cual su nombre es tecleado por el usuario, se valida la existencia de este mismo para
    despues contar la cantidad de lineas en blanco, con comentarios y con codigo tiene en total.
    Autor: Diego Fernando Montaño Pérez A01282875  
    Fecha de creación : 17/02/2020
    Ultima fecha de modificación: 17/02/2020
*/
#include <iostream>
#include <fstream>
#include "LecturaArchivo.h"
#include "ImprimirArchivo.h"
using namespace std;

int main(){

    //Variables
    string sNombreArchivo;
    bool bArchivoExiste = false;
    LecturaArchivo Lectura;
    ImprimirArchivo Imprimir;


    //Pedir a usuario ingresar nombre del archivo
    while(!bArchivoExiste){
        cout << "Teclear nombre del archivo: " ;
        cin >> sNombreArchivo;
        bArchivoExiste = Lectura.VerificarExistenciaArchivo(sNombreArchivo);
        if(!bArchivoExiste){
            cout << "!Error archivo con ese nombre no existe!" << endl;
        }        
    }

    //Pasar a objeto de lectura nombre del archivo cuando sea correcto
    Lectura.setNombreArchivo(sNombreArchivo);
    //Iniciar lectura de archivo
    Lectura.LeerArchivo();
    //Pasar valores finales al objeto de Imprimir para tener los resutlados
    Imprimir.setNombreArchivo(Lectura.getNombreArchivo());
    Imprimir.setLineasBlancas(Lectura.getLineasBlancas());
    Imprimir.setLineasComentarios(Lectura.getLineasComentario());
    Imprimir.setLineasCodigo(Lectura.getLineasCodigo());
    //Imprimir resultados
    Imprimir.ImprimirResultados();
    
    return 0;
}