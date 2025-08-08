#pragma once

class MenuTarifas{

    public:

        /// ---------- FUNCIONES DE MENU ----------
        void Menu();
        void SubMenu_Listados();
        void SubMenu_Consultas();
        void SubMenu_Informes();

        /// ---------- FUNCIONES "ABML" ----------
        void Cargar();
        void Editar();

        /// ---------- LISTADOS ----------
        void ListadoPorId();
        void ListadoPorEstacionOrigen();
        void ListadoPorEstacionDestino();
        void ListadoPorValorTarifaASC();
        void ListadoPorValorTarifaDSC();

        /// ---------- CONSULTAS ----------
        void ConsultaPorId();
        void ConsultaPorEstacion();
        void ConsultaPorValorTarifa();

        /// ---------- INFORMES ----------
        void InformeTarifaMasAlta();
        void InformeTarifaMasBaja();
        void InformePromedioValorTarifas();
};
