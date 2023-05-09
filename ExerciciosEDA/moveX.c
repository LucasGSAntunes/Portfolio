#include <stdio.h>
#include <string.h>

void move_x(char* str) {
    if (strlen(str) == 0) { // caso base da recursão
        printf("%s", str);
        return;
    }
    
    if (str[0] == 'x') { // caractere 'x' encontrado
        move_x(str + 1);
        printf("x");
    } else { // caractere diferente de 'x'
        printf("%c", str[0]);
        move_x(str + 1);
    }
}

int main() {
    char str[101];
    scanf("%100s", str);
    move_x(str);
    return 0;
}
