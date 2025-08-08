#pragma once
#include <string>

class Pasajero{

    private:
        int _idPasajero;
        char _nombre[30];
        char _apellido[30];
        char _dni[10];
        char _email[50];
        bool _estado;

    public:
        /// CONSTRUCTORES
        Pasajero();
        Pasajero(int id, const char* nombre, const char* apellido, const char* dni, const char* email, bool estado);

        /// METODOS "GET"
        int getIDPasajero();
        const char* getNombre();
        const char* getApellido();
        const char* getDni();
        const char* getEmail();
        bool getEstado();

        /// METODOS "SET"
        void setIDPasajero(int id);
        void setNombre(const char* nombre);
        void setApellido(const char* apellido);
        void setDni(const char* dni);
        void setEmail(const char* email);
        void setEstado(bool estado);

        /// METODOS GENERALES
        void cargar(int id = 0, char *dni = (char*)"NADA");
        void mostrar();
        std::string toCSV();
};
