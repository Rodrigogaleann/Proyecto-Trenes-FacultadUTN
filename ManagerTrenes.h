#pragma once
#include "Tren.h"

class ManagerTrenes{

    public:
        /// METODOS GENERALES
        bool cargarVector(Tren *registros, int tam);
        int obtenerProximoID();
        Tren obtenerTren(int idTren);

        bool verificarAsientosDisponibles(int idTren);
        Tren cambiarEstadoAsientos(Tren registro, int pos);
        bool ocuparAsiento(int idTren);
        bool revisarEspacioTren(Tren registro);

        bool reiniciarTrenes();
        Tren reiniciarAsientos(Tren registro);

        int mostrarAsientos(Tren registro);

        /// METODOS DE INFORMES

        int obtenerCantidadTrenesOperativos();
        int obtenerCantidadTrenesNoOperativos();
        float obtenerOcupacionPromedio();

        /// METODOS DE VALIDACION
        bool validarIdTren(int id);
        bool validarEstado(int id);

        /// METODOS DE COINCIDENCIAS
        int coincidenciasID(int id);
        int coincidenciasEstado(bool estado);

        /// METODOS DE ORDENAMIENTO
        bool ordenarPorIdTren(Tren *registros, int tam);
        bool ordenarPorEstado(Tren *registros, int tam);

        /// METODOS "ABML"
        Tren cargarTren();
        Tren editarTren();

        bool altaTren();
        bool modificacionTren();

        bool altaLogica(int id);
        bool bajaLogica(int id);

        void mostrarRegistros(Tren *registros, int tam);

        /// LISTADOS
        bool listadoPorID();
        bool listadoPorEstado();

        /// CONSULTAS
        bool consultaPorID();
        bool consultaPorEstado();

        /// INFORMES
        bool informeCantidadTrenesOperativos();
        bool informeCantidadTrenesNoOperativos();
        bool informeOcupacionPromedio();
};
