#include "MenuBoletos.h"
#include "ManagerBoletos.h"

#include "FuncionesGlobales.h"

#include <iostream>

/// ---------- FUNCIONES DE MENU ----------

void MenuBoletos::Menu(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "================================================================================================================" << std::endl;
        std::cout << "||                                                                                                            ||" << std::endl;
        std::cout << "||     ******* MENU BOLETOS *******                                    =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                          |                                   //                                      ||" << std::endl;
        std::cout << "||     | 1 - CARGAR BOLETO        |                                  //                                       ||" << std::endl;
        std::cout << "||     | 2 - LISTADOS             |                                 //                                        ||" << std::endl;
        std::cout << "||     | 3 - CONSULTAS            |                                //                                         ||" << std::endl;
        std::cout << "||     | 4 - INFORMES             |                               //                                          ||" << std::endl;
        std::cout << "||     |                          |                      [5.VICENTE LOPEZ]                                    ||" << std::endl;
        std::cout << "||     | 0 - SALIR                |                             //                                            ||" << std::endl;
        std::cout << "||     |                          |                            //                                             ||" << std::endl;
        std::cout << "||     ****************************                           //                                              ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                          ||" << std::endl;
        std::cout << "||                                                          //                                                ||" << std::endl;
        std::cout << "||                                                         //                                                 ||" << std::endl;
        std::cout << "||                                                        //                                                  ||" << std::endl;
        std::cout << "||                                                       //                                                   ||" << std::endl;
        std::cout << "||                                                      //                                                    ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                     ||" << std::endl;
        std::cout << "||                                                                                                            ||" << std::endl;
        std::cout << "================================================================================================================" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        system("cls");

        switch(opcion){

            case 1:
                Cargar();
            break;

            case 2:
                SubMenu_Listados();
            break;

            case 3:
                SubMenu_Consultas();
            break;

            case 4:
                SubMenu_Informes();
            break;

            case 0:
                mostrarTexto("VOLVIENDO AL MENU ANTERIOR");
                return;
            break;

            default:
                mostrarTexto("< ERROR: OPCION NO VALIDA. INTENTE NUEVAMENTE >");
            break;
        }

        system("pause");
    }
}

void MenuBoletos::SubMenu_Listados(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "===================================================================================================================" << std::endl;
        std::cout << "||                                                                                                               ||" << std::endl;
        std::cout << "||     ********* LISTADOS - BOLETOS **********                            =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                     |                           //                                      ||" << std::endl;
        std::cout << "||     | 1 - LISTADO POR ID DE BOLETO        |                          //                                       ||" << std::endl;
        std::cout << "||     | 2 - LISTADO POR ID DE TREN          |                         //                                        ||" << std::endl;
        std::cout << "||     | 3 - LISTADO POR DNI DE PASAJERO     |                        //                                         ||" << std::endl;
        std::cout << "||     | 4 - LISTADO POR ESTACION DE ORIGEN  |                       //                                          ||" << std::endl;
        std::cout << "||     | 5 - LISTADO POR ESTACION DE DESTINO |               [5.VICENTE LOPEZ]                                   ||" << std::endl;
        std::cout << "||     | 6 - LISTADO POR PRECIO PAGADO       |                     //                                            ||" << std::endl;
        std::cout << "||     | 7 - LISTADO POR FECHA               |                    //                                             ||" << std::endl;
        std::cout << "||     |                                     |                   //                                              ||" << std::endl;
        std::cout << "||     | 0 - SALIR                           |                  //                                               ||" << std::endl;
        std::cout << "||     |                                     |                 //                                                ||" << std::endl;
        std::cout << "||     ***************************************                //                                                 ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                             ||" << std::endl;
        std::cout << "||                                                          //                                                   ||" << std::endl;
        std::cout << "||                                                         //                                                    ||" << std::endl;
        std::cout << "||                                                        //                                                     ||" << std::endl;
        std::cout << "||                                                       //                                                      ||" << std::endl;
        std::cout << "||                                                      //                                                       ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                        ||" << std::endl;
        std::cout << "||                                                                                                               ||" << std::endl;
        std::cout << "===================================================================================================================" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        system("cls");

        switch(opcion){

            case 1:
                ListadoPorIdBoleto();
            break;

            case 2:
                ListadoPorIdTren();
            break;

            case 3:
                ListadoPorDniPasajero();
            break;

            case 4:
                ListadoPorEstacionOrigen();
            break;

            case 5:
                ListadoPorEstacionDestino();
            break;

            case 6:
                ListadoPorPrecioPagado();
            break;

            case 7:
                ListadoPorFecha();
            break;

            case 0:
                mostrarTexto("VOLVIENDO AL MENU ANTERIOR");
                return;
            break;

            default:
                mostrarTexto("< ERROR: OPCION NO VALIDA. INTENTE NUEVAMENTE >");
            break;
        }

        system("pause");
    }
}

