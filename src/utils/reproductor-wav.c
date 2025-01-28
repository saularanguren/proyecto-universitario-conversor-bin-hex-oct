#include "../lib/reproductor-wav.h"
#include "../constants/config.h"

void reproducir_sonido(char *nombre_archivo_wav)
{
    // Se crea un proceso adicional, con la finalidad de no esperar mucho tiempo, mientras acaba el sonido
    pid_t pid = fork();
    
    char comando[MAX_CARACTERES];
    // /dev/null 2>&1 = evita que se muestren valores despues de reproducir el sonido
    snprintf(comando, sizeof(comando), "aplay %s/%s.wav > /dev/null 2>&1", DIRECCION_ARCHIVOS_WAV, nombre_archivo_wav);
    
    // se creó exitosamente el proceso hijo
    if(pid == 0)
    {
        system(comando);
        exit(0); // finalizar proceso hijo
    }
}