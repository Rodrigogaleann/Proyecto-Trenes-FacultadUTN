#include "ManagerEstaciones.h"
#include "ArchivoEstaciones.h"
#include "Estacion.h"

#include "FuncionesGlobales.h"

#include <cstring>
#include <iostream>
#include <iomanip>

/// ------------------------------------------------ MÉTODOS GENERALES ------------------------------------------------

bool ManagerEstaciones::cargarVector(Estacion *registros, int tam){

    ArchivoEstaciones archivo;

    /// ALMACENO LOS REGISTROS DEL ARCHIVO DENTRO DEL NUEVO VECTOR
    for(int i=0; i<tam; i++){;
        registros[i] = archivo.leer(i);
    }

    return true;
}

int ManagerEstaciones::obtenerProximoIdEstacion(){

    ArchivoEstaciones archivo;

    int id = archivo.getCantidadRegistros() + 1;

    return id;
}

int ManagerEstaciones::obtenerIdEstacion(const char *nombreEstacion){

    Estacion estacion;
    ArchivoEstaciones archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        estacion = archivo.leer(i);

        if(stricmp(estacion.getNombreEstacion(), nombreEstacion) == 0){
            return estacion.getIDEstacion();
        }
    }

    return 0;
}

Estacion ManagerEstaciones::obtenerEstacion(int id){

    Estacion registro;
    ArchivoEstaciones archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDEstacion() == id){
            return registro;
        }
    }

    return Estacion();
}

Estacion ManagerEstaciones::obtenerEstacion(const char *nombreEstacion){

    Estacion registro;
    ArchivoEstaciones archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if( stricmp(registro.getNombreEstacion(), nombreEstacion) == 0){
            return registro;
        }
    }

    return Estacion();
}

int ManagerEstaciones::obtenerTotalActivas(){

    Estacion registro;
    ArchivoEstaciones archivo;

    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return -1;
    }

    int contador = 0;

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getEstado() == 1){
            contador ++;
        }
    }

    return contador;
}

int ManagerEstaciones::obtenerTotalInactivas(){

    Estacion registro;
    ArchivoEstaciones archivo;

    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return -1;
    }

    int contador = 0;

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getEstado() == 0){
            contador ++;
        }
    }

    return contador;
}

/// ------------------------------------------------ METODOS DE VALIDACION ------------------------------------------------

bool ManagerEstaciones::validarIdEstacion(int idEstacion){

    Estacion registro;
    ArchivoEstaciones archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDEstacion() == idEstacion){
            return true;
        }
    }

    return false;
}

bool ManagerEstaciones::validarNombreEstacion(const char *nombreEstacion){

    Estacion registro;
    ArchivoEstaciones archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getNombreEstacion(), nombreEstacion) == 0){
            return true;
        }
    }

    return false;
}

bool ManagerEstaciones::validarEstado(const char *nombreEstacion){

    Estacion registro;
    ArchivoEstaciones archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if( stricmp(registro.getNombreEstacion(), nombreEstacion) == 0 ){

            if( registro.getEstado() == true ){
                return true;
            }
        }
    }

    return false;
}


/// ------------------------------------------------ MÉTODOS DE COINCIDENCIAS ------------------------------------------------

