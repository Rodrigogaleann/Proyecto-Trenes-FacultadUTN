#pragma once
#include "Administrador.h"

#include <string>

class ArchivoAdministradores{
    private:
        std::string _nombreArchivo;
    public:
        /// CONSTRUCTORES
        ArchivoAdministradores();
        ArchivoAdministradores(std::string nombreArchivo);

        /// METODOS "ABML"
        bool guardar(Administrador registro);
        bool editar(Administrador registro, int pos);
        Administrador leer(int pos);
        int getCantidadRegistros();

        /// CONFIGURACIONES
        bool copiaDeSeguridad();
        bool restaurarCopiaDeSeguridad();
        bool exportarCSV();
};
