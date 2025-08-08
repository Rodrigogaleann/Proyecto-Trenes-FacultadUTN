#pragma once

class ManagerConfiguraciones{

    public:
        /// REALIZAR COPIAS DE SEGURIDAD
        bool backupPasajeros();
        bool backupTrenes();
        bool backupEstaciones();
        bool backupTarifas();
        bool backupBoletos();
        int backupTodos();

        /// RESTAURAR COPIAS DE SEGURIDAD
        bool restaurarPasajeros();
        bool restaurarTrenes();
        bool restaurarEstaciones();
        bool restaurarTarifas();
        bool restaurarBoletos();
        int restaurarTodos();

        /// EXPORTAR EN FORMATO .CSV
        bool exportarPasajeros();
        bool exportarTrenes();
        bool exportarEstaciones();
        bool exportarTarifas();
        bool exportarBoletos();
        int exportarTodos();
};
