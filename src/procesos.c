#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/procesos.h"
#include "../include/utilidades.h"
#include "../include/conversor-bin.h"
#include "../include/conversor-hex.h"
#include "../include/conversor-oct.h"

void administrar_procesos()
{
    char informacion_ingresada[999];
    int filas_contador = 8;

    do
    {     
        // modificar la impresión del menú
        printf("\033[%d;%dH",filas_contador++,4);

        // recibir entrada
        printf(": ");
        fgets(informacion_ingresada, sizeof(informacion_ingresada), stdin);
        eliminar_salto_linea(informacion_ingresada, 999);

        if(strcmp(informacion_ingresada, "1") == 0)
        {
            // Conversión Hexadecimal
            reproducir_sonido("exito");
            conversion_hexadecimal();
            imprimir_menu();
            filas_contador = 8;
        }
        else if(strcmp(informacion_ingresada, "2") == 0)
        {
            // Conversión Binario
            reproducir_sonido("exito");
            conversion_binario();
            imprimir_menu();
            filas_contador = 8;
        }
        else if(strcmp(informacion_ingresada, "3") == 0)
        {
            // Conversión Octal
            reproducir_sonido("exito");
            conversion_octal();
            imprimir_menu();
            filas_contador = 8;
        }
        else if(strcmp(informacion_ingresada, ".salir") == 0 || strcmp(informacion_ingresada, "4") == 0)
        {
            // Salir
            reproducir_sonido("adios");
            system("clear");
            break;
        }
        else if(strcmp(informacion_ingresada, ".ayuda") == 0)
        {
            // ".ayuda" para obtener más información
            reproducir_sonido("ganador");
            imprimir_tabla();
            imprimir_menu();
            filas_contador = 8;
        }
        else if(strcmp(informacion_ingresada, ".limpiar") == 0)
        {
            // limpiar terminal
            reproducir_sonido("exito");
            imprimir_menu();
            filas_contador = 8;
        }
        else
        {
            // errores...
            reproducir_sonido("error");
            printf("\033[%d;%dH",filas_contador++,4);
            printf("\033[1;31mError: \"%s\" no está definido.\033[0m\n",informacion_ingresada);
        }
    } while (1);
}