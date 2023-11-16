#include "libreria.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[], char *envp[]){

    if(argc < 2 || argc > 3){ //Control de errores en el caso de que los parámetros sean erroneos
        printf("ERROR --> Numero de argumentos erroneo\n");
        return 1;
    } 
    else{
        if(argv[1][0] != '-'){
            printf("%c \n", argv[1][0]);
            printf("ERROR --> Argumeto invalido");
            return 1;
        }
        else{
            char funcionSel[10];
            strcpy(funcionSel, argv[1]);
            int lineas;

            if(argc == 3){
                int aux = atoi(argv[2]);
                if(aux > 0){
                    lineas = atoi(argv[2]); //Seleccionamos el número de líneas a procesar
                    printf("%i \n", lineas);
                }
                else{
                    printf("ERROR --> El número de lineas introducido no es válido\n");
                    return 1;
                }
            }else{
                lineas = 10;
                printf("%i", lineas);
            }

            if(strcmp(funcionSel, "-head")==0){
                head(lineas);
                return 0;
            }
            else if(strcmp(funcionSel, "-tail")==0){
                tail(lineas);
                return 0;
            }
            else if(strcmp(funcionSel, "-longlines")==0){
                longlines(lineas);
                return 0;
            }
            else{
                printf("ERROR --> La funcion introducida no se reconoce\n");
                return 1;
            }
        }
    }
}
