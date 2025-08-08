#pragma once

#include "Estacion.h"

class ManagerEstaciones{

    public:
        /// METODOS GENERALES
        bool cargarVector(Estacion *registros, int tam);
        int obtenerProximoIdEstacion();
        int obtenerIdEstacion(const char *nombreEstacion);
        Estacion obtenerEstacion(int id);
        Estacion obtenerEstacion(const char *nombreEstacion);
        int obtenerTotalActivas();
        int obtenerTotalInactivas();

        /// METODOS DE VALIDACION
        bool validarIdEstacion(int idEstacion);
        bool validarNombreEstacion(const char *nombreEstacion);
        bool validarEstado(const char *nombreEstacion);

        /// METODOS DE COINCIDENCIAS
        int coincidenciasID(int id);
        int coincidenciasNombre(const char *nombre);
        int coincidenciasEstado(bool estado);

        /// METODOS DE ORDENAMIENTO
        bool ordenarPorIdEstacion(Estacion *registros, int tam);
        bool ordenarPorNombre(Estacion *registros, int tam);
        bool ordenarPorEstado(Estacion *registros, int tam);

        /// METODOS "ABML"
        Estacion cargarEstacion();
        Estacion editarEstacion();

        bool altaEstacion();
        bool modificacionEstacion();

        bool altaLogica(const char *nombreEstacion);
        bool bajaLogica(const char *nombreEstacion);

        void mostrarEncabezado();
        void mostrarRegistros(Estacion *registros, int tam);

        /// LISTADOS
        bool listadoPorIdEstacion();
        bool listadoPorNombreEstacion();
        bool listadoPorEstado();

        /// CONSULTAS
        bool consultaPorIdEstacion();
        bool consultaPorNombreEstacion();
        bool consultaPorEstado();

        /// INFORMES
        bool informeTotalEstacionesRegistradas();
        bool informeTotalEstacionesActivas();
        bool informeTotalEstacionesInactivas();
};
