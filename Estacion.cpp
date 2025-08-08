#include "Estacion.h"

#include "FuncionesGlobales.h"

#include <iostream>
#include <string>
#include <cstring>

/// ---------- CONSTRUCTORES ----------

Estacion::Estacion(){
    setIDEstacion(0);
    setNombreEstacion("");
    setEstado(false);
}

Estacion::Estacion(int id, const char *nombreEstacion, bool estado){
    setIDEstacion(id);
    setNombreEstacion(nombreEstacion);
    setEstado(estado);
}

/// ---------- MÉTODOS GET ----------

int Estacion::getIDEstacion(){
    return _idEstacion;
}

const char *Estacion::getNombreEstacion(){
    return _nombreEstacion;
}

bool Estacion::getEstado(){
    return _estado;
}

/// ---------- MÉTODOS SET ----------

void Estacion::setIDEstacion(int id){
    _idEstacion = id;
}

void Estacion::setNombreEstacion(const char *nombreEstacion){
    strcpy(_nombreEstacion, nombreEstacion);
}

void Estacion::setEstado(bool estado){
    _estado = estado;
}

/// ---------- MÉTODOS GENERALES ----------

void Estacion::cargar(int id, char *nombreEstacion){
    if(id == 0){
        std::cout << "ID: ";
        std::cin >> _idEstacion;
    }
    else{
        _idEstacion = id;
    }

    if(strcmp(nombreEstacion, "NADA") == 0){
        std::cout << "NOMBRE DE ESTACION: ";
        cargarCadena(_nombreEstacion, sizeof(_nombreEstacion) - 1);
    }
    else{
        strcpy(_nombreEstacion, nombreEstacion);
    }

    _estado = true;
}

void Estacion::mostrar(){
    std::cout << "ID: " << getIDEstacion() << std::endl;
    std::cout << "NOMBRE: " << getNombreEstacion() << std::endl;
    std::cout << "ESTADO (1-ACTIVA / 0-INACTIVA): " << getEstado() << std::endl;
}

std::string Estacion::toCSV(){
    std::string str = std::to_string(getIDEstacion()) + "," + getNombreEstacion() + "," + binarioActivo(getEstado());

    return str;
}
