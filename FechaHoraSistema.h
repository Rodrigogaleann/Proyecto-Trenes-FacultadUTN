#pragma once

#include <ctime>

/// IGUAL AL VIDEO DE LA EXLPICACION DE ANGEL QUE PASE POR EL GRUPO DE WHATSAPP
/// PERO ARMADO COMO CLASE EN VEZ DE STRUCT

class FechaHoraSistema{

    private:
        int _anio;
        int _mes;
        int _dia;

        int _hora;
        int _minuto;
        int _segundo;

    public:
        FechaHoraSistema();
        FechaHoraSistema(time_t fechaHora);

        int getAnio();
        int getMes();
        int getDia();

        int getHora();
        int getMinuto();
        int getSegundo();
};
