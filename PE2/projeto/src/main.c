#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "./settings/settings.h"
#include "./helpers/terminal/terminal.h"
#include "./teams/teams.h"
#include "./leagues/leagues.h"
#include "./reports/reports.h"

void showHeader(char* title){
  printTableLine(40);
  printf("| %-36s |", "BOLA NA REDE");
  if(title != "") printf(" - %s\n", title);
  else printf("\n");
  printTableLine(40);
}

void showTeamsMenu(){
  cleanScreen();
  int op, invalid_option = 0;
  do{
    showHeader("TIMES");
    char* message = invalid_option ? "\nOPÇÃO INVALIDA!!! Selecione uma opção válida para continuar...\n" : "";
    printf("0 - Voltar ao menu inicial\n1 - Ver times cadastrados\n2 - Cadastrar novo time\n3 - Atualizar nome do time\n4 - Apagar time\n%s\nEscolha uma opção: ", message);
    scanf("%d", &op);
    switch (op){
      case 0: 
        break;
      case 1: listTeams();
        break;
      case 2: createTeam();
        break;
      case 3: updateTeam();
        break;
      case 4: deleteTeam();
        break;
      default:
        invalid_option = 1;
    }
    cleanScreen();
  }while(op < 0 || op > 4);
}

void showLeagueMenu(){
  cleanScreen();
  int op, invalid_option = 0;
  do{
    showHeader("CAMPEONATOS");
    char* message = invalid_option ? "\nOPÇÃO INVALIDA!!! Selecione uma opção válida para continuar...\n" : "";
    printf("0 - Voltar ao menu inicial\n1 - Ver campeonatos cadastrados\n2 - Ver times participantes de um campeonato\n3 - Cadastrar novo campeonato\n4 - Apagar campeonato\n5 - Mostrar as rodadas de um campeonato\n6 - Iniciar rodada de campeonato\n7 - Mostrar tabela\n%s\nEscolha uma opção: ", message);
    scanf("%d", &op);
    switch (op){
      case 0: 
        break;
      case 1: showLeagues();
        break;
      case 2: showTeamsInLeague();
        break;
      case 3: createLeague();
        break;
      case 4: deleteLeague();
        break;
      case 5: showLeagueGames();
        break;
      case 6: startRound();
        break;
      case 7: showTable();
        break;
      default:
        invalid_option = 1;
    }
    cleanScreen();
  } while(op < 0 || op > 7);
}

int main(){
  cleanScreen();
  loadSettings();
  int op, invalid_option = 0;
  do{
    showHeader("");
    char* message = invalid_option ? "\nOPÇÃO INVALIDA!!! Selecione uma opção válida para continuar...\n" : "";
    printf("0 - Encerrar aplicação\n1 - Gerenciar Times\n2 - Gerenciar Campeonatos\n3 - Gerar Relatório de campeonato\n%s\nEscolha uma opção: ", message);
    scanf("%d", &op);
    invalid_option = 0;
    switch (op){
      case 0: 
        break;
      case 1: showTeamsMenu();
        break;
      case 2: showLeagueMenu();
        break;
      case 3: generateLeagueReport();
        break;
      default:
        invalid_option = 1;
    }
    cleanScreen();
  } while(op != 0);
  return 0;
}