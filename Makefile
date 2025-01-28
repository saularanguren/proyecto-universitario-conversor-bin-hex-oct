# nombre del ejecutable de desarrollo: dev
# nombre del ejecutable de producción: bin-hex-oct-converter
TARGET = dev

SRC = src/*.c src/*/*.c

all:
	gcc $(SRC) -o ./bin/$(TARGET) && ./bin/$(TARGET)
clean:
	rm -rf ./bin/$(TARGET)