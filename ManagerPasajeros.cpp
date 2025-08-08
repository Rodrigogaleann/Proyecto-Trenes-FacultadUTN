#include "ManagerPasajeros.h"
#include "ArchivoPasajeros.h"
#include "Pasajero.h"

#include "FuncionesGlobales.h"

#include <iostream>
#include <cstring>

/// ------------------------------------------------ MÉTODOS GENERALES ------------------------------------------------

bool ManagerPasajeros::cargarVector(Pasajero *registros, int tam){

    ArchivoPasajeros archivo;

    /// ALMACENO LOS REGISTROS DEL ARCHIVO DENTRO DEL NUEVO VECTOR
    for(int i=0; i<tam; i++){
        registros[i] = archivo.leer(i);
    }

    return true;
}

int ManagerPasajeros::obtenerProximoID(){

    ArchivoPasajeros archivo;

    int id = archivo.getCantidadRegistros() + 1;

    return id;
}

int ManagerPasajeros::obtenerID(const char *dni){

    Pasajero pasajero;
    ArchivoPasajeros archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        pasajero = archivo.leer(i);

        if(stricmp(pasajero.getDni(), dni) == 0){
            return pasajero.getIDPasajero();
        }
    }

    return 0;
}

int ManagerPasajeros::obtenerTotalActivos(){

    Pasajero registro;
    ArchivoPasajeros archivo;

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

int ManagerPasajeros::obtenerTotalInactivos(){

    Pasajero registro;
    ArchivoPasajeros archivo;

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

Pasajero ManagerPasajeros::obtenerPasajeroPorDNI(const char* dni){
   Pasajero pasajero;
   ArchivoPasajeros archivopasajero;

   int cantidad=archivopasajero.getCantidadRegistros();

   for(int i=0;i<cantidad;i++){
    pasajero=archivopasajero.leer(i);
     if(stricmp(dni,pasajero.getDni())==0){
        return pasajero;
     }
   }

   return Pasajero();
}

/// ------------------------------------------------ MÉTODOS DE VALIDACIÓN ------------------------------------------------

bool ManagerPasajeros::validarID(int id){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDPasajero() == id){
            return true;
        }
    }

    return false;
}

bool ManagerPasajeros::validarNombre(const char *nombre){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getNombre(), nombre) == 0){
            return true;
        }
    }

    return false;
}

bool ManagerPasajeros::validarApellido(const char *apellido){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getApellido(), apellido) == 0){
            return true;
        }
    }

    return false;
}

bool ManagerPasajeros::validarDni(const char *dni){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);


        if(stricmp(registro.getDni(), dni) == 0){
            return true;
        }
    }

    return false;
}

bool ManagerPasajeros::validarEmail(const char *email){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getEmail(), email) == 0){
            return true;
        }
    }

    return false;
}

bool ManagerPasajeros::validarEstado(bool estado){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getEstado() == estado){
            return true;
        }
    }

    return false;
}

/// ------------------------------------------------ METODOS DE COINCIDENCIAS ------------------------------------------------