void MenuBoletos::SubMenu_Consultas(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==================================================================================================================" << std::endl;
        std::cout << "||                                                                                                               ||" << std::endl;
        std::cout << "||     ********* CONSULTAS - BOLETOS **********                           =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                      |                          //                                      ||" << std::endl;
        std::cout << "||     | 1 - CONSULTA POR ID DE BOLETO        |                         //                                       ||" << std::endl;
        std::cout << "||     | 2 - CONSULTA POR ID DE TREN          |                        //                                        ||" << std::endl;
        std::cout << "||     | 3 - CONSULTA POR DNI DE PASAJERO     |                       //                                         ||" << std::endl;
        std::cout << "||     | 4 - CONSULTA POR ESTACION DE ORIGEN  |                      //                                          ||" << std::endl;
        std::cout << "||     | 5 - CONSULTA POR ESTACION DE DESTINO |              [5.VICENTE LOPEZ]                                   ||" << std::endl;
        std::cout << "||     | 6 - CONSULTA POR PRECIO PAGADO       |                    //                                            ||" << std::endl;
        std::cout << "||     |                                      |                   //                                             ||" << std::endl;
        std::cout << "||     | 0 - SALIR                            |                  //                                              ||" << std::endl;
        std::cout << "||     |                                      |                 //                                               ||" << std::endl;
        std::cout << "||     ****************************************                //                                                ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                             ||" << std::endl;
        std::cout << "||                                                          //                                                   ||" << std::endl;
        std::cout << "||                                                         //                                                    ||" << std::endl;
        std::cout << "||                                                        //                                                     ||" << std::endl;
        std::cout << "||                                                       //                                                      ||" << std::endl;
        std::cout << "||                                                      //                                                       ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                        ||" << std::endl;
        std::cout << "||                                                                                                               ||" << std::endl;
        std::cout << "===================================================================================================================" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        system("cls");

        switch(opcion){

            case 1:
                ConsultaPorIdBoleto();
            break;

            case 2:
                ConsultaPorIdTren();
            break;

            case 3:
                ConsultaPorDniPasajero();
            break;

            case 4:
                ConsultaPorEstacionOrigen();
            break;

            case 5:
                ConsultaPorEstacionDestino();
            break;

            case 6:
                ConsultaPorPrecioPagado();
            break;

            case 0:
                mostrarTexto("VOLVIENDO AL MENU ANTERIOR");
                return;
            break;

            default:
                mostrarTexto("< ERROR: OPCION NO VALIDA. INTENTE NUEVAMENTE >");
            break;
        }

        system("pause");
    }
}

