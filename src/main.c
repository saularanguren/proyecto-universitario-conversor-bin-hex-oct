#include <string.h>
#include "constants/config.h"
#include "constants/colores.h"
#include "lib/conversores.h"
#include "lib/reproductor-wav.h"
#include "lib/configurar-terminal.h"
#include "lib/imprimir-utilidades.h"

int main()
{
    char informacion_ingresada[MAX_CARACTERES];
    int filas_contador = 8;

    // reproducir el sonido de bienvenida al iniciar
    reproducir_sonido("bienvenida");

    // validar medidas minimas, para el correcto funcionamiento
    medidas_minimas();

    // mostrando la bienvenida al usuario
    imprimir_bienvenida();

    // mostrando el menu de opciones
    imprimir_menu();

    do
    {
        printf("\033[%d;%dH",filas_contador++,4);

        // recibir entrada
        printf(": ");
        fgets(informacion_ingresada, sizeof(informacion_ingresada), stdin);

        // eliminar el salto de linea
        informacion_ingresada[strlen(informacion_ingresada) - 1] = '\0';

        if(strcmp(informacion_ingresada, "1") == 0)
        {
            //* conversión hexadecimal *//

            reproducir_sonido("exito");
            conversor("Hexadecimal", VIOLETA, 2, 1, 16, "s");
            
            imprimir_menu();
            filas_contador = 8;

            continue;
        }

        if(strcmp(informacion_ingresada, "2") == 0)
        {
            //* conversión binario *//

            reproducir_sonido("exito");
            conversor("Binario", AMARILLO, 8, 7, 2, "n");

            imprimir_menu();
            filas_contador = 8;

            continue;
        }

        if(strcmp(informacion_ingresada, "3") == 0)
        {
            //* conversión octal *//

            reproducir_sonido("exito");
            conversor("Octal", CYAN, 3, 2, 8, "n");

            imprimir_menu();
            filas_contador = 8;

            continue;
        }
        
        if(strcmp(informacion_ingresada, ".salir") == 0 || strcmp(informacion_ingresada, "4") == 0)
        {
            //* salir *//

            reproducir_sonido("adios");
            limpiar_terminal();

            break;
        }
        
        if(strcmp(informacion_ingresada, ".ayuda") == 0)
        {
            //* ".ayuda" para obtener más información *//

            reproducir_sonido("ganador");
            imprimir_tabla();
            
            imprimir_menu();
            filas_contador = 8;

            continue;
        }

        if(strcmp(informacion_ingresada, ".limpiar") == 0)
        {
            //* limpiar terminal *//

            reproducir_sonido("exito");

            imprimir_menu();
            filas_contador = 8;

            continue;
        }

        //* errores *//
        reproducir_sonido("error");

        printf(ROJO); // imprimir texto en color: rojo

        printf("\033[%d;%dH",filas_contador++,4);
        printf("Error: \"%s\" no está definido.\n",informacion_ingresada);

        printf(RESET_COLOR); // restablecer color predeterminado
    } 
    while(1);

    return 0;
}