#include "./include/procesos.h"
#include "./include/utilidades.h"

int main()
{
    reproducir_sonido("bienvenida");
    medidas_minimas();
    imprimir_bienvenida();
    imprimir_menu();
    administrar_procesos();
    return 0;
}