#include "ManagerTarifas.h"
#include "ArchivoTarifas.h"
#include "Tarifa.h"

#include "Estacion.h"
#include "ManagerEstaciones.h"

#include "FuncionesGlobales.h"

#include <cstring>
#include <iostream>

/// ------------------------------------------------ MÉTODOS GENERALES ------------------------------------------------

bool ManagerTarifas::cargarVector(Tarifa *registros, int tam){

    ArchivoTarifas archivo;

    /// ALMACENO LOS REGISTROS DEL ARCHIVO DENTRO DEL NUEVO VECTOR
    for(int i=0; i<tam; i++){;
        registros[i] = archivo.leer(i);
    }

    return true;
}

int ManagerTarifas::obtenerProximoIdTarifa(){

    ArchivoTarifas archivo;

    int id = archivo.getCantidadRegistros() + 1;

    return id;
}

int ManagerTarifas::obtenerIdTarifa(Estacion origen, Estacion destino){

    Tarifa tarifa;
    ArchivoTarifas archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        tarifa = archivo.leer(i);

        if(tarifa.getEstacionOrigen().getIDEstacion() == origen.getIDEstacion() && tarifa.getEstacionDestino().getIDEstacion() == origen.getIDEstacion()){
            return tarifa.getIDTarifa();
        }
    }

    return 0;
}

int ManagerTarifas::obtenerIdEstacion(Estacion estacion){

    ManagerEstaciones manager;

    return manager.obtenerIdEstacion(estacion.getNombreEstacion());
}

float ManagerTarifas::obtenerTarifa(int idTarifa){

    Tarifa tarifa;
    ArchivoTarifas archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        tarifa = archivo.leer(i);

        if(tarifa.getIDTarifa() == idTarifa){
            return tarifa.getTarifa();
        }
    }

    return -1;
}

float ManagerTarifas::obtenerTarifa(Estacion origen, Estacion destino){

    Tarifa registro;
    ArchivoTarifas archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getEstacionOrigen().getIDEstacion() == origen.getIDEstacion() && registro.getEstacionDestino().getIDEstacion() == destino.getIDEstacion()){
            return registro.getTarifa();
        }
    }

    return 0;
}

float ManagerTarifas::obtenerTarifaMasAlta(){

    Tarifa registro;
    ArchivoTarifas archivo;

    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return -1;
    }

    float tarifaMasAlta = 0;

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getTarifa() > tarifaMasAlta){
            tarifaMasAlta = registro.getTarifa();
        }
    }

    return tarifaMasAlta;
}

float ManagerTarifas::obtenerTarifaMasBaja(){

    Tarifa registro;
    ArchivoTarifas archivo;

    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return -1;
    }

    float tarifaMasBaja = archivo.leer(0).getTarifa();

    for(int i=1; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getTarifa() < tarifaMasBaja){
            tarifaMasBaja = registro.getTarifa();
        }
    }

    return tarifaMasBaja;
}

float ManagerTarifas::obtenerPromedioTarifas(){

    Tarifa registro;
    ArchivoTarifas archivo;

    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return -1;
    }

    float total = 0;

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);
        total += registro.getTarifa();
    }

    return (float)total/tam;
}

/// ------------------------------------------------ METODOS DE VALIDACION ------------------------------------------------

bool ManagerTarifas::validarIDTarifa(int idTarifa){
    ArchivoTarifas archivo;
    Tarifa tarifa;

    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    for(int i=0; i<tam; i++){
        tarifa = archivo.leer(i);

        if(tarifa.getIDTarifa() == idTarifa){
            return true;
        }
    }

    return false;
}

bool ManagerTarifas::validarEstacion(Estacion estacion){

    ManagerEstaciones manager;

    if(manager.validarNombreEstacion(estacion.getNombreEstacion()) == true && manager.validarIdEstacion(estacion.getIDEstacion() == true)){
        return true;
    }

    return false;
}

bool ManagerTarifas::validarTarifa(float tarifa){

    Tarifa registro;
    ArchivoTarifas archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getTarifa() == tarifa){
            return true;
        }
    }

    return false;
}

/// ------------------------------------------------ METODOS DE COINCIDENCIAS ------------------------------------------------

