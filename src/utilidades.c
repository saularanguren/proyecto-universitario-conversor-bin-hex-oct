#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "../include/utilidades.h"

void enter_para_continuar()
{
    printf("\n\n\033[1;37mpresiona Enter para continuar...\033[0m");
    getchar();
}

void medidas_minimas()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    if(w.ws_col < 63)
    {
        system("clear");
        printf("\033[8;16;63t");
        printf("\033[33mSe modificaron las medidas de la terminal\ndisculpe las molestias…");
		enter_para_continuar();		
	}
}

void imprimir_bienvenida()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    system("clear");
    // Centrar elemento
    printf("\033[%d;%dH",(w.ws_row-1)/2,(w.ws_col-34)/2);
    printf("\033[1;32mBienvenido, software de conversión\n");
    // Centrar elemento
    printf("\033[%d;%dH",(w.ws_row+1)/2,(w.ws_col-46)/2);
    printf("Convierte texto a hexadecimal, binario y octal\033[0m\n");
    // Posicionar elemento a la derecha
    printf("\033[%d;%dH",w.ws_row-2,w.ws_col-35);
    printf("\033[1;37mpresiona Enter para continuar...\033[0m");
    getchar();
}

void imprimir_menu()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    system("clear");
    // Centrar elemento
    printf("\033[%d;%dH",2,(w.ws_col-48)/2);
    printf("\033[1;34mEscribe \".ayuda\" para obtener más información.\033[0m");
    // Posicionar elemento en la siguiente linea con 4 espacios a la izquierda
    printf("\033[%d;%dH",4,4);
    printf("1. Conversión Hexadecimal\n");
    // Posicionar elemento en la siguiente linea con 4 espacios a la izquierda
    printf("\033[%d;%dH",5,4);
    printf("2. Conversión Binario\n");
    // Posicionar elemento en la siguiente linea con 4 espacios a la izquierda
    printf("\033[%d;%dH",6,4);
    printf("3. Conversión Octal\n");
    // Posicionar elemento en la siguiente linea con 4 espacios a la izquierda
    printf("\033[%d;%dH",7,4);
    printf("4. Salir\n");
}

void imprimir_tabla()
{
    system("clear");
    printf("┌─────────────────┬────────────────────────────────┐\n");
    printf("│    \033[1;34mComandos\033[0m     │          \033[1;34mDescripción\033[0m           │\n");
    printf("├─────────────────┼────────────────────────────────┤\n");
    printf("│ 1) .ayuda       │ Visualizar esta tabla.         │\n");
    printf("│ 2) .limpiar     │ Limpiar la terminal.           │\n");
    printf("│ 3) .salir       │ Finalizar programa.            │\n");
    printf("└─────────────────┴────────────────────────────────┘\n");

    enter_para_continuar();
}

void imprimir_titulo(char *titulo, int can_caracteres)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    // centrar titulo
    printf("\033[%d;%dH",2,(w.ws_col-can_caracteres)/2);
    printf("%s",titulo);

    can_caracteres += 4;

    // centrar linea
    printf("\033[%d;%dH",3,(w.ws_col-can_caracteres)/2);
    for(int i = 0; i < can_caracteres; i++)
    {
        printf("═");
    }
    printf("\n\n");
}

int eliminar_salto_linea(char *cadena_ingresada, int almacenamiento)
{
    for(int i = 0; i < almacenamiento; i++)
    {
        if(cadena_ingresada[i] == '\n')
        {
            cadena_ingresada[i] = '\0';
            return 1;
        }
    }
    return 0;
}