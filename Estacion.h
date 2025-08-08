#pragma once
#include <string>

class Estacion{

    private:
        int _idEstacion;
        char _nombreEstacion[30];
        bool _estado;

    public:
        /// CONSTRUCTORES
        Estacion();
        Estacion(int id, const char *nombre, bool estado);

        /// METODOS "GET"
        int getIDEstacion();
        const char *getNombreEstacion();
        bool getEstado();

        
        void setIDEstacion(int id);
        void setNombreEstacion(const char *nombreEstacion);
        void setEstado(bool estado);


        void cargar(int id = 0, char *dni = (char*)"NADA");
        void mostrar();
        std::string toCSV();
};
