#include "MenuTarifas.h"
#include "ManagerTarifas.h"

#include "FuncionesGlobales.h"

#include <iostream>

/// ---------- FUNCIONES DE MENU ----------

void MenuTarifas::Menu(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "=================================================================================================================" << std::endl;
        std::cout << "||                                                                                                             ||" << std::endl;
        std::cout << "||     ******* MENU TARIFAS *******                                     =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                          |                                    //                                      ||" << std::endl;
        std::cout << "||     | 1 - CARGAR TARIFA        |                                   //                                       ||" << std::endl;
        std::cout << "||     | 2 - EDITAR TARIFA        |                                  //                                        ||" << std::endl;
        std::cout << "||     | 3 - LISTADOS             |                                 //                                         ||" << std::endl;
        std::cout << "||     | 4 - CONSULTAS            |                                //                                          ||" << std::endl;
        std::cout << "||     | 5 - INFORMES             |                        [5.VICENTE LOPEZ]                                   ||" << std::endl;
        std::cout << "||     |                          |                              //                                            ||" << std::endl;
        std::cout << "||     | 0 - SALIR                |                             //                                             ||" << std::endl;
        std::cout << "||     |                          |                            //                                              ||" << std::endl;
        std::cout << "||     ****************************                           //                                               ||" << std::endl;
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
                Cargar();
            break;

            case 2:
                Editar();
            break;

            case 3:
                SubMenu_Listados();
            break;

            case 4:
                SubMenu_Consultas();
            break;

            case 5:
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

void MenuTarifas::SubMenu_Listados(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "=================================================================================================================" << std::endl;
        std::cout << "||                                                                                                             ||" << std::endl;
        std::cout << "||     ********* LISTADOS - TARIFAS **********                          =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                     |                         //                                      ||" << std::endl;
        std::cout << "||     | 1 - LISTADO POR ID                  |                        //                                       ||" << std::endl;
        std::cout << "||     | 2 - LISTADO POR ESTACION DE ORIGEN  |                       //                                        ||" << std::endl;
        std::cout << "||     | 3 - LISTADO POR ESTACION DE DESTINO |                      //                                         ||" << std::endl;
        std::cout << "||     | 4 - LISTADO POR VALOR ASCENDENTE    |                     //                                          ||" << std::endl;
        std::cout << "||     | 5 - LISTADO POR VALOR DESCENDENTE   |            [5.VICENTE LOPEZ]                                    ||" << std::endl;
        std::cout << "||     |                                     |                   //                                            ||" << std::endl;
        std::cout << "||     | 0 - SALIR                           |                  //                                             ||" << std::endl;
        std::cout << "||     |                                     |                 //                                              ||" << std::endl;
        std::cout << "||     ***************************************                //                                               ||" << std::endl;
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
                ListadoPorId();
            break;

            case 2:
                ListadoPorEstacionOrigen();
            break;

            case 3:
                ListadoPorEstacionDestino();
            break;

            case 4:
                ListadoPorValorTarifaASC();
            break;

            case 5:
                ListadoPorValorTarifaDSC();
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

void MenuTarifas::SubMenu_Consultas(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "||                                                                                                           ||" << std::endl;
        std::cout << "||     ****** CONSULTAS - TARIFAS ******                              =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                               |                             //                                      ||" << std::endl;
        std::cout << "||     | 1 - CONSULTA POR ID           |                            //                                       ||" << std::endl;
        std::cout << "||     | 2 - CONSULTA POR ESTACION     |                           //                                        ||" << std::endl;
        std::cout << "||     | 3 - CONSULTA VALOR            |                          //                                         ||" << std::endl;
        std::cout << "||     |                               |                  [5.VICENTE LOPEZ]                                  ||" << std::endl;
        std::cout << "||     | 0 - SALIR                     |                        //                                           ||" << std::endl;
        std::cout << "||     |                               |                       //                                            ||" << std::endl;
        std::cout << "||     *********************************                      //                                             ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                         ||" << std::endl;
        std::cout << "||                                                          //                                               ||" << std::endl;
        std::cout << "||                                                         //                                                ||" << std::endl;
        std::cout << "||                                                        //                                                 ||" << std::endl;
        std::cout << "||                                                       //                                                  ||" << std::endl;
        std::cout << "||                                                      //                                                   ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                    ||" << std::endl;
        std::cout << "||                                                                                                           ||" << std::endl;
        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        system("cls");

        switch(opcion){

            case 1:
                ConsultaPorId();
            break;

            case 2:
                ConsultaPorEstacion();
            break;

            case 3:
                ConsultaPorValorTarifa();
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

void MenuTarifas::SubMenu_Informes(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "||                                                                                                           ||" << std::endl;
        std::cout << "||     ****** INFORMES - TARIFAS *******                              =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                               |                             //                                      ||" << std::endl;
        std::cout << "||     | 1 - TARIFA MAS ALTA           |                            //                                       ||" << std::endl;
        std::cout << "||     | 2 - TARIFA MAS BAJA           |                           //                                        ||" << std::endl;
        std::cout << "||     | 3 - VALOR PROMEDIO DE TARIFAS |                          //                                         ||" << std::endl;
        std::cout << "||     |                               |                  [5.VICENTE LOPEZ]                                  ||" << std::endl;
        std::cout << "||     | 0 - SALIR                     |                        //                                           ||" << std::endl;
        std::cout << "||     |                               |                       //                                            ||" << std::endl;
        std::cout << "||     *********************************                      //                                             ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                         ||" << std::endl;
        std::cout << "||                                                          //                                               ||" << std::endl;
        std::cout << "||                                                         //                                                ||" << std::endl;
        std::cout << "||                                                        //                                                 ||" << std::endl;
        std::cout << "||                                                       //                                                  ||" << std::endl;
        std::cout << "||                                                      //                                                   ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                    ||" << std::endl;
        std::cout << "||                                                                                                           ||" << std::endl;
        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        system("cls");

        switch(opcion){

            case 1:
                InformeTarifaMasAlta();
            break;

            case 2:
                InformeTarifaMasBaja();
            break;

            case 3:
                InformePromedioValorTarifas();
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

void MenuTarifas::Cargar(){

    mostrarTexto("1. CARGAR TARIFA");

    ManagerTarifas manager;

    if(manager.altaTarifa() == true){
        mostrarTexto("TARIFA REGISTRADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REGISTRAR LA TARIFA >");
    }
}

void MenuTarifas::Editar(){

    mostrarTexto("2. EDITAR TARIFA");

    ManagerTarifas manager;

    if(manager.modificacionTarifa() == true){
        mostrarTexto("TARIFA EDITADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EDITAR LA TARIFA");
    }
}

/// ---------- LISTADOS ----------

void MenuTarifas::ListadoPorId(){

    mostrarTexto("1. TARIFAS - LISTADO ORDENADO POR ID");

    ManagerTarifas manager;

    if(manager.listadoPorIdTarifa() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ID >");
    }
}

void MenuTarifas::ListadoPorEstacionOrigen(){

    mostrarTexto("2. TARIFAS - LISTADO ORDENADO POR ESTACION DE ORIGEN");

    ManagerTarifas manager;

    if(manager.listadoPorIdEstacionOrigen() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ESTACION DE ORIGEN >");
    }
}

void MenuTarifas::ListadoPorEstacionDestino(){

    mostrarTexto("3. TARIFAS - LISTADO ORDENADO POR ESTACION DE DESTINO");

    ManagerTarifas manager;

    if(manager.listadoPorIdEstacionDestino() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ESTACION DE DESTINO >");
    }
}

void MenuTarifas::ListadoPorValorTarifaASC(){

    mostrarTexto("4. TARIFAS - LISTADO ORDENADO POR VALOR DE TARIFA ASCENDENTE");

    ManagerTarifas manager;

    if(manager.listadoPorTarifaASC() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR VALOR DE TARIFA ASCENDENTE >");
    }
}

void MenuTarifas::ListadoPorValorTarifaDSC(){

    mostrarTexto("5. TARIFAS - LISTADO ORDENADO POR VALOR DE TARIFA DESCENDENTE");

    ManagerTarifas manager;

    if(manager.listadoPorTarifaDSC() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR VALOR DE TARIFA DESCENDENTE >");
    }
}

/// ---------- CONSULTAS ----------

void MenuTarifas::ConsultaPorId(){

    mostrarTexto("1. TARIFAS - CONSULTA POR ID");

    ManagerTarifas manager;

    if(manager.consultaTarifaPorIdTarifa() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ID >");
    }
}

void MenuTarifas::ConsultaPorEstacion(){

    mostrarTexto("2. TARIFAS - CONSULTA POR ESTACION");

    ManagerTarifas manager;

    if(manager.consultaTarifaPorEstacion() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ESTACION >");
    }
}

void MenuTarifas::ConsultaPorValorTarifa(){

    mostrarTexto("3. TARIFAS - CONSULTA POR VALOR DE TARIFA");

    ManagerTarifas manager;

    if(manager.consultaTarifa() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR VALOR DE TARIFA >");
    }
}

/// ---------- INFORMES ----------

void MenuTarifas::InformeTarifaMasAlta(){

    mostrarTexto("1. TARIFAS - INFORME DE TARIFA MAS ALTA");

    ManagerTarifas manager;

    if(manager.informeTarifaMasAlta() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DE LA TARIFA MAS ALTA >");
    }
}

void MenuTarifas::InformeTarifaMasBaja(){

    mostrarTexto("2. TARIFAS - INFORME DE TARIFA MAS BAJA");

    ManagerTarifas manager;

    if(manager.informeTarifaMasBaja() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DE LA TARIFA MAS BAJA >");
    }
}

void MenuTarifas::InformePromedioValorTarifas(){

    mostrarTexto("3. TARIFAS - INFORME VALOR PROMEDIO DE TARIFAS");

    ManagerTarifas manager;

    if(manager.informePromedioDeTarifas() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DEL VALOR PROMEDIO DE TARIFAS >");
    }
}
