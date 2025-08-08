#include "Administrador.h"

#include "FuncionesGlobales.h"

#include <iostream>
#include <string>
#include <cstring>

/// ---------- CONSTRUCTORES ----------

Administrador::Administrador(){
    setIdAdministrador(0);
    setDni("");
    setNombre("");
    setApellido("");
    setUsuario("");
    setContrasenia("");
    setEstado(false);
}

Administrador::Administrador(int id, const char *dni, const char *nombre, const char *apellido, const char *usuario, const char *contrasenia, bool estado){
    setIdAdministrador(id);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setUsuario(usuario);
    setContrasenia(contrasenia);
    setEstado(estado);
}

/// ---------- MÉTODOS GET ----------

int Administrador::getIdAdministrador(){
    return _idAdministrador;
}

const char *Administrador::getNombre(){
    return _nombre;
}

const char *Administrador::getApellido(){
    return _apellido;
}

const char *Administrador::getDni(){
    return _dni;
}

const char *Administrador::getUsuario(){
    return _usuario;
}

const char *Administrador::getContrasenia(){
    return _contrasenia;
}

bool Administrador::getEstado(){
    return _estado;
}

/// ---------- MÉTODOS SET ----------

void Administrador::setIdAdministrador(int id){
    _idAdministrador = id;
}

void Administrador::setNombre(const char *nombre){
    strcpy(_nombre, nombre);
}

void Administrador::setApellido(const char *apellido){
    strcpy(_apellido, apellido);
}

void Administrador::setDni(const char *dni){
    strcpy(_dni, dni);
}

void Administrador::setUsuario(const char *usuario){
    strcpy(_usuario, usuario);
}

void Administrador::setContrasenia(const char *contrasenia){
    strcpy(_contrasenia, contrasenia);
}

void Administrador::setEstado(bool estado){
    _estado = estado;
}

/// ---------- MÉTODOS GENERALES ----------

void Administrador::cargar(int id, char *dni){

    if(id == 0){
        std::cout << "ID: ";
        std::cin >> id;
    }
    else{
        _idAdministrador = id;
    }

    if(stricmp(dni, "NADA") == 0){
        std::cout << "DNI: ";
        cargarCadena(_dni, sizeof(_dni) - 1);
    }
    else{
        strcpy(_dni, dni);
    }

    std::cout<<"NOMBRE: ";
    cargarCadena(_nombre, sizeof(_nombre) -1);
    std::cout<<"APELLIDO: ";
    cargarCadena(_apellido, sizeof(_apellido) -1);
    std::cout<<"NOMBRE DE USUARIO: ";
    cargarCadena(_usuario, sizeof(_usuario) -1);
    std::cout<<"CONTRASENIA: ";
    cargarCadena(_contrasenia, sizeof(_contrasenia) - 1);
}

void Administrador::mostrar(){
    std::cout << "ID: " << getIdAdministrador() << std::endl;
    std::cout << "DNI: " << getDni() << std::endl;
    std::cout << "NOMBRE: "<< getNombre() << std::endl;
    std::cout << "APELLIDO: "<< getApellido() << std::endl;
    std::cout << "USUARIO: "<< getUsuario() << std::endl;
    std::cout << "CONTRASENIA: "<< getContrasenia() << std::endl;
    std::cout << "ESTADO: " << getEstado() << std::endl;
}

std::string Administrador::toCSV(){

    std::string str = std::to_string(getIdAdministrador()) + "," + getDni() + "," + getNombre() + "," + getApellido() + "," + getUsuario() + "," + getContrasenia() + std::to_string(getEstado());

    return str;
}
