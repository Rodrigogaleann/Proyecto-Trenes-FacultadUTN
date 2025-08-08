#include "FuncionesGlobales.h"

#include <iostream>
#include <cstring>

void cargarCadena(char *cadena, int tam){
    int i;
    fflush(stdin);

    for(i = 0; i<tam; i++){

        cadena[i] = std::cin.get();

        if (cadena[i] == '\n'){
            break;
        }
    }
    cadena[i] = '\0';
    fflush(stdin);
}

void mostrarTexto(const char *texto){

    int anchoTotal = 110;

    int longitudTexto = strlen(texto);

    int espaciosIzquierda = (anchoTotal - longitudTexto) / 2;

    std::cout << std::endl;
    std::cout << std::string(anchoTotal, '=') << std::endl;
    std::cout << std::string(espaciosIzquierda, ' ') << texto << std::endl;
    std::cout << std::string(anchoTotal, '=') << std::endl;
    std::cout << std::endl;
}

std::string binarioActivo(bool binario){

    if(binario == 1){
        return "ACTIVO";
    }
    else{
        return "INACTIVO";
    }
}

std::string binarioDisponible(bool binario){

    if(binario == 1){
        return "DISPONIBLE";
    }
    else{
        return "NO DISPONIBLE";
    }
}

std::string espaciar(int tam, int valor){

    int espacio = 0;
    std::string texto = "";

    espacio = valor - tam;

    for(int i=0; i<espacio; i++){
        texto = texto + " ";
    }

    return texto;
}

int obtenerCantidadDigitos(int numero){

    int cont = 0;

    while(numero > 0){
        numero /= 10;
        cont++;
    }

    return cont;
}

int obtenerCantidadDigitos(float numero){

    std::string digitos = std::to_string(numero);

    return digitos.length();
}

bool compararFechas(FechaHoraSistema fecha1, FechaHoraSistema fecha2){

    if(fecha1.getAnio() < fecha2.getAnio()){
        return true;
    }
    else{
        if(fecha1.getAnio() == fecha2.getAnio() && fecha1.getMes() < fecha2.getMes()){
            return true;
        }
        else{
            if(fecha1.getAnio() == fecha2.getAnio() && fecha1.getMes() == fecha2.getMes() && fecha1.getDia() < fecha2.getDia()){
                return true;
            }
        }
    }

    return false;
}

bool ponerVectorEnCero(int *v, int tam){

    int contador = 0;

    for(int i=0; i<tam; i++){
        v[i] = 0;

        contador ++;
    }

    if(contador == tam){
        return true;
    }

    return false;
}
