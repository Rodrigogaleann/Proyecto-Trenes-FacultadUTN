#include "ManagerBoletos.h"
#include "ArchivoBoletos.h"
#include "Boleto.h"

#include "ManagerEstaciones.h"
#include "ArchivoEstaciones.h"
#include "Estacion.h"

#include "ManagerPasajeros.h"
#include "ManagerTarifas.h"
#include "ManagerTrenes.h"

#include "FuncionesGlobales.h"
#include "FechaHoraSistema.h"

#include <iostream>
#include <cstring>
#include <ctime>

/// ------------------------------------------------ MÉTODOS GENERALES ------------------------------------------------

bool ManagerBoletos::cargarVector(Boleto *registros, int tam)
{

    ArchivoBoletos archivo;

    /// ALMACENO LOS REGISTROS DEL ARCHIVO DENTRO DEL NUEVO VECTOR
    for(int i=0; i<tam; i++)
    {
        registros[i] = archivo.leer(i);
    }

    return true;
}

int ManagerBoletos::obtenerProximoIdBoleto()
{

    ArchivoBoletos archivo;

    int id = archivo.getCantidadRegistros() + 1;

    return id;
}

Boleto ManagerBoletos::obtenerBoleto(int id)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if(registro.getIDBoleto() == id)
        {
            return registro;
        }
    }

    return Boleto();
}

float ManagerBoletos::obtenerTotalRecaudado()
{

    Boleto registro;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();
    float totalRecaudado = 0;

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        totalRecaudado += registro.getPrecioPagado();
    }

    return totalRecaudado;
}

bool ManagerBoletos::obtenerVentasPorEstacionOrigen(int *v, int tamEstaciones)
{

    Boleto registro;
    ArchivoBoletos archivoBoletos;

    int tamBoletos = archivoBoletos.getCantidadRegistros();
    if(tamBoletos == 0)
    {
        return false;
    }

    for(int i=0; i<tamEstaciones; i++)
    {

        for(int j=0; j<tamBoletos; j++)
        {

            registro = archivoBoletos.leer(j);

            if(registro.getEstacionOrigen().getIDEstacion() == i + 1)
            {
                v[i] ++;
            }
        }
    }

    return true;
}

bool ManagerBoletos::obtenerVentasPorEstacionDestino(int *v, int tamEstaciones)
{

    Boleto registro;
    ArchivoBoletos archivoBoletos;

    int tamBoletos = archivoBoletos.getCantidadRegistros();
    if(tamBoletos == 0)
    {
        return false;
    }

    for(int i=0; i<tamEstaciones; i++)
    {

        for(int j=0; j<tamBoletos; j++)
        {

            registro = archivoBoletos.leer(j);

            if(registro.getEstacionDestino().getIDEstacion() == i + 1)
            {
                v[i] ++;
            }
        }
    }

    return true;
}

int ManagerBoletos::obtenerIdEstacionMayorVentas(int *v, int tamEstaciones)
{

    int id;
    int cantMax = 0;

    for(int i=0; i<tamEstaciones; i++)
    {

        if(v[i] > cantMax)
        {
            cantMax = v[i];
            id = i + 1;
        }
    }

    return id;
}

int ManagerBoletos::obtenerCantidadEstacionMayorVentas(int *v, int tamEstaciones)
{

    int cantMax = 0;

    for(int i=0; i<tamEstaciones; i++)
    {

        if(v[i] > cantMax)
        {
            cantMax = v[i];
        }
    }

    return cantMax;
}

Estacion ManagerBoletos::obtenerEstacionOrigenConMayorVentas()
{

    ArchivoEstaciones archivoEstaciones;

    int tamEstaciones = archivoEstaciones.getCantidadRegistros();
    if(tamEstaciones == 0)
    {
        /// EL ARCHIVO NO TIENE REGISTROS
        return Estacion();
    }

    int *cantEstaciones = new int[tamEstaciones];
    if(cantEstaciones == nullptr)
    {
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] cantEstaciones;
        return Estacion();
    }

    if(ponerVectorEnCero(cantEstaciones, tamEstaciones) == false)
    {
        delete [] cantEstaciones;
        return Estacion();
    }

    if(obtenerVentasPorEstacionOrigen(cantEstaciones, tamEstaciones) == false)
    {
        delete [] cantEstaciones;
        return Estacion();
    }

    int id = obtenerIdEstacionMayorVentas(cantEstaciones, tamEstaciones);

    delete [] cantEstaciones;

    /// DEVUELVO LA ESTACION ORIGEN CON MAYOR VENTAS
    ManagerEstaciones manager;

    return manager.obtenerEstacion(id);
}

