#include "ManagerAdministradores.h"
#include "ArchivoAdministradores.h"
#include "Administrador.h"

#include "FuncionesGlobales.h"

#include <iostream>
#include <cstring>

/// ------------------------------------------------ MÉTODOS GENERALES ------------------------------------------------

bool ManagerAdministradores::cargarVector(Administrador *registros, int tam){

    ArchivoAdministradores archivo;

    /// ALMACENO LOS REGISTROS DEL ARCHIVO DENTRO DEL NUEVO VECTOR
    for(int i=0; i<tam; i++){
        registros[i] = archivo.leer(i);
    }

    return true;
}

int ManagerAdministradores::obtenerProximoID(){

    ArchivoAdministradores archivo;

    int id = archivo.getCantidadRegistros() + 1;

    return id;
}

int ManagerAdministradores::obtenerID(const char *dni){

    Administrador registro;
    ArchivoAdministradores archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getDni(), dni) == 0){
            return registro.getIdAdministrador();
        }
    }

    return 0;
}

int ManagerAdministradores::obtenerIdConUsuario(const char *usuario){

    Administrador registro;
    ArchivoAdministradores archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(strcmp(registro.getUsuario(), usuario) == 0){
            return registro.getIdAdministrador();
        }
    }

    return 0;
}

Administrador ManagerAdministradores::obtenerAdministradorConDNI(const char* dni){
    Administrador administrador;
    ArchivoAdministradores archivoadministrador;

    int cantidad=archivoadministrador.getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
      administrador=archivoadministrador.leer(i);
       if(stricmp(dni,administrador.getDni())==0){
        return administrador;
       }
    }
    return Administrador();
}

/// ------------------------------------------------ MÉTODOS DE VALIDACIÓN ------------------------------------------------

bool ManagerAdministradores::validarID(int id){

    Administrador registro;
    ArchivoAdministradores archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(registro.getIdAdministrador() == id){
            return true;
        }
    }

    return false;
}

bool ManagerAdministradores::validarDni(const char *dni){

    Administrador registro;
    ArchivoAdministradores archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(stricmp(registro.getDni(), dni) == 0){
            return true;
        }
    }

    return false;
}

bool ManagerAdministradores::validarUsuario(const char *usuario){

    Administrador registro;
    ArchivoAdministradores archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(strcmp(registro.getUsuario(), usuario) == 0){
            return true;
        }
    }

    return false;
}

bool ManagerAdministradores::validarUsuarioContrasenia(const char *usuario, const char *contrasenia){

    Administrador registro;
    ArchivoAdministradores archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        registro = archivo.leer(i);

        if(strcmp(registro.getUsuario(), usuario) == 0){

            if(strcmp(registro.getContrasenia(), contrasenia) == 0){
                return true;
            }
        }
    }

    return false;
}

bool ManagerAdministradores::esAdministradorPrincipal(const char *usuario){

    Administrador registro;
    ArchivoAdministradores archivo;

    if(validarUsuario(usuario) == true){

        int pos = obtenerIdConUsuario(usuario) - 1;
        registro = archivo.leer(pos);

        if(registro.getEstado() == true){
            return true;
        }
    }

    return false;
}

/// ------------------------------------------------ METODOS DE ORDENAMIENTO ------------------------------------------------

bool ManagerAdministradores::ordenarPorID(Administrador *registros, int tam){

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ID
    Administrador aux;

    for(int i=0; i<tam; i++){

        for(int j = i+1; j<tam; j++){
            if(registros[j].getIdAdministrador() < registros[i].getIdAdministrador()){
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

/// ------------------------------------------------ MÉTODOS "ABML" ------------------------------------------------

Administrador ManagerAdministradores::cargarPrimerAdministrador(){

    Administrador registro;
    ArchivoAdministradores archivo;

    mostrarTexto("BIENVIENDO! USTED ES EL PRIMER ADMINISTRADOR. PROCEDA A CARGAR SUS DATOS");

    int id = obtenerProximoID();

    registro.cargar(id);
    registro.setEstado(true);

    return registro;
}

Administrador ManagerAdministradores::cargarAdministrador(char *dniAdministrador){

    Administrador registro;
    ArchivoAdministradores archivo;

    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        registro = cargarPrimerAdministrador();
        return registro;
    }

    char usuario[30];
    char contrasenia[30];

    std::cout << "USUARIO: ";
    cargarCadena(usuario, sizeof(usuario) - 1);
    std::cout << "CONTRASENIA: ";
    cargarCadena(contrasenia, sizeof(contrasenia) - 1);

    if(validarUsuarioContrasenia(usuario, contrasenia) == true){

        if(esAdministradorPrincipal(usuario) == true){

            mostrarTexto("PROCEDA A CARGAR LOS DATOS DEL NUEVO ADMINISTRADOR");

            int id = obtenerProximoID();
            registro.cargar(id);

            /// VALIDO EL DNI
            if(validarDni(registro.getDni()) == true){
                return Administrador();
            }

            /// VALIDO EL NOMBRE DE USUARIO DEL ADMINISTRADOR
            if(validarUsuario(registro.getUsuario()) == true){
                return Administrador();
            }

            registro.setEstado(false);

            return registro;
        }
        else{
            mostrarTexto("< ERROR: NO TIENE LOS PERMISOS NECESARIOS >");
        }
    }
    else{
        mostrarTexto("< ERROR: NO EXISTE EL ADMINISTRADOR EN EL SISTEMA >");
    }

    return Administrador();
}

bool ManagerAdministradores::altaAdministrador(char *dniAdministrador){

    Administrador registro;
    ArchivoAdministradores archivo;

    if( stricmp(dniAdministrador, "NADA") == 0){
        registro = cargarAdministrador();
    }
    else{
        registro = cargarAdministrador(dniAdministrador);
    }

    if(registro.getIdAdministrador() == 0){
        return false;
    }

    if(archivo.guardar(registro) == true){
        return true;
    }

    return false;
}

bool ManagerAdministradores::altaLogica(const char *dni){

    Administrador registro;
    ArchivoAdministradores archivo;

    int pos = obtenerID(dni) - 1;
    if(pos == -1){
        return false;
    }

    registro = archivo.leer(pos);

    registro.setEstado(true);

    return archivo.editar(registro, pos);
}

bool ManagerAdministradores::bajaLogica(const char *dni){

    Administrador registro;
    ArchivoAdministradores archivo;

    int pos = obtenerID(dni) - 1;
    if(pos == -1){
        return false;
    }

    registro = archivo.leer(pos);

    registro.setEstado(false);

    return archivo.editar(registro, pos);
}

void ManagerAdministradores::mostrarRegistros(Administrador *registros, int tam){

    for(int i=0; i<tam; i++){
        registros[i].mostrar();
        std::cout << std::endl;
    }
}

/// ------------------------------------------------ MÉTODOS "ABML" ------------------------------------------------

bool ManagerAdministradores::listadoPorID(){

    ArchivoAdministradores archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE PASAJEROS DEL ARCHIVO "administradores.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0){
        /// EL ARCHIVO "administradores.dat" NO TIENE REGISTROS
        return false;
    }

    Administrador *registros = new Administrador[tam];
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
