#include "MenuPasajeros.h"
#include "ManagerPasajeros.h"
#include "Pasajero.h"

#include "FuncionesGlobales.h"

#include <iostream>
#include <cstring>

/// ---------- FUNCIONES DE MENU ----------

void MenuPasajeros::Menu(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==================================================================================================================" << std::endl;
        std::cout << "||                                                                                                              ||" << std::endl;
        std::cout << "||     ******* MENU PASAJEROS *******                                    =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                            |                                   //                                      ||" << std::endl;
        std::cout << "||     | 1 - CARGAR PASAJERO        |                                  //                                       ||" << std::endl;
        std::cout << "||     | 2 - EDITAR PASAJERO        |                                 //                                        ||" << std::endl;
        std::cout << "||     | 3 - ALTA LOGICA            |                                //                                         ||" << std::endl;
        std::cout << "||     | 4 - BAJA LOGICA            |                               //                                          ||" << std::endl;
        std::cout << "||     | 5 - LISTADOS               |                      [5.VICENTE LOPEZ]                                    ||" << std::endl;
        std::cout << "||     | 6 - CONSULTAS              |                              //                                           ||" << std::endl;
        std::cout << "||     | 7 - INFORMES               |                             //                                            ||" << std::endl;
        std::cout << "||     |                            |                            //                                             ||" << std::endl;
        std::cout << "||     | 0 - SALIR                  |                           //                                              ||" << std::endl;
        std::cout << "||     |                            |                          //                                               ||" << std::endl;
        std::cout << "||     ******************************                         //                                                ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                            ||" << std::endl;
        std::cout << "||                                                          //                                                  ||" << std::endl;
        std::cout << "||                                                         //                                                   ||" << std::endl;
        std::cout << "||                                                        //                                                    ||" << std::endl;
        std::cout << "||                                                       //                                                     ||" << std::endl;
        std::cout << "||                                                      //                                                      ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                       ||" << std::endl;
        std::cout << "||                                                                                                              ||" << std::endl;
        std::cout << "==================================================================================================================" << std::endl;
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

void MenuPasajeros::SubMenu_Listados(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==================================================================================================================" << std::endl;
        std::cout << "||                                                                                                              ||" << std::endl;
        std::cout << "||     ******* LISTADOS - PASAJEROS *******                              =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                  |                             //                                      ||" << std::endl;
        std::cout << "||     | 1 - LISTADO POR ID               |                            //                                       ||" << std::endl;
        std::cout << "||     | 2 - LISTADO POR NOMBRE           |                           //                                        ||" << std::endl;
        std::cout << "||     | 3 - LISTADO POR APELLIDO         |                          //                                         ||" << std::endl;
        std::cout << "||     | 4 - LISTADO POR DNI              |                         //                                          ||" << std::endl;
        std::cout << "||     | 5 - LISTADO POR EMAIL            |                [5.VICENTE LOPEZ]                                    ||" << std::endl;
        std::cout << "||     | 6 - LISTADO POR ESTADO           |                       //                                            ||" << std::endl;
        std::cout << "||     |                                  |                      //                                             ||" << std::endl;
        std::cout << "||     | 0 - SALIR                        |                     //                                              ||" << std::endl;
        std::cout << "||     |                                  |                    //                                               ||" << std::endl;
        std::cout << "||     ************************************                   //                                                ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                            ||" << std::endl;
        std::cout << "||                                                          //                                                  ||" << std::endl;
        std::cout << "||                                                         //                                                   ||" << std::endl;
        std::cout << "||                                                        //                                                    ||" << std::endl;
        std::cout << "||                                                       //                                                     ||" << std::endl;
        std::cout << "||                                                      //                                                      ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                       ||" << std::endl;
        std::cout << "||                                                                                                              ||" << std::endl;
        std::cout << "==================================================================================================================" << std::endl;
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
                ListadoPorApellido();
            break;

            case 4:
                ListadoPorDni();
            break;

            case 5:
                ListadoPorEmail();
            break;

            case 6:
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

void MenuPasajeros::SubMenu_Consultas(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==================================================================================================================" << std::endl;
        std::cout << "||                                                                                                              ||" << std::endl;
        std::cout << "||     ******* CONSULTAS - PASAJEROS *******                             =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                   |                            //                                      ||" << std::endl;
        std::cout << "||     | 1 - CONSULTA POR ID               |                           //                                       ||" << std::endl;
        std::cout << "||     | 2 - CONSULTA POR NOMBRE           |                          //                                        ||" << std::endl;
        std::cout << "||     | 3 - CONSULTA POR APELLIDO         |                         //                                         ||" << std::endl;
        std::cout << "||     | 4 - CONSULTA POR DNI              |                        //                                          ||" << std::endl;
        std::cout << "||     | 5 - CONSULTA POR EMAIL            |               [5.VICENTE LOPEZ]                                    ||" << std::endl;
        std::cout << "||     | 6 - CONSULTA POR ESTADO           |                      //                                            ||" << std::endl;
        std::cout << "||     |                                   |                     //                                             ||" << std::endl;
        std::cout << "||     | 0 - SALIR                         |                    //                                              ||" << std::endl;
        std::cout << "||     |                                   |                   //                                               ||" << std::endl;
        std::cout << "||     *************************************                  //                                                ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                            ||" << std::endl;
        std::cout << "||                                                          //                                                  ||" << std::endl;
        std::cout << "||                                                         //                                                   ||" << std::endl;
        std::cout << "||                                                        //                                                    ||" << std::endl;
        std::cout << "||                                                       //                                                     ||" << std::endl;
        std::cout << "||                                                      //                                                      ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                       ||" << std::endl;
        std::cout << "||                                                                                                              ||" << std::endl;
        std::cout << "==================================================================================================================" << std::endl;
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
                ConsultaPorApellido();
            break;

            case 4:
                ConsultaPorDni();
            break;

            case 5:
                ConsultaPorEmail();
            break;

            case 6:
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

void MenuPasajeros::SubMenu_Informes(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "=================================================================================================================" << std::endl;
        std::cout << "||                                                                                                             ||" << std::endl;
        std::cout << "||     ******* INFORMES - PASAJEROS *******                            =====[6.BELGRANO C]=====[7.RETIRO]      ||" << std::endl;
        std::cout << "||     |                                  |                           //                                       ||" << std::endl;
        std::cout << "||     | 1 - PASAJEROS REGISTRADOS        |                          //                                        ||" << std::endl;
        std::cout << "||     | 2 - PASAJEROS ACTIVOS            |                         //                                         ||" << std::endl;
        std::cout << "||     | 3 - PASAJEROS INACTIVOS          |                        //                                          ||" << std::endl;
        std::cout << "||     |                                  |                [5.VICENTE LOPEZ]                                   ||" << std::endl;
        std::cout << "||     |                                  |                      //                                            ||" << std::endl;
        std::cout << "||     | 0 - SALIR                        |                     //                                             ||" << std::endl;
        std::cout << "||     |                                  |                    //                                              ||" << std::endl;
        std::cout << "||     ************************************                   //                                               ||" << std::endl;
        std::cout << "||                                                           //                                                ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                           ||" << std::endl;
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
                InformeTotalPasajerosRegistrados();
            break;

            case 2:
                InformeTotalPasajerosActivos();
            break;

            case 3:
                InformeTotalPasajerosInactivos();
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

void MenuPasajeros::Cargar(){

    mostrarTexto("1. CARGAR PASAJERO");

    ManagerPasajeros manager;

    if(manager.altaPasajero() == true){
        mostrarTexto("PASAJERO REGISTRADO CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REGISTRAR EL PASAJERO >");
    }
}

void MenuPasajeros::Editar(){

    mostrarTexto("2. EDITAR PASAJERO");


    ManagerPasajeros manager;

    if(manager.modificacionPasajero() == true){
        mostrarTexto("PASAJERO EDITADO CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EDITAR EL PASAJERO >");
    }
}

void MenuPasajeros::AltaLogica(){

    mostrarTexto("3. PASAJEROS - ALTA LOGICA");

    char dni[10];
    std::cout << "INGRESE EL DNI DEL PASAJERO: ";
    cargarCadena(dni, sizeof(dni) - 1);

    ManagerPasajeros manager;

    ///nuevo metodo para verificar que ya se encuentra ACTIVO el PASAJERO
    Pasajero pasajeroEncontrado = manager.obtenerPasajeroPorDNI(dni);
    if(pasajeroEncontrado.getEstado() == true){
        mostrarTexto("PASAJERO YA SE ENCUENTRA ACTIVO");
        pasajeroEncontrado.mostrar();
        return;
    }

    if(manager.altaLogica(dni) == true){
        mostrarTexto("PASAJERO DADO DE ALTA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO DAR DE ALTA AL PASAJERO >");
    }
}

void MenuPasajeros::BajaLogica(){

    mostrarTexto("4. PASAJEROS - BAJA LOGICA");

    char dni[10];
    std::cout << "INGRESE EL DNI DEL PASAJERO: ";
    cargarCadena(dni, sizeof(dni) - 1);

    ManagerPasajeros manager;

    ///nuevo metodo para verificar que ya esta dado de baja el PASAJERO
    Pasajero pasajeroEncontrado = manager.obtenerPasajeroPorDNI(dni);

      if (pasajeroEncontrado.getIDPasajero() == 0) {
        mostrarTexto("ERROR: EL PASAJERO CON ESE DNI NO SE ENCUENTRA EN EL SISTEMA ");
        return;
    }

    if(pasajeroEncontrado.getEstado() == false){
        mostrarTexto("PASAJERO YA SE ENCUENTRA DADO DE BAJA");
        pasajeroEncontrado.mostrar();
        return;
    }

    if(manager.bajaLogica(dni) == true){
        mostrarTexto("PASAJERO DADO DE BAJA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO DAR DE BAJA AL PASAJERO >");
    }
}

/// ---------- LISTADOS ----------

void MenuPasajeros::ListadoPorId(){

    mostrarTexto("1. PASAJEROS - LISTADO ORDENADO POR ID");

    ManagerPasajeros manager;

    if(manager.listadoPorID() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ID >");
    }
}

void MenuPasajeros::ListadoPorNombre(){

    mostrarTexto("2. PASAJEROS - LISTADO ORDENADO POR NOMBRE");

    ManagerPasajeros manager;

    if(manager.listadoPorNombre() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR NOMBRE >");
    }
}

void MenuPasajeros::ListadoPorApellido(){

    mostrarTexto("3. PASAJEROS - LISTADO ORDENADO POR APELLIDO");

    ManagerPasajeros manager;

    if(manager.listadoPorApellido() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR APELLIDO >");
    }
}

void MenuPasajeros::ListadoPorDni(){

    mostrarTexto("4. PASAJEROS - LISTADO ORDENADO POR DNI");

    ManagerPasajeros manager;

    if(manager.listadoPorDni() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR DNI >");
    }
}

void MenuPasajeros::ListadoPorEmail(){

    mostrarTexto("4. PASAJEROS - LISTADO ORDENADO POR EMAIL");

    ManagerPasajeros manager;

    if(manager.listadoPorEmail() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR EMAIL >");
    }
}

void MenuPasajeros::ListadoPorEstado(){

    mostrarTexto("5. PASAJEROS - LISTADO ORDENADO POR ESTADO");

    ManagerPasajeros manager;

    if(manager.listadoPorEstado() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ESTADO >");
    }
}

/// ---------- CONSULTAS ----------

void MenuPasajeros::ConsultaPorId(){

    mostrarTexto("1. PASAJEROS - CONSULTA POR ID");

    ManagerPasajeros manager;

    if(manager.consultaPorID() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ID >");
    }
}

void MenuPasajeros::ConsultaPorNombre(){

    mostrarTexto("2. PASAJEROS - CONSULTA POR NOMBRE");

    ManagerPasajeros manager;

    if(manager.consultaPorNombre() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR NOMBRE >");
    }
}

void MenuPasajeros::ConsultaPorApellido(){

    mostrarTexto("3. PASAJEROS - CONSULTA POR APELLIDO");

    ManagerPasajeros manager;

    if(manager.consultaPorApellido() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR APELLIDO >");
    }
}

void MenuPasajeros::ConsultaPorDni(){

    mostrarTexto("4. PASAJEROS - CONSULTA POR DNI");

    ManagerPasajeros manager;

    if(manager.consultaPorDni() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR DNI >");
    }
}

void MenuPasajeros::ConsultaPorEmail(){

    mostrarTexto("4. PASAJEROS - CONSULTA POR EMAIL");

    ManagerPasajeros manager;

    if(manager.consultaPorEmail() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR EMAIL >");
    }
}

void MenuPasajeros::ConsultaPorEstado(){

    mostrarTexto("5. PASAJEROS - CONSULTA POR ESTADO");

    ManagerPasajeros manager;

    if(manager.consultaPorEstado() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ESTADO");
    }
}

/// ---------- INFORMES ----------

void MenuPasajeros::InformeTotalPasajerosRegistrados(){

    mostrarTexto("1. PASAJEROS - INFORME DEL TOTAL DE PASAJEROS REGISTRADOS");

    ManagerPasajeros manager;

    if(manager.informeTotalPasajerosRegistrados() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DEL TOTAL DE PASAJEROS REGISTRADOS >");
    }
}

void MenuPasajeros::InformeTotalPasajerosActivos(){

    mostrarTexto("2. PASAJEROS - INFORME DEL TOTAL DE PASAJEROS ACTIVOS");

    ManagerPasajeros manager;

    if(manager.informeTotalPasajerosActivos() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DEL TOTAL DE PASAJEROS ACTIVOS >");
    }
}

void MenuPasajeros::InformeTotalPasajerosInactivos(){

    mostrarTexto("2. PASAJEROS - INFORME DEL TOTAL DE PASAJEROS ACTIVOS");

    ManagerPasajeros manager;

    if(manager.informeTotalPasajerosActivos() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL INFORME DEL TOTAL DE PASAJEROS ACTIVOS >");
    }
}
