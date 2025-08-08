#include "ManagerConfiguraciones.h"
#include "ArchivoPasajeros.h"
#include "ArchivoTrenes.h"
#include "ArchivoEstaciones.h"
#include "ArchivoTarifas.h"
#include "ArchivoBoletos.h"

#include <iostream>

/// ---------- REALIZAR COPIAS DE SEGURIDAD ----------
bool ManagerConfiguraciones::backupPasajeros(){

    ArchivoPasajeros archivo;

    if(archivo.copiaDeSeguridad() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::backupTrenes(){

    ArchivoTrenes archivo;

    if(archivo.copiaDeSeguridad() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::backupEstaciones(){

    ArchivoEstaciones archivo;

    if(archivo.copiaDeSeguridad() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::backupTarifas(){

    ArchivoTarifas archivo;

    if(archivo.copiaDeSeguridad() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::backupBoletos(){

    ArchivoBoletos archivo;

    if(archivo.copiaDeSeguridad() == true){
        return true;
    }

    return false;
}

int ManagerConfiguraciones::backupTodos(){
    if(backupPasajeros() == false){
        return -1;
    }
    else{
        if(backupTrenes() == false){
            return -2;
        }
        else{
            if(backupEstaciones() == false){
                return -3;
            }
            else{
                if(backupTarifas() == false){
                    return -4;
                }
                else{
                    if(backupBoletos() == false){
                        return -5;
                    }
                }
            }
        }
    }

    return 1;
}

/// ---------- RESTAURAR COPIAS DE SEGURIDAD ----------

bool ManagerConfiguraciones::restaurarPasajeros(){

    ArchivoPasajeros archivo;

    if(archivo.restaurarCopiaDeSeguridad() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::restaurarTrenes(){

    ArchivoTrenes archivo;

    if(archivo.restaurarCopiaDeSeguridad() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::restaurarEstaciones(){

    ArchivoEstaciones archivo;

    if(archivo.restaurarCopiaDeSeguridad() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::restaurarTarifas(){

    ArchivoTarifas archivo;

    if(archivo.restaurarCopiaDeSeguridad() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::restaurarBoletos(){

    ArchivoBoletos archivo;

    if(archivo.restaurarCopiaDeSeguridad() == true){
        return true;
    }

    return false;
}

int ManagerConfiguraciones::restaurarTodos(){
    if(restaurarPasajeros() == false){
        return -1;
    }
    else{
        if(restaurarTrenes() == false){
            return -2;
        }
        else{
            if(restaurarEstaciones() == false){
                return -3;
            }
            else{
                if(restaurarTarifas() == false){
                    return -4;
                }
                else{
                    if(restaurarBoletos() == false){
                        return -5;
                    }
                }
            }
        }
    }

    return 1;
}

/// ---------- EXPORTAR EN FORMATO .CSV ----------

bool ManagerConfiguraciones::exportarPasajeros(){

    ArchivoPasajeros archivo;

    if(archivo.exportarCSV() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::exportarTrenes(){

    ArchivoTrenes archivo;

    if(archivo.exportarCSV() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::exportarEstaciones(){

    ArchivoEstaciones archivo;

    if(archivo.exportarCSV() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::exportarTarifas(){

    ArchivoTarifas archivo;

    if(archivo.exportarCSV() == true){
        return true;
    }

    return false;
}

bool ManagerConfiguraciones::exportarBoletos(){

    ArchivoBoletos archivo;

    if(archivo.exportarCSV() == true){
        return true;
    }

    return false;
}

int ManagerConfiguraciones::exportarTodos(){
    if(exportarPasajeros() == false){
        return -1;
    }
    else{
        if(exportarTrenes() == false){
            return -2;
        }
        else{
            if(exportarEstaciones() == false){
                return -3;
            }
            else{
                if(exportarTarifas() == false){
                    return -4;
                }
                else{
                    if(exportarBoletos() == false){
                        return -5;
                    }
                }
            }
        }
    }

    return 1;
}