bool ManagerTarifas::coincidenciasID(int idTarifa){

    Tarifa registro;
    ArchivoTarifas archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDTarifa() == idTarifa){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

bool ManagerTarifas::coincidenciasEstacion(Estacion estacion){

    Tarifa registro;
    ArchivoTarifas archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getEstacionOrigen().getIDEstacion() == estacion.getIDEstacion() || registro.getEstacionDestino().getIDEstacion() == estacion.getIDEstacion()){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

bool ManagerTarifas::coincidenciasTarifas(float tarifa){

    Tarifa registro;
    ArchivoTarifas archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getTarifa() == tarifa){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}


/// ------------------------------------------------ METODOS DE ORDENAMIENTO ------------------------------------------------

bool ManagerTarifas::ordenarPorIdTarifa(Tarifa *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ID DE TARIFA
    Tarifa aux;

    for(int i=0; i<tam; i++){

        for(int j=i+1; j<tam; j++){

            if(registros[i].getIDTarifa() > registros[j].getIDTarifa()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerTarifas::ordenarPorIdEstacionOrigen(Tarifa *registros, int tam){

    /// /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ID DE ESTACION DE ORIGEN
    Tarifa aux;

    for(int i=0; i<tam; i++){

        for(int j=i+1; j<tam; j++){

            if(registros[j].getEstacionOrigen().getIDEstacion() < registros[i].getEstacionOrigen().getIDEstacion()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerTarifas::ordenarPorIdEstacionDestino(Tarifa *registros, int tam){

    /// /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ID DE ESTACION DE DESTINO
    Tarifa aux;

    for(int i=0; i<tam; i++){

        for(int j=i+1; j<tam; j++){

            if(registros[j].getEstacionDestino().getIDEstacion() < registros[i].getEstacionDestino().getIDEstacion()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerTarifas::ordenarPorTarifaASC(Tarifa *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR VALOR DE TARIFA ASCENDENTE
    Tarifa aux;

    for(int i=0; i<tam; i++){

        for(int j=i+1; j<tam; j++){

            if(registros[i].getTarifa() < registros[j].getTarifa()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerTarifas::ordenarPorTarifaDSC(Tarifa *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR VALOR DE TARIFA DESCENDENTE
    Tarifa aux;

    for(int i=0; i<tam; i++){

        for(int j=i+1; j<tam; j++){

            if(registros[i].getTarifa() > registros[j].getTarifa()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

/// ------------------------------------------------ MÉTODOS "ABML" ------------------------------------------------

Tarifa ManagerTarifas::cargarTarifa(){

    Tarifa registro;
    ArchivoTarifas archivo;

    int id = obtenerProximoIdTarifa();

    registro.cargar(id);

    if(validarEstacion(registro.getEstacionOrigen()) == false){
        mostrarTexto("< ERROR: NO EXISTE LA ESTACION DE ORIGEN INGRESADA >");
        return Tarifa();
    }

    if(validarEstacion(registro.getEstacionDestino()) == false){
        mostrarTexto("< ERROR: NO EXISTE LA ESTACION DE DESTINO INGRESADA >");
        return Tarifa();
    }

    return registro;
}

Tarifa ManagerTarifas::editarTarifa(){

    Tarifa registro;
    ArchivoTarifas archivo;

    int idTarifa;
    float valorTarifa;

    std::cout << "ID DE TARIFA: ";
    std::cin >> idTarifa;
    if(validarIDTarifa(idTarifa) == true){

        std::cout << "NUEVO VALOR DE LA TARIFA: ";
        std::cin >> valorTarifa;
        if(valorTarifa > 0){

            int pos = idTarifa - 1;
            registro = archivo.leer(pos);
            registro.setTarifa(valorTarifa);
            mostrarTexto("TARIFA EDITADA");
        }
    }
    else{
        mostrarTexto("< ERROR: EL ID DE TARIFA INGRESADO NO EXISTE >");
        return Tarifa();
    }

    return registro;
}

bool ManagerTarifas::altaTarifa(){

    Tarifa registro;
    ArchivoTarifas archivo;

    registro = cargarTarifa();
    if(registro.getIDTarifa() == 0){
        return false;
    }

    if(archivo.guardar(registro) == true){
        return true;
    }

    return false;
}

bool ManagerTarifas::modificacionTarifa(){

    Tarifa registro;
    ArchivoTarifas archivo;

    registro = editarTarifa();
    if(registro.getIDTarifa() == 0){
        return false;
    }

    int pos = registro.getIDTarifa();

    if(archivo.editar(registro, pos - 1) == true){
        /// SI SE PUDO EDITAR EL REGISTRO
        return true;
    }

    return false;
}

void ManagerTarifas::mostrarEncabezado(){
    /*
    ManagerEstaciones manager;

    int anchoIdTarifa = obtenerCantidadDigitos(obtenerCantidadRegistros());
    int anchoIdOrigen = obtenerCantidadDigitos(manager.obtenerCantidadRegistros());
    int anchoIdDestino = obtenerCantidadDigitos(manager.obtenerCantidadRegistros());
    int anchoTarifa = obtenerCantidadDigitos(obtenerTarifaMasAlta());

    std::cout << "ID DE TARIFA" << espaciar(anchoIdTarifa, strlen("ID TARIFA") + anchoIdTarifa);
    std::cout << "VALOR DE TARIFA" << espaciar(anchoTarifa, strlen("VALOR DE TARIFA") + anchoTarifa);
    std::cout << "ID ORIGEN" << espaciar(anchoIdOrigen, strlen("ID ORIGEN") + anchoIdOrigen);
    std::cout << "NOMBRE DE ESTACION ORIGEN" << espaciar(strlen("NOMBRE DE ESTACION ORIGEN"), 35);
    std::cout << "ID DESTINO" << espaciar(anchoIdDestino, strlen("ID DESTINO") + anchoIdDestino);
    std::cout << "NOMBRE DE ESTACION DESTINO" << espaciar(strlen("NOMBRE DE ESTACION DESTINO"), 35);
    */
}

void ManagerTarifas::mostrarRegistros(Tarifa *registros, int tam){

    /**
    int anchoIdTarifa = obtenerCantidadDigitos(obtenerCantidadRegistros());
    int anchoIdOrigen = obtenerCantidadDigitos(manager.obtenerCantidadRegistros());
    int anchoIdDestino = obtenerCantidadDigitos(manager.obtenerCantidadRegistros());
    int anchoTarifa = obtenerCantidadDigitos(obtenerTarifaMasAlta())

    std::cout << registro.getIDTarifa() << espaciar(anchoIdTarifa, strlen("ID TARIFA") + anchoIdTarifa);
    std::cout << registro.getTarifa() << espaciar(anchoTarifa, strlen("VALOR DE TARIFA") + anchoTarifa);
    std::cout << registro.getIDEstacionOrigen() << espaciar(anchoIdOrigen, strlen("ID ORIGEN") + anchoIdOrigen);
    std::cout << obtenerTextoEstacion(registro.getIDTarifa())" << espaciar(strlen("NOMBRE DE ESTACION ORIGEN"), 35);
    std::cout << registro.getIDEstacionDestino() << espaciar(anchoIdDestino, strlen("ID DESTINO") + anchoIdDestino);
    std::cout << obtenerTextoEstacion(registro.getIDTarifa()) << espaciar(strlen("NOMBRE DE ESTACION DESTINO"), 35);
    */

    for(int i=0; i<tam; i++){
        registros[i].mostrar();
        std::cout << "------------------------------------------------" << std::endl;
    }
}

/// ------------------------------------------------ LISTADOS ------------------------------------------------

bool ManagerTarifas::listadoPorIdTarifa(){

    ArchivoTarifas archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE TARIFAS DEL ARCHIVO "tarifas.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "tarifas.dat" NO TIENE REGISTROS
        return false;
    }

    Tarifa *registros = new Tarifa[tam];
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

    /// ORDENO EL VECTOR DINAMICO POR ID DE TARIFA
    if(ordenarPorIdTarifa(registros, tam) == false){
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID
    mostrarRegistros(registros, tam);

    delete[] registros;

    return true;
}

bool ManagerTarifas::listadoPorIdEstacionOrigen(){

    ArchivoTarifas archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE TARIFAS DEL ARCHIVO "tarifas.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "tarifas.dat" NO TIENE REGISTROS
        return false;
    }

    Tarifa *registros = new Tarifa[tam];
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

    /// ORDENO EL VECTOR DINAMICO POR ID DE ORIGEN
    if(ordenarPorIdEstacionOrigen(registros, tam) == false){
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID DE ORIGEN
    mostrarRegistros(registros, tam);

    delete[] registros;

    return true;
}

bool ManagerTarifas::listadoPorIdEstacionDestino(){

    ArchivoTarifas archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE TARIFAS DEL ARCHIVO "tarifas.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "tarifas.dat" NO TIENE REGISTROS
        return false;
    }

    Tarifa *registros = new Tarifa[tam];
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

    /// ORDENO EL VECTOR DINAMICO POR ID DE DESTINO
    if(ordenarPorIdEstacionDestino(registros, tam) == false){
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID DE DESTINO
    mostrarRegistros(registros, tam);

    delete[] registros;

    return true;
}

bool ManagerTarifas::listadoPorTarifaASC(){

    ArchivoTarifas archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE TARIFAS DEL ARCHIVO "tarifas.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "tarifas.dat" NO TIENE REGISTROS
        return false;
    }

    Tarifa *registros = new Tarifa[tam];
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

    /// ORDENO EL VECTOR DINAMICO POR VALOR DE TARIFA ASCENDENTE
    if(ordenarPorTarifaASC(registros, tam) == false){
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR VALOR DE TARIFA ASCENDENTE
    mostrarRegistros(registros, tam);

    delete[] registros;

    return true;
}

bool ManagerTarifas::listadoPorTarifaDSC(){

    ArchivoTarifas archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE TARIFAS DEL ARCHIVO "tarifas.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "tarifas.dat" NO TIENE REGISTROS
        return false;
    }

    Tarifa *registros = new Tarifa[tam];
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

    /// ORDENO EL VECTOR DINAMICO POR VALOR DE TARIFA DESCENDENTE
    if(ordenarPorTarifaDSC(registros, tam) == false){
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR VALOR DE TARIFA DESCENDENTE
    mostrarRegistros(registros, tam);

    delete[] registros;

    return true;
}

/// ------------------------------------------------ CONSULTAS ------------------------------------------------

bool ManagerTarifas::consultaTarifaPorIdTarifa(){

    /// LE PIDO AL USUARIO EL ID
    int id;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << std::endl;

    /// VALIDO EL ID
    if(validarIDTarifa(id) == false){
        /// NO SE ENCONTRO EL ID
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL ID
    if(coincidenciasID(id) == 0){
        /// NO SE ENCONTRARON COINCIDDENCIAS
        return false;
    }

    return true;
}

bool ManagerTarifas::consultaTarifaPorEstacion(){

    Estacion registro;

    /// LE PIDO AL USUARIO CARGAR LA ESTACION
    registro.cargar();

    /// VERIFICO QUE LA ESTACION EXISTA
    if(validarEstacion(registro) == false){
        /// LA ESTACION INGRESADA NO EXISTE
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON LA ESTACION
    if(coincidenciasEstacion(registro) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

bool ManagerTarifas::consultaTarifa(){

    /// LE PIDO AL USUARIO EL VALOR DE LA TARIFA
    float tarifa;
    std::cout << "TARIFA: $";
    std::cin >> tarifa;

    /// VALIDO EL VALOR DE LA TARIFA
    if(validarTarifa(tarifa) == false){
        /// EL VALOR DE LA TARIFA NO EXISTE
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS
    if(coincidenciasTarifas(tarifa) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

/// ------------------------------------------------ INFORMES -------------------------------------------------

bool ManagerTarifas::informeTarifaMasAlta(){

    ArchivoTarifas archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "EL VALOR DE LA TARIFA MAS ALTA ES DE: $" << obtenerTarifaMasAlta() << std::endl;

    return true;
}

bool ManagerTarifas::informeTarifaMasBaja(){

    ArchivoTarifas archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "EL VALOR DE LA TARIFA MAS BAJA ES DE: $" << obtenerTarifaMasBaja() << std::endl;

    return true;
}

bool ManagerTarifas::informePromedioDeTarifas(){

    ArchivoTarifas archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "EL VALOR PROMEDIO DE LAS TARIFAS ES DE: $" << obtenerPromedioTarifas() << std::endl;

    return false;
}
