#include "MenuConfiguraciones.h"
#include "ManagerConfiguraciones.h"

#include "FuncionesGlobales.h"

#include <iostream>

/// ---------- FUNCIONES DE MENU ----------

void MenuConfiguraciones::Menu(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==============================================================================================================" << std::endl;
        std::cout << "||                                                                                                          ||" << std::endl;
        std::cout << "||     ******* MENU CONFIGURACIONES ********                         =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                   |                        //                                      ||" << std::endl;
        std::cout << "||     | 1 - REALIZAR COPIAS DE SEGURIDAD  |                       //                                       ||" << std::endl;
        std::cout << "||     | 2 - RESTAURAR COPIAS DE SEGURIDAD |                      //                                        ||" << std::endl;
        std::cout << "||     | 3 - EXPORTAR EN FORMATO .CSV      |                     //                                         ||" << std::endl;
        std::cout << "||     |                                   |            [5.VICENTE LOPEZ]                                   ||" << std::endl;
        std::cout << "||     | 0 - SALIR                         |                   //                                           ||" << std::endl;
        std::cout << "||     *************************************                  //                                            ||" << std::endl;
        std::cout << "||                                                           //                                             ||" << std::endl;
        std::cout << "||                                                    [4.MARTINEZ]                                          ||" << std::endl;
        std::cout << "||                                                         //                                               ||" << std::endl;
        std::cout << "||                                                        //                                                ||" << std::endl;
        std::cout << "||                                                       //                                                 ||" << std::endl;
        std::cout << "||                                                      //                                                  ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                   ||" << std::endl;
        std::cout << "||                                                                                                          ||" << std::endl;
        std::cout << "==============================================================================================================" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        system("cls");

        switch(opcion){

            case 1:
                SubMenu_RealizarBackups();
            break;

            case 2:
                SubMenu_RestaurarBackups();
            break;

            case 3:
                SubMenu_ExportarCSV();
            break;

            case 0:
                mostrarTexto("VOLVIENDO AL MENU ANTERIOR");
                return;
            break;

            default:
                mostrarTexto("< ERROR: OPCION NO VALIDA. INTENTE NUEVAMENTE");
            break;
        }

        system("pause");
    }
}

