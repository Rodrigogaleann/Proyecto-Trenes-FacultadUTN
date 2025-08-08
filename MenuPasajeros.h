#pragma once

class MenuPasajeros{

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
        void ListadoPorApellido();
        void ListadoPorDni();
        void ListadoPorEmail();
        void ListadoPorEstado();

        /// ---------- CONSULTAS ----------
        void ConsultaPorId();
        void ConsultaPorNombre();
        void ConsultaPorApellido();
        void ConsultaPorDni();
        void ConsultaPorEmail();
        void ConsultaPorEstado();

        /// ---------- INFORMES ----------
        void InformeTotalPasajerosRegistrados();
        void InformeTotalPasajerosActivos();
        void InformeTotalPasajerosInactivos();
};
