#include "Tren.h"

#include "FuncionesGlobales.h"

#include <iostream>
#include <string>
#include <cstring>

/// ---------- CONSTRUCTORES ----------

Tren::Tren(){
    _idTren = 0;
    _estado = 0;
    for(int i=0; i<15; i++){
        _capacidadDisponible[i] = false;
    }
}

Tren::Tren(int id){
    setIDTren(id);
    setEstado(true);
    for(int i=0; i<15; i++){
        _capacidadDisponible[i] = true;
    }
}

/// ---------- MÉTODOS GET ----------

int Tren::getIDTren(){
    return _idTren;
}

bool Tren::getCapacidadDisponible(int pos){
    return _capacidadDisponible[pos];
}

bool Tren::getEstado(){
    return _estado;
}

/// ---------- MÉTODOS SET ----------

void Tren::setIDTren(int id){
    _idTren = id;
}

void Tren::setCapacidadDisponible(int pos, bool estado){
    _capacidadDisponible[pos] = estado;
}

void Tren::setEstado(bool estado){
    _estado = estado;
}

/// ---------- MÉTODOS GENERALES ----------

void Tren::cargar(int id){
    if(id == 0){
        std::cout << "ID: ";
        std::cin >> _idTren;
    }
    else{
        _idTren = id;
    }

    _estado = true;

    for(int i=0; i<getCantidadAsientos(); i++){
        _capacidadDisponible[i] = true;
    }
}

void Tren::mostrar(){
    std::cout << "ID: " << getIDTren() << std::endl;
    std::cout << "ESTADO: " << binarioActivo(getEstado()) << std::endl;
    std::cout << "DISPONIBILIDAD DE ASIENTOS: " << std::endl;
    for(int i=0; i<getCantidadAsientos(); i++){
        std::cout << "- " << i + 1 << "# " << binarioDisponible(getCapacidadDisponible(i)) << std::endl;
    }
}

std::string Tren::toCSV(){

    std::string str = std::to_string(getIDTren()) + "," + binarioActivo(getEstado());

    for(int i=0; i<getCantidadAsientos(); i++){
        str += "," + binarioDisponible(getCapacidadDisponible(i));
    }

    return str;
}

int Tren::getCantidadAsientos(){
    return sizeof(_capacidadDisponible);
}