Estacion ManagerBoletos::obtenerEstacionDestinoConMayorVentas()
{

    ArchivoEstaciones archivoEstaciones;

    int tamEstaciones = archivoEstaciones.getCantidadRegistros();
    if(tamEstaciones == 0)
    {
        /// EL ARCHIVO NO TIENE REGISTROS
        return Estacion();
    }

    int *cantEstaciones = new int[tamEstaciones];
    if(cantEstaciones == nullptr)
    {
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] cantEstaciones;
        return Estacion();
    }

    if(ponerVectorEnCero(cantEstaciones, tamEstaciones) == false)
    {
        delete [] cantEstaciones;
        return Estacion();
    }

    if(obtenerVentasPorEstacionDestino(cantEstaciones, tamEstaciones) == false)
    {
        delete [] cantEstaciones;
        return Estacion();
    }

    int id = obtenerIdEstacionMayorVentas(cantEstaciones, tamEstaciones);

    delete [] cantEstaciones;

    /// DEVUELVO LA ESTACION DESTINO CON MAYOR VENTAS
    ManagerEstaciones manager;

    return manager.obtenerEstacion(id);
}

int ManagerBoletos::obtenerIdBoletoMasCaro()
{

    Boleto registro;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();

    int idBoleto;
    float boletoMasCaro = 0;

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if(registro.getPrecioPagado() > boletoMasCaro)
        {
            boletoMasCaro = registro.getPrecioPagado();
            idBoleto = registro.getIDBoleto();
        }
    }

    return idBoleto;
}

float ManagerBoletos::obtenerValorBoletoMasCaro()
{

    Boleto registro;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();

    float boletoMasCaro = 0;

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if(registro.getPrecioPagado() > boletoMasCaro)
        {
            boletoMasCaro = registro.getPrecioPagado();
        }
    }

    return boletoMasCaro;
}

bool ManagerBoletos::confirmarCompra(Boleto registro)
{

    int opc;

    system("cls");
    mostrarTexto("INFORMACION DEL BOLETO");
    registro.mostrar();
    std::cout << std::endl;
    std::cout << "DESEA CONFIRMAR LA COMPRA? (1-SI / 0-NO): ";
    std::cin >> opc;
    if(opc == 1)
    {
        system("pause");
        return true;
    }

    system("pause");
    return false;
}

bool ManagerBoletos::reiniciarTrenes()
{

    Boleto registro;
    ArchivoBoletos archivo;
    ManagerTrenes managerTrenes;

    int tam = archivo.getCantidadRegistros();
    if(tam == 0)
    {
        return false;
    }

    registro = archivo.leer(tam - 1);

    FechaHoraSistema fechaUltimoBoleto = registro.getFechaHoraSistema();
    FechaHoraSistema fechaActual = time(nullptr);

    if(compararFechas(fechaUltimoBoleto, fechaActual) == true)
    {

        if(managerTrenes.reiniciarTrenes())
        {
            return true;
        }
    }

    return false;
}

/// ------------------------------------------------ MÉTODOS DE VALIDACIÓN ------------------------------------------------

bool ManagerBoletos::validarIdBoleto(int id)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if(registro.getIDBoleto() == id)
        {
            return true;
        }
    }

    return false;
}

bool ManagerBoletos::validarIdTren(int id)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if(registro.getIDTren() == id)
        {
            return true;
        }
    }

    return false;
}

bool ManagerBoletos::validarDni(const char *dni)
{

    Boleto registros;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registros = archivo.leer(i);

        if( stricmp(registros.getDniPasajero(), dni) == 0 )
        {
            return true;
        }
    }

    return false;
}

bool ManagerBoletos::validarEstacionOrigen(const char *nombreEstacion)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if( stricmp(registro.getEstacionOrigen().getNombreEstacion(), nombreEstacion) == 0 )
        {
            return true;
        }
    }

    return false;
}

