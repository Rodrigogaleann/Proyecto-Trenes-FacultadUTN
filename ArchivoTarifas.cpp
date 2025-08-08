#include "ArchivoTarifas.h"
#include <string>
#include <cstring>
#include <stdio.h>

/// -------------------- CONSTRUCTORES --------------------

ArchivoTarifas::ArchivoTarifas(){
    _nombreArchivo = "datos/tarifas.dat";
}

ArchivoTarifas::ArchivoTarifas(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

/// -------------------- METODOS AMBL ---------------------

bool ArchivoTarifas::guardar(Tarifa registro){

    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }

    resultado = (fwrite(&registro, sizeof(Tarifa), 1, pFile) == 1);

    fclose(pFile);

    return resultado;
}

bool ArchivoTarifas::editar(Tarifa registro, int pos){

    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(Tarifa), SEEK_SET);
    resultado = (fwrite(&registro, sizeof(Tarifa), 1, pFile) == 1);

    fclose(pFile);

    return resultado;
}

Tarifa ArchivoTarifas::leer(int pos){

    FILE *pFile;
    Tarifa reg;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return reg;
    }

    fseek(pFile, sizeof(Tarifa) * pos, SEEK_SET);
    fread(&reg, sizeof(Tarifa), 1, pFile);
    fclose(pFile);

    return reg;
}

int ArchivoTarifas::getCantidadRegistros(){

    int total;
    int cant;
    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    total = ftell(pFile);

    cant = total / sizeof(Tarifa);

    fclose(pFile);

    return cant;
}

/// -------------------- CONFIGURACIONES ---------------------

bool ArchivoTarifas::copiaDeSeguridad(){

    FILE *pFileOriginal;

    /// ABRO EL ARCHIVO "tarifas.dat" QUE SE ENCUENTRA EN LA CARPETA "datos"
    pFileOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if(pFileOriginal == nullptr){
        return false;
    }

    FILE *pFileCopia;

    /// ABRO EL ARCHIVO "tarifas.backup" QUE SE ENCUENTRA EN LA CARPETA "backups"
    pFileCopia = fopen("backups/tarifas.backup", "wb");
    if(pFileCopia == nullptr){
        fclose(pFileOriginal);
        return false;
    }

    /// COPIO LOS REGISTROS DE "tarifas.dat" a "tarifas.backup"
    Tarifa registro;

    while(fread(&registro, sizeof(Tarifa), 1, pFileOriginal) == 1){
        if(fwrite(&registro, sizeof(Tarifa), 1, pFileCopia) != 1){
            fclose(pFileOriginal);
            fclose(pFileCopia);
            return false;
        }
    }

    /// CIERRO LOS ARCHIVOS
    fclose(pFileOriginal);
    fclose(pFileCopia);

    return true;
}

bool ArchivoTarifas::restaurarCopiaDeSeguridad(){

    FILE *pFileCopia;

    /// ABRO EL ARCHIVO "tarifas.backup" QUE SE ENCUENTRA EN LA CARPETA "backups"
    pFileCopia = fopen("backups/tarifas.backup", "rb");
    if(pFileCopia == nullptr){
        return false;
    }

    FILE *pFileOriginal;

    /// ABRO EL ARCHIVO "tarifas.dat" QUE SE ENCUENTRA EN LA CARPETA "datos"
    pFileOriginal = fopen(_nombreArchivo.c_str(), "wb");
    if(pFileOriginal == nullptr){
        fclose(pFileCopia);
        return false;
    }

    /// COPIO LOS REGISTROS DE "tarifas.backup" A "tarifas.dat"
    Tarifa registro;

    while(fread(&registro, sizeof(Tarifa), 1, pFileCopia) == 1){
        if(fwrite(&registro, sizeof(Tarifa), 1, pFileOriginal) != 1){
            fclose(pFileCopia);
            fclose(pFileOriginal);
            return false;
        }
    }

    /// CIERRO LOS ARCHIVOS
    fclose(pFileCopia);
    fclose(pFileOriginal);

    return true;
}

bool ArchivoTarifas::exportarCSV(){
    FILE *pFileOriginal;

    /// ABRO EL ARCHIVO "tarifas.dat" QUE SE ENCUENTRA EN LA CARPETA "datos"
    pFileOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if(pFileOriginal == nullptr){
        return false;
    }

    FILE *pFileCSV;

    /// ABRO EL ARCHIVO "tarifas.csv" QUE SE ENCUENTRA EN LA CARPETA "exportaciones"
    pFileCSV = fopen("exportaciones/tarifas.csv", "w");
    if(pFileCSV == nullptr){
        fclose(pFileOriginal);
        return false;
    }

    /// COPIO LOS REGISTROS DE "tarifas.dat" a "tarifas.csv"
    Tarifa registro;
    std::string registroCSV;

    /// UTILIZO LOS METODOS "toCSV()" y "c_str()" PARA MODIFICAR EL FORMATO DE LOS REGISTROS

    while(fread(&registro, sizeof(Tarifa), 1, pFileOriginal) == 1){
        registroCSV = registro.toCSV();

        /// "%s" ESCPECIFICA QUE SE VA A ESCRIBIR UNA CADENA DE CARACTERES
        /// "\n" AGREGA UN SALTO DE LINEA, SEPARANDO LOS REGISTROS EN FILAS
        if(fprintf(pFileCSV, "%s\n", registroCSV.c_str()) < 0){
            fclose(pFileOriginal);
            fclose(pFileCSV);
            return false;

            /// A DIFERENCIA DE "fread()" o "fwrite()", "fprintf()" DEVUELVE LA CANTIDAD DE CARACTERES ESCRITOS
            /// SI NO PUEDE ESCRIBIR, DEVUELVE UN NUMERO NEGATIVO
        }
    }

    /// ---------------------------------------- FUNCION "fprintf()" ------------------------------

    /// DECLARACION: int fprintf(FILE *stream, const char *format, ...)
    ///
    /// ARGUMENTOS:
    /// - *stream = Puntero a un objeto file
    /// - format = Recibe parametros que indican como se muestran / escriben los registros
    /// - additional arguments = En nuestro caso, reemplaza en "%s" por el registro como cadena
    ///                          de caracteres, gracias al c_str()

    /// ------------------------------------------------------------------------------------------

    /// ¿PORQUE "fprintf()" Y NO "fwrite()"? ¿PORQUE SE ABRE EL ARCHIVO CON "a" Y NO CON "ab"?
    ///
    /// "fprintf()" permite escribir registros con formato de texto sobre los archivos. En cambio
    /// "fwrite()" escribe directamente los bytes en memoria.

    /// No se utiliza la apertura "ab"(append binary), ya que lo que queremos escribir en el archivo
    /// ".csv" debe ser en un formato de texto, para ser utilizable y facil de leer para aplicacioens
    ///como excel, visual studio, bloc de notas, entre otras

    /// ------------------------------------------------------------------------------------------

    /// CIERRO LOS ARCHIVOS
    fclose(pFileOriginal);
    fclose(pFileCSV);

    return true;
}
