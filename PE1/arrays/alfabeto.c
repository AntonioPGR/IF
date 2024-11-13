#include <stdio.h>
#include <string.h>
#include <sys/time.h>

char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";

int main(){

  char answer[100];
  struct timeval start, end;
  double time_spent = 0;
  int errors = 0;

  printf("Digite o alfabeto de A a Z! \nPressione ENTER para começar.");
  getchar();

  gettimeofday(&start, NULL);
  fgets(answer, sizeof(answer), stdin);
  gettimeofday(&end, NULL);
  time_spent = (end.tv_sec - start.tv_sec) + (end.tv_sec - start.tv_sec) / 1000000.0;

  for(int i = 0; i < strlen(answer) - 1; i++){
    if(answer[i] != ALPHABET[i]){
      errors++;
      break;
    }
  }
  
  if(!errors){
    printf("Você digitou corretamente!\n");
    printf("O tempo gasto foi: %lf\n", time_spent);
  } else printf("Você digitou a sequencia incorretamente!\n");

  return 0;
}