/*
Este programa serve para calcular a área de uma casa e sua piscina
*/
#include <stdio.h>
#include <math.h>
float lateral, comprimento, areas, areaq, areap, areat;
double raio;

void areainterna(float lateral, comprimento){
    areas = pow(lateral,2);
    printf("Area da sala: %f\n", areas);
    areaq = (lateral/2)*comprimento;
    printf("Area do quarto: %f\n", areaq);
    printf("Area do banheiro: %f\n", areaq);
    return 0;
}
double areapiscina(double raio) {
    return (M_PI*pow(raio,2));
}
int main() {
printf("Digite o valor da lateral da casa:\n");
scanf("f", &lateral);
printf("Digite o valor do comprimento da casa:\n");
scanf("f", &comprimento);
printf("Digite o valor do raio da piscina:\n");
scanf("d", &raio);
areainterna()
areapscina()
areat = areas + 2*areaq + areap + areat;
printf("Area total: %f\n", areat);
return 0;
}