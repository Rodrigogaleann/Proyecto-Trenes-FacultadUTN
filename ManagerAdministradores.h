#pragma once

#include "Administrador.h"

class ManagerAdministradores{

    public:
        /// METODOS GENERALES
        bool cargarVector(Administrador *registros, int tam);
        int obtenerProximoID();
        int obtenerID(const char *dni);
        int obtenerIdConUsuario(const char *usuario);
        Administrador obtenerAdministradorConDNI(const char* dni);

        /// METODOS DE VALIDACIÓN
        bool validarID(int id);
        bool validarDni(const char *dni);
        bool validarUsuario(const char *usuario);
        bool validarUsuarioContrasenia(const char *usuario, const char *contrasenia);
        bool esAdministradorPrincipal(const char *usuario);

        /// METODOS DE ORDENAMIENTO
        bool ordenarPorID(Administrador *registros, int tam);

        /// METODOS "ABML"

        Administrador cargarPrimerAdministrador();
        Administrador cargarAdministrador(char *dniAdministrador = (char*)"NADA");

        bool altaAdministrador(char *dniPasajero = (char*)"NADA");

        bool altaLogica(const char *dni);
        bool bajaLogica(const char *dni);

        void mostrarRegistros(Administrador *registros, int tam);

        /// LISTADOS
        bool listadoPorID();


};
