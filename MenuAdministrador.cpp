#include "MenuAdministrador.h"

#include "MenuPasajeros.h"
#include "MenuTrenes.h"
#include "MenuEstaciones.h"
#include "MenuTarifas.h"
#include "MenuBoletos.h"
#include "MenuConfiguraciones.h"

#include "ManagerAdministradores.h"
#include "ArchivoAdministradores.h"
#include "Administrador.h"

#include "FuncionesGlobales.h"

#include <iostream>

void MenuAdministrador::Menu(){

    if(AntesalaAdministrador() == false){
        mostrarTexto("< ERROR: ADMINISTRADOR NO EXISTENTE >");
        return;
    }

    MenuPasajeros pasajeros;
    MenuTrenes trenes;
    MenuEstaciones estaciones;
    MenuTarifas tarifas;
    MenuBoletos boletos;
    MenuConfiguraciones configuraciones;

    int opcion;

    while(true){
        system("cls");

        std::cout << "=====================================================================================================================" << std::endl;
        std::cout << "||                                                                                                                 ||" << std::endl;
        std::cout << "||     ****** ADMINISTRADORES *******                                       =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                            |                                      //                                      ||" << std::endl;
        std::cout << "||     | 1 - MENU PASAJEROS         |                                     //                                       ||" << std::endl;
        std::cout << "||     | 2 - MENU TRENES            |                                    //                                        ||" << std::endl;
        std::cout << "||     | 3 - MENU ESTACIONES        |                                   //                                         ||" << std::endl;
        std::cout << "||     | 4 - MENU TARIFAS           |                                  //                                          ||" << std::endl;
        std::cout << "||     | 5 - MENU BOLETOS           |                                 //                                           ||" << std::endl;
        std::cout << "||     |                            |                          [5.VICENTE LOPEZ]                                   ||" << std::endl;
        std::cout << "||     | 6 - CONFIGURACIONES        |                               //                                             ||" << std::endl;
        std::cout << "||     |                            |                              //                                              ||" << std::endl;
        std::cout << "||     | 7 - 'ABML' ADMINISTRADORES |                             //                                               ||" << std::endl;
        std::cout << "||     |                            |                            //                                                ||" << std::endl;
        std::cout << "||     | 0 - SALIR                  |                           //                                                 ||" << std::endl;
        std::cout << "||     |                            |                          //                                                  ||" << std::endl;
        std::cout << "||     ******************************                   [4.MARTINEZ]                                               ||" << std::endl;
        std::cout << "||                                                           //                                                    ||" << std::endl;
        std::cout << "||                                                          //                                                     ||" << std::endl;
        std::cout << "||                                                         //                                                      ||" << std::endl;
        std::cout << "||                                                        //                                                       ||" << std::endl;
        std::cout << "||                                                       //                                                        ||" << std::endl;
        std::cout << "||                                                      //                                                         ||" << std::endl;
        std::cout << "||     [1.TIGRE]=====[2.SAN FERNANDO]=====[3.BECCAR]=====                                                          ||" << std::endl;
        std::cout << "||                                                                                                                 ||" << std::endl;
        std::cout << "=====================================================================================================================" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        system("cls");

        switch(opcion){

            case 1:
                pasajeros.Menu();
            break;

            case 2:
                trenes.Menu();
            break;

            case 3:
                estaciones.Menu();
            break;

            case 4:
                tarifas.Menu();
            break;

            case 5:
                boletos.Menu();
            break;

            case 6:
                configuraciones.Menu();
            break;

            case 7:
                AdministradoresABML();
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

void MenuAdministrador::AdministradoresABML(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "================================================================================================================" << std::endl;
        std::cout << "||                                                                                                            ||" << std::endl;
        std::cout << "||     ***** 'ABML' ADMINISTRADORES *****                              =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                |                             //                                      ||" << std::endl;
        std::cout << "||     | 1 - CARGAR ADMINISTRADOR       |                            //                                       ||" << std::endl;
        std::cout << "||     | 2 - ALTA ADMINISTRADOR         |                           //                                        ||" << std::endl;
        std::cout << "||     | 3 - BAJA ADMINISTRADOR         |                          //                                         ||" << std::endl;
        std::cout << "||     | 4 - LISTADOS                   |                         //                                          ||" << std::endl;
        std::cout << "||     |                                |                 [5.VICENTE LOPEZ]                                   ||" << std::endl;
        std::cout << "||     | 0 - SALIR                      |                       //                                            ||" << std::endl;
        std::cout << "||     |                                |                      //                                             ||" << std::endl;
        std::cout << "||     **********************************                [4.MARTINEZ]                                         ||" << std::endl;
        std::cout << "||                                                           //                                               ||" << std::endl;
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
                CargarAdministrador();
            break;

            case 2:
                AltaAdministrador();
            break;

            case 3:
                BajaAdministrador();
            break;

            case 4:
                ListadoAdministradores();
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

bool MenuAdministrador::AntesalaAdministrador(){

    system("cls");

    ManagerAdministradores manager;
    ArchivoAdministradores archivo;

    if(archivo.getCantidadRegistros() == 0){

        Administrador registro;

        registro = manager.cargarPrimerAdministrador();

        archivo.guardar(registro);

        return true;
    }

    mostrarTexto("INGRESO DE ADMINISTRADOR");

    char usuario[30];
    char contrasenia[30];

    std::cout << "USUARIO: ";
    cargarCadena(usuario, sizeof(usuario) - 1);
    std::cout << "CONTRASENIA: ";
    cargarCadena(contrasenia, sizeof(contrasenia) - 1);

    if(manager.validarUsuarioContrasenia(usuario, contrasenia) == true){
        return true;
    }

    return false;
}

void MenuAdministrador::CargarAdministrador(){

    mostrarTexto("1. CARGAR ADMINISTRADOR");

    ManagerAdministradores manager;

    if(manager.altaAdministrador() == true){
        mostrarTexto("ADMINISTRADOR REGISTRADO CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REGISTRAR AL ADMINISTRADOR >");
    }
}

void MenuAdministrador::AltaAdministrador(){

    mostrarTexto("2. ADMINISTRADORES - ALTA LOGICA");

    ManagerAdministradores manager;

    char usuario[30];
    char contrasenia[30];

    std::cout << "USUARIO: ";
    cargarCadena(usuario, sizeof(usuario) - 1);
    std::cout << "CONTRASENIA: ";
    cargarCadena(contrasenia, sizeof(contrasenia) - 1);

    if(manager.validarUsuarioContrasenia(usuario, contrasenia) == true){

        if(manager.esAdministradorPrincipal(usuario) == true){

            char dni[10];
            std::cout << "DNI A DAR DE ALTA: ";
            cargarCadena(dni, sizeof(dni) - 1);

            ///NUEVO METODO PARA SABER SI SE ENCUNTRA YA ACTIVO EL ADMINISTRADOR
            Administrador administradorAbuscar=manager.obtenerAdministradorConDNI(dni);

            if(administradorAbuscar.getEstado()==true){
                mostrarTexto("EL ADMINISTRADOR YA SE ENCUENTRA ACTIVO");
                administradorAbuscar.mostrar();
                return;
            }

            if(manager.altaLogica(dni) == true){
                mostrarTexto("ADMINISTRADOR DADO DE ALTA CON EXITO!");
            }
            else{
                mostrarTexto("< ERRROR: NO SE LOGRO DAR DE ALTA AL ADMINISTRADOR >");
            }
        }
        else{
            mostrarTexto("< ERROR: NO TIENE LOS PERMISOS NECESARIOS >");
        }
    }
    else{
        mostrarTexto("< ERROR: NO EXISTE EL ADMINISTRADOR EN EL SISTEMA >");
    }
}

void MenuAdministrador::BajaAdministrador(){

    mostrarTexto("3. ADMINISTRADORES - BAJA LOGICA");

    ManagerAdministradores manager;

    char usuario[30];
    char contrasenia[30];

    std::cout << "USUARIO: ";
    cargarCadena(usuario, sizeof(usuario) - 1);
    std::cout << "CONTRASENIA: ";
    cargarCadena(contrasenia, sizeof(contrasenia) - 1);
    std::cout << std::endl;

    if(manager.validarUsuarioContrasenia(usuario, contrasenia) == true){

        if(manager.esAdministradorPrincipal(usuario) == true){

            char dni[10];
            std::cout << "DNI A DAR DE BAJA: ";
            cargarCadena(dni, sizeof(dni) - 1);

            ///NUEVO METODO PARA SABER SI SE ENCUNTRA DADO DE BAJA EL ADMINISTRADOR
            Administrador administradorAbuscar=manager.obtenerAdministradorConDNI(dni);

            if (administradorAbuscar.getIdAdministrador() == 0) {
                mostrarTexto("ERROR: EL ADMINISTRADOR CON ESE DNI NO SE ENCUENTRA EN EL SISTEMA ");
                return;
            }

            if(administradorAbuscar.getEstado()==false){
                mostrarTexto("EL ADMINISTRADOR YA SE ENCUENTRA DADO DE BAJA");
                administradorAbuscar.mostrar();
                return;
            }

            if(manager.bajaLogica(dni) == true){
                mostrarTexto("ADMINISTRADOR DADO DE BAJA CON EXITO!");
            }
            else{
                mostrarTexto("< ERRROR: NO SE LOGRO DAR DE BAJA AL ADMINISTRADOR >");
            }
        }
        else{
            mostrarTexto("< ERROR: NO TIENE LOS PERMISOS NECESARIOS >");
        }

    }
    else{
        mostrarTexto("< ERROR: NO EXISTE EL ADMINISTRADOR EN EL SISTEMA >");
    }
}

void MenuAdministrador::ListadoAdministradores(){

    mostrarTexto("4. ADMINISTRADORES - LISTADOS ORDDENADOS POR ID");

    ManagerAdministradores manager;

    char usuario[30];
    char contrasenia[30];

    std::cout << "USUARIO: ";
    cargarCadena(usuario, sizeof(usuario) - 1);
    std::cout << "CONTRASENIA: ";
    cargarCadena(contrasenia, sizeof(contrasenia) - 1);
    std::cout << std::endl;

    if(manager.validarUsuarioContrasenia(usuario, contrasenia) == true){

        if(manager.esAdministradorPrincipal(usuario) == true){

            if(manager.listadoPorID() == false){
                mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LOS LISTADOS >");
            }
        }
        else{
            mostrarTexto("< ERROR: NO TIENE LOS PERMISOS NECESARIOS");
        }
    }
    else{
        mostrarTexto("< ERROR: NO EXISTE EL ADMINISTRADOR EN EL SISTEMA >");
    }
}
