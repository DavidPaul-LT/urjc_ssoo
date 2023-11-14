#include <string.h>
#include <stdlib.h>
#include "libreria.h"
#include <stdio.h>

//Muestra las N primeras líneas en la salida estándar recibidas por la entrada estándar
int head(int n){ 
    int lenght = 1024;                                             //Contine el máximo de carácteres que tendrá cada línea a leer
    char text[lenght];                                             //Contiene el valor de la línea a leer en cada iteración
    int i = 0;                                                     //Contador para realizar [n] iteraciones
    //Se lee de la entrada estándar línea por línea hasta que se hayan leído n líneas.
    while(fgets(text, lenght, stdin) != NULL && i < n){
        printf("%s", text);
        i++;                                                       //actualizamos el valor del contador [i]
    }
}

//Muestra las N últimas líneas en la salida estándar recibidas por la entrada estándar
int tail(int n){
    int l = 1;                                                     //tamaño actual del array
    int i = 0;                                                     //Índice actual
    char** array;                                                  //Se declara un array de punteros a char.
    int length = 1024;                                             //Tamaño máximo de cada línea.
    array = (char**) malloc(l*sizeof(char*));                      //Se reserva memoria para el array.
    //control de error por asignación de memoria, lanza un error en caso
    if(array == NULL){
        fprintf(stderr, "Error al asignar memoria. \n");
        exit(1);
    }
    array[i] = (char*) malloc(length * sizeof(char));              //Se reserva memoria para el primer elemento del array.
    if(array[i] == NULL) {
        fprintf(stderr, "Error al asignar memoria al elemento.\n");
        exit(1);
    }
    //Se lee de la entrada estándar línea por línea.
    while(fgets(array[i], length, stdin) != NULL){
        // Si el tamaño del array es menor que n, se incrementa el tamaño del array.
        if(l < n){
            l++;
            array = (char**) realloc(array, l*sizeof(char*));       //Se reserva memoria para el array (+1 tamaño).
            if(array == NULL){
                fprintf(stderr, "Error al asignar memoria al array con un elemento nuevo. \n");
                exit(1);
            }
            array[l-1] = (char*) malloc(length * sizeof(char));     //Se reserva memoria para el nuevo elemento del array.
            if(array[l-1] == NULL) {
                fprintf(stderr, "Error al asignar memoria al elemento nuevo.\n");
                exit(1);
            }
        }
        i++;                                                        //Se incrementa el índice.
        // Si el índice alcanza n, se reinicia a 0.
        if(i == n){
            i = 0;
        }
    }

    // Se imprime el contenido del array.
    for(int i = 0; i < l; i++){
        printf("·%s\n", array[i]);
        free(array[i]);                                             //Se libera la memoria de cada elemento del array.
    }
    free(array);                                                    //Se libera la memoria del array.
}

//Muestra las N líneas más largas recibidas de mayor a menor, o todas ellas si hay menos de N líneas
int longline(int n){
    //If comprobando si hay menos de n líneas
        //For para recorrer las líneas
            //Imprimir línea
        //Fin del for
    //Else hay más de n líneas
        //For para recorrer las líneas
            //Comparar tamaño líneas e ir almacenándolas en un array
        //Fin for
        //For para recorrer el array de líneas ordenado por tamaño
            //Imprimir línea
        //Fin del for
}
