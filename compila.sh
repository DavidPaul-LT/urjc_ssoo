#!/bin/bash

#Definimos una función para manejar errores
handle_error(){
    echo "/-Error-\ --> $1"
    exit 1
}

#Compilar los archivos de la librería
gcc libreria.c -c -o libreria.o || handle_error "Error al compilar la libreria"

#Crear la librería
ar -rv libreria.a libreria.o

#Compilar el programa que usa la librería
gcc -o test test.c libreria.a || handle_error "Error al compilar el programa de test"

#Dar permiso al archivo ejecutable
chmod +x test || handle_error "Error al dar permisos de ejecucion"

#Se avisa al usuario que el script se ha ejecutado con éxito
echo "Compilacion compleltada, puede ejecutar el programa './test'"
