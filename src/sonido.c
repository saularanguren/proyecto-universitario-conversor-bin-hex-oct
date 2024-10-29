#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "../include/sonido.h"

void reproducir_sonido_bienvenida()
{
    pid_t pid = fork();

    if (pid == 0) {
        system("aplay ./sound/bienvenida.wav > /dev/null 2>&1");
        exit(0);
    }
}

void reproducir_sonido_exito()
{
    pid_t pid = fork();

    if (pid == 0) {
        system("aplay ./sound/exito.wav > /dev/null 2>&1");
        exit(0);
    }
}

void reproducir_sonido_ganador()
{
    pid_t pid = fork();

    if (pid == 0) {
        system("aplay ./sound/ganador.wav > /dev/null 2>&1");
        exit(0);
    }
}

void reproducir_sonido_error() 
{
    pid_t pid = fork();

    if (pid == 0) {
        system("aplay ./sound/error.wav > /dev/null 2>&1");
        exit(0);
    }
}

void reproducir_sonido_adios()
{
    pid_t pid = fork();

    if (pid == 0) {
        system("aplay ./sound/adios.wav > /dev/null 2>&1");
        exit(0);
    }
}