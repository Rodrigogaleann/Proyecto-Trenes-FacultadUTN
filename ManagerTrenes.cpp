#include "ManagerTrenes.h"
#include "ArchivoTrenes.h"
#include "Tren.h"

#include "FuncionesGlobales.h"

#include <iostream>

/// ------------------------------------------------ MÉTODOS GENERALES ------------------------------------------------

bool ManagerTrenes::cargarVector(Tren *registros, int tam){

    ArchivoTrenes archivo;

    /// ALMACENO LOS REGISTROS DEL ARCHIVO DENTRO DEL NUEVO VECTOR
    for(int i=0; i<tam; i++){
        registros[i] = archivo.leer(i);
    }

    return true;
}

int ManagerTrenes::obtenerProximoID(){
    ArchivoTrenes archivo;

    int id = archivo.getCantidadRegistros() + 1;

    return id;
}

Tren ManagerTrenes::obtenerTren(int idTren){

    Tren registro;
    ArchivoTrenes archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDTren() == idTren){
            return registro;
        }
    }

    return Tren();
}

bool ManagerTrenes::verificarAsientosDisponibles(int idTren){

    Tren registro;
    registro = obtenerTren(idTren);

    int cantidadAsientos = registro.getCantidadAsientos();

    for(int i=0; i<cantidadAsientos; i++){

        if(registro.getCapacidadDisponible(i) == true){
            return true;
        }
    }

    return false;
}

Tren ManagerTrenes::cambiarEstadoAsientos(Tren registro, int pos){

    if(registro.getCapacidadDisponible(pos) == false){
        registro.setCapacidadDisponible(pos, true);
    }
    else{
        registro.setCapacidadDisponible(pos, false);
    }

    return registro;
}

bool ManagerTrenes::ocuparAsiento(int idTren){

    Tren registro;
    ArchivoTrenes archivo;

    registro = obtenerTren(idTren);
    int cantidadAsientos = registro.getCantidadAsientos();

    for(int i=0; i<cantidadAsientos; i++){

        if(registro.getCapacidadDisponible(i) == true){
            registro.setCapacidadDisponible(i, false);

            if(revisarEspacioTren(registro) == true){
                registro.setEstado(false);
            }

            return archivo.editar(registro, idTren - 1);
        }
    }

    return false;
}

bool ManagerTrenes::revisarEspacioTren(Tren registro){

    int cantidadAsientos = registro.getCantidadAsientos();
    int contador = 0;

    for(int i=0; i<cantidadAsientos; i++){

        if(registro.getCapacidadDisponible(i) == false){
            contador ++;
        }
    }

    if(contador == cantidadAsientos){
        return true;
    }

    return false;
}

Tren ManagerTrenes::reiniciarAsientos(Tren registro){

    int cantidadAsientos = registro.getCantidadAsientos();

    for(int i = 0; i < cantidadAsientos; i++){
        registro.setCapacidadDisponible(i, true);
    }

    return registro;
}

bool ManagerTrenes::reiniciarTrenes(){

    Tren registro;
    ArchivoTrenes archivo;

    int contador = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        registro.setEstado(true);
        registro = reiniciarAsientos(registro);

        if(archivo.editar(registro, i)) {
            contador++;
        }
    }

    return (contador == tam);
}


int ManagerTrenes::mostrarAsientos(Tren registro) {

    registro.mostrar();

    int cantidadAsientos = registro.getCantidadAsientos();

    int opc;
    mostrarTexto("INGRESE EL NUMERO DE ASIENTO A MODIFICAR (0-SALIR)");
    std::cout << "OPCION: ";
    std::cin >> opc;

    if(opc < 0 || opc > cantidadAsientos) {
        return 0;
    }

    system("pause");
    system("cls");

    return opc;
}

/// ------------------------------------------------ METODOS DE INFORMES ------------------------------------------------

int ManagerTrenes::obtenerCantidadTrenesOperativos(){
    ArchivoTrenes archivo;
    Tren registro;

    /// OBTENGO LA CANTIDAD DE TRENES DEL ARCHIVO "trenes.dat"
    int tam = archivo.getCantidadRegistros();
    int cantidadTrenesOperativos = 0;

    /// ACUMULO LA CANTIDAD DE TRENES OPERATIVOS
    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getEstado() == true){
            cantidadTrenesOperativos++;
        }
    }

    return cantidadTrenesOperativos;
}

