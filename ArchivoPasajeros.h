#pragma once

#include "Pasajero.h"

#include <string>

class ArchivoPasajeros{

    private:
        std::string _nombreArchivo;

    public:
        /// CONSTRUCTORES
        ArchivoPasajeros();
        ArchivoPasajeros(std::string nombreArchivo);

        /// METODOS "ABML"
        bool guardar(Pasajero registro);
        bool editar (Pasajero registro, int pos);
        Pasajero leer(int pos);
        int getCantidadRegistros();

        /// CONFIGURACIONES
        bool copiaDeSeguridad();
        bool restaurarCopiaDeSeguridad();
        bool exportarCSV();
};
