#include "Boleto.h"

#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

/// ---------- CONSTRUCTORES ----------

Boleto::Boleto(){
    setIDBoleto(0);
    setIDTren(0);
    setDniPasajero("");
    setEstacionOrigen(Estacion());
    setEstacionDestino(Estacion());
    setPrecioPagado(0);
    setFechaHoraSistema(0);
}

Boleto::Boleto(int idBoleto, int idTren, const char *dniPasajero, Estacion estacionOrigen, Estacion estacionDestino, float precioPagado){

    time_t fechaHoraSistema = time(nullptr);

    setIDBoleto(idBoleto);
    setIDTren(idTren);
    setDniPasajero(dniPasajero);
    setEstacionOrigen(estacionOrigen);
    setEstacionDestino(estacionDestino);
    setPrecioPagado(precioPagado);
    setFechaHoraSistema(fechaHoraSistema);
}

/// ---------- MÉTODOS GET ----------

int Boleto::getIDBoleto(){
    return _idBoleto;
}

int Boleto::getIDTren(){
    return _idTren;
}

const char *Boleto::getDniPasajero(){
    return _dniPasajero;
}

Estacion Boleto::getEstacionOrigen(){
    return _estacionOrigen;
}

Estacion Boleto::getEstacionDestino(){
    return _estacionDestino;
}

float Boleto::getPrecioPagado(){
    return _precioPagado;
}

time_t &Boleto::getFechaHoraSistema(){
    return _fechaHoraSistema;
}

/// ---------- MÉTODOS SET ----------

void Boleto::setIDBoleto(int id){
    _idBoleto = id;
}

void Boleto::setIDTren(int id){
    _idTren = id;
}

void Boleto::setDniPasajero(const char *dni){
    strcpy(_dniPasajero, dni);
}

void Boleto::setEstacionOrigen(Estacion estacionOrigen){
    _estacionOrigen = estacionOrigen;
}

void Boleto::setEstacionDestino(Estacion estacionDestino){
    _estacionDestino = estacionDestino;
}

void Boleto::setPrecioPagado(float precioPagado){
    _precioPagado = precioPagado;
}

void Boleto::setFechaHoraSistema(time_t fechaHoraSistema){
    _fechaHoraSistema = fechaHoraSistema;
}

/// ---------- MÉTODOS GENERALES ----------

void Boleto::mostrar(){
    std::cout << "ID DE BOLETO: " << getIDBoleto() << std::endl;
    std::cout << "ID DE TREN: " << getIDTren() << std::endl;
    std::cout << "DNI: " << getDniPasajero() << std::endl;
    std::cout << "ESTACION DE ORIGEN:" << std::endl;
    getEstacionOrigen().mostrar();
    std::cout << "ESTACION DE DESTINO:" << std::endl;
    getEstacionDestino().mostrar();
    std::cout << "PRECIO PAGADO: $" << getPrecioPagado() << std::endl;
    std::cout << "FECHA: " << asctime(localtime(&getFechaHoraSistema())) << std::endl;
}

std::string Boleto::toCSV(){

    /// "ASCTIME" AGREGA UN "\n" AL FINAL
    std::string str = std::to_string(getIDBoleto()) + "," + std::to_string(getIDTren()) + "," + std::string(getDniPasajero()) + "," + getEstacionOrigen().toCSV() + "," + getEstacionDestino().toCSV() + "," + std::to_string(getPrecioPagado()) + "," + std::string(asctime(localtime(&getFechaHoraSistema())));

    return str;
}
