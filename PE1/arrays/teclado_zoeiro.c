#include <stdio.h>

int main(){

  int trocas, frases;
  scanf("%d %d", &trocas, &frases);

  char original[trocas], trocado[trocas], quote[100];
  for(int i = 0; i < trocas; i++){
    scanf("%c %c", &original[i], &trocado[i]);
  }

  for(int i = 0; i < frases; i++){
    fgets(quote, sizeof(quote), stdin);

    for()

  }




  return 0;
}