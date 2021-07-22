#include <stdio.h>

#define pecaX 'X'
#define pecaY 'O'
#define espacoVazio ' '

#define true 1
#define false 0

typedef int bool;
//retorna true se todas as casas foram preenchidas e não houve vencedor
bool verificaEmpate (char tabuleiro[][3]){
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      if(tabuleiro[i][j] == espacoVazio) return false;
    }
  }
  return true;
}

//retorna true se nenhuma casa está com peça, indicando que o jogo não começou 
bool verificaInicio (char tabuleiro[][3]){
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      if(tabuleiro[i][j] != espacoVazio) return false;
    }
  }
  return true;
}

//retorna true se houve vencedor e false se não houve
bool verificaVencedor (char tabuleiro[][3], char peca){
  int i, j, contX, contY;
  for(i=0;i<3;i++){
    contX = 0;
    contY = 0;
    for(j=0;j<3;j++){
      if(tabuleiro[i][j] == peca) contX++;
      if(tabuleiro[j][i] == peca) contY++;
    }
    if(contX == 3 || contY == 3) return true;
  }
  if(tabuleiro[0][0] == peca && tabuleiro[1][1] == peca && tabuleiro[2][2] == peca) return true;
  if(tabuleiro[0][2] == peca && tabuleiro[1][1] == peca && tabuleiro[2][0] == peca) return true;
  
  return false;
}

int verificaStatus(char tabuleiro[][3]) {
	int status = 4;
  if(verificaInicio(tabuleiro)) status = 0;
  if(verificaVencedor(tabuleiro, pecaX)) status =  1;
  if(verificaVencedor(tabuleiro, pecaY)) status =  2;
  if(verificaEmpate(tabuleiro)) status =  3;
  return status;
}

int main(){
	char tab0[][3] =   {{' ',' ',' '},
                      {' ',' ',' '},
                      {' ',' ',' '}};
	
    char tab1[][3] = {{' ',' ','X'},
                      {'O','X',' '},
                      {'X',' ','O'}};
	
    char tab2[][3] = {{' ','O',' '},
                      {' ','O','X'},
                      {' ','O','X'}};
	
    char tab3[][3] = {{'O','X','X'},
                      {'X','O','O'},
                      {'O','X','X'}};
	
    char tab4[][3] = {{' ',' ',' '},
                      {'X','O','X'},
                      {' ',' ',' '}};

    char tab5[][3] = {{'X',' ',' '},
                      {'X',' ',' '},
                      {' ',' ',' '}};

  

	printf("Status calculado: %i\n", verificaStatus(tab0));
	printf("Status esperado para o tabuleiro0: 0\n\n");

	printf("Status calculado: %i\n", verificaStatus(tab1));
	printf("Status esperado para o tabuleiro1: 1\n\n");

	printf("Status calculado: %i\n", verificaStatus(tab2));
	printf("Status esperado para o tabuleiro2: 2\n\n");
	
	printf("Status calculado: %i\n", verificaStatus(tab3));
	printf("Status esperado para o tabuleiro3: 3\n\n");
	
	printf("Status calculado: %i\n", verificaStatus(tab4));
	printf("Status esperado para o tabuleiro4: 4\n\n");

    printf("Status calculado: %i\n", verificaStatus(tab5));
	printf("Status esperado para o tabuleiro5: 4\n\n");
  
	return 0;
}