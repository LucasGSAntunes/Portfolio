#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 14

int SomaDigito(char *n, int count);

int main(){

    char n[MAX_DIGITS];
    int soma;

    scanf(" %s", n);

    soma = SomaDigito(n, 0);

    printf("%d\n", soma);

    return 0;
}



int SomaDigito(char *n, int count){
    int soma;

    if(n[count+1]=='\0')
        return n[count]-'0';
    
    soma = SomaDigito(n,count+1);

    return soma+n[count]-'0';    
}