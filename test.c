#include "libreria.h"
#include <stdio.h>

int main(int argc, char const *argv[], char *envp[]){

    if(argc < 2 || argc > 3){ //Control de errores en el caso de que los parámetros sean erroneos
        printf("ERROR --> Numero de argumentos erroneo\n");
        return 1;
    } 
    else{   
        if(argv[1][0] != "-"){
            printf("ERROR --> Argumeto invalido");
            return 1;
        }
        else{
            char funcionSel = argv[1][strlen(argv[1])]; //Seleccionamos la función introducida
            int lineas = 10; //El número de líneas a procesar por defecto es 10

            if(argc == 3){
                int aux = atoi(argv[2]);
                if(aux > 0){
                    int lineas = atoi(argv[2]); //Seleccionamos el número de líneas a procesar    
                }
                else{
                    printf("ERROR --> El numero de lineas introducido no es valido\n");
                    return 1;
                }
            }

            if(funcionSel == "-head"){
                head(lineas);
                return 0;
            }
            else if(funcionSel == "-tail"){
                tail(lineas);
                return 0;
            }
            else if(funcionSel == "-longlines"){
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