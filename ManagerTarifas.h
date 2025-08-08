#pragma once

#include "Tarifa.h"

class ManagerTarifas{

    public:
        /// METODOS GENERALES
        bool cargarVector(Tarifa *registros, int tam);
        int obtenerProximoIdTarifa();
        int obtenerIdTarifa(Estacion origen, Estacion Destino);
        int obtenerIdEstacion(Estacion estacion);
        float obtenerTarifa(int idTarifa);
        float obtenerTarifa(Estacion origen, Estacion destino);

        float obtenerTarifaMasAlta();
        float obtenerTarifaMasBaja();
        float obtenerPromedioTarifas();

        /// METODOS DE VALIDACION
        bool validarIDTarifa(int idTarifa);
        bool validarEstacion(Estacion estacion);
        bool validarTarifa(float tarifa);

        /// METODOS DE COINCIDENCIAS
        bool coincidenciasID(int idTarifa);
        bool coincidenciasEstacion(Estacion estacion);
        bool coincidenciasTarifas(float tarifa);

        /// METODOS DE ORDENAMIENTO
        bool ordenarPorIdTarifa(Tarifa *registros, int tam);
        bool ordenarPorIdEstacionOrigen(Tarifa *registros, int tam);
        bool ordenarPorIdEstacionDestino(Tarifa *registros, int tam);
        bool ordenarPorTarifaASC(Tarifa *registros, int tam);
        bool ordenarPorTarifaDSC(Tarifa *registros, int tam);

        /// METODOS "ABML"
        Tarifa cargarTarifa();
        Tarifa editarTarifa();

        bool altaTarifa();
        bool modificacionTarifa();

        void mostrarEncabezado();
        void mostrarRegistros(Tarifa *registros, int tam);

        /// LISTADOS
        bool listadoPorIdTarifa();
        bool listadoPorIdEstacionOrigen();
        bool listadoPorIdEstacionDestino();
        bool listadoPorTarifaASC();
        bool listadoPorTarifaDSC();

        /// CONSULTAS
        bool consultaTarifaPorIdTarifa();
        bool consultaTarifaPorEstacion();
        bool consultaTarifa();

        /// INFORMES
        bool informeTarifaMasAlta();
        bool informeTarifaMasBaja();
        bool informePromedioDeTarifas();
};
