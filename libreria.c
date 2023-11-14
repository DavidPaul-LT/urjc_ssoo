#include <string.h>
#include <stdlib.h>
#include "libreria.h"
#include <stdio.h>

// Función para intercambiar dos strings
void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// Función para particionar el array
int partition(char* arr[], int low, int high) {
    // El pivote es la longitud de la última string
    int pivot = strlen(arr[high]);
    int i = (low - 1);

    // Recorre el array y mueve las strings más largas que el pivote al principio del array
    for (int j = low; j <= high - 1; j++) {
        if (strlen(arr[j]) >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Coloca el pivote en su posición correcta
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función principal del algoritmo QuickSort
void quickSort(char* arr[], int low, int high) {
    if (low < high) {
        // Encuentra la posición del pivote
        int pi = partition(arr, low, high);

        // Ordena recursivamente las dos mitades
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


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
    return 0;
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
    return 0;
}

//Muestra las N líneas más largas recibidas de mayor a menor, o todas ellas si hay menos de N líneas
int longline(int n){
    int l = 1;                                                     //tamaño actual del array
    int i = 0;                                                     //Índice actual
    char** array;                                                  //Se declara un array de punteros a char.
    int length = 1024;                                             //Tamaño máximo de cada línea.
    char textO[length];                                            //Para almacenar el string recibido de la stdin
    array = (char*) malloc(l*sizeof(char));                      //Se reserva memoria para el array.
    // Control de error por asignación de memoria * 
    if(array == NULL){                                             //*
        fprintf(stderr, "Error al asignar memoria. \n");
        exit(1);
    }
    array[i] = (char*) malloc(length * sizeof(char));              //Se reserva memoria para el primer elemento del array.
    if(array[i] == NULL) {                                         //*
        fprintf(stderr, "Error al asignar memoria al elemento.\n");
        exit(1);
    }
    
    // Se lee de la entrada estándar línea por línea.
    while(fgets(textO, length, stdin) != NULL){
        // Si el tamaño del array es menor que n(máximo de líneas requeridas), se incrementa el tamaño del array.
        if(l < n){
            l++;
            i++;
            array = (char*) realloc(array, l*sizeof(char));      //Se reserva memoria para el array (+1 tamaño).
            if(array == NULL){                                     //*
                fprintf(stderr, "Error al asignar memoria al array con un elemento nuevo. \n");
                exit(1);
            }
            array[l-1] = (char*) malloc(length * sizeof(char));    //Se reserva memoria para el nuevo elemento del array.
            if(array[l-1] == NULL) {                               //*
                fprintf(stderr, "Error al asignar memoria al elemento nuevo.\n");
                exit(1);
            }
        }
        // Si el número de caractéres del string de la última posición del array es menor al de la línea recibida por el stdin 
        if(strlen(array[i]) < strlen(textO)){
            strcpy(array[i], textO);                               //copiar el valor de textO al array en la posicion i 
            quickSort(array, 0, l-1);                              //Se ordena el array actual, dependiendo del tamaño de los strings high > low
        }
    }

    // Se imprime el contenido del array.
    for(int i = 0; i < l; i++){
        printf("\n%s", array[i]);
        free(array[i]);                                             //Se libera la memoria de cada elemento del array.
    }
    free(array);                                                    //Se libera la memoria del array.
    return 0;
}
