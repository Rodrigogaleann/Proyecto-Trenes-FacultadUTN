#include "ArchivoAdministradores.h"

#include <string>
#include <cstring>

/// -------------------- CONSTRUCTORES --------------------

ArchivoAdministradores::ArchivoAdministradores(){
    _nombreArchivo = "datos/administradores.dat";
}

ArchivoAdministradores::ArchivoAdministradores(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

/// -------------------- METODOS AMBL ---------------------

bool ArchivoAdministradores::guardar(Administrador registro){

    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }

    resultado = (fwrite(&registro, sizeof(Administrador), 1, pFile) == 1);

    fclose(pFile);

    return resultado;
}

bool ArchivoAdministradores::editar(Administrador registro, int pos){

    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(Administrador), SEEK_SET);
    resultado = (fwrite(&registro, sizeof(Administrador), 1, pFile) == 1);

    fclose(pFile);

    return resultado;
}

Administrador ArchivoAdministradores::leer(int pos){

    FILE *pFile;
    Administrador reg;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return reg;
    }

    fseek(pFile, sizeof(Administrador) * pos, SEEK_SET);
    fread(&reg, sizeof(Administrador), 1, pFile);

    fclose(pFile);

    return reg;
}

int ArchivoAdministradores::getCantidadRegistros(){

    int total;
    int cant;
    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    total = ftell(pFile);

    cant = total / sizeof(Administrador);

    fclose(pFile);

    return cant;
}

/// -------------------- CONFIGURACIONES ---------------------

bool ArchivoAdministradores::copiaDeSeguridad(){

    FILE *pFileOriginal;

    /// ABRO EL ARCHIVO "administradores.dat" QUE SE ENCUENTRA EN LA CARPETA "datos"
    pFileOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if(pFileOriginal == nullptr){
        return false;
    }

    FILE *pFileCopia;

    /// ABRO EL ARCHIVO "administradores.backup" QUE SE ENCUENTRA EN LA CARPETA "backups"
    pFileCopia = fopen("backups/administradores.backup", "wb");
    if(pFileCopia == nullptr){
        fclose(pFileOriginal);
        return false;
    }

    /// COPIO LOS REGISTROS DE "administradores.dat" a "administradores.backup"
    Administrador registro;

    while(fread(&registro, sizeof(Administrador), 1, pFileOriginal) == 1){
        if(fwrite(&registro, sizeof(Administrador), 1, pFileCopia) != 1){
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

bool ArchivoAdministradores::restaurarCopiaDeSeguridad(){

    FILE *pFileCopia;

    /// ABRO EL ARCHIVO "administradores.backup" QUE SE ENCUENTRA EN LA CARPETA "backups"
    pFileCopia = fopen("backups/administradores.backup", "rb");
    if(pFileCopia == nullptr){
        return false;
    }

    FILE *pFileOriginal;

    /// ABRO EL ARCHIVO "administradores.dat" QUE SE ENCUENTRA EN LA CARPETA "datos"
    pFileOriginal = fopen(_nombreArchivo.c_str(), "wb");
    if(pFileOriginal == nullptr){
        fclose(pFileCopia);
        return false;
    }

    /// COPIO LOS REGISTROS DE "administradores.backup" A "administradores.dat"
    Administrador registro;

    while(fread(&registro, sizeof(Administrador), 1, pFileCopia) == 1){
        if(fwrite(&registro, sizeof(Administrador), 1, pFileOriginal) != 1){
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

bool ArchivoAdministradores::exportarCSV(){

    FILE *pFileOriginal;

    /// ABRO EL ARCHIVO "administradores.dat" QUE SE ENCUENTRA EN LA CARPETA "datos"
    pFileOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if(pFileOriginal == nullptr){
        return false;
    }

    FILE *pFileCSV;

    /// ABRO EL ARCHIVO "administradores.csv" QUE SE ENCUENTRA EN LA CARPETA "exportaciones"
    pFileCSV = fopen("exportaciones/administradores.csv", "w");
    if(pFileCSV == nullptr){
        fclose(pFileOriginal);
        return false;
    }

    /// COPIO LOS REGISTROS DE "administradores.dat" a "administradores.csv"
    Administrador registro;
    std::string registroCSV;

    /// UTILIZO LOS METODOS "toCSV()" y "c_str()" PARA MODIFICAR EL FORMATO DE LOS REGISTROS

    while(fread(&registro, sizeof(Administrador), 1, pFileOriginal) == 1){
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