bool ManagerBoletos::validarEstacionDestino(const char *nombreEstacion)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if( stricmp(registro.getEstacionDestino().getNombreEstacion(), nombreEstacion) == 0 )
        {
            return true;
        }
    }

    return false;
}

bool ManagerBoletos::validarPrecioPagado(float precioPagado)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if(registro.getPrecioPagado() == precioPagado)
        {
            return true;
        }
    }

    return false;
}

/// ------------------------------------------------ METODOS DE COINCIDENCIAS ------------------------------------------------

int ManagerBoletos::coincidenciasIdBoleto(int idBoleto)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if(registro.getIDBoleto() == idBoleto)
        {
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerBoletos::coincidenciasIdTren(int idTren)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if(registro.getIDTren() == idTren)
        {
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerBoletos::coincidenciasDniPasajero(const char *dni)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if( stricmp(registro.getDniPasajero(), dni) == 0)
        {
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerBoletos::coincidenciasEstacionOrigen(const char *nombreEstacion)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if( stricmp(registro.getEstacionOrigen().getNombreEstacion(), nombreEstacion) == 0 )
        {
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerBoletos::coincidenciasEstacionDestino(const char *nombreEstacion)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if( stricmp(registro.getEstacionDestino().getNombreEstacion(), nombreEstacion) == 0 )
        {
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerBoletos::coincidenciasPrecioPagado(float precioPagado)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);

        if(registro.getPrecioPagado() == precioPagado)
        {
            registro.mostrar();
            std::cout << std::endl;
            cont ++;
        }
    }

    return cont;
}

int ManagerBoletos::coincidenciasFecha(time_t fecha)
{

    Boleto registro;
    ArchivoBoletos archivo;

    int cont = 0;
    int tam = archivo.getCantidadRegistros();

    for(int i=0; i<tam; i++)
    {
        registro = archivo.leer(i);


    }

    return cont;
}

/// ------------------------------------------------ METODOS DE ORDENAMIENTO ------------------------------------------------

bool ManagerBoletos::ordenarPorIdBoleto(Boleto *registros, int tam)
{

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ID DE BOLETO
    Boleto aux;

    for(int i=0; i<tam; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(registros[j].getIDBoleto() < registros[i].getIDBoleto())
            {
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerBoletos::ordenarPorIdTren(Boleto *registros, int tam)
{

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ID DE TREN
    Boleto aux;

    for(int i=0; i<tam; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(registros[j].getIDTren() < registros[i].getIDTren())
            {
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerBoletos::ordenarPorDniPasajero(Boleto *registros, int tam)
{

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR DNI DE PASAJEROS
    Boleto aux;

    for(int i=0; i<tam; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if( stricmp(registros[j].getDniPasajero(), registros[i].getDniPasajero()) > 0 )
            {
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerBoletos::ordenarPorEstacionOrigen(Boleto *registros, int tam)
{

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ESTACION DE ORIGEN
    Boleto aux;

    for(int i=0; i<tam; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if( registros[j].getEstacionOrigen().getIDEstacion() < registros[i].getEstacionOrigen().getIDEstacion() )
            {
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerBoletos::ordenarPorEstacionDestino(Boleto *registros, int tam)
{

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR ESTACION DE DESTINO
    Boleto aux;

    for(int i=0; i<tam; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if( registros[j].getEstacionDestino().getIDEstacion() < registros[i].getEstacionDestino().getIDEstacion() )
            {
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerBoletos::ordenarPorPrecioPagado(Boleto *registros, int tam)
{

    /// REALIZO EL "BURBUJEO" PARA ORDENAR LOS REGISTROS POR PRECIO PAGADO
    Boleto aux;

    for(int i=0; i<tam; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(registros[j].getPrecioPagado() < registros[i].getPrecioPagado())
            {
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

bool ManagerBoletos::ordenarPorFecha(Boleto *registros, int tam)
{

    /// REALIZO EL "BURBUJEO" PARA ORDENAR POR FECHA
    Boleto aux;

    for(int i=0; i<tam; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(registros[j].getFechaHoraSistema() < registros[i].getFechaHoraSistema())
            {
                aux = registros[j];
                registros[j] = registros[i];
                registros[i] = aux;
            }
        }
    }

    return true;
}

/// ------------------------------------------------ MÉTODOS "ABML" ------------------------------------------------

Boleto ManagerBoletos::cargarBoleto()
{

    Estacion estacionOrigen;
    Estacion estacionDestino;

    ManagerPasajeros managerPasajeros;
    ManagerTrenes managerTrenes;
    ManagerEstaciones managerEstaciones;
    ManagerTarifas managerTarifas;

    /// SI CAMBIA EL DIA, REINCIO LOS ASIENTOS DE TODOS LOS TRENES EN EL SISTEMA
    reiniciarTrenes();

    /// ---------- OBTENGO EL ID DE BOLETO ---------------------------------------------------------------------
    int idBoleto = obtenerProximoIdBoleto();

    /// ---------- OBTENGO EL DNI DEL PASAJERO. EN CASO DE NO EXISTIR, LE PIDE AL USUARIO REGISTRARSE ----------
    char dni[10];
    std::cout << "DNI: ";
    cargarCadena(dni, sizeof(dni) - 1);
    if(managerPasajeros.validarDni(dni) == false)
    {

        if(managerPasajeros.altaPasajero(dni) == false)
        {
            return Boleto();
        }
    }

    /// ---------- OBTENGO EL ID DE TREN EN EL QUE QUIERE VIAJAR -----------------------------------------------
    int idTren;
    std::cout << "INGRESE EL ID DE TREN: ";
    std::cin >> idTren;
    if(managerTrenes.validarIdTren(idTren) == false || managerTrenes.validarEstado(idTren) == false)
    {
        return Boleto();
    }

    /// ---------- OBTENGO LA ESTACION DE ORIGEN ----------------------------------------------------------------
    char nombreEstacionOrigen[30];
    std::cout << "NOMBRE DE ESTACION DE ORIGEN: ";
    cargarCadena(nombreEstacionOrigen, sizeof(nombreEstacionOrigen) - 1);
    if(managerEstaciones.validarNombreEstacion(nombreEstacionOrigen) == false || managerEstaciones.validarEstado(nombreEstacionOrigen) == false)
    {
        return Boleto();
    }
    else
    {
        estacionOrigen = managerEstaciones.obtenerEstacion(nombreEstacionOrigen);
    }

    /// ---------- OBTENGO LA ESTACION DE DESTINO ---------------------------------------------------------------
    char nombreEstacionDestino[30];
    std::cout << "NOMBRE DE ESTACION DE DESTINO: ";
    cargarCadena(nombreEstacionDestino, sizeof(nombreEstacionDestino) - 1);
    if(managerEstaciones.validarNombreEstacion(nombreEstacionDestino) == false || managerEstaciones.validarEstado(nombreEstacionDestino) == false)
    {
        return Boleto();
    }
    else
    {
        estacionDestino = managerEstaciones.obtenerEstacion(nombreEstacionDestino);
    }

    /// ---------- OBTENGO EL PRECIO DEL BOLETO -----------------------------------------------------------------
    float precioPagado = managerTarifas.obtenerTarifa(estacionOrigen, estacionDestino);
    if(precioPagado == 0)
    {
        return Boleto();
    }

    /// ---------- CARGO EL REGISTRO CON EL CONSTRUCTOR DE LA CLASE BOLETO --------------------------------------
    Boleto registro(idBoleto, idTren, dni, estacionOrigen, estacionDestino, precioPagado);

    /// ---------- LE DOY AL USUARIO LA POSIBILIDAD DE CONFIRMAR LA COMPRA --------------------------------------
    if(confirmarCompra(registro) == false)
    {
        return Boleto();
    }

    /// ---------- CAMBIO UN LUGAR EN EL TREN. LUEGO DE LA VENTA, SI NO HAY MAS LUGARES DESHABILITO EL TREN -----
    if(managerTrenes.ocuparAsiento(idTren) == false)
    {
        return Boleto();
    }

    return registro;
}

bool ManagerBoletos::altaBoleto()
{

    Boleto registro;
    ArchivoBoletos archivo;

    registro = cargarBoleto();
    if(registro.getIDBoleto() == 0)
    {
        return false;
    }

    if(archivo.guardar(registro) == true)
    {
        return true;
    }

    return false;
}

void ManagerBoletos::mostrarRegistros(Boleto *registros, int tam)
{

    for(int i=0; i<tam; i++)
    {
        registros[i].mostrar();
        std::cout << std::endl;
    }
}

/// ------------------------------------------------ LISTADOS ------------------------------------------------

bool ManagerBoletos::listadoPorIdBoleto()
{

    ArchivoBoletos archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE BOLETOS DEL ARCHIVO "boletos.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0)
    {
        /// EL ARCHIVO "boletos.dat" NO TIENE REGISTROS
        return false;
    }

    Boleto *registros = new Boleto[tam];
    if(registros == nullptr)
    {
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false)
    {
        /// NO SE PUDO CARGAR EL VECTOR
        delete [] registros;
        return false;
    }

    /// ORDENO EL VECTOR DINAMICO
    if(ordenarPorIdBoleto(registros, tam) == false)
    {
        /// NO SE PUDO ORDENAR POR ID
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID DE BOLETO
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerBoletos::listadoPorIdTren()
{

    ArchivoBoletos archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE BOLETOS DEL ARCHIVO "boletos.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0)
    {
        /// EL ARCHIVO "boletos.dat" NO TIENE REGISTROS
        return false;
    }

    Boleto *registros = new Boleto[tam];
    if(registros == nullptr)
    {
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false)
    {
        /// NO SE PUDO CARGAR EL VECTOR
        delete [] registros;
        return false;
    }

    /// ORDENO EL VECTOR DINAMICO
    if(ordenarPorIdTren(registros, tam) == false)
    {
        /// NO SE PUDO ORDENAR POR ID TREN
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ID DE TREN
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerBoletos::listadoPorDniPasajero()
{

    ArchivoBoletos archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE BOLETOS DEL ARCHIVO "boletos.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0)
    {
        /// EL ARCHIVO "boletos.dat" NO TIENE REGISTROS
        return false;
    }

    Boleto *registros = new Boleto[tam];
    if(registros == nullptr)
    {
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false)
    {
        /// NO SE PUDO CARGAR EL VECTOR
        delete [] registros;
        return false;
    }

    /// ORDENO EL VECTOR DINAMICO
    if(ordenarPorDniPasajero(registros, tam) == false)
    {
        /// NO SE PUDO ORDENAR POR DNI DE PASAJERO
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR DNI DE PASAJERO
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerBoletos::listadoPorEstacionOrigen()
{

    ArchivoBoletos archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE BOLETOS DEL ARCHIVO "boletos.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0)
    {
        /// EL ARCHIVO "boletos.dat" NO TIENE REGISTROS
        return false;
    }

    Boleto *registros = new Boleto[tam];
    if(registros == nullptr)
    {
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false)
    {
        /// NO SE PUDO CARGAR EL VECTOR
        delete [] registros;
        return false;
    }

    /// ORDENO EL VECTOR DINAMICO
    if(ordenarPorEstacionOrigen(registros, tam) == false)
    {
        /// NO SE PUDO ORDENAR POR ESTACION DE ORIGEN
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ESTACION DE ORIGEN
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerBoletos::listadoPorEstacionDestino()
{

    ArchivoBoletos archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE BOLETOS DEL ARCHIVO "boletos.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0)
    {
        /// EL ARCHIVO "boletos.dat" NO TIENE REGISTROS
        return false;
    }

    Boleto *registros = new Boleto[tam];
    if(registros == nullptr)
    {
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false)
    {
        /// NO SE PUDO CARGAR EL VECTOR
        delete [] registros;
        return false;
    }

    /// ORDENO EL VECTOR DINAMICO
    if(ordenarPorEstacionDestino(registros, tam) == false)
    {
        /// NO SE PUDO ORDENAR POR ESTACION DE DESTINO
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR ESTACION DE DESTINO
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerBoletos::listadoPorPrecioPagado()
{

    ArchivoBoletos archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE BOLETOS DEL ARCHIVO "boletos.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0)
    {
        /// EL ARCHIVO "boletos.dat" NO TIENE REGISTROS
        return false;
    }

    Boleto *registros = new Boleto[tam];
    if(registros == nullptr)
    {
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false)
    {
        /// NO SE PUDO CARGAR EL VECTOR
        delete [] registros;
        return false;
    }

    /// ORDENO EL VECTOR DINAMICO
    if(ordenarPorPrecioPagado(registros, tam) == false)
    {
        /// NO SE PUDO ORDENAR POR PRECIO PAGADO
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR PRECIO PAGADO
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

bool ManagerBoletos::listadoPorFecha()
{

    ArchivoBoletos archivo;

    /// CREO UN VECTOR DINAMICO PARA ALMACENAR REGISTROS DE BOLETOS DEL ARCHIVO "boletos.dat"
    int tam = archivo.getCantidadRegistros();
    if(tam == 0)
    {
        /// EL ARCHIVO "boletos.dat" NO TIENE REGISTROS
        return false;
    }

    Boleto *registros = new Boleto[tam];
    if(registros == nullptr)
    {
        /// NO SE PUDO ASIGNAR MEMORIA
        delete [] registros;
        return false;
    }

    /// CARGO EL VECTOR DINAMICO
    if(cargarVector(registros, tam) == false)
    {
        /// NO SE PUDO CARGAR EL VECTOR
        delete [] registros;
        return false;
    }

    /// ORDENO EL VECTOR DINAMICO
    if(ordenarPorFecha(registros, tam) == false)
    {
        /// NO SE PUDO ORDENAR POR FECHA
        delete [] registros;
        return false;
    }

    /// MUESTRO EL VECTOR ORDENADO POR FECHA
    mostrarRegistros(registros, tam);

    delete [] registros;

    return true;
}

/// ------------------------------------------------ CONSULTAS ------------------------------------------------

bool ManagerBoletos::consultaPorIdBoleto()
{

    /// LE PIDO AL USUARIO EL ID
    int id;
    std::cout << "ID DE BOLETO: ";
    std::cin >> id;
    std::cout << std::endl;

    /// VALIDO EL ID
    if(validarIdBoleto(id) == false)
    {
        /// NO SE ENCONTRO EL ID DE BOLETO
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL ID DE BOLETO
    if(coincidenciasIdBoleto(id) == 0)
    {
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

bool ManagerBoletos::consultaPorIdTren()
{

    ManagerTrenes manager;

    /// LE PIDO AL USUARIO EL ID DE TREN
    int id;
    std::cout << "ID DE TREN: ";
    std::cin >> id;
    std::cout << std::endl;

    /// VALIDO EL ID DE TREN EN "trenes.dat"
    if(manager.validarIdTren(id) == false)
    {
        /// NO SE ENCONTRO EL ID DE TREN
        return false;
    }

    /// VALIDO EL ID DE TREN EN "boletos.dat"
    if(validarIdTren(id) == false)
    {
        /// NO SE ENCONTRO EL ID DE TREN
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL ID
    if(coincidenciasIdTren(id) == 0)
    {
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

bool ManagerBoletos::consultaPorDniPasajero()
{

    ManagerPasajeros manager;

    /// LE PIDO AL USUARIO EL DNI
    char dni[10];
    std::cout << "DNI: ";
    cargarCadena(dni, sizeof(dni) - 1);
    std::cout << std::endl;

    /// VALIDO EL DNI EN "pasajeros.dat"
    if(manager.validarDni(dni) == false)
    {
        /// NO SE ENCONTRO EL DNI "pasajeros.dat"
        return false;
    }

    /// VALIDO EL DNI EN "boletos.dat"
    if(validarDni(dni) == false)
    {
        /// NO SE ENCONTRO EL DNI EN "boletos.dat"
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL DNI
    if(coincidenciasDniPasajero(dni) == 0)
    {
        /// NO SE ENCONTRARON COINCIDENCIA
        return false;
    }

    return true;
}

bool ManagerBoletos::consultaPorEstacionOrigen()
{

    ManagerEstaciones manager;

    /// LE PIDO AL USUARIO EL NOMBRE DE ESTACION
    char nombreEstacion[30];
    std::cout << "NOMBRE DE ESTACION: ";
    cargarCadena(nombreEstacion, sizeof(nombreEstacion) - 1);
    std::cout << std::endl;

    /// VALIDO EL NOMBRE DE ESTACION EN "estaciones.dat"
    if(manager.validarNombreEstacion(nombreEstacion) == false)
    {
        /// NO SE ENCONTRO EL DNI "estaciones.dat"
        return false;
    }

    /// VALIDO EL NOMBRE DE ESTACION EN "boletos.dat"
    if(validarEstacionOrigen(nombreEstacion) == false)
    {
        /// NO SE ENCONTRO EL DNI EN "boletos.dat"
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL DNI
    if(coincidenciasEstacionOrigen(nombreEstacion) == 0)
    {
        /// NO SE ENCONTRARON COINCIDENCIA
        return false;
    }

    return true;
}

bool ManagerBoletos::consultaPorEstacionDestino()
{

    ManagerEstaciones manager;

    /// LE PIDO AL USUARIO EL NOMBRE DE ESTACION
    char nombreEstacion[30];
    std::cout << "NOMBRE DE ESTACION: ";
    cargarCadena(nombreEstacion, sizeof(nombreEstacion) - 1);
    std::cout << std::endl;

    /// VALIDO EL NOMBRE DE ESTACION EN "estaciones.dat"
    if(manager.validarNombreEstacion(nombreEstacion) == false)
    {
        /// NO SE ENCONTRO EL DNI "estaciones.dat"
        return false;
    }

    /// VALIDO EL NOMBRE DE ESTACION EN "boletos.dat"
    if(validarEstacionDestino(nombreEstacion) == false)
    {
        /// NO SE ENCONTRO EL DNI EN "boletos.dat"
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS CON EL DNI
    if(coincidenciasEstacionDestino(nombreEstacion) == 0)
    {
        /// NO SE ENCONTRARON COINCIDENCIA
        return false;
    }

    return true;
}

bool ManagerBoletos::consultaPorPrecioPagado()
{

    /// LE PIDO AL USUARIO EL VALOR DE TARIFA
    float precioPagado;
    std::cin >> precioPagado;
    std::cout << std::endl;

    /// VALIDO EL PRECIO PAGADO
    if(validarPrecioPagado(precioPagado) == false)
    {
        /// NO SE ENCONTRO EL PRECIO PAGADO
        return false;
    }

    /// BUSCO Y MUESTRO LAS COINCIDENCIAS
    if(coincidenciasPrecioPagado(precioPagado) == 0)
    {
        /// NO SE ENCONTRARON COINCIDENCIAS
        return false;
    }

    return true;
}

/// ------------------------------------------------ INFORMES -------------------------------------------------

bool ManagerBoletos::informeTotalBoletosVendidos()
{

    ArchivoBoletos archivo;

    if(archivo.getCantidadRegistros() == 0)
    {
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "CANTIDAD TOTAL DE BOLETOS VENDIDOS: " << archivo.getCantidadRegistros() << std::endl;

    return true;
}

bool ManagerBoletos::informeTotalRecaudado()
{

    ArchivoBoletos archivo;

    if(archivo.getCantidadRegistros() == 0)
    {
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "TOTAL RECAUDADO: $" << obtenerTotalRecaudado() << std::endl;

    return true;
}

bool ManagerBoletos::informeEstacionOrigenConMayorVentas()
{

    ArchivoBoletos archivo;

    if(archivo.getCantidadRegistros() == 0)
    {
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    Estacion registro;
    registro = obtenerEstacionOrigenConMayorVentas();

    if(registro.getIDEstacion() > 0)
    {
        std::cout << "ESTACION ORIGEN CON MAYOR VENTAS: " << std::endl;
        registro.mostrar();
        return true;
    }

    return false;
}

bool ManagerBoletos::informeEstacionDestinoConMayorVentas()
{

    ArchivoBoletos archivo;

    if(archivo.getCantidadRegistros() == 0)
    {
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    Estacion registro;
    registro = obtenerEstacionOrigenConMayorVentas();

    if(registro.getIDEstacion() > 0)
    {
        std::cout << "ESTACION DESTINO CON MAYOR VENTAS: " << std::endl;
        registro.mostrar();
        return true;
    }

    return false;
}

bool ManagerBoletos::informeBoletoMasCaro()
{

    ArchivoBoletos archivo;

    if(archivo.getCantidadRegistros() == 0)
    {
        /// EL ARCHIVO NO TIENE REGISTROS
        return false;
    }

    std::cout << "ID DE BOLETO MAS CARO: #" << obtenerIdBoletoMasCaro() << " | VALOR: $" << obtenerValorBoletoMasCaro() << std::endl;

    return true;
}
