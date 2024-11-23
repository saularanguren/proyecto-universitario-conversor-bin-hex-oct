# compilador
CC = gcc

# nombre del ejecutable de desarrollo: dev, app
# nombre del ejecutable de producción: bin-hex-oct-converter
TARGET = bin-hex-oct-converter

# Muestran los posibles errores dentro del código
CFLAGS = -g -Wall

# dirección de los archivos .c
SRC = main.c src/utilidades.c src/procesos.c src/conversor-bin.c src/conversor-hex.c src/conversor-oct.c

# Crea el ejecutable dentro de la carpeta build, lo ejecuta y elimina
# el anterior ejecutable, si existe en esa carpeta
all:
	$(CC) $(CFLAGS) $(SRC) -o ./build/$(TARGET)
clean:
	rm -rf ./build/$(TARGET)