#ifndef LECTURAARCHIVO_H
#define LECTURAARCHIVO_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LecturaArchivo {

    protected:
        string sLineaActual;
        string sNombreArchivo;
        int iLineasBlancas;
        int iLineasComentario;
        int iLineasCodigo;
        ifstream ifArchivo;

    public:
        //Constructores
        inline LecturaArchivo(){
            sLineaActual = "";
            sNombreArchivo = "";
            iLineasBlancas = 0;
            iLineasComentario = 0;
            iLineasCodigo = 0;
        }

        inline LecturaArchivo(string sLinAct, string sNomArch, int iLinBla, int iLinCom, int iLinCod){
            sLineaActual = sLinAct;
            sNombreArchivo = sNomArch;
            iLineasBlancas = iLinBla;
            iLineasComentario = iLinCom;
            iLineasCodigo = iLinCod;
        }

        //Getters y Setters
        // Setters
        inline void setLineaActual(string sLA){
            sLineaActual = sLA;
        }

        inline void setNombreArchivo(string sNA){
            sNombreArchivo = sNA;
        }

        inline void setLineasBlancas(int iLB){
            iLineasBlancas = iLB;
        }

        inline void setLineasComentario(int iLCom){
            iLineasComentario = iLCom;
        } 

        inline void setLineasCodigo(int iLCod){
            iLineasCodigo = iLCod;
        }

        //Getters
        inline string getLineaActual(){
            return sLineaActual;
        }

        inline string getNombreArchivo(){
            return sNombreArchivo;
        }

        inline int getLineasBlancas(){
            return iLineasBlancas;
        }

        inline int getLineasComentario(){
            return iLineasComentario;
        }

        inline int getLineasCodigo(){
            return iLineasCodigo;
        }

        //Funcion para leer el archivo y contar el tipo de lineas que tiene
        inline void LeerArchivo(){
            //Variables locales para guardar si hay comentarios multilineas y si la linea tiene codigo
            bool bComentarioMultiLineaActivo = false;
            bool bEsLineaCodigo = false;
            //Se abre archivo y se lee hasta que se acabe (alcanze el ultimo endline) dentro del while
            ifArchivo.open(sNombreArchivo);
            while(!ifArchivo.eof()){
                //Se obtiene la fila completa para analizar que tipo de linea es
                getline(ifArchivo,sLineaActual);
                // Entra la lectura de archivos si no se encuentra un comentario multilinea
                if(!bComentarioMultiLineaActivo){
                    //Contador para checar si la linea contiene al menos un caracter
                    for(int i = 0; i < sLineaActual.length(); i++){
                        if(sLineaActual[i] != ' ' && sLineaActual[i] != '\t' && sLineaActual[i] != '\n'){       
                            bEsLineaCodigo = true;
                        }
                    }
                    //Checa si la linea es comentario
                    if(sLineaActual.find("//") != -1){
                        setLineasComentario(getLineasComentario() + 1);
                    } else if(sLineaActual.find("/*") != -1){
                        //Activa flag para que la proxima vez solo agrugue lineas de comentarios hasta que encuentre el fin de multilinea
                        bComentarioMultiLineaActivo = true;
                        setLineasComentario(getLineasComentario() + 1);
                    //Si es linea de codigo
                    } else if (bEsLineaCodigo){
                        setLineasCodigo(getLineasCodigo()+1);
                    } else {
                        setLineasBlancas(getLineasBlancas() + 1);
                    }
                    // Entra lectura para solo agregar lineas de comentarios por estar en modo de comentario multilinea hasta que se encuentre el fin de este  
                    } else {
                    if(sLineaActual.find("*/") != -1){
                        bComentarioMultiLineaActivo = false;
                        setLineasComentario(getLineasComentario() + 1);
                    } else {
                        setLineasComentario(getLineasComentario() + 1);
                    }    
                    }
                    bEsLineaCodigo = false;
            }
            ifArchivo.close();
        }

        inline bool VerificarExistenciaArchivo(string sNombreArch){
            ifstream ifArchivo(sNombreArch);
            if(ifArchivo.fail()){
                return false;
            } else {
                return true;
            }
        }


};

#endif //   LECTURAARCHIVO_H