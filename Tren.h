#pragma once
#include <string>

class Tren{

    private:
        int _idTren;
        bool _capacidadDisponible[15];
        bool _estado;

    public:
        /// CONSTRUCTORES
        Tren();
        Tren(int id);

        /// METODOS "GET"
        int getIDTren();
        bool getCapacidadDisponible(int pos);
        bool getEstado();

        /// METODOS "SET"
        void setIDTren(int id);
        void setCapacidadDisponible(int pos, bool estado);
        void setEstado(bool estado);

        /// METODOS GENERALES
        void cargar(int id = 0);
        void mostrar();
        std::string toCSV();

        int getCantidadAsientos();
};
