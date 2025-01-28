#ifndef IMPRIMIR_UTILIDADES_H
#define IMPRIMIR_UTILIDADES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

void imprimir_bienvenida();
void imprimir_menu();
void imprimir_tabla();
void imprimir_titulo(char *titulo);
void imprimir_resultado(int longitud, int arreglo[], char *es_hex);
void enter_para_continuar();

#endif