void MenuConfiguraciones::SubMenu_RealizarBackups(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==================================================================================================================" << std::endl;
        std::cout << "||                                                                                                              ||" << std::endl;
        std::cout << "||     **** REALIZAR COPIAS DE SEGURIDAD ****                            =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                    |                           //                                      ||" << std::endl;
        std::cout << "||     | 1 - 'pasajeros.dat'                |                          //                                       ||" << std::endl;
        std::cout << "||     | 2 - 'trenes.dat'                   |                         //                                        ||" << std::endl;
        std::cout << "||     | 3 - 'estaciones.dat'               |                        //                                         ||" << std::endl;
        std::cout << "||     | 4 - 'tarifas.dat'                  |                       //                                          ||" << std::endl;
        std::cout << "||     | 5 - 'boletos.dat'                  |              [5.VICENTE LOPEZ]                                    ||" << std::endl;
        std::cout << "||     |                                    |                     //                                            ||" << std::endl;
        std::cout << "||     | 6 - TODOS LOS ARCHIVOS             |                    //                                             ||" << std::endl;
        std::cout << "||     |                                    |                   //                                              ||" << std::endl;
        std::cout << "||     | 0 - SALIR                          |                  //                                               ||" << std::endl;
        std::cout << "||     **************************************                 //                                                ||" << std::endl;
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
                BackupPasajeros();
            break;

            case 2:
                BackupTrenes();
            break;

            case 3:
                BackupEstaciones();
            break;

            case 4:
                BackupTarifas();
            break;

            case 5:
                BackupBoletos();
            break;

            case 6:
                BackupTodos();
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

void MenuConfiguraciones::SubMenu_RestaurarBackups(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==================================================================================================================" << std::endl;
        std::cout << "||                                                                                                              ||" << std::endl;
        std::cout << "||     **** RESTAURAR COPIAS DE SEGURIDAD ****                           =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                     |                          //                                      ||" << std::endl;
        std::cout << "||     | 1 - 'pasajeros.dat'                 |                         //                                       ||" << std::endl;
        std::cout << "||     | 2 - 'trenes.dat'                    |                        //                                        ||" << std::endl;
        std::cout << "||     | 3 - 'estaciones.dat'                |                       //                                         ||" << std::endl;
        std::cout << "||     | 4 - 'tarifas.dat'                   |                      //                                          ||" << std::endl;
        std::cout << "||     | 5 - 'boletos.dat'                   |              [5.VICENTE LOPEZ]                                   ||" << std::endl;
        std::cout << "||     |                                     |                    //                                            ||" << std::endl;
        std::cout << "||     | 6 - TODOS LOS ARCHIVOS              |                   //                                             ||" << std::endl;
        std::cout << "||     |                                     |                  //                                              ||" << std::endl;
        std::cout << "||     | 0 - SALIR                           |                 //                                               ||" << std::endl;
        std::cout << "||     ***************************************                //                                                ||" << std::endl;
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
                RestaurarPasajeros();
            break;

            case 2:
                RestaurarTrenes();
            break;

            case 3:
                RestaurarEstaciones();
            break;

            case 4:
                RestaurarTarifas();
            break;

            case 5:
                RestaurarBoletos();
            break;

            case 6:
                RestaurarTodos();
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

void MenuConfiguraciones::SubMenu_ExportarCSV(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==================================================================================================================" << std::endl;
        std::cout << "||                                                                                                              ||" << std::endl;
        std::cout << "||     ****** EXPORTAR EN FORMATO .CSV *******                           =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                     |                          //                                      ||" << std::endl;
        std::cout << "||     | 1 - 'pasajeros.dat'                 |                         //                                       ||" << std::endl;
        std::cout << "||     | 2 - 'trenes.dat'                    |                        //                                        ||" << std::endl;
        std::cout << "||     | 3 - 'estaciones.dat'                |                       //                                         ||" << std::endl;
        std::cout << "||     | 4 - 'tarifas.dat'                   |                      //                                          ||" << std::endl;
        std::cout << "||     | 5 - 'boletos.dat'                   |              [5.VICENTE LOPEZ]                                   ||" << std::endl;
        std::cout << "||     |                                     |                    //                                            ||" << std::endl;
        std::cout << "||     | 6 - TODOS LOS ARCHIVOS              |                   //                                             ||" << std::endl;
        std::cout << "||     |                                     |                  //                                              ||" << std::endl;
        std::cout << "||     | 0 - SALIR                           |                 //                                               ||" << std::endl;
        std::cout << "||     ***************************************                //                                                ||" << std::endl;
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
                ExportarPasajeros();
            break;

            case 2:
                ExportarTrenes();
            break;

            case 3:
                ExportarEstaciones();
            break;

            case 4:
                ExportarTarifas();
            break;

            case 5:
                ExportarBoletos();
            break;

            case 6:
                ExportarTodos();
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

/// ---------- REALIZAR COPIAS DE SEGURIDAD ----------

void MenuConfiguraciones::BackupPasajeros(){

    mostrarTexto("1. REALIZAR COPIA DE SEGIRIDAD - PASAJEROS");

    ManagerConfiguraciones manager;

    if(manager.backupPasajeros() == true){
        mostrarTexto("COPIA DE SEGURIDAD REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REALIZAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::BackupTrenes(){

    mostrarTexto("2. REALIZAR COPIA DE SEGIRIDAD - TRENES");

    ManagerConfiguraciones manager;

    if(manager.backupTrenes() == true){
        mostrarTexto("COPIA DE SEGURIDAD REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REALIZAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::BackupEstaciones(){

    mostrarTexto("3. REALIZAR COPIA DE SEGIRIDAD - ESTACIONES");

    ManagerConfiguraciones manager;

    if(manager.backupEstaciones() == true){
        mostrarTexto("COPIA DE SEGURIDAD REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REALIZAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::BackupTarifas(){

    mostrarTexto("4. REALIZAR COPIA DE SEGIRIDAD - TARIFAS");

    ManagerConfiguraciones manager;

    if(manager.backupTarifas() == true){
        mostrarTexto("COPIA DE SEGURIDAD REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REALIZAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::BackupBoletos(){

    mostrarTexto("5. REALIZAR COPIA DE SEGIRIDAD - BOLETOS");

    ManagerConfiguraciones manager;

    if(manager.backupBoletos() == true){
        mostrarTexto("COPIA DE SEGURIDAD REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REALIZAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::BackupTodos(){

    mostrarTexto("6. REALIZAR COPIA DE SEGIRIDAD - TODOS LOS ARCHIVOS");

    ManagerConfiguraciones manager;

    if(manager.backupTodos() == true){
        mostrarTexto("COPIAS DE SEGURIDAD REALIZADAS CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REALIZAR LAS COPIAS DE SEGURIDAD >");
    }
}

/// ---------- RESTAURAR COPIAS DE SEGURIDAD ----------

void MenuConfiguraciones::RestaurarPasajeros(){

    mostrarTexto("1. RESTAURAR COPIA DE SEGIRIDAD - PASAJEROS");

    ManagerConfiguraciones manager;

    if(manager.restaurarPasajeros() == true){
        mostrarTexto("COPIA DE SEGURIDAD RESTAURADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO RESTAURAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::RestaurarTrenes(){

    mostrarTexto("2. RESTAURAR COPIA DE SEGIRIDAD - TRENES");

    ManagerConfiguraciones manager;

    if(manager.restaurarTrenes() == true){
        mostrarTexto("COPIA DE SEGURIDAD RESTAURADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO RESTAURAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::RestaurarEstaciones(){

    mostrarTexto("3. RESTAURAR COPIA DE SEGIRIDAD - ESTACIONES");

    ManagerConfiguraciones manager;

    if(manager.restaurarEstaciones() == true){
        mostrarTexto("COPIA DE SEGURIDAD RESTAURADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO RESTAURAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::RestaurarTarifas(){

    mostrarTexto("4. RESTAURAR COPIA DE SEGIRIDAD - TARIFAS");

    ManagerConfiguraciones manager;

    if(manager.restaurarTarifas() == true){
        mostrarTexto("COPIA DE SEGURIDAD RESTAURADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO RESTAURAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::RestaurarBoletos(){

    mostrarTexto("5. RESTAURAR COPIA DE SEGIRIDAD - BOLETOS");

    ManagerConfiguraciones manager;

    if(manager.restaurarBoletos() == true){
        mostrarTexto("COPIA DE SEGURIDAD RESTAURADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO RESTAURAR LA COPIA DE SEGURIDAD >");
    }
}

void MenuConfiguraciones::RestaurarTodos(){

    mostrarTexto("6. RESTAURAR COPIA DE SEGIRIDAD - TODOS LOS ARCHIVOS");

    ManagerConfiguraciones manager;

    if(manager.restaurarTodos() == true){
        mostrarTexto("COPIAS DE SEGURIDAD RESTAURADAS CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO RESTAURAR LAS COPIAS DE SEGURIDAD >");
    }
}

/// ---------- EXPORTAR EN FORMATO .CSV ----------

void MenuConfiguraciones::ExportarPasajeros(){

    mostrarTexto("1. EXPORTAR EN FORMATO .CSV - PASAJEROS");

    ManagerConfiguraciones manager;

    if(manager.exportarPasajeros() == true){
        mostrarTexto("EXPORTACION REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EXPORTAR EL ARCHIVO >");
    }
}

void MenuConfiguraciones::ExportarTrenes(){

    mostrarTexto("2. EXPORTAR EN FORMATO .CSV - TRENES");

    ManagerConfiguraciones manager;

    if(manager.exportarTrenes() == true){
        mostrarTexto("EXPORTACION REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EXPORTAR EL ARCHIVO >");
    }
}

void MenuConfiguraciones::ExportarEstaciones(){

    mostrarTexto("3. EXPORTAR EN FORMATO .CSV - ESTACIONES");

    ManagerConfiguraciones manager;

    if(manager.exportarEstaciones() == true){
        mostrarTexto("EXPORTACION REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EXPORTAR EL ARCHIVO >");
    }
}

void MenuConfiguraciones::ExportarTarifas(){

    mostrarTexto("4. EXPORTAR EN FORMATO .CSV - TARIFAS");

    ManagerConfiguraciones manager;

    if(manager.exportarTarifas() == true){
        mostrarTexto("EXPORTACION REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EXPORTAR EL ARCHIVO >");
    }
}

void MenuConfiguraciones::ExportarBoletos(){

    mostrarTexto("5. EXPORTAR EN FORMATO .CSV - BOLETOS");

    ManagerConfiguraciones manager;

    if(manager.exportarBoletos() == true){
        mostrarTexto("EXPORTACION REALIZADA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EXPORTAR EL ARCHIVO >");
    }
}

void MenuConfiguraciones::ExportarTodos(){

    mostrarTexto("6. EXPORTAR EN FORMATO .CSV - TODOS LOS ARCHIVOS");

    ManagerConfiguraciones manager;

    if(manager.exportarTodos() == true){
        mostrarTexto("EXPORTACIONES REALIZADAS CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EXPORTAR LOS ARCHIVOS >");
    }
}
