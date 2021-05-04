#include <stdio.h>
int main () {
    #define PI 3.14159
    int raio = 12;
    int lateral = 10;
    int cquarto = 7;
    int areas;
    int areaq;
    float areap;
    float areat;
    printf("Esse programa calcula a área de uma casa.\n");
    areas= lateral*lateral;
    printf("A área da sala é %i\n", areas);
    areaq= (lateral/2)*cquarto;
    printf("A área do quarto é %i\n", areaq);
    printf("A área do banheiro é %i\n", areaq);
    areap= raio*PI;
    printf("A área da pscina é %f\n", areap);
    areat= 2*areaq + areap + areas;
    printf("A ´área total é %f\n", areat);
    printf("11 dividido por 2 é %i\n", 11/2);
    printf("O resto da divisão inteira entre 11 e 2 é %i\n", 11%2);
    return 0;
}