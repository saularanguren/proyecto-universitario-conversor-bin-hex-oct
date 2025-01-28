#include "lib/conversores.h"
#include "lib/imprimir-utilidades.h"
#include "lib/configurar-terminal.h"
#include "constants/config.h"
#include "constants/colores.h"

void conversor(char *nombre, char *COLOR, int longitud, int contador, int numero, char *es_hex)
{
    char cadena[MAX_CARACTERES];

    limpiar_terminal();

    printf(COLOR); // imprimir texto en color seleccionado
    imprimir_titulo(nombre);
    
    printf("Ingrese texto: ");
    printf(RESET_COLOR); // restablecer color a default

    fgets(cadena, sizeof(cadena), stdin); // leer entrada de informacion

    printf(VERDE);
    printf("\nResultado %s:\n",nombre);
    printf(VERDE_RESULTADO);

    // recorrer cada caracter de la cadena ingresada
    for(int i = 0; cadena[i] != '\n'; i++)
    {
        // transformar carácter a decimal según la tabla ASCII
        unsigned int codigo_ascii = cadena[i];
        int ordenar_valores[longitud];
        int indice = contador;

        // inicializar arreglo a 0
        for(int j = 0; j < longitud; j++) { ordenar_valores[j] = 0; }

        while(codigo_ascii > 0)
        {
            ordenar_valores[indice] = codigo_ascii % numero;
            codigo_ascii = codigo_ascii / numero;
            indice--;
        }

        imprimir_resultado(longitud, ordenar_valores, es_hex);
        
        printf(" ");
    }

    enter_para_continuar();
}