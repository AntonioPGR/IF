#include <stdio.h>
#include <string.h>
#include "./settings/settings.h"
#include "./teams/teams.h"
#include "./leagues/leagues.h"

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
  printf("0 - Encerrar aplicação\n1 - Cadastrar time\n2 - Ver times cadastrados\n3 - Deletar time\n4 - Atualizar time\n5 - Criar Campeonato\n6 - Listar Campeonatos\n");
}

int main(){
  loadSettings();

  int op;
  do{
    showHeader();
    showOptionMenu();
    scanf("%d", &op);
    printf("\n");
    switch(op){
      case 1:
        createTeam();
        break;
      case 2:
        listTeams();
        break;
      case 3:
        deleteTeam();
        break;
      case 4:
        updateTeam();
        break;
      case 5:
        createLeague();
        break;
      case 6:
        showLeagues();
        break;
    }
    printf("\n");
  } while(op != 0);

  return 0;
}