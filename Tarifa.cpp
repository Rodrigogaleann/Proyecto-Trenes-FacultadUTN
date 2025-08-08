#include "Tarifa.h"

#include "Estacion.h"
#include "ManagerEstaciones.h"

#include <iostream>
#include <string>
#include <cstring>

/// ---------- CONSTRUCTORES ----------

Tarifa::Tarifa(){
    setIDTarifa(0);
    setEstacionOrigen(Estacion());
    setEstacionDestino(Estacion());
    setTarifa(0);
}

Tarifa::Tarifa(int idTarifa, Estacion origen, Estacion destino, float tarifa){
    setIDTarifa(idTarifa);
    setEstacionOrigen(origen);
    setEstacionDestino(destino);
    setTarifa(tarifa);
}

/// ---------- MÉTODOS GET ----------

int Tarifa::getIDTarifa(){
    return _idTarifa;
}

Estacion Tarifa::getEstacionOrigen(){
    return _estacionOrigen;
}

Estacion Tarifa::getEstacionDestino(){
    return _estacionDestino;
}

float Tarifa::getTarifa(){
    return _tarifa;
}

/// ---------- MÉTODOS SET ----------

void Tarifa::setIDTarifa(int id){
    _idTarifa = id;
}

void Tarifa::setEstacionOrigen(Estacion origen){
    _estacionOrigen = origen;
}

void Tarifa::setEstacionDestino(Estacion destino){
    _estacionDestino = destino;
}

void Tarifa::setTarifa(float tarifa){
    _tarifa = tarifa;
}

/// ---------- MÉTODOS GENERALES ----------

float Tarifa::calcularValorTarifa(Estacion origen, Estacion destino){

    float valor;

    if(origen.getIDEstacion() < destino.getIDEstacion()){
        valor = 50 + 100*(destino.getIDEstacion() - origen.getIDEstacion());
    }
    if(origen.getIDEstacion() > destino.getIDEstacion()){
        valor = 50 + 100*(origen.getIDEstacion() - destino.getIDEstacion());
    }

    return valor;
}

void Tarifa::cargar(int id){

    if(id == 0){
        std::cout << "ID: ";
        std::cin >> _idTarifa;
    }
    else{
        _idTarifa = id;
    }

    std::cout << "- ESTACION DE ORIGEN:" << std::endl;
    _estacionOrigen.cargar();
    std::cout << "- ESTACION DE DESTINO:" << std::endl;
    _estacionDestino.cargar();

    _tarifa = calcularValorTarifa(_estacionOrigen, _estacionDestino);
}

void Tarifa::mostrar(){
    std::cout << "ID: " << getIDTarifa() << std::endl;
    std::cout << "TARIFA: $" << getTarifa() << std::endl;
    std::cout << std::endl;
    std::cout << "- ESTACION DE ORIGEN:" << std::endl;
    getEstacionOrigen().mostrar();
    std::cout << std::endl;
    std::cout << "- ESTACION DE DESTINO:" << std::endl;
    getEstacionDestino().mostrar();
}

std::string Tarifa::toCSV(){
    std::string str = std::to_string(getIDTarifa()) + "," + getEstacionOrigen().toCSV() + "," + getEstacionDestino().toCSV() + "," + std::to_string(getTarifa());

    return str;
}
