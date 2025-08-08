#include "MenuEstaciones.h"
#include "ManagerEstaciones.h"

#include "FuncionesGlobales.h"

#include <iostream>

void MenuEstaciones::Menu(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "===================================================================================================================" << std::endl;
        std::cout << "||                                                                                                               ||" << std::endl;
        std::cout << "||     ****** MENU ESTACIONES *******                                     =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                            |                                    //                                      ||" << std::endl;
        std::cout << "||     | 1 - CARGAR ESTACION        |                                   //                                       ||" << std::endl;
        std::cout << "||     | 2 - EDITAR ESTACION        |                                  //                                        ||" << std::endl;
        std::cout << "||     | 3 - ALTA LOGICA            |                                 //                                         ||" << std::endl;
        std::cout << "||     | 4 - BAJA LOGICA            |                                //                                          ||" << std::endl;
        std::cout << "||     | 5 - LISTADOS               |                       [5.VICENTE LOPEZ]                                    ||" << std::endl;
        std::cout << "||     | 6 - CONSULTAS              |                              //                                            ||" << std::endl;
        std::cout << "||     | 7 - INFORMES               |                             //                                             ||" << std::endl;
        std::cout << "||     |                            |                            //                                              ||" << std::endl;
        std::cout << "||     | 0 - SALIR                  |                           //                                               ||" << std::endl;
        std::cout << "||     |                            |                          //                                                ||" << std::endl;
        std::cout << "||     ******************************                         //                                                 ||" << std::endl;
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
                Cargar();
            break;

            case 2:
                Editar();
            break;

            case 3:
                AltaLogica();
            break;

            case 4:
                BajaLogica();
            break;

            case 5:
                SubMenu_Listados();
            break;

            case 6:
                SubMenu_Consultas();
            break;

            case 7:
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

void MenuEstaciones::SubMenu_Listados(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "||                                                                                                           ||" << std::endl;
        std::cout << "||     ****** LISTADOS - ESTACIONES *******                           =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                  |                          //                                      ||" << std::endl;
        std::cout << "||     | 1 - LISTADO POR ID               |                         //                                       ||" << std::endl;
        std::cout << "||     | 2 - LISTADO POR NOMBRE           |                        //                                        ||" << std::endl;
        std::cout << "||     | 3 - LISTADO POR ESTADO           |                       //                                         ||" << std::endl;
        std::cout << "||     |                                  |                [5.VICENTE LOPEZ]                                 ||" << std::endl;
        std::cout << "||     | 0 - SALIR                        |                     //                                           ||" << std::endl;
        std::cout << "||     |                                  |                    //                                            ||" << std::endl;
        std::cout << "||     ************************************                   //                                             ||" << std::endl;
        std::cout << "||                                                           //                                              ||" << std::endl;
        std::cout << "||                                                     [4.MARTINEZ]                                          ||" << std::endl;
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
                ListadoPorId();
            break;

            case 2:
                ListadoPorNombre();
            break;

            case 3:
                ListadoPorEstado();
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

void MenuEstaciones::SubMenu_Consultas(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "||                                                                                                           ||" << std::endl;
        std::cout << "||     ****** CONSULTAS - ESTACIONES ******                           =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                  |                          //                                      ||" << std::endl;
        std::cout << "||     | 1 - CONSULTA POR ID              |                         //                                       ||" << std::endl;
        std::cout << "||     | 2 - CONSULTA POR NOMBRE          |                        //                                        ||" << std::endl;
        std::cout << "||     | 3 - CONSULTA POR ESTADO          |                       //                                         ||" << std::endl;
        std::cout << "||     |                                  |                [5.VICENTE LOPEZ]                                 ||" << std::endl;
        std::cout << "||     | 0 - SALIR                        |                     //                                           ||" << std::endl;
        std::cout << "||     |                                  |                    //                                            ||" << std::endl;
        std::cout << "||     ************************************                   //                                             ||" << std::endl;
        std::cout << "||                                                           //                                              ||" << std::endl;
        std::cout << "||                                                     [4.MARTINEZ]                                          ||" << std::endl;
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
                ConsultaPorNombre();
            break;

            case 3:
                ConsultaPorEstado();
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

void MenuEstaciones::SubMenu_Informes(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "||                                                                                                           ||" << std::endl;
        std::cout << "||     ****** INFORMES - ESTACIONES *******                           =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                  |                          //                                      ||" << std::endl;
        std::cout << "||     | 1 - ESTACIONES REGISTRADAS       |                         //                                       ||" << std::endl;
        std::cout << "||     | 2 - ESTACIONES ACTIVAS           |                        //                                        ||" << std::endl;
        std::cout << "||     | 3 - ESTACIONES INACTIVAS         |                       //                                         ||" << std::endl;
        std::cout << "||     |                                  |                [5.VICENTE LOPEZ]                                 ||" << std::endl;
        std::cout << "||     | 0 - SALIR                        |                     //                                           ||" << std::endl;
        std::cout << "||     |                                  |                    //                                            ||" << std::endl;
        std::cout << "||     ************************************                   //                                             ||" << std::endl;
        std::cout << "||                                                           //                                              ||" << std::endl;
        std::cout << "||                                                     [4.MARTINEZ]                                          ||" << std::endl;
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
                InformeTotalEstacionesRegistradas();
            break;

            case 2:
                InformeTotalEstacionesActivas();
            break;

            case 3:
                InformeTotalEstacionesInactivas();
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

void MenuEstaciones::Cargar(){

    mostrarTexto("1. CARGAR ESTACION");

    ManagerEstaciones manager;

    if(manager.altaEstacion() == true){
        mostrarTexto("ESTACION REGISTRADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REGISTRAR LA ESTACION >");
    }
}

void MenuEstaciones::Editar(){

    mostrarTexto("2. EDITAR ESTACION");

    ManagerEstaciones manager;

    if(manager.modificacionEstacion() == true){
        mostrarTexto("ESTACION EDITADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EDITAR LA ESTACION >");
    }
}

void MenuEstaciones::AltaLogica(){

    mostrarTexto("3. ESTACIONES - ALTA LOGICA");

    char nombreEstacion[30];
    std::cout << "INGRESE EL NOMBRE DE LA ESTACION: ";
    cargarCadena(nombreEstacion, sizeof(nombreEstacion) - 1);

    ManagerEstaciones manager;

    if(manager.altaLogica(nombreEstacion) == true){
        mostrarTexto("ESTACION DADA DE ALTA CON EXITO");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO DAR DE ALTA A LA ESTACION >");
    }
}

void MenuEstaciones::BajaLogica(){

    mostrarTexto("4. ESTACIONES - BAJA LOGICA");

    char nombreEstacion[30];
    std::cout << "INGRESE EL NOMBRE DE LA ESTACION: ";
    cargarCadena(nombreEstacion, sizeof(nombreEstacion) - 1);

    ManagerEstaciones manager;

    if(manager.bajaLogica(nombreEstacion) == true){
        mostrarTexto("ESTACION DADA DE BAJA CON EXITO");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO DAR DE BAJA A LA ESTACION >");
    }
}

/// ---------- LISTADOS ----------

void MenuEstaciones::ListadoPorId(){

    mostrarTexto("1. ESTACIONES - LISTADO ORDENADO POR ID");

    ManagerEstaciones manager;

    if(manager.listadoPorIdEstacion() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ID >");
    }
}

void MenuEstaciones::ListadoPorNombre(){

    mostrarTexto("2. ESTACIONES - LISTADO ORDENADO POR NOMBRE");

    ManagerEstaciones manager;

    if(manager.listadoPorNombreEstacion() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR NOMBRE >");
    }
}

void MenuEstaciones::ListadoPorEstado(){

    mostrarTexto("3. ESTACIONES - LISTADO ORDENADO POR ESTADO");

    ManagerEstaciones manager;

    if(manager.listadoPorEstado() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ESTADO");
    }
}

/// ---------- CONSULTAS ----------

void MenuEstaciones::ConsultaPorId(){

    mostrarTexto("1. ESTACIONES - CONSULTA POR ID");

    ManagerEstaciones manager;

    if(manager.consultaPorIdEstacion() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ID >");
    }
}

void MenuEstaciones::ConsultaPorNombre(){

    mostrarTexto("2. ESTACIONES - CONSULTA POR NOMBRE");

    ManagerEstaciones manager;

    if(manager.consultaPorNombreEstacion() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR NOMBRE >");
    }
}

void MenuEstaciones::ConsultaPorEstado(){

    mostrarTexto("3. ESTACIONES - CONSULTA POR ESTADO");

    ManagerEstaciones manager;

    if(manager.consultaPorEstado() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ESTADO >");
    }
}

/// ---------- INFORMES ----------

void MenuEstaciones::InformeTotalEstacionesRegistradas(){

    mostrarTexto("1. ESTACIONES - INFORME DEL TOTAL DE ESTACIONES REGISTRADAS");

    ManagerEstaciones manager;

    if(manager.informeTotalEstacionesRegistradas() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DEL TOTAL DE ESTACIONES REGISTRADAS >");
    }
}

void MenuEstaciones::InformeTotalEstacionesActivas(){

    mostrarTexto("2. ESTACIONES - INFORME DEL TOTAL DE ESTACIONES ACTIVAS");

    ManagerEstaciones manager;

    if(manager.informeTotalEstacionesActivas() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DEL TOTAL DE ESTACIONES ACTIVAS >");
    }
}

void MenuEstaciones::InformeTotalEstacionesInactivas(){

    mostrarTexto("3. ESTACIONES - INFORME DEL TOTATL DE ESTACIONES INACTIVAS");

    ManagerEstaciones manager;

    if(manager.informeTotalEstacionesInactivas() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DEL TOTAL DE ESTACIONES INACTIVAS >");
    }
}
