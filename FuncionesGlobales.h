#pragma once

#include "FechaHoraSistema.h"

#include <string>

void cargarCadena(char *cadena, int tam);

void mostrarTexto(const char *texto);

std::string binarioActivo(bool binario);

std::string binarioDisponible(bool binario);


std::string espaciar(int tam, int valor);

int obtenerCantidadDigitos(int numero);

int obtenerCantidadDigitos(float numero);

bool compararFechas(FechaHoraSistema fecha1, FechaHoraSistema fecha2);

bool ponerVectorEnCero(int *v, int tam);
