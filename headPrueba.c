#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printLine(int n)
{

    char text[n][1000];
    int i = 0;
    bool sigue = true;
    while(fgets(text[i], 1000, stdin) != NULL){
        if(i < n){
            i++;
        }
    }
    printf("\n");
    printf("Las %i primeras lineas son: \n", n);

    for(int j = 0; j < n; j++){
        printf("Linea %i, contiene: %s \n",j+1, text[j]);
    }
}


int main(){
    int n = 5;
    printLine(n);
    return 0;
}