int ManagerTrenes::obtenerCantidadTrenesNoOperativos(){
    ArchivoTrenes archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE TRENES, DEL TAMAÑO DE LA CANTIDAD DE REGISTROS DEL ARCHIVO "trenes.dat"
    int tam = archivo.getCantidadRegistros();

    Tren *registros = new Tren[tam];
    if(registros == nullptr){
        std::cout  << "ERROR: NO SE PUDO ASIGNAR LA MEMORIA" << std::endl;
        return 0;
    }

    /// ALMACENO LOS REGISTROS DEL ARCHIVO DENTRO DEL NUEVO VECTOR
    for(int i=0; i<tam; i++){
        registros[i] = archivo.leer(i);
    }

    int cantidadTrenesNoOperativos = 0;

    /// ACUMULO LA CANTIDAD DE TRENES OPERATIVOS
    for(int i=0; i<tam; i++){
        if(registros[i].getEstado() == false){
            cantidadTrenesNoOperativos++;
        }
    }

    delete []registros;

    return cantidadTrenesNoOperativos;
}

float ManagerTrenes::obtenerOcupacionPromedio(){

    Tren registro;
    ArchivoTrenes archivo;

    /// OBTENGO LA CANTIDAD DE TRENES DEL ARCHIVO "trenes.dat"
    int tam = archivo.getCantidadRegistros();
    int cantidadAsientos = registro.getCantidadAsientos();

    int cantidadAsientosOcupados = 0;

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i); /// OBJETO TEMPORAL

        /// FALSE = ASIENTO OCUPADO
        /// TRUE = ASIENTO DISPONIBLE
        for(int j=0; j<cantidadAsientos; j++){
            if(registro.getCapacidadDisponible(j) == false){
                cantidadAsientosOcupados++;
            }
        }
    }

    return (float)cantidadAsientosOcupados/tam;
}

/// ------------------------------------------------ METODOS DE VALIDACION ------------------------------------------------

bool ManagerTrenes::validarIdTren(int id){

    Tren registro;
    ArchivoTrenes archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDTren() == id){
            return true;
        }
    }

    return false;
}

bool ManagerTrenes::validarEstado(int id){

    Tren registro;
    ArchivoTrenes archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDTren() == id){

            if(registro.getEstado() == true){
                return true;
            }
        }
    }

    return false;
}

/// ------------------------------------------------ METODOS DE COINCIDENCIAS ------------------------------------------------