int ManagerEstaciones::coincidenciasID(int id){

    Estacion registro;
    ArchivoEstaciones archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDEstacion() == id){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerEstaciones::coincidenciasNombre(const char *nombre){

    Estacion registro;
    ArchivoEstaciones archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getNombreEstacion(), nombre) == 0){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerEstaciones::coincidenciasEstado(bool estado){

    Estacion registro;
    ArchivoEstaciones archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getEstado() == estado){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

/// ------------------------------------------------ MÉTODOS DE ORDENAMIENTO ------------------------------------------------

bool ManagerEstaciones::ordenarPorIdEstacion(Estacion *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ID DE ESTACION
    Estacion aux;

    for(int i=0; i<tam; i++){

        for(int j=i+1; j<tam; j++){

            if(registros[j].getIDEstacion() < registros[i].getIDEstacion()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerEstaciones::ordenarPorNombre(Estacion *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR NOMBRE DE ESTACION
    Estacion aux;

    for(int i=0; i<tam; i++){

        for(int j=i+1; j<tam; j++){

            if((stricmp(registros[i].getNombreEstacion(), registros[j].getNombreEstacion()) ) > 0){
                /// STRICMP IGNORA MAYUSCULAS Y MINUSCULAS
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerEstaciones::ordenarPorEstado(Estacion *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ESTADO
    Estacion aux;

    for(int i=0; i<tam; i++){

        for(int j=i+1; j<tam; j++){

            if(registros[j].getEstado() > registros[i].getEstado()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

/// ------------------------------------------------ MÉTODOS "ABML" ------------------------------------------------

Estacion ManagerEstaciones::cargarEstacion(){

    Estacion registro;
    ArchivoEstaciones archivo;

    char nombreEstacion[30];

    std::cout << "NOMBRE DE ESTACION: ";
    cargarCadena(nombreEstacion, sizeof(nombreEstacion) - 1);
    if(validarNombreEstacion(nombreEstacion) == true){

        int pos = obtenerIdEstacion(nombreEstacion) - 1;
        registro = archivo.leer(pos);

        if(registro.getEstado() == false){
            int opc = 0;

            mostrarTexto("LA ESTACION ESTA INACTIVA. DESEA REACTIVARLA? (1-SI / 0-NO)");
            std::cout << "OPCION: ";
            std::cin >> opc;

            if(opc == 1){

                if(altaLogica(nombreEstacion) == true){
                    mostrarTexto("ESTACION REACTIVADA");
                    return Estacion();
                }
            }
        }
        else{
            mostrarTexto("LA ESTACION EXISTE Y SE ENCUENTRA ACTIVA");
            return Estacion();
        }
    }
    else{
        int id = obtenerProximoIdEstacion();
        registro.cargar(id, nombreEstacion);
    }

    return registro;
}

Estacion ManagerEstaciones::editarEstacion(){

    Estacion registro;
    ArchivoEstaciones archivo;

    char nombreEstacion[30];

    std::cout << "NOMBRE DE ESTACION: ";
    cargarCadena(nombreEstacion, sizeof(nombreEstacion) - 1);
    if(validarNombreEstacion(nombreEstacion) == true){

        int pos = obtenerIdEstacion(nombreEstacion) - 1;
        registro = archivo.leer(pos);

        if(registro.getEstado() == false){
            int opc = 0;

            mostrarTexto("LA ESTACION ESTA INACTIVA. DESEA REACTIVARLA? (1-SI / 0-NO)");
            std::cout << "OPCION: ";
            std::cin >> opc;

            if(opc == 1){

                if(altaLogica(nombreEstacion) == true){
                    mostrarTexto("ESTACION REACTIVADA");
                    return Estacion();
                }
            }
        }
        else{
            mostrarTexto("LA ESTACION SE ENCUENTRA ACTIVA. POR FAVOR PROCEDA A MODIFICAR LOS DATOS");
            registro.cargar(pos + 1);
            /// POS + 1 = ID
        }
    }
    else{
        mostrarTexto("< ERROR: LA ESTACION INGRESADA NO EXISTE >");
        return Estacion();
    }

    return registro;
}

bool ManagerEstaciones::altaEstacion(){

    Estacion registro;
    ArchivoEstaciones archivo;

    registro = cargarEstacion();
    if(registro.getIDEstacion() == 0){
        return false;
    }

    if(archivo.guardar(registro) == true){
        return true;
    }

    return false;
}

bool ManagerEstaciones::modificacionEstacion(){

    Estacion registro;
    ArchivoEstaciones archivo;

    registro = editarEstacion();
    if(registro.getIDEstacion() == 0){
        return false;
    }

    int pos = registro.getIDEstacion() - 1;

    if(archivo.editar(registro, pos) == true){
        return true;
    }

    return false;
}

bool ManagerEstaciones::altaLogica(const char *nombre){

    Estacion registro;
    ArchivoEstaciones archivo;

    int pos = obtenerIdEstacion(nombre) - 1;
    if(pos == -1){
        return false;
    }

    registro = archivo.leer(pos);

    registro.setEstado(true);

    return archivo.editar(registro, pos);
}

bool ManagerEstaciones::bajaLogica(const char *nombre){

    Estacion registro;
    ArchivoEstaciones archivo;

    int pos = obtenerIdEstacion(nombre) - 1;
    if(pos == -1){
        return false;
    }

    registro = archivo.leer(pos);

    registro.setEstado(true);

    return archivo.editar(registro, pos);
}

void ManagerEstaciones::mostrarEncabezado(){

    ArchivoEstaciones archivo;

    int anchoID = obtenerCantidadDigitos(archivo.getCantidadRegistros());

    std::cout << "ID" << espaciar(anchoID, anchoID + 5);
    std::cout << "NOMBRE DE ESTACION" << espaciar(strlen("NOMBRE DE ESTACION"), 35);
}

void ManagerEstaciones::mostrarRegistros(Estacion *registros, int tam){
    /**
    int anchoID = obtenerCantidadDigitos(obtenerCantidadRegistros());
    int anchoNombreEstacion = 30;

    int espacio = 5;

    std::cout << registro.getIDEstacion() << espaciar(obtenerCantidadDigitos(registro.getIDEstacion()), anchoID + espacio);
    std::cout << registro.getNombreEstacion() << espaciar(strlen(registro.getNombreEstacion()), anchoNombreEstacion + espacio);
    std::cout << std::endl;
    */

    for(int i=0; i<tam; i++){
        registros[i].mostrar();
        std::cout << std::endl;
    }
}

/// ------------------------------------------------ LISTADOS ------------------------------------------------

bool ManagerEstaciones::listadoPorIdEstacion(){

    ArchivoEstaciones archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE ESTACIONES DEL ARCHIVO "estaciones.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "estaciones.dat" NO TIENE REGISTROS
        return false;
    }

    Estacion *registros = new Estacion[tam];
    if(registros == nullptr){
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false){
        /// NO SE PUDO CARGAR EL VECTOR
        delete [] registros;
        return false;
    }

    /// ORDENO EL VECTOR DINAMICO POR ID DE ESTACION
    if(ordenarPorIdEstacion(registros, tam) == false){
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerEstaciones::listadoPorNombreEstacion(){

    ArchivoEstaciones archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE ESTACIONES DEL ARCHIVO "estaciones.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "estaciones.dat" NO TIENE REGISTROS
        return false;
    }

    Estacion *registros = new Estacion[tam];
    if(registros == nullptr){
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false){
        /// NO SE PUDO CARGAR EL VECTOR
        delete[] registros;
        return false;
    }

    /// ORDENO EL VECTOR DINAMICO
    if(ordenarPorNombre(registros, tam) == false){
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID
    mostrarTexto("ESTACIONES - LISTADO POR NOMBRE DE ESTACION");
    mostrarRegistros(registros, tam);

    delete[] registros;

    return true;
}

bool ManagerEstaciones::listadoPorEstado(){

    ArchivoEstaciones archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE ESTACIONES DEL ARCHIVO "estaciones.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "estaciones.dat" NO TIENE REGISTROS
        return false;
    }

    Estacion *registros = new Estacion[tam];
    if(registros == nullptr){
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false){
        /// NO SE PUDO CARGAR EL VECTOR
        delete [] registros;
        return false;
    }

    /// ORDENO EL VECTOR POR ESTADO
    if(ordenarPorEstado(registros, tam) == false){
        /// NO SE PUDO ORDENAR POR ESTADO
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ESTADO
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

/// ------------------------------------------------ CONSULTAS ------------------------------------------------

bool ManagerEstaciones::consultaPorIdEstacion(){

    /// LE PIDO AL USUARIO EL ID
    int id;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout  << std::endl;

    /// VALIDO EL ID
    if(validarIdEstacion(id) == false){
        /// NO SE ENCONTRO EL ID
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL ID
    if(coincidenciasID(id) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

bool ManagerEstaciones::consultaPorNombreEstacion(){

    /// LE PIDO AL USUARIO EL NOMBRE DE ESTACION
    char nombreEstacion[30];
    std::cout << "NOMBRE DE ESTACION: ";
    cargarCadena(nombreEstacion, sizeof(nombreEstacion) - 1);
    std::cout << std::endl;

    /// VALIDO EL ID
    if(validarNombreEstacion(nombreEstacion) == false){
        /// NO SE ENCONTRO EL NOMBRE
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL NOMBRE DE ESTACION
    if(coincidenciasNombre(nombreEstacion) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

bool ManagerEstaciones::consultaPorEstado(){

    /// LE PIDO AL USUARIO EL ESTADO
    bool estado;
    std::cout << "ESTADO (1-ACTIVO / 0-INACTIVO): ";
    std::cin >> estado;
    std::cout << std::endl;

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL ESTADO
    if(coincidenciasEstado(estado) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

/// ------------------------------------------------ INFORMES -------------------------------------------------

bool ManagerEstaciones::informeTotalEstacionesRegistradas(){

    ArchivoEstaciones archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "CANTIDAD TOTAL DE ESTACIONES REGISTRADAS: " << archivo.getCantidadRegistros() << std::endl;

    return true;
}

bool ManagerEstaciones::informeTotalEstacionesActivas(){

    ArchivoEstaciones archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }
    std::cout << "CANTIDAD TOTAL DE ESTACIONES ACTIVAS: " << obtenerTotalActivas() << std::endl;

    return true;
}

bool ManagerEstaciones::informeTotalEstacionesInactivas(){

    ArchivoEstaciones archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }
    std::cout << "CANTIDAD TOTAL DE ESTACIONES INACTIVAS: " << obtenerTotalInactivas() << std::endl;

    return true;
}
