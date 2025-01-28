#include "../constants/config.h"
#include "../constants/colores.h"
#include "../lib/configurar-terminal.h"
#include "../lib/imprimir-utilidades.h"

void medidas_minimas()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    if(w.ws_col < 63)
    {
        limpiar_terminal();

        printf("\033[8;%d;63t",w.ws_row); // modificar medidas de la terminal
        
        printf(MARRON); // imprimir texto en color: marrón
        printf("Se modificaron las medidas de la terminal\ndisculpe las molestias...");
        printf(RESET_COLOR); // restablecer color predeterminado

        enter_para_continuar();
    }
}

void limpiar_terminal() { system(LIMPIAR); }