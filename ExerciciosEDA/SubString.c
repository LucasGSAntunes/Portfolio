#include <stdio.h>
#include <string.h>

int maior_substring(char *str, char *sub, int soma) {
    
    int n = strlen(str);
    int m = strlen(sub);

    if (strstr(str, sub) == NULL) 
        return soma;
    if(strncmp(str, sub, m)==0)
        maior_substring(str+m,sub,soma+m);
    else if(soma!=0)
        maior_substring(str+1,sub,soma+1);
    else
        maior_substring(str+1,sub,soma);
}

int main() {
    char str[101], sub[101];
    scanf("%100s %100s", str, sub);
    printf("%d\n", maior_substring(str, sub, 0));
    return 0;
}