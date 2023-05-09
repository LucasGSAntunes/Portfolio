#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

int main() {
    int integers[MAX_LINES];
    char message[MAX_LINES*4+1] = ""; // uma string para armazenar a mensagem
    int i = 0;
    
    // ler os números inteiros hexadecimais da entrada
    while (scanf("%x", &integers[i]) != EOF) {
        // verificar se o grupo de 4 bytes contém o valor zero (EOS)
        if ((integers[i] & 0xFF) == 0) {
            break;
        }
        i++;
    }
    
    // decodificar a mensagem a partir dos números inteiros
    int j;
    for (j = 0; j < i; j++) {
        // extrair os 4 bytes do grupo de 4 bytes e converter cada byte em um caractere ASCII
        char c[5];
        sprintf(c, "%c%c%c%c", (integers[j] & 0xFF), ((integers[j] >> 8) & 0xFF), ((integers[j] >> 16) & 0xFF), ((integers[j] >> 24) & 0xFF));
        // concatenar os caracteres ASCII na string da mensagem
        strcat(message, c);
    }
    
    // imprimir a mensagem decodificada
    printf("%s\n", message);
    
    return 0;
}