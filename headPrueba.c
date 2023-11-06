#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printLine(int n)
{

    printf("COMENZAMOS A ESCANEAR\n");
    char *storage;
    char texto[100];
    int counter = 0;
    while(counter < n){
        fgets(texto, 100, stdin);
        if(strcmp(storage[counter], "fin\n") == 0){
            break;9o0o
        }
        storage[counter] = &(texto);
        counter++;
    };
    printf("PROCESANDO...\n");
    for(int i = 0; i < n; i++){
        printf("en la posicion %i ", i);
        printf("se encuentra el valor: %s\n", storage[i]);
    }
    printf("TERMINAMOS EL PROGRAMA\n");

    /*printf();
    printf("Comenzando");
    while (fgets(line, 100, stdin) != NULL && count < n){
        printf("%s", line);
        printf();
        count++;
    }*/

}

int main(){
    int n = 3;
    printLine(n);
    return 0;
}