#pragma once

class MenuEstaciones{

    public:

        /// ---------- FUNCIONES DE MENU ----------
        void Menu();
        void SubMenu_Listados();
        void SubMenu_Consultas();
        void SubMenu_Informes();

        /// ---------- FUNCIONES "ABML" ----------
        void Cargar();
        void Editar();
        void AltaLogica();
        void BajaLogica();

        /// ---------- LISTADOS ----------
        void ListadoPorId();
        void ListadoPorNombre();
        void ListadoPorEstado();

        /// ---------- CONSULTAS ----------
        void ConsultaPorId();
        void ConsultaPorNombre();
        void ConsultaPorEstado();

        /// ---------- INFORMES ----------
        void InformeTotalEstacionesRegistradas();
        void InformeTotalEstacionesActivas();
        void InformeTotalEstacionesInactivas();
};
