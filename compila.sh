#!/bin/bash

#Definimos una función para manejar errores
handle_error(){
    echo "/-Error-\ --> $1"
    exit 1
}

#Compilar los archivos de la librería
gcc libreria.c -c -o libreria.o || handle_error "Error al compilar la libreria"

#Compilar los archivos de test
gcc test.c -c -o test.o || handle_error "Error al compilar el test"

#Enlazar los archivos objeto
gcc -o test libreria.o test.o || handle_error "Error al enlazar los archivos objeto"

#Dar permiso al archivo ejecutable
chmod +x test || handle_error "Error al dar permisos de ejecucion"

#Se avisa al usuario que el script se ha ejecutado con éxito
echo "Compilación compleltada, puede ejecutar el programa './test'"
