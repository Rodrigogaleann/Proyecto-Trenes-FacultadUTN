#pragma once
#include "Boleto.h"
#include <string>

class ArchivoBoletos{

    private:
        std::string _nombreArchivo;

    public:
        /// CONSTRUCTORES
        ArchivoBoletos();
        ArchivoBoletos(std::string nombreArchivo);

        /// METODOS "ABML"
        bool guardar(Boleto registro);
        bool editar(Boleto registro, int pos);
        Boleto leer(int pos);
        int getCantidadRegistros();

        /// CONFIGURACIONES
        bool copiaDeSeguridad();
        bool restaurarCopiaDeSeguridad();
        bool exportarCSV();
};
