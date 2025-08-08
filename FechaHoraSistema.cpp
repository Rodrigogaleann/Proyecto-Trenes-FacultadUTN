#include "FechaHoraSistema.h"

#include <ctime>

FechaHoraSistema::FechaHoraSistema(){

    time_t t;

    t = time(NULL); /// OBTENGO UN NUMERO QUE ES LA MARCA DE TIEMPO

    struct tm *f; /// STRUCT QUE CONTIENE FECHA Y HORA SEPARADOS POR COMPONENTES
    f = localtime(&t);

    _anio = f->tm_year + 1900;
    _mes = f->tm_mon + 1;
    _dia = f->tm_mday;

    _hora = f->tm_hour;
    _minuto = f->tm_min;
    _segundo = f->tm_sec;
}

FechaHoraSistema::FechaHoraSistema(time_t fechaHora){

    time_t t = fechaHora; /// OBTENGO UN NUMERO QUE ES LA MARCA DE TIEMPO

    struct tm *f; /// STRUCT QUE CONTIENE FECHA Y HORA SEPARADOS POR COMPONENTES
    f = localtime(&t);

    _anio = f->tm_year + 1900;
    _mes = f->tm_mon + 1;
    _dia = f->tm_mday;

    _hora = f->tm_hour;
    _minuto = f->tm_min;
    _segundo = f->tm_sec;
}

int FechaHoraSistema::getAnio(){
    return _anio;
}

int FechaHoraSistema::getMes(){
    return _mes;
}

int FechaHoraSistema::getDia(){
    return _dia;
}

int FechaHoraSistema::getHora(){
    return _hora;
}

int FechaHoraSistema::getMinuto(){
    return _minuto;
}

int FechaHoraSistema::getSegundo(){
    return _segundo;
}
