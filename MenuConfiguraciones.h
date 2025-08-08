#pragma once

class MenuConfiguraciones{

    public:

        /// ---------- FUNCIONES DE MENU ----------
        void Menu();
        void SubMenu_RealizarBackups();
        void SubMenu_RestaurarBackups();
        void SubMenu_ExportarCSV();

        /// ---------- REALIZAR COPIAS DE SEGURIDAD ----------
        void BackupPasajeros();
        void BackupTrenes();
        void BackupEstaciones();
        void BackupTarifas();
        void BackupBoletos();
        void BackupTodos();

        /// ---------- RESTAURAR COPIAS DE SEGURIDAD ----------
        void RestaurarPasajeros();
        void RestaurarTrenes();
        void RestaurarEstaciones();
        void RestaurarTarifas();
        void RestaurarBoletos();
        void RestaurarTodos();

        /// ---------- EXPORTAR EN FORMATO .CSV ----------
        void ExportarPasajeros();
        void ExportarTrenes();
        void ExportarEstaciones();
        void ExportarTarifas();
        void ExportarBoletos();
        void ExportarTodos();
};
