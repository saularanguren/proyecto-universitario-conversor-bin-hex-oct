# Proyecto Universitario de Conversión de Texto a: Binario, Hexadecimal y Octal

Este proyecto tiene como objetivo desarrollar una herramienta que permita a los usuarios convertir cadenas de caracteres a los sistemas numéricos binario, hexadecimal y octal. La aplicación transforma cada carácter a su representación decimal según la tabla ASCII; este número decimal se convierte luego a la representación numérica seleccionada. El programa es útil para estudiantes y profesionales que necesiten realizar conversiones rápidas y precisas. Sin embargo, es una herramienta de conversión diseñada exclusivamente para sistemas operativos Linux.

## Características

- **Conversión Interactiva**: Permite al usuario seleccionar el tipo de conversión (binario, hexadecimal u octal) mediante un menú.
- **Soporte para Cadenas de Caracteres**: Convierte cadenas de caracteres a los formatos seleccionados.
- **Efectos de Sonido**: Mejora la experiencia del usuario con sonidos al realizar conversiones, navegar en la aplicación y otros.
- **Interfaz Colorida**: Utiliza colores en la terminal para hacer el uso más atractivo e intuitivo.

## Compilar y Ejecutar

Para compilar y ejecutar el proyecto, sigue estos pasos:

1. Asegúrate de tener instalado `make` y un compilador compatible (como `gcc`) en tu sistema.
2. Clona este repositorio en tu máquina local.
3. Navega al directorio del proyecto.
4. Ejecuta el siguiente comando para compilar el software:

   ```bash
   make
   ```
5. Una vez compilado, puedes ejecutar la aplicación con:
   ```bash
   ./bin/bin-hex-oct-converter
   ```

## Uso

1. Al ejecutar la aplicación, se mostrará un menú con las opciones disponibles.
2. Selecciona el tipo de conversión que deseas realizar.
3. Ingresa la cadena de caracteres que deseas convertir.
4. La aplicación mostrará el resultado en el formato seleccionado.