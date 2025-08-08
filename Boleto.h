#pragma once

#include "Estacion.h"

#include <string>
#include <ctime>

class Boleto{

    private:
        int _idBoleto;
        int _idTren;
        char _dniPasajero[10];
        Estacion _estacionOrigen;
        Estacion _estacionDestino;
        float _precioPagado;
        time_t _fechaHoraSistema;

    public:
        /// CONSTRUCTORES
        Boleto();
        Boleto(int idBoleto, int idTren, const char *dniPasajero, Estacion estacionOrigen, Estacion estacionDestino, float precioPagado);

        /// METODOS "GET"
        int getIDBoleto();
        int getIDTren();
        const char *getDniPasajero();
        Estacion getEstacionOrigen();
        Estacion getEstacionDestino();
        float getPrecioPagado();
        time_t &getFechaHoraSistema();

        /// METODOS "SET"
        void setIDBoleto(int id);
        void setIDTren(int id);
        void setDniPasajero(const char *dni);
        void setEstacionOrigen(Estacion origen);
        void setEstacionDestino(Estacion destino);
        void setPrecioPagado(float precioPagado);
        void setFechaHoraSistema(time_t fechaHoraSistema);

        /// METODOS GENERALES
        void mostrar();
        std::string toCSV();
};
