#include <string.h>
#include <stdlib.h>
#include "libreria.h"
#include <stdio.h>

//Muestra las N primeras líneas en la salida estándar recibidas por la entrada estándar
int head(int n){ 
                                                                //Recibimos el valor de un entero en la variable [n]
    char text[1000];                                            //Contiene el valor de la línea a leer, max. 1000 chrts.
    int i = 0;                                                  //Contador para realizar [n] iteraciones
    while(fgets(text, 1000, stdin) != NULL && i < n){           //Con cada iteración, se actualiza el contenido de [text]
        printf("%s", text);
        i++;                                                    //actualizamos el valor del contador [i]
    }
    exit(0);
}

//Muestra las N últimas líneas en la salida estándar recibidas por la entrada estándar
int tail(int n){ 
    //For inverso para ir leyendo las n últimas líneas
        //Imprimir por pantalla
    //Fin dle for
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
