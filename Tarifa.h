#pragma once
#include <string>

#include "Estacion.h"

class Tarifa{

    private:
        int _idTarifa;
        Estacion _estacionOrigen;
        Estacion _estacionDestino;
        float _tarifa;

    public:
        /// CONSTRUCTORES
        Tarifa();
        Tarifa(int idTarifa, Estacion origen, Estacion destino, float tarifa);

        /// METODOS "GET"
        int getIDTarifa();
        Estacion getEstacionOrigen();
        Estacion getEstacionDestino();
        float getTarifa();

        /// METODOS "SET"
        void setIDTarifa(int id);
        void setEstacionOrigen(Estacion origen);
        void setEstacionDestino(Estacion destino);
        void setTarifa(float tarifa);

        /// METODOS GENERALES
        float calcularValorTarifa(Estacion origen, Estacion destino);
        void cargar(int id = 0);
        void mostrar();
        std::string toCSV();
};
