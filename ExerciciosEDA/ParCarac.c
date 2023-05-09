#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 200

int ContaPar(char *n, int count, int pares);

int main(){

    char n[MAX_DIGITS];
    int pares;

    scanf("%s", n);

    pares = ContaPar(n,0,0);

    printf ("%d", pares);

    return 0;
}

int ContaPar(char *n, int count, int pares){
    if(n[count+2]=='\0')
        return pares;
    if(n[count]==n[count+2])
        ContaPar(n,count+1,pares+1);
    else
        ContaPar(n,count+1,pares);

}