void MenuBoletos::SubMenu_Informes(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "=================================================================================================================" << std::endl;
        std::cout << "||                                                                                                             ||" << std::endl;
        std::cout << "||     ********** INFORMES - BOLETOS ***********                        =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                       |                       //                                      ||" << std::endl;
        std::cout << "||     | 1 - TOTAL DE BOLETOS VENDIDOS         |                      //                                       ||" << std::endl;
        std::cout << "||     | 2 - TOTAL RECAUDADO                   |                     //                                        ||" << std::endl;
        std::cout << "||     | 3 - ESTACION ORIGEN CON MAYOR VENTAS  |                    //                                         ||" << std::endl;
        std::cout << "||     | 4 - ESTACION DESTINO CON MAYOR VENTAS |                   //                                          ||" << std::endl;
        std::cout << "||     | 5 - BOLETO MAS CARO                   |            [5.VICENTE LOPEZ]                                  ||" << std::endl;
        std::cout << "||     |                                       |                 //                                            ||" << std::endl;
        std::cout << "||     | 0 - SALIR                             |                //                                             ||" << std::endl;
        std::cout << "||     |                                       |               //                                              ||" << std::endl;
        std::cout << "||     *****************************************              //                                               ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                           ||" << std::endl;
        std::cout << "||                                                          //                                                 ||" << std::endl;
        std::cout << "||                                                         //                                                  ||" << std::endl;
        std::cout << "||                                                        //                                                   ||" << std::endl;
        std::cout << "||                                                       //                                                    ||" << std::endl;
        std::cout << "||                                                      //                                                     ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                      ||" << std::endl;
        std::cout << "||                                                                                                             ||" << std::endl;
        std::cout << "=================================================================================================================" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        system("cls");

        switch(opcion){

            case 1:
                InformeTotalBoletosVendidos();
            break;

            case 2:
                InformeTotalRecaudado();
            break;

            case 3:
                InformeEstacionOrigenConMayorVentas();
            break;

            case 4:
                InformeEstacionDestinoConMayorVentas();
            break;

            case 5:
                InformeBoletoMasCaro();
            break;

            case 0:
                mostrarTexto("VOLVIENDO AL MENU ANTERIOR");
                return;
            break;

            default:
                mostrarTexto("< ERROR: OPCION NO VALIDA. INTENTE NUEVAMENTE >");
            break;
        }

        system("pause");
    }
}

/// ---------- FUNCIONES "ABML" ----------

void MenuBoletos::Cargar(){

    mostrarTexto("1. CARGAR BOLETO");

    ManagerBoletos manager;

    if(manager.altaBoleto() == true){
        mostrarTexto("BOLETO REGISTRADO CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REGISTRAR EL BOLETO >");
    }
}

/// ---------- LISTADOS ----------

void MenuBoletos::ListadoPorIdBoleto(){

    mostrarTexto("1. BOLETOS - LISTADO ORDENADO POR ID DE BOLETO");

    ManagerBoletos manager;

    if(manager.listadoPorIdBoleto() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ID DE BOLETO >");
    }
}

void MenuBoletos::ListadoPorIdTren(){

    mostrarTexto("2. BOLETOS - LISTADO POR ORDENADO POR ID DE TREN");

    ManagerBoletos manager;

    if(manager.listadoPorIdTren() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ID DE TREN >");
    }
}

void MenuBoletos::ListadoPorDniPasajero(){

    mostrarTexto("3. BOLETOS - LISTADO ORDENADO POR DNI DE PASAJERO");

    ManagerBoletos manager;

    if(manager.listadoPorDniPasajero() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR DNI DE PASAJERO >");
    }
}

void MenuBoletos::ListadoPorEstacionOrigen(){

    mostrarTexto("4. BOLETOS - LISTADO ORDENADO POR ESTACION DE ORIGEN");

    ManagerBoletos manager;

    if(manager.listadoPorEstacionOrigen() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ESTACION DE ORIGEN >");
    }
}

void MenuBoletos::ListadoPorEstacionDestino(){

    mostrarTexto("5. BOLETOS - LISTADO ORDENADO POR ESTACION DE DESTINO");

    ManagerBoletos manager;

    if(manager.listadoPorEstacionDestino() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ESTACION DE DESTINO >");
    }
}

void MenuBoletos::ListadoPorPrecioPagado(){

    mostrarTexto("6. BOLETOS - LISTADO ORDENADO POR PRECIO PAGADO");

    ManagerBoletos manager;

    if(manager.listadoPorPrecioPagado() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR PRECIO PAGADO >");
    }
}

