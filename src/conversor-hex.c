#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/conversor-hex.h"
#include "../include/utilidades.h"

void conversion_hexadecimal()
{
    char informacion_ingresada[999];

    system("clear");
    imprimir_titulo("\033[1;35mConversor Hexadecimal.", 22);
    printf("Ingresar texto:\033[0m ");
    fgets(informacion_ingresada, sizeof(informacion_ingresada), stdin);
    eliminar_salto_linea(informacion_ingresada, 999);

    printf("\n\033[1;32mResultado hexadecimal:\033[0;32m\n");
    for(int i = 0; informacion_ingresada[i] != '\0'; i++)
    {
        unsigned int codigo_ascii = informacion_ingresada[i];
        int ordenar_valores_hexadecimales[2] = {0};
        int indice = 1;

        while(codigo_ascii > 0)
        {
            ordenar_valores_hexadecimales[indice] = codigo_ascii % 16;
            codigo_ascii = codigo_ascii / 16;
            indice--;
        }

        for (int j = 0; j < 2; j++)
        {
            switch (ordenar_valores_hexadecimales[j])
            {
                case 10:
                    printf("A");
                    break;
                
                case 11:
                    printf("B");
                    break;

                case 12:
                    printf("C");
                    break;

                case 13:
                    printf("D");
                    break;

                case 14:
                    printf("E");
                    break;
        
                case 15:
                    printf("F");
                    break;

                default:
                    printf("%d",ordenar_valores_hexadecimales[j]);
                    break;
            }
        }
        printf(" ");
    }
    enter_para_continuar();
}