int ManagerPasajeros::coincidenciasID(int id){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIDPasajero() == id){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerPasajeros::coincidenciasNombre(const char *nombre){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getNombre(), nombre) == 0){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerPasajeros::coincidenciasApellido(const char *apellido){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getApellido(), apellido) == 0){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerPasajeros::coincidenciasDni(const char *dni){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getDni(), dni) == 0){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerPasajeros::coincidenciasEmail(const char *email){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getEmail(), email) == 0){
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerPasajeros::coincidenciasEstado(bool estado){

    Pasajero registro;
    ArchivoPasajeros archivo;

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

bool ManagerPasajeros::ordenarPorID(Pasajero *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ID
    Pasajero aux;

    for(int i=0; i<tam; i++){

        for(int j = i+1; j<tam; j++){
            if(registros[j].getIDPasajero() < registros[i].getIDPasajero()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerPasajeros::ordenarPorNombre(Pasajero *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR NOMBRE
    Pasajero aux;

    for(int i=0; i<tam; i++){

        for(int j = i+1; j < tam; j++){
            /// STRICMP IGNORA MAYUSCULAS Y MINUSCULAS
            if((stricmp(registros[i].getNombre(), registros[j].getNombre()) ) > 0){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerPasajeros::ordenarPorApellido(Pasajero *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR APELLIDO
    Pasajero aux;

    for(int i=0; i<tam; i++){

        for(int j = i+1; j < tam; j++){
            /// STRICMP IGNORA MAYUSCULAS Y MINUSCULAS
            if((stricmp(registros[i].getApellido(), registros[j].getApellido()) ) > 0){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerPasajeros::ordenarPorDni(Pasajero *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR DNI
    Pasajero aux;

    for(int i=0; i<tam; i++){

        for(int j = i+1; j < tam; j++){
            /// STRICMP IGNORA MAYUSCULAS Y MINUSCULAS
            if((stricmp(registros[i].getDni(), registros[j].getDni()) ) > 0){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerPasajeros::ordenarPorEmail(Pasajero *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR EMAIL
    Pasajero aux;

    for(int i=0; i<tam; i++){

        for(int j = i+1; j < tam; j++){
            /// STRICMP IGNORA MAYUSCULAS Y MINUSCULAS
            if((stricmp(registros[i].getEmail(), registros[j].getEmail()) ) > 0){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerPasajeros::ordenarPorEstado(Pasajero *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ESTADO
    Pasajero aux;

    for(int i=0; i<tam; i++){

        for(int j = i+1; j < tam; j++){
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

Pasajero ManagerPasajeros::cargarPasajero(char *dniPasajero){

    Pasajero registro;
    ArchivoPasajeros archivo;

    char dni[10];

    if(stricmp(dniPasajero, "NADA") == 0){
        std::cout << "DNI: ";
        cargarCadena(dni, sizeof(dni) - 1);
    }
    else{
        strcpy(dni, dniPasajero);
    }

    if(validarDni(dni) == true){

        int pos = obtenerID(dni) - 1;
        registro = archivo.leer(pos);

        if(registro.getEstado() == false){
            mostrarTexto("EL PASAJERO ESTA INACTIVO. DESEA REACTIVARLO? (1-SI / 0-NO)");

            int opc;
            std::cout << "OPCION: ";
            std::cin >> opc;

            if (opc == 1 && altaLogica(dni) == true) {
                mostrarTexto("PASAJERO REACTIVADO");
                return Pasajero();
            }
        }
        else{
            mostrarTexto("EL PASAJERO EXISTE Y SE ENCUENTRA ACTIVO");
            return Pasajero();
        }
    }
    else{
        mostrarTexto("EL PASAJERO NO EXISTE. POR FAVOR PROCEDA A CARGAR LOS DATOS");

        int id = obtenerProximoID();
        registro.cargar(id, dni);

        if(validarEmail(registro.getEmail())) {
            mostrarTexto("< ERROR: EL EMAIL YA ESTA EN USO >");
            return Pasajero();
        }
    }

    return registro;
}

Pasajero ManagerPasajeros::editarPasajero(){

    Pasajero registro;
    ArchivoPasajeros archivo;

    char dni[10];

    std::cout << "DNI: ";
    cargarCadena(dni, sizeof(dni) - 1);
    if(validarDni(dni) == true){

        int pos = obtenerID(dni) - 1;
        registro = archivo.leer(pos);

        if(registro.getEstado() == false){
            mostrarTexto("EL PASAJERO ESTA INACTIVO. DESEA REACTIVARLO? (1-SI / 0-NO)");

            int opc = 0;
            std::cout << "OPCION: ";
            std::cin >> opc;

            if(opc == 1 && altaLogica(dni) == true){
                mostrarTexto("PASAJERO REACTIVADO");
                return Pasajero();
            }
        }
        else{
            ///muestro datos del pasajero para corroborar
            registro.mostrar();
            std::cout<<std::endl;
            mostrarTexto("EL PASAJERO SE ENCUENTRA ACTIVO. POR FAVOR PROCEDA A MODIFICAR LOS DATOS");
            registro.cargar(pos + 1, dni);

            if(validarEmail(registro.getEmail()) == true){
                mostrarTexto("< ERROR: EL EMAIL YA SE ENCUENTRA EN USO >");
                return Pasajero();
            }
        }
    }
    else{
        mostrarTexto("< ERROR: EL PASAJERO NO EXISTE >");
        return Pasajero();
    }

    return registro;
}

bool ManagerPasajeros::altaPasajero(char *dniPasajero){

    Pasajero registro;
    ArchivoPasajeros archivo;

    if(stricmp(dniPasajero, "NADA") == 0){
        registro = cargarPasajero();
    }
    else{
        registro = cargarPasajero(dniPasajero);
    }

    if(registro.getIDPasajero() == 0){
        return false;
    }

    if(archivo.guardar(registro) == true){
        return true;
    }

    return false;
}

bool ManagerPasajeros::modificacionPasajero(){

    Pasajero registro;
    ArchivoPasajeros archivo;

    registro = editarPasajero();
    if(registro.getIDPasajero() == 0){
        return false;
    }

    int pos = registro.getIDPasajero() - 1;

    if(archivo.editar(registro, pos) == true){
        return true;
    }

    return false;
}

bool ManagerPasajeros::altaLogica(const char *dni){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int pos = obtenerID(dni) - 1;
    if(pos == -1){
        return false;
    }

    registro = archivo.leer(pos);

    registro.setEstado(true);

    return archivo.editar(registro, pos);
}

bool ManagerPasajeros::bajaLogica(const char *dni){

    Pasajero registro;
    ArchivoPasajeros archivo;

    int pos = obtenerID(dni) - 1;
    if(pos == -1){
        return false;
    }

    registro = archivo.leer(pos);

    registro.setEstado(false);

    return archivo.editar(registro, pos);
}

void ManagerPasajeros::mostrarEncabezado(){

    ArchivoPasajeros archivo;

    int anchoID = obtenerCantidadDigitos(archivo.getCantidadRegistros());

    std::cout << "ID" << espaciar(anchoID, anchoID + 5);
    std::cout << "NOMBRE" << espaciar(strlen("NOMBRE"), 35);
    std::cout << "APELLIDO" << espaciar(strlen("APELLIDO"), 35);
    std::cout << "DNI" << espaciar(strlen("DNI"), 15);
    std::cout << "EMAIL" << espaciar(strlen("EMAIL"), 35);
}

void ManagerPasajeros::mostrarRegistros(Pasajero *registros, int tam){

    /**
    int anchoID = obtenerCantidadDigitos(obtenerCantidadRegistros());
    int anchoNombre = 30;
    int anchoApellido = 30;
    int anchoDni = 10;
    int anchoEmail = 30;

    int espacio = 5;

    std::cout << registro.getIDPasajero() << espaciar(obtenerCantidadDigitos(registro.getIDPasajero()), anchoID + espacio);
    std::cout << registro.getNombre() << espaciar(strlen(registro.getNombre()), anchoNombre + espacio);
    std::cout << registro.getApellido() << espaciar(strlen(registro.getApellido()), anchoApellido + espacio);
    std::cout << registro.getDni() << espaciar(strlen(registro.getDni()), anchoDni + espacio);
    std::cout << registro.getEmail() << espaciar(strlen(registro.getEmail()), anchoEmail + espacio);
    std::cout << std::endl;
    */

    for(int i=0; i<tam; i++){
        registros[i].mostrar();
        std::cout << std::endl;
    }
}

/// ------------------------------------------------ LISTADOS ------------------------------------------------

bool ManagerPasajeros::listadoPorID(){

    ArchivoPasajeros archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE PASAJEROS DEL ARCHIVO "pasajeros.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "pasajeros.dat" NO TIENE REGISTROS
        return false;
    }

    Pasajero *registros = new Pasajero[tam];
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

    /// ORDENO EL VECTOR DINAMICO
    if(ordenarPorID(registros, tam) == false){
        /// NO SE PUDO ORDENAR POR ID
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerPasajeros::listadoPorNombre(){

    ArchivoPasajeros archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE PASAJEROS DEL ARCHIVO "pasajeros.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "pasajeros.dat" NO TIENE REGISTROS
        return false;
    }

    Pasajero *registros = new Pasajero[tam];
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

    /// ORDENO EL VECTOR POR NOMBRE
    if(ordenarPorNombre(registros, tam) == false){
        /// NO SE PUDO ORDENAR POR NOMBRE
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR NOMBRE
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerPasajeros::listadoPorApellido(){

    ArchivoPasajeros archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE PASAJEROS DEL ARCHIVO "pasajeros.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "pasajeros.dat" NO TIENE REGISTROS
        return false;
    }

    Pasajero *registros = new Pasajero[tam];
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

    /// ORDENO EL VECTOR POR APELLIDO
    if(ordenarPorApellido(registros, tam) == false){
        /// NO SE PUDO ORDENAR POR APELLIDO
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR APELLIDO
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerPasajeros::listadoPorDni(){

    ArchivoPasajeros archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE PASAJEROS DEL ARCHIVO "pasajeros.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "pasajeros.dat" NO TIENE REGISTROS
        return false;
    }

    Pasajero *registros = new Pasajero[tam];
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

    /// ORDENO EL VECTOR POR DNI
    if(ordenarPorDni(registros, tam) == false){
        /// NO SE PUDO ORDENAR POR DNI
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR DNI
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerPasajeros::listadoPorEmail(){

    ArchivoPasajeros archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE PASAJEROS DEL ARCHIVO "pasajeros.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "pasajeros.dat" NO TIENE REGISTROS
        return false;
    }

    Pasajero *registros = new Pasajero[tam];
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

    /// ORDENO EL VECTOR POR EMAIL
    if(ordenarPorEmail(registros, tam) == false){
        /// NO SE PUDO ORDENAR POR EMAIL
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerPasajeros::listadoPorEstado(){

    ArchivoPasajeros archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE PASAJEROS DEL ARCHIVO "pasajeros.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "pasajeros.dat" NO TIENE REGISTROS
        return false;
    }

    Pasajero *registros = new Pasajero[tam];
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

bool ManagerPasajeros::consultaPorID(){

    /// LE PIDO AL USUARIO EL ID
    int id;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << std::endl;

    /// VALIDO EL ID
    if(validarID(id) == false){
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

bool ManagerPasajeros::consultaPorNombre(){

    /// LE PIDO AL USUARIO EL NOMBRE
    char nombre[30];
    std::cout << "NOMBRE: ";
    cargarCadena(nombre, sizeof(nombre) - 1);
    std::cout << std::endl;

    /// VALIDO EL ID
    if(validarNombre(nombre) == false){
        /// NO SE ENCONTRO EL NOMBRE
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL NOMBRE
    if(coincidenciasNombre(nombre) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

bool ManagerPasajeros::consultaPorApellido(){

    /// LE PIDO AL USUARIO EL APELLIDO
    char apellido[30];
    std::cout << "APELLIDO: ";
    cargarCadena(apellido, sizeof(apellido) - 1);
    std::cout << std::endl;

    /// VALIDO EL ID
    if(validarApellido(apellido) == false){
        /// NO SE ENCONTRO EL NOMBRE
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL APELLIDO
    if(coincidenciasApellido(apellido) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

bool ManagerPasajeros::consultaPorDni(){

    /// LE PIDO AL USUARIO EL DNI
    char dni[10];
    std::cout << "DNI: ";
    cargarCadena(dni, sizeof(dni) - 1);
    std::cout << std::endl;

    /// VALIDO EL ID
    if(validarDni(dni) == false){
        /// NO SE ENCONTRO EL NOMBRE
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL DNI
    if(coincidenciasDni(dni) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

bool ManagerPasajeros::consultaPorEmail(){

    /// LE PIDO AL USUARIO EL EMAIL
    char email[50];
    std::cout << "EMAIL: ";
    cargarCadena(email, sizeof(email) - 1);
    std::cout << std::endl;

    /// VALIDO EL ID
    if(validarEmail(email) == false){
        /// NO SE ENCONTRO EL NOMBRE
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL EMAIL
    if(coincidenciasEmail(email) == 0){
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

bool ManagerPasajeros::consultaPorEstado(){

    /// LE PIDO AL USUARIO EL ESTADO
    bool estado;
    std::cout << "ESTADO (1-ACTIVO / 0-INACTIVO): ";
    std::cin >> estado;
    std::cout << std::endl;

    /// VALIDO EL ESTADO
    if(validarEstado(estado) == false){
        /// NO SE ENCONTRO EL NOMBRE
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

bool ManagerPasajeros::informeTotalPasajerosRegistrados(){

    ArchivoPasajeros archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "CANTIDAD TOTAL DE PASAJEROS REGISTRADOS: " << archivo.getCantidadRegistros() << std::endl;

    return true;
}

bool ManagerPasajeros::informeTotalPasajerosActivos(){

    ArchivoPasajeros archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    if(obtenerTotalActivos() < 1){
        /// SE PRODIJO UN ERROR AL OBTENER LA CANTIDAD DE PASAJEROS ACTIVOS
        return false;
    }

    std::cout << "CANTIDAD TOTAL DE PASAJEROS ACTIVOS: " << obtenerTotalActivos() << std::endl;

    return true;
}

bool ManagerPasajeros::informeTotalPasajerosInactivos(){

    ArchivoPasajeros archivo;

    if(archivo.getCantidadRegistros() == 0){
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    if(obtenerTotalInactivos() < 1){
        /// SE PRODIJO UN ERROR AL OBTENER LA CANTIDAD DE PASAJEROS INACTIVOS
        return false;
    }

    std::cout << "CANTIDAD TOTAL DE PASAJEROS INACTIVOS: " << obtenerTotalInactivos() << std::endl;

    return true;
}
