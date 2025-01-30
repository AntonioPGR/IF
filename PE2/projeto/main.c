#include <stdio.h>
#include <string.h>
#include "./settings/settings.h"
#include "./teams/teams.h"

void showHeader(){
  int traces_amount = 40;
  char line[traces_amount];
  memset(line, '-', traces_amount);
  line[traces_amount] = '\0' ;
  printf("%s\n", line);
  printf("BOLA NA REDE\n");
  printf("%s\n", line);
}

void showOptionMenu(){
  printf("0 - Encerrar aplicação\n");
  printf("1 - Cadastrar time\n");
  printf("2 - Ver times cadastrados\n");
  printf("3 - Iniciar novo campeonato\n");
  printf("4 - Ver campeonatos\n");
}

int main(){
  loadSettings();

  int op;
  do{
    showHeader();
    showOptionMenu();
    scanf("%d", &op);
    switch(op){
      case 1:
        registerTeam();
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
    }

  } while(op != 0);

  return 0;
}