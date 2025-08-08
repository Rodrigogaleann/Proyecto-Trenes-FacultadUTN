#pragma once

#include "Pasajero.h"

class ManagerPasajeros{

    public:
        /// METODOS GENERALES
        bool cargarVector(Pasajero *registros, int tam);
        int obtenerProximoID();
        int obtenerID(const char *dni);
        int obtenerTotalActivos();
        int obtenerTotalInactivos();
        Pasajero obtenerPasajeroPorDNI(const char* dni); ///retornar un pasajero

        /// METODOS DE VALIDACIÓN
        bool validarID(int id);
        bool validarNombre(const char *nombre);
        bool validarApellido(const char *apelldo);
        bool validarDni(const char *dni);
        bool validarEmail(const char *email);
        bool validarEstado(bool estado);

        /// METODOS DE COINCIDENCIAS
        int coincidenciasID(int id);
        int coincidenciasNombre(const char *nombre);
        int coincidenciasApellido(const char *apellido);
        int coincidenciasDni(const char *dni);
        int coincidenciasEmail(const char *email);
        int coincidenciasEstado(bool estado);

        /// METODOS DE ORDENAMIENTO
        bool ordenarPorID(Pasajero *registros, int tam);
        bool ordenarPorNombre(Pasajero *registros, int tam);
        bool ordenarPorApellido(Pasajero *registros, int tam);
        bool ordenarPorDni(Pasajero *registros, int tam);
        bool ordenarPorEmail(Pasajero *registros, int tam);
        bool ordenarPorEstado(Pasajero *registro, int tam);

        /// METODOS "ABML"
        Pasajero cargarPasajero(char *dniPasajero = (char*)"NADA");
        Pasajero editarPasajero();

        bool altaPasajero(char *dniPasajero = (char*)"NADA");
        bool modificacionPasajero();

        bool altaLogica(const char *dni);
        bool bajaLogica(const char *dni);

        void mostrarEncabezado();
        void mostrarRegistros(Pasajero *registros, int tam);

        /// LISTADOS
        bool listadoPorID();
        bool listadoPorNombre();
        bool listadoPorApellido();
        bool listadoPorDni();
        bool listadoPorEmail();
        bool listadoPorEstado();

        /// CONSULTAS
        bool consultaPorID();
        bool consultaPorNombre();
        bool consultaPorApellido();
        bool consultaPorDni();
        bool consultaPorEmail();
        bool consultaPorEstado();

        /// INFORMES
        bool informeTotalPasajerosRegistrados();
        bool informeTotalPasajerosActivos();
        bool informeTotalPasajerosInactivos();
};
