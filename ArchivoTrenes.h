#pragma once
#include "Tren.h"
#include <string>

class ArchivoTrenes{

    private:
        std::string _nombreArchivo;

    public:
        /// CONSTRUCTORES
        ArchivoTrenes();
        ArchivoTrenes(std::string nombreArchivo);

        /// METODOS "ABML"
        bool guardar(Tren registro);
        bool editar(Tren registro, int pos);
        Tren leer(int pos);
        int getCantidadRegistros();

        /// CONFIGURACIONES
        bool copiaDeSeguridad();
        bool restaurarCopiaDeSeguridad();
        bool exportarCSV();
};

