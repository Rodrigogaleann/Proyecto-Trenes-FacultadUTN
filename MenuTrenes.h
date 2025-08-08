#pragma once

class MenuTrenes{

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
        void ListadoPorEstado();

        /// ---------- CONSULTAS ----------
        void ConsultaPorId();
        void ConsultaPorEstado();

        /// ---------- INFORMES ----------
        void InformeCantidadTrenesOperativos();
        void InformeCantidadTrenesNoOperativos();
        void InformeOcupacionPromedioDelDia();
};

