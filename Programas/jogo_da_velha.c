#include <stdio.h>

#define pecaX 'X'
#define pecaY 'O'
#define espacoVazio ' '

#define true 1
#define false 0

typedef int bool;

int verificaStatus(char tabuleiro[][3]) {
	int status = -1;
int i, j;
 
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      char peca = tabuleiro[i][j];
      if((tabuleiro[i][0] == ' ' && tabuleiro[i][1] == ' ' && tabuleiro[i][2] == ' ')
           && (tabuleiro[0][i] == ' ' && tabuleiro[1][i] == ' ' && tabuleiro[2][i] == ' ')
        && (tabuleiro[0][0] == ' ' && tabuleiro[1][1] == ' ' && tabuleiro [2][2] == ' '))
      
        
      status = 0;
      else {
      
      if((tabuleiro[i][2] == peca && peca !=' ' && tabuleiro [i][0] == tabuleiro [i][1] && tabuleiro [i][1] == tabuleiro [i][2])
      ||  (tabuleiro[2][j] == peca && peca !=' ' && tabuleiro [0][j] == tabuleiro [1][j] && tabuleiro [1][j] == tabuleiro [2][j])
      ||  (tabuleiro[1][1] == peca && peca !=' ' && tabuleiro [0][0] == tabuleiro [1][1] && tabuleiro [1][1] == tabuleiro [2][2])
      ||  (tabuleiro[1][1] == peca && peca !=' ' && tabuleiro [2][0] == tabuleiro [1][1] && tabuleiro [1][1] == tabuleiro [0][2]))
      status = true;
     else status = false;
      if (status){
       switch(peca){
          case 'X': return status = 1;
          case 'O': return status = 2;
          default: return status = 4; 
        }
        }
      
          
             if((tabuleiro[i][0] != ' ' && tabuleiro[i][1] != ' ' && tabuleiro[i][2] != ' ')
           && (tabuleiro[0][i] != ' ' && tabuleiro[1][i] != ' ' && tabuleiro[2][i] != ' '))
       
             status = 3;
            else status = 4;
               
          
       
      }
    }    
   }
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