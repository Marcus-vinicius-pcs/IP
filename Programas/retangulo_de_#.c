#include <stdio.h>

void retangulo(int largura, int altura){
  int i, j;
  for (i=0; i<altura; i++){
    for (j=1; j<largura; j++){
      printf("#");
    }
  printf("#\n");
    }
  }
int main (){
  retangulo (2,5);
  return 0;
}