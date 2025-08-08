#include "MenuUsuario.h"
#include "MenuAdministrador.h"

#include "FuncionesGlobales.h"
#include <ctime>
#include <iostream>

void MenuPrincipal(){

    MenuUsuario usuario;
    MenuAdministrador administrador;

    int opcion;

    while(true){
        system("cls");

        std::cout << "==============================================================================================================" << std::endl;
        std::cout << "||                                                                                                          ||" << std::endl;
        std::cout << "||     ********* MENU PRINCIPAL *********                            =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                |                           //                                      ||" << std::endl;
        std::cout << "||     | 1 - SISTEMA DE USUARIOS        |                          //                                       ||" << std::endl;
        std::cout << "||     | 2 - SISTEMA DE ADMINISTRADORES |                         //                                        ||" << std::endl;
        std::cout << "||     |                                |                 [5.VICENTE LOPEZ]                                 ||" << std::endl;
        std::cout << "||     | 0- SALIR                       |                       //                                          ||" << std::endl;
        std::cout << "||     |                                |                      //                                           ||" << std::endl;
        std::cout << "||     **********************************                     //                                            ||" << std::endl;
        std::cout << "||                                                           //                                             ||" << std::endl;
        std::cout << "||                                                          //                                              ||" << std::endl;
        std::cout << "||                                                    [4.MARTINEZ]                                          ||" << std::endl;
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
                usuario.Menu();
            break;

            case 2:
                administrador.Menu();
            break;

            case 0:
                mostrarTexto("CERRANDO SISTEMA. GRACIAS POR UTILIZAR EL SISTEMA DE GESTION DE TRENES!");
                return;
            break;

            default:
                mostrarTexto("< ERROR: OPCION NO VALIDA. INTENTE NUEVAMENTE >");
            break;
        }

        system("pause");
    }
}

int main()
{
    MenuPrincipal();

    return 0;
}

/// "time_t" DEL DOMINGO 20/7/2025: 1753050717;
