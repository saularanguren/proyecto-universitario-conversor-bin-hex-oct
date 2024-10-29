#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/conversor-bin.h"
#include "../include/utilidades.h"

void conversion_binario()
{
    char informacion_ingresada[999];

    system("clear");
    imprimir_titulo("\033[1;33mConversor Binario.", 18);
    printf("Ingrese texto:\033[0m ");
    fgets(informacion_ingresada, sizeof(informacion_ingresada), stdin);
    eliminar_salto_linea(informacion_ingresada, 999);

    printf("\n\033[1;32mResultado Binario:\033[0;32m\n");
    for(int i = 0; informacion_ingresada[i] != '\0'; i++)
    {
        unsigned int codigo_ascii = informacion_ingresada[i];
        int ordenar_valores_binario[8] = {0};
        int contador = 7;

        while (codigo_ascii > 0)
        {
            ordenar_valores_binario[contador] = codigo_ascii % 2;
            codigo_ascii = codigo_ascii / 2;
            contador--;
        }
        
        for (int j = 0; j < 8; j++)
        {
            printf("%d",ordenar_valores_binario[j]);
        }
        printf(" ");
    }
    enter_para_continuar();
}