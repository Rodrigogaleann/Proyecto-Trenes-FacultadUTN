#pragma once

#include "Boleto.h"
#include "Estacion.h"

class ManagerBoletos{

    public:
        /// METODOS GENERALES
        bool cargarVector(Boleto *registros, int tam);
        int obtenerProximoIdBoleto();
        Boleto obtenerBoleto(int id);

        float obtenerTotalRecaudado();

        bool obtenerVentasPorEstacionOrigen(int *v, int tamEstaciones);
        bool obtenerVentasPorEstacionDestino(int *v, int tamEstaciones);
        int obtenerIdEstacionMayorVentas(int *v, int tamEstaciones);
        int obtenerCantidadEstacionMayorVentas(int *v, int tamEstaciones);
        Estacion obtenerEstacionOrigenConMayorVentas();
        Estacion obtenerEstacionDestinoConMayorVentas();

        int obtenerIdBoletoMasCaro();
        float obtenerValorBoletoMasCaro();

        bool confirmarCompra(Boleto registro);
        bool reiniciarTrenes();

        /// METODOS DE VALIDACION
        bool validarIdBoleto(int id);
        bool validarIdTren(int id);
        bool validarDni(const char *dni);
        bool validarEstacionOrigen(const char *nombreEstacion);
        bool validarEstacionDestino(const char *nombreEstacion);
        bool validarPrecioPagado(float precioPagado);

        /// METODOS DE COINCIDENCIAS
        int coincidenciasIdBoleto(int idBoleto);
        int coincidenciasIdTren(int idTren);
        int coincidenciasDniPasajero(const char *dni);
        int coincidenciasEstacionOrigen(const char *nombreEstacion);
        int coincidenciasEstacionDestino(const char *nombreEstacion);
        int coincidenciasPrecioPagado(float precioPagado);
        int coincidenciasFecha(time_t fecha); /// TODO

        /// METODOS DE ORDENAMIENTO
        bool ordenarPorIdBoleto(Boleto *registros, int tam);
        bool ordenarPorIdTren(Boleto *registros, int tam);
        bool ordenarPorDniPasajero(Boleto *registros, int tam);
        bool ordenarPorEstacionOrigen(Boleto *registros, int tam);
        bool ordenarPorEstacionDestino(Boleto *registros, int tam);
        bool ordenarPorPrecioPagado(Boleto *registros, int tam);
        bool ordenarPorFecha(Boleto *registros, int tam); /// TODO

        /// METODOS ABML
        Boleto cargarBoleto();
        Boleto editarBoleto();

        bool altaBoleto();
        bool modificacionBoleto();

        void mostrarRegistros(Boleto *registros, int tam);

        /// LISTADOS
        bool listadoPorIdBoleto();
        bool listadoPorIdTren();
        bool listadoPorDniPasajero();
        bool listadoPorEstacionOrigen();
        bool listadoPorEstacionDestino();
        bool listadoPorPrecioPagado();
        bool listadoPorFecha(); /// TODO

        /// CONSULTAS
        bool consultaPorIdBoleto();
        bool consultaPorIdTren();
        bool consultaPorDniPasajero();
        bool consultaPorEstacionOrigen();
        bool consultaPorEstacionDestino();
        bool consultaPorPrecioPagado();

        /// INFORMES
        bool informeTotalBoletosVendidos();
        bool informeTotalRecaudado();
        bool informeEstacionOrigenConMayorVentas();
        bool informeEstacionDestinoConMayorVentas();
        bool informeBoletoMasCaro();
};
