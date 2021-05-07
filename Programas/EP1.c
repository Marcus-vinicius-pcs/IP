#include <stdio.h>
int n50, n20, n5, n1, valor;
int main() {
    
    printf("Digite um valor inteiro a ser retirado: R$\n");
    scanf("%i", &valor);
    if (valor<0)
    {
      printf("O número de notas de 50 reais a serem emitidas são -1\n");  
      printf("O número de notas de 20 reais a serem emitidas são -1\n");
      printf("O número de notas de 5 reais a serem emitidas são -1\n");
      printf("O número de notas de 1 real a serem emitidas é -1\n");
    }
    else
    {
    n50 = valor/50;
    printf("O número de notas de 50 reais a serem emitidas são %i\n", n50);
    n20 = (valor-n50*50)/20;
    printf("O número de notas de 20 reais a serem emitidas são %i\n", n20);
    n5 = (valor-n50*50 - n20*20)/5;
    printf("O número de notas de 5 reais a serem emitidas são %i\n", n5);
    n1 = (valor-n50*50 -n20*20 -n5*5)/1;
    printf("O número de notas de 1 real a serem emitidas é %i\n", n1);
    }
    return 0;

}