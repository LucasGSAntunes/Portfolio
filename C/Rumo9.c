#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1001

int SomaDigito(char *n);
int degree(int soma,int grau) ;

int main()
{
    char n[MAX_DIGITS];
    int soma = 0, i = 0, grau;

    scanf("%s", n);

    while(n[0]!='0'){
        
        soma = SomaDigito(n);

        if(soma%9!=0)
            printf("%s is not a multiple of 9.\n", n);
        else{
            grau = degree(soma, 1);
            printf("%s is a multiple of 9 and has 9-degree %d.\n", n, grau);
        }
            
        
        scanf("%s", n);
    }
    return 0;
}

int SomaDigito(char *n){
    int i=0, soma=0;

    while (n[i] != '\0')
    {
        soma += n[i] - '0';
        i++;
    }

    return soma;
}

int SomaInt(int num){
    int soma=0;
    while(num>10){
        soma += num%10;
        num = num/10;
    }
    return soma+num;
}

int degree(int soma, int grau){

    if(soma == 9)
        return grau;
    else
        degree(SomaInt(soma),grau+1);
}