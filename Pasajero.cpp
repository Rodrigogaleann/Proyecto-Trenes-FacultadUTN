#include "Pasajero.h"

#include "FuncionesGlobales.h"

#include <iostream>
#include <string>
#include <cstring>

/// ---------- CONSTRUCTORES ----------

Pasajero::Pasajero(){
    setIDPasajero(0);
    setNombre("");
    setApellido("");
    setDni("");
    setEmail("");
    setEstado(false);
}

Pasajero::Pasajero(int id, const char* nombre, const char* apellido, const char* dni, const char* email, bool estado){
    setIDPasajero(id);
    setNombre(nombre);
    setApellido(apellido);
    setDni(dni);
    setEmail(email);
    setEstado(estado);
}

/// ---------- MÉTODOS GET ----------

int Pasajero::getIDPasajero(){
    return _idPasajero;
}

const char *Pasajero::getNombre(){
    return _nombre;
}

const char *Pasajero::getApellido(){
    return _apellido;
}

const char *Pasajero::getDni(){
    return _dni;
}

const char *Pasajero::getEmail(){
    return _email;
}

bool Pasajero::getEstado(){
    return _estado;
}

/// ---------- MÉTODOS SET ----------

void Pasajero::setIDPasajero(int id){
    _idPasajero = id;
}

void Pasajero::setNombre(const char *nombre){
    strcpy(_nombre, nombre);
}

void Pasajero::setApellido(const char *apellido){
    strcpy(_apellido, apellido);
}

void Pasajero::setDni(const char *dni){
    strcpy(_dni, dni);
}

void Pasajero::setEmail(const char *email){
    strcpy(_email, email);
}

void Pasajero::setEstado(bool estado){
    _estado = estado;
}

/// ---------- MÉTODOS GENERALES ----------

void Pasajero::cargar(int id, char *dni){

    if(id == 0){
        std::cout << "ID: ";
        std::cin >> _idPasajero;
    }
    else{
        _idPasajero = id;
    }

    if(stricmp(dni, "NADA") == 0){
        std::cout << "DNI: ";
        cargarCadena(_dni, sizeof(_dni) - 1);
    }
    else{
        strcpy(_dni, dni);
    }

    std::cout << "NOMBRE: ";
    cargarCadena(_nombre, sizeof(_nombre) - 1);
    std::cout << "APELLIDO: ";
    cargarCadena(_apellido, sizeof(_apellido) - 1);
    std::cout << "EMAIL: ";
    cargarCadena(_email, sizeof(_email) - 1);

    _estado = true;
}

void Pasajero::mostrar(){
    std::cout << "ID: " << getIDPasajero() << std::endl;
    std::cout << "NOMBRE: " << getNombre() << std::endl;
    std::cout << "APELLIDO: " << getApellido() << std::endl;
    std::cout << "DNI: " << getDni() << std::endl;
    std::cout << "EMAIL: " << getEmail() << std::endl;
    std::cout << "ESTADO: " << getEstado() << std::endl;
}

std::string Pasajero::toCSV(){

    std::string str = std::to_string(getIDPasajero()) + "," + getNombre() + "," + getApellido() + "," + getDni() + "," + getEmail() + "," + binarioActivo(getEstado());

    return str;
}
