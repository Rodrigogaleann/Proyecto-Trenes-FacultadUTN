#pragma once
#include "Tarifa.h"
#include <string>

class ArchivoTarifas{

    private:
        std::string _nombreArchivo;

    public:
        /// CONSTRUCTORES
        ArchivoTarifas();
        ArchivoTarifas(std::string nombreArchivo);

        /// METODOS "ABML"
        bool guardar(Tarifa registro);
        bool editar(Tarifa registro, int pos);
        Tarifa leer(int pos);
        int getCantidadRegistros();

        /// CONFIGURACIONES
        bool copiaDeSeguridad();
        bool restaurarCopiaDeSeguridad();
        bool exportarCSV();
};
