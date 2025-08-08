#pragma once

#include <string>

class Administrador{

    private:
        int _idAdministrador;
        char _nombre[30];
        char _apellido[30];
        char _dni [10];
        char _usuario[30];
        char _contrasenia[30];
        bool _estado;

    public:

        /// CONSTRUCTORES
        Administrador();
        Administrador(int id, const char *dni, const char *nombre, const char *apellido, const char *usuario, const char *contrasenia, bool estado);

        /// METODOS "GET"
        int getIdAdministrador();
        const char *getNombre();
        const char *getApellido();
        const char *getDni();
        const char *getUsuario();
        const char *getContrasenia();
        bool getEstado();

        /// METODOS "SET"
        void setIdAdministrador(int id);
        void setNombre(const char *nombre);
        void setApellido(const char *apellido);
        void setDni(const char *dni);
        void setUsuario(const char *apellido);
        void setContrasenia(const char *constrasenia);
        void setEstado(bool estado);

        /// METODOS GENERALES
        void cargar(int id = 0, char *dni = (char*)"NADA");
        void mostrar();
        std::string toCSV();

};
