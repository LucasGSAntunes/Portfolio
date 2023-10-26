#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 500

char PrintaContrario(char *n, int count);

int main(){

    char n[MAX_DIGITS];
    char *s;

    scanf("%s", n);

    PrintaContrario(n,0);
    printf("\n");

    return 0;
}

char PrintaContrario(char *n, int count){
    char letra;

    if(n[count]=='\0')
        return n[count-1];
    
    letra = PrintaContrario(n, count+1);

    printf("%c", letra);
    return n[count-1];
}