void MenuBoletos::ListadoPorFecha(){

    mostrarTexto("7. BOLETOS - LISTADO ORDENADO POR FECHA DE EMISION");

    ManagerBoletos manager;

    if(manager.listadoPorFecha() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR FECHA DE EMISION >");
    }
}

/// ---------- CONSULTAS ----------

void MenuBoletos::ConsultaPorIdBoleto(){

    mostrarTexto("1. BOLETOS - CONSULTA POR ID DE BOLETO");

    ManagerBoletos manager;

    if(manager.consultaPorIdBoleto() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ID DE BOLETO >");
    }
}

void MenuBoletos::ConsultaPorIdTren(){

    mostrarTexto("2. BOLETOS - CONSULTA POR ID DE TREN");

    ManagerBoletos manager;

    if(manager.consultaPorIdTren() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ID DE TREN >");
    }
}

void MenuBoletos::ConsultaPorDniPasajero(){

    mostrarTexto("3. BOLETOS - CONSULTA POR DNI DE PASAJERO");

    ManagerBoletos manager;

    if(manager.consultaPorDniPasajero() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR DNI DE PASAJERO >");
    }
}

void MenuBoletos::ConsultaPorEstacionOrigen(){

    mostrarTexto("4. BOLETOS - CONSULTA POR ESTACION DE ORIGEN");

    ManagerBoletos manager;

    if(manager.consultaPorEstacionOrigen() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ESTACION DE ORIGEN >");
    }
}

void MenuBoletos::ConsultaPorEstacionDestino(){

    mostrarTexto("5. BOLETOS - CONSULTA POR ESTACION DE DESTINO");

    ManagerBoletos manager;

    if(manager.consultaPorEstacionDestino() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ESTACION DE DESTINO >");
    }
}

void MenuBoletos::ConsultaPorPrecioPagado(){

    mostrarTexto("6. BOLETOS - CONSULTA POR PRECIO PAGADO");

    ManagerBoletos manager;

    if(manager.consultaPorPrecioPagado() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR PRECIO PAGADO >");
    }
}

/// ---------- INFORMES ----------

void MenuBoletos::InformeTotalBoletosVendidos(){

    mostrarTexto("BOLETOS - INFORME DE LA CANTIDAD TOTAL DE BOLETOS VENDIDOS");

    ManagerBoletos manager;

    if(manager.informeTotalBoletosVendidos() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DE LA CANTIDAD TOTAL DE BOLETOS VENDIDOS >");
    }
}

void MenuBoletos::InformeTotalRecaudado(){

    mostrarTexto("BOLETOS - INFORME DEL TOTAL RECAUDADO");

    ManagerBoletos manager;

    if(manager.informeTotalRecaudado() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DEL TOTAL RECAUDADO >");
    }
}

void MenuBoletos::InformeEstacionOrigenConMayorVentas(){

    mostrarTexto("BOLETOS - INFORME DE LA ESTACION DE ORIGEN CON MAYOR CANTIDAD DE VENTAS");

    ManagerBoletos manager;

    if(manager.informeEstacionOrigenConMayorVentas() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DE LA ESTACION DE ORIGEN CON MAYOR CANTIDAD DE VENTAS >");
    }
}

void MenuBoletos::InformeEstacionDestinoConMayorVentas(){

    mostrarTexto("BOLETOS - INFORME DE LA ESTACION DE DESTINO CON MAYOR CANTIDAD DE VENTAS");

    ManagerBoletos manager;

    if(manager.informeEstacionDestinoConMayorVentas() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DE LA ESTACION DE DESTINO CON MAYOR CANTIDAD DE VENTAS >");
    }
}

void MenuBoletos::InformeBoletoMasCaro(){

    mostrarTexto("BOLETOS - INFORME DEL BOLETO MAS CARO");

    ManagerBoletos manager;

    if(manager.informeBoletoMasCaro() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DEL BOLETO MAS CARO >");
    }
}
