#include "MenuUsuario.h"

#include "ManagerPasajeros.h"
#include "ManagerTrenes.h"
#include "ManagerEstaciones.h"
#include "ManagerTarifas.h"
#include "ManagerBoletos.h"

#include "FuncionesGlobales.h"

#include <iostream>

/// ---------- FUNCIONES DE MENU ----------

void MenuUsuario::Menu(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "====================================================================================================================" << std::endl;
        std::cout << "||                                                                                                                ||" << std::endl;
        std::cout << "||     ********* USUARIOS *********                                        =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                          |                                       //                                      ||" << std::endl;
        std::cout << "||     | 1 - SACAR BOLETO         |                                      //                                       ||" << std::endl;
        std::cout << "||     | 2 - VER TRENES           |                                     //                                        ||" << std::endl;
        std::cout << "||     | 3 - VER ESTACIONES       |                                    //                                         ||" << std::endl;
        std::cout << "||     | 4 - VER TARIFAS          |                                   //                                          ||" << std::endl;
        std::cout << "||     |                          |                            [5.VICENTE LOPEZ]                                  ||" << std::endl;
        std::cout << "||     | 5 - REGISTRARSE          |                                 //                                            ||" << std::endl;
        std::cout << "||     | 6 - DARSE DE BAJA        |                                //                                             ||" << std::endl;
        std::cout << "||     | 7 - HISTORIAL DE BOLETOS |                               //                                              ||" << std::endl;
        std::cout << "||     |                          |                              //                                               ||" << std::endl;
        std::cout << "||     | 0 - SALIR                |                             //                                                ||" << std::endl;
        std::cout << "||     |                          |                            //                                                 ||" << std::endl;
        std::cout << "||     ****************************                           //                                                  ||" << std::endl;
        std::cout << "||                                                      [4.MARTINEZ]                                              ||" << std::endl;
        std::cout << "||                                                          //                                                    ||" << std::endl;
        std::cout << "||                                                         //                                                     ||" << std::endl;
        std::cout << "||                                                        //                                                      ||" << std::endl;
        std::cout << "||                                                       //                                                       ||" << std::endl;
        std::cout << "||                                                      //                                                        ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                         ||" << std::endl;
        std::cout << "||                                                                                                                ||" << std::endl;
        std::cout << "====================================================================================================================" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        system("cls");

        switch(opcion){

            case 1:
                SacarBoleto();
            break;

            case 2:
                VerTrenes();
            break;

            case 3:
                VerEstaciones();
            break;

            case 4:
                VerTarifas();
            break;

            case 5:
                Registrarse();
            break;

            case 6:
                DarseDeBaja();
            break;

            case 7:
                HistorialBoletos();
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

/// ---------- FUNCIONES DE USUARIO ----------

void MenuUsuario::SacarBoleto(){

    mostrarTexto("1. SACAR BOLETO");

    std::cout << std::endl;
    std::cout << "[1.TIGRE]===[2.SAN FERNANDO]===[3.BECCAR]===[4.MARTINEZ]===[5.VICENTE LOPEZ]===[6.BELGRANO C]===[7.RETIRO]" << std::endl;
    std::cout << std::endl;

    ManagerBoletos manager;

    if(manager.altaBoleto() == true){
        mostrarTexto("BOLETO REGISTRADO CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REGISTRAR EL BOLETO >");
    }
}

void MenuUsuario::VerTrenes(){

    mostrarTexto("2. VISUALIZAR TRENES ");

    ManagerTrenes manager;

    if(manager.listadoPorID() == false){
        mostrarTexto("< ERROR: NO SE LOGRO VISUALIZAR LOS TRENES >");
    }
}

void MenuUsuario::VerEstaciones(){

    mostrarTexto("3. VISUALIZAR ESTACIONES ");

    ManagerEstaciones manager;

    if(manager.listadoPorIdEstacion() == false){
        mostrarTexto("< ERROR: NO SE LOGRO VISUALIZAR LAS ESTACIONES >");
    }
}

void MenuUsuario::VerTarifas(){

    mostrarTexto("4. VISUALIZAR TARIFAS");

    ManagerTarifas manager;

    if(manager.listadoPorIdTarifa() == false){
        mostrarTexto("< ERROR: NO SE LOGRO VISUALIZAR LAS TARIFAS >");
    }
}

void MenuUsuario::Registrarse(){

    mostrarTexto("5. REGISTRO DE PASAJERO");

    ManagerPasajeros manager;

    if(manager.altaPasajero() == true){
        mostrarTexto("PASAJERO REGISTRADO CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REGISTRAR EL PASAJERO >");
    }
}

void MenuUsuario::DarseDeBaja(){

    mostrarTexto("6. BAJA DE PASAJERO");

    ManagerPasajeros manager;

    char dni[10];
    std::cout << "DNI: ";
    cargarCadena(dni, sizeof(dni) - 1);

    if(manager.bajaLogica(dni) == true){
        mostrarTexto("PASAJERO DADO DE BAJA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO DAR DE BAJA AL PASAJERO");
    }
}

void MenuUsuario::HistorialBoletos(){

    mostrarTexto("7. HISTORIAL DE BOLETOS");

    ManagerBoletos manager;

    if(manager.consultaPorDniPasajero() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL HISTORAIL DE BOLETOS DEL PASAJERO");
    }
}
