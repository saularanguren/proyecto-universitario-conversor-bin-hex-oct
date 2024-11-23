#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "../include/conversor-oct.h"
#include "../include/utilidades.h"

void conversion_octal()
{
    char informacion_ingresada[999];

    system("clear");
    imprimir_titulo("\033[1;36mConversor Octal.", 16);

    printf("Ingresar texto:\033[0m ");
    fgets(informacion_ingresada, sizeof(informacion_ingresada), stdin);
    eliminar_salto_linea(informacion_ingresada, 999);

    printf("\n\033[1;32mResultado Octal:\033[0;32m\n");
    
    for(int i = 0; informacion_ingresada[i] != '\0'; i++)
    {
        // transformar carácter a decimal según la tabla ASCII
        int codigo_ascii = (unsigned char)informacion_ingresada[i];
        int ordenar_valores_octales[3] = {0};
        int indice = 2;

        // transformar decimal a octal
        while(codigo_ascii > 0)
        {
            ordenar_valores_octales[indice] = codigo_ascii % 8;
            codigo_ascii = codigo_ascii / 8;
            indice--;
        }

        // imprimir representación octal de ese momento
        for (int j = 0; j < 3; j++)
        {
            printf("%d",ordenar_valores_octales[j]);
        }

        // se imprime un espacio, para separar cada representación octal
        printf(" ");
    }

    enter_para_continuar();
}