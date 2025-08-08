#pragma once

class MenuBoletos{

    public:

        /// ---------- FUNCIONES DE MENU ----------
        void Menu();
        void SubMenu_Listados();
        void SubMenu_Consultas();
        void SubMenu_Informes();

        /// ---------- FUNCIONES "ABML" ----------
        void Cargar();

        /// ---------- LISTADOS ----------
        void ListadoPorIdBoleto();
        void ListadoPorIdTren();
        void ListadoPorDniPasajero();
        void ListadoPorEstacionOrigen();
        void ListadoPorEstacionDestino();
        void ListadoPorPrecioPagado();
        void ListadoPorFecha();

        /// ---------- CONSULTAS ----------
        void ConsultaPorIdBoleto();
        void ConsultaPorIdTren();
        void ConsultaPorDniPasajero();
        void ConsultaPorEstacionOrigen();
        void ConsultaPorEstacionDestino();
        void ConsultaPorPrecioPagado();

        /// ---------- INFORMES ----------
        void InformeTotalBoletosVendidos();
        void InformeTotalRecaudado();
        void InformeEstacionOrigenConMayorVentas();
        void InformeEstacionDestinoConMayorVentas();
        void InformeBoletoMasCaro();
};
