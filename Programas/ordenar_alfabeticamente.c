/* Este é um programa que recebe um conjunto de nomes e organiza-os em ordem alfabetica*/
#include <stdio.h>
#include <string.h>




void adicionarNomes (char nomes[][10], int tamanho){
int i;
for(i=0; i<tamanho; i++){
    printf("\nDigite um nome : ");
    scanf("%s", nomes[i]);
	}
	}

void OrdemAlfabetica (char nomes[][10], int tamanho){
    int i, ult;
    char aux[10];
    for(ult=tamanho-1; ult>0; ult--){
        for(i=0; i<ult; i++){
            if(strcmp(nomes[i], nomes[i+1]) > 0){
            strcpy(aux, nomes[i]);
            strcpy(nomes[i], nomes[i+1]);
            strcpy(nomes[i+1], aux);
            }
            }
    }
	printf("\norganizando em ordem alfabetica:");
}

void imprimirNomes(char nomes[][10], int tamanho){
	int i;
	printf("\n\n");
	for(i=0; i<tamanho; i++){
		printf("%s\n", nomes[i]);
	}
}

int main(){
    int tamanho;
	printf("\ndigite a quantidade de nomes: ");
	scanf("%i", &tamanho);
	char nomes[tamanho][10];
    adicionarNomes(nomes, tamanho);
    OrdemAlfabetica (nomes, tamanho);
    imprimirNomes(nomes, tamanho);
        
    
    return 0;
}
  
  