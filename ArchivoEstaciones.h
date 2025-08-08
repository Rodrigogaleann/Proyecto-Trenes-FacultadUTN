#pragma once
#include "Estacion.h"
#include <string>

class ArchivoEstaciones{

    private:
        std::string _nombreArchivo;

    public:
        /// CONSTRUCTORES
        ArchivoEstaciones();
        ArchivoEstaciones(std::string nombreArchivo);

        /// METODOS "ABML"
        bool guardar(Estacion registro);
        bool editar(Estacion registro, int pos);
        Estacion leer(int pos);
        int getCantidadRegistros();

        /// CONFIGURACIONES
        bool copiaDeSeguridad();
        bool restaurarCopiaDeSeguridad();
        bool exportarCSV();
};
