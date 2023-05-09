#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 80

char * TrocaXY(char *n, int count);

int main(){

    char n[MAX_DIGITS];
    char *s;

    scanf("%s", n);

    s = TrocaXY(n,0);

    printf ("%s\n", s);

    return 0;
}

char * TrocaXY(char *n, int count){
    if(n[count]=='\0')
        return n;
    if(n[count]=='x')
        n[count] = 'y';
    TrocaXY(n,count+1);
}