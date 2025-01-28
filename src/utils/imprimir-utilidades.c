#include "../lib/imprimir-utilidades.h"
#include "../lib/configurar-terminal.h"
#include "../constants/colores.h"

void imprimir_bienvenida()
{
    // estructura para obtener dimensiones de la terminal
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    limpiar_terminal();

    printf(VERDE); // imprimir texto en color: verde

    // imprimir texto en el centro
    printf("\033[%d;%dH",(w.ws_row-3)/2,(w.ws_col-34)/2);
    printf("Bienvenido, software de conversión\n");

    // imprimir texto en el centro
    printf("\033[%d;%dH",(w.ws_row-1)/2,(w.ws_col-46)/2);
    printf("Convierte texto a hexadecimal, binario y octal\n");

    printf(BLANCO); // imprimir texto en color: blanco

    // imprimir texto a la derecha
    printf("\033[%d;%dH",w.ws_row-3,w.ws_col-35);
    printf("presiona Enter para continuar...");
    getchar();

    printf(RESET_COLOR); // restablecer color predeterminado
}

void imprimir_menu()
{
    // estructura para obtener dimensiones de la terminal
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    limpiar_terminal();

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
    limpiar_terminal();

    printf("┌─────────────────┬────────────────────────────────┐\n");
    printf("│    Comandos     │          Descripción           │\n");
    printf("├─────────────────┼────────────────────────────────┤\n");
    printf("│ 1) .ayuda       │ Visualizar esta tabla.         │\n");
    printf("│ 2) .limpiar     │ Limpiar la terminal.           │\n");
    printf("│ 3) .salir       │ Finalizar programa.            │\n");
    printf("└─────────────────┴────────────────────────────────┘\n");

    enter_para_continuar();
}

void imprimir_titulo(char *titulo)
{
    int numero_caracteres = (strlen(titulo)) + 11;

    // estructura para obtener dimensiones de la terminal
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf("\033[%d;%dH",2,(w.ws_col-numero_caracteres)/2); // centrar titulo
    printf("Conversor %s.",titulo);

    numero_caracteres += 4;
    printf("\033[%d;%dH",3,(w.ws_col-numero_caracteres)/2); // centrar linea
    for(int i = 0; i < numero_caracteres; i++) { printf("═"); }

    printf("\n\n");
}

void enter_para_continuar()
{
    printf(BLANCO); // imprimir texto en color: blanco
    printf("\n\npresiona Enter para continuar...");
    printf(RESET_COLOR); // restablecer color predeterminado
 
    getchar();
}

void imprimir_resultado(int longitud, int arreglo[], char *es_hex)
{
    for(int i = 0; i < longitud; i++)
    {
        if(*es_hex != 's') { printf("%d",arreglo[i]); }
        else
        {
            switch(arreglo[i])
            {
                case 10: printf("A"); break;
                case 11: printf("B"); break;
                case 12: printf("C"); break;
                case 13: printf("D"); break;
                case 14: printf("E"); break;
                case 15: printf("F"); break;
                default: printf("%d",arreglo[i]); break;
            }
        }
    }
}