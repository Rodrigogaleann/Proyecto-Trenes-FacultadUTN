#include "MenuTrenes.h"
#include "ManagerTrenes.h"
#include "Tren.h"

#include "FuncionesGlobales.h"

#include <iostream>

/// ---------- FUNCIONES DE MENU ----------

void MenuTrenes::Menu(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "===================================================================================================================" << std::endl;
        std::cout << "||                                                                                                               ||" << std::endl;
        std::cout << "||     ******** MENU TRENES *********                                     =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                            |                                    //                                      ||" << std::endl;
        std::cout << "||     | 1 - CARGAR TREN            |                                   //                                       ||" << std::endl;
        std::cout << "||     | 2 - EDITAR TREN            |                                  //                                        ||" << std::endl;
        std::cout << "||     | 3 - ALTA LOGICA            |                                 //                                         ||" << std::endl;
        std::cout << "||     | 4 - BAJA LOGICA            |                                //                                          ||" << std::endl;
        std::cout << "||     | 5 - LISTADOS               |                        [5.VICENTE LOPEZ]                                   ||" << std::endl;
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

void MenuTrenes::SubMenu_Listados(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==============================================================================================================" << std::endl;
        std::cout << "||                                                                                                          ||" << std::endl;
        std::cout << "||     ******* LISTADOS - TRENES ********                            =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                |                           //                                      ||" << std::endl;
        std::cout << "||     | 1 - LISTADO POR ID DE TREN     |                          //                                       ||" << std::endl;
        std::cout << "||     | 2 - LISTADO POR ESTADO DE TREN |                         //                                        ||" << std::endl;
        std::cout << "||     |                                |                [5.VICENTE LOPEZ]                                  ||" << std::endl;
        std::cout << "||     | 0 - SALIR                      |                       //                                          ||" << std::endl;
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
                ListadoPorId();
            break;

            case 2:
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

void MenuTrenes::SubMenu_Consultas(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "==============================================================================================================" << std::endl;
        std::cout << "||                                                                                                          ||" << std::endl;
        std::cout << "||     ******** CONSULTAS - TRENES ********                          =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                  |                         //                                      ||" << std::endl;
        std::cout << "||     | 1 - CONSULTAS POR ID DE TREN     |                        //                                       ||" << std::endl;
        std::cout << "||     | 2 - CONSULTAS POR ESTADO DE TREN |                       //                                        ||" << std::endl;
        std::cout << "||     |                                  |              [5.VICENTE LOPEZ]                                  ||" << std::endl;
        std::cout << "||     | 0 - SALIR                        |                     //                                          ||" << std::endl;
        std::cout << "||     |                                  |                    //                                           ||" << std::endl;
        std::cout << "||     ************************************                   //                                            ||" << std::endl;
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
                ConsultaPorId();
            break;

            case 2:
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

void MenuTrenes::SubMenu_Informes(){

    int opcion;

    while(true){
        system("cls");

        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "||                                                                                                           ||" << std::endl;
        std::cout << "||     ********** INFORMES - TRENES ***********                       =====[6.BELGRANO C]=====[7.RETIRO]     ||" << std::endl;
        std::cout << "||     |                                      |                      //                                      ||" << std::endl;
        std::cout << "||     | 1 - CANTIDAD DE TRENES OPERATIVOS    |                     //                                       ||" << std::endl;
        std::cout << "||     | 2 - CANTIDAD DE TRENES NO OPERATIVOS |                    //                                        ||" << std::endl;
        std::cout << "||     | 3 - OCUPACION PROMEDIO DEL DIA       |            [5.VICENTE LOPEZ]                                 ||" << std::endl;
        std::cout << "||     |                                      |                  //                                          ||" << std::endl;
        std::cout << "||     | 0 - SALIR                            |                 //                                           ||" << std::endl;
        std::cout << "||     |                                      |                //                                            ||" << std::endl;
        std::cout << "||     ****************************************               //                                             ||" << std::endl;
        std::cout << "||                                                           //                                              ||" << std::endl;
        std::cout << "||                                                          //                                               ||" << std::endl;
        std::cout << "||                                                    [4.MARTINEZ]                                           ||" << std::endl;
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
                InformeCantidadTrenesOperativos();
            break;

            case 2:
                InformeCantidadTrenesNoOperativos();
            break;

            case 3:
                InformeOcupacionPromedioDelDia();
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

void MenuTrenes::Cargar(){

    mostrarTexto("1. CARGAR TREN");

    ManagerTrenes manager;

    if(manager.altaTren() == true){
        mostrarTexto("TREN REGISTRADO CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO REGISTRAR EL TREN >");
    }
}

void MenuTrenes::Editar(){

    mostrarTexto("2. EDITAR TREN");

    ManagerTrenes manager;

    if(manager.modificacionTren() == true){
        mostrarTexto("TREN EDITADO CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO EDITAR EL TREN >");
    }
}

void MenuTrenes::AltaLogica(){

    mostrarTexto("3. TRENES - ALTA LOGICA");

    ManagerTrenes manager;

    int id;
    std::cout << "INGRESE EL ID DEL TREN: ";
    std::cin >> id;

    Tren trenAbuscar=manager.obtenerTren(id);

    if(trenAbuscar.getEstado()==true){
        mostrarTexto("EL TREN YA SE ENCUENTRA ACTIVO");
        return;
    }

    if(manager.altaLogica(id) == true){
        mostrarTexto("TREN DADO DE ALTA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO DAR DE ATLA AL TREN >");
    }
}

void MenuTrenes::BajaLogica(){

    mostrarTexto("4. TRENES - BAJA LOGICA");

    ManagerTrenes manager;

    int id;
    std::cout << "INGRESE EL ID DEL TREN: ";
    std::cin >> id;

    Tren trenAbuscar=manager.obtenerTren(id);

    if(trenAbuscar.getEstado()==false){
        mostrarTexto("EL TREN YA SE ENCUENTRA DADO DE BAJA");
        return;
    }

    if(manager.bajaLogica(id) == true){
        mostrarTexto("TREN DADO DE BAJA CON EXITO!");
    }
    else{
        mostrarTexto("< ERROR: NO SE LOGRO DAR DE BAJA AL TREN >");
    }
}

/// ---------- LISTADOS ----------

void MenuTrenes::ListadoPorId(){

    mostrarTexto("1. TRENES - LISTADO ORDENADO POR ID");

    ManagerTrenes manager;

    if(manager.listadoPorID() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ID >");
    }
}

void MenuTrenes::ListadoPorEstado(){

    mostrarTexto("2. TRENES - LISTADO ORDENADO POR ESTADO");

    ManagerTrenes manager;

    if(manager.listadoPorEstado() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR EL LISTADO ORDENADO POR ESTADO >");
    }
}

/// ---------- CONSULTAS ----------

void MenuTrenes::ConsultaPorId(){

    mostrarTexto("1. TRENES - CONSULTA POR ID");

    ManagerTrenes manager;

    if(manager.consultaPorID() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ID >");
    }
}

void MenuTrenes::ConsultaPorEstado(){

    mostrarTexto("2. TRENES - CONSULTA POR ESTADO");

    ManagerTrenes manager;

    if(manager.consultaPorEstado() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR LAS CONSULTAS POR ESTADO >");
    }
}

/// ---------- INFORMES ----------

void MenuTrenes::InformeCantidadTrenesOperativos(){

    mostrarTexto("1. TRENES - INFORME DE LA CANTIDAD DE TRENES OPERATIVOS");

    ManagerTrenes manager;

    if(manager.informeCantidadTrenesOperativos() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR INFORME DE LA CANTIDAD DE TRENES OPERATIVOS >");
    }
}

void MenuTrenes::InformeCantidadTrenesNoOperativos(){

    mostrarTexto("2. TRENES - INFORME DE LA CANTIDAD DE TRENES NO OPERATIVOS");

    ManagerTrenes manager;

    if(manager.informeCantidadTrenesNoOperativos() == false){
        mostrarTexto("< ERROR: NO SE LOGRO MOSTRAR INFORME DE LA CANTIDAD DE TRENES NO OPERATIVOS >");
    }
}

void MenuTrenes::InformeOcupacionPromedioDelDia(){

    mostrarTexto("3. TRENES - INFORME DE OCUPACION PROMEDIO DEL DIA ACTUAL");

    ManagerTrenes manager;

    if(manager.informeOcupacionPromedio() == false){
        mostrarTexto("< ERRRO: NO SE LOGRO MOSTRAR LA OCUPACION PROMEDIO DEL DIA ACTUAL >");
    }
}
