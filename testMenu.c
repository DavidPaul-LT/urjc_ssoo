#include "libreria.h"
#include <stdio.h>

int menu(){
    int opcion; //Opcion del menu

    printf(" ______________________________________________\n");
    printf("|_____________MENU_PROBAR_LIBRERIA_____________|\n");
    printf("| 1. Introducir el numero de lineas a procesar |\n");
    printf("| 2. Ver numero de lineas que se procesan      |\n");
    printf("| 3. Head                                      |\n");
    printf("| 4. Tail                                      |\n");
    printf("| 5. Longline                                  |\n");
    printf("| 6. Salir                                     |\n");
    printf("|______________________________________________|\n");
    printf("\n");
    printf("--> Introduzca una opcion: ");
    scanf("%d", &opcion);
    printf("\n");
    //Constrol de errores
    if(opcion < 1 || opcion > 6){
        printf("ERROR --> La opcion introducida es incorrecta");
        printf("\n");
        printf("--> Introduzca una opcion valida: ");
        scanf("%d", &opcion);
        printf("\n");
    }
    else
        return opcion;

}

void main(int argc, char const *argv[], char *envp[]){
    int num = 5; //Valor que se le pasará a las funciones (5 por defecto)
    int opc; //Opcion seleccionada del menu

    opc = menu();
    while(opc != 6){
        switch (opc){
        case 1:
            printf("--> Introduzca el numero de lineas: ");
            scanf("%d", &num);
            printf("\n");
            break;
        case 2:
            printf("El numero de lineas que se procesan es: %d\n", num);
            printf(" \n");
            break;
        case 3:
            printf("Ejecutando la funcion 'head'...\n");
            head(num);
            printf("\n");
            break;
        case 4:
            printf("Ejecutando la funcion 'tail'...\n");
            tail(num);
            printf("\n");
            break;
        case 5:
            printf("Ejecutando la funcion Longline...\n");
            longline(num);
            printf("\n");
            break;
        }
        opc = menu();
    }
}