int ManagerTrenes::coincidenciasID(int id){

    Tren registro;
    ArchivoTrenes archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDTren() == id){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerTrenes::coincidenciasEstado(bool estado){

    Tren registro;
    ArchivoTrenes archivo;

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

/// ------------------------------------------------ METODOS DE ORDENAMIENTO ------------------------------------------------

bool ManagerTrenes::ordenarPorIdTren(Tren *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ID DE TREN
    Tren aux;

    for(int i=0; i<tam; i++){

        for(int j=i+1; j<tam; j++){

            if(registros[j].getIDTren() < registros[i].getIDTren()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerTrenes::ordenarPorEstado(Tren *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ESTADO
    Tren aux;

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

Tren ManagerTrenes::cargarTren(){

    Tren registro;

    int id = obtenerProximoID();
    if(id == 0){
        return Tren();
    }

    /// CARGO EL REGISTRO
    registro.cargar(id);

    int opc;

    std::cout << "TREN #" << id << std::endl;
    std::cout << "ESTADO DEL TREN: " << binarioActivo(registro.getEstado()) << std::endl;
    std::cout << "DESEAS CONFIRMAR EL REGISTRO? (1-SI / 0-NO): ";
    std::cin >> opc;

    if(opc == 1){
        return registro;
    }

    return Tren();
}

Tren ManagerTrenes::editarTren(){

    Tren registro;
    ArchivoTrenes archivo;

    int idTren;
    std::cout << "ID DEL TREN: ";
    std::cin >> idTren;
    if(validarIdTren(idTren) == false){
        return Tren();
    }

    registro = archivo.leer(idTren - 1);

    while(true){

        int opc = mostrarAsientos(registro);
        if(opc == 0){
            break;
        }

        registro = cambiarEstadoAsientos(registro, opc - 1);
    }

    if(revisarEspacioTren(registro) == true){
        registro.setEstado(false);
    }

    return registro;
}

bool ManagerTrenes::altaTren(){

    Tren registro;
    ArchivoTrenes archivo;

    registro = cargarTren();
    if(registro.getIDTren() == 0){
        return false;
    }

    if(archivo.guardar(registro) == true){
        return true;
    }

    return false;
}

bool ManagerTrenes::modificacionTren(){

    Tren registro;
    ArchivoTrenes archivo;

    registro = editarTren();
    if(registro.getIDTren() == 0){
        return false;
    }

    int pos = registro.getIDTren() - 1;

    if(archivo.editar(registro, pos) == true){
        return true;
    }

    return false;
}

bool ManagerTrenes::altaLogica(int id){

    Tren registro;
    ArchivoTrenes archivo;

    if(validarIdTren(id) == false){
        return false;
    }

    int pos = id - 1;

    registro = archivo.leer(pos);

    registro.setEstado(true);

    registro = reiniciarAsientos(registro);

    return archivo.editar(registro, pos);
}

bool ManagerTrenes::bajaLogica(int id){

    Tren registro;
    ArchivoTrenes archivo;

    if(validarIdTren(id) == false){
        return false;
    }

    int pos = id - 1;

    registro = archivo.leer(pos);

    registro.setEstado(false);

    return archivo.editar(registro, pos);
}

void ManagerTrenes::mostrarRegistros(Tren *registros, int tam){

    for(int i=0; i<tam; i++){
        registros[i].mostrar();
        std::cout << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
    }
}

/// ------------------------------------------------ LISTADOS ------------------------------------------------

bool ManagerTrenes::listadoPorID(){

    ArchivoTrenes archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE TRENES DEL ARCHIVO "trenes.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "trenes.dat" NO TIENE REGISTROS
        return false;
    }

    Tren *registros = new Tren[tam];
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

    /// ORDENO EL VECTOR DINAMICO POR ID DE TREN
    if(ordenarPorIdTren(registros, tam) == false){
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerTrenes::listadoPorEstado(){

    ArchivoTrenes archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE TRENES DEL ARCHIVO "trenes.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "trenes.dat" NO TIENE REGISTROS
        return false;
    }

    Tren *registros = new Tren[tam];
    if(registros == nullptr){
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] registros;
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

bool ManagerTrenes::consultaPorID(){

    /// LE PIDO AL USUARIO EL ID
    int id;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << std::endl;

    /// VALIDO EL ID
    if(validarIdTren(id) == false){
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

bool ManagerTrenes::consultaPorEstado(){

    /// LE PIDO AL USUARIO EL ESTADO
    bool estado;
    std::cout << "ESTADO (1-ACTIVO / 0-INACTIVO): ";
    std::cin >> estado;
    std::cout << std::endl;

    /// VALIDO EL ESTADO
    if(validarEstado(estado) == false){
        /// NO SE ENCONTRO EL ESTADO
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL ESTADO
    if(coincidenciasEstado(estado) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

/// ------------------------------------------------ INFORMES -------------------------------------------------

bool ManagerTrenes::informeCantidadTrenesOperativos(){

    ArchivoTrenes archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "CANTIDAD DE TRENES OPERATIVOS: " << obtenerCantidadTrenesOperativos() << std::endl;

    return true;
}

bool ManagerTrenes::informeCantidadTrenesNoOperativos(){

    ArchivoTrenes archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "CANTIDAD DE TRENES NO OPERATIVOS: " << obtenerCantidadTrenesNoOperativos() << std::endl;

    return true;
}

bool ManagerTrenes::informeOcupacionPromedio(){

    ArchivoTrenes archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    float resultado = obtenerOcupacionPromedio();

    std::cout << "OCUPACION PROMEDIO DE LOS TRENES: ";
    if(resultado == 0){
        std::cout << "NO HUBO PASAJEROS" << std::endl;
    }
    else{
        if(resultado > 0){
            std::cout << "ENTRE " << (int)resultado << " y " << (int)resultado + 1 << std::endl;
        }
    }

    return true;
}
