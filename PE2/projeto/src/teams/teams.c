#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teams.h"
#include "../helpers/terminal/terminal.h"
#include "../helpers/binary/binary.h"

void checkTeamsFileIsInitialized() {
  if (!doesFileExists(TEAMS_FILENAME)) {
    Teams teams;
    teams.teams_amount = 0;
    writeBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));
  }
}

void listTeams() {
  cleanScreen();
  checkTeamsFileIsInitialized();
  Teams teams;
  readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));
  if(teams.teams_amount == 0){
    printf("Sem times cadastrados\n");
  } else {
    printf("\n|- ID -|- NOME -------------------|\n");
    for (int i = 0; i < teams.teams_amount; i++) {
      printf("| %d | %-24s |\n", teams.teams[i].id, teams.teams[i].name);
    }
    printf("|------|--------------------------|\n\n");
  }
  cleanInputBuffer();
  pressEnterToContinue();
}

// TEAM SCAN NAME
void createTeam() {
  cleanScreen();
  checkTeamsFileIsInitialized();

  Teams teams;
  readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));

  if (teams.teams_amount == TEAMS_MAX) {
    printf("Limite de times cadastrados atingido\n");
  } else {
    Team new_team;
    if (teams.teams_amount == 0) new_team.id = TEAMS_DEFAULT_ID;
    else new_team.id = teams.teams[teams.teams_amount - 1].id + 1;
    cleanInputBuffer();
    printf("Nome do time: ");
    fgets(new_team.name, 25, stdin);
    new_team.name[strcspn(new_team.name, "\n")] = '\0';
    teams.teams[teams.teams_amount] = new_team;
    teams.teams_amount++;
    writeBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));
    printf("\nO time foi cadastrado com sucesso!\n\n");
  }

  pressEnterToContinue();
}

// NOT FOUND TEAM
// TEAM SCAN NAME
void updateTeam(){
  cleanScreen();

  Team new_team;
  printf("Id do time: ");
  scanf("%d", &new_team.id);
  cleanInputBuffer();
  printf("Nome do time: ");
  fgets(new_team.name, 25, stdin);
  new_team.name[strcspn(new_team.name, "\n")] = '\0';

  Teams teams;
  readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));

  for(int i = 0; i < teams.teams_amount; i++){
    if(teams.teams[i].id == new_team.id){
      strcpy(teams.teams[i].name, new_team.name);
      break;
    }
  }
  
  writeBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));

  printf("\nO nome do time foi atualizado com sucesso!\n\n");
  pressEnterToContinue();
}

// NOT FOUND TEAM
void deleteTeam(){
  cleanScreen();

  int team_id;
  printf("Id do time: ");
  scanf("%d", &team_id);

  Teams teams;
  readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));
  for(int i = 0; i < teams.teams_amount; i++){
    if(teams.teams[i].id == team_id){
      for(int j = i; j < teams.teams_amount - 1; j++){
        teams.teams[j] = teams.teams[j + 1];
      }
      teams.teams_amount--;
      writeBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));
      printf("\nO time foi deletado com sucesso!\n\n");
      cleanInputBuffer();
      pressEnterToContinue();
      return;
    }
  }

  printf("\nTime não encontrado!\n\n");
  cleanInputBuffer();
  pressEnterToContinue();
}

int doesTeamExists(int team_id){
  Teams teams;
  readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));

  for(int i = 0; i < teams.teams_amount; i++){
    if(teams.teams[i].id == team_id){
      return 1;
    }
  }
  return 0;
}

Team getTeam(int team_id){
  Teams teams;
  readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));

  for(int i = 0; i < teams.teams_amount; i++){
    if(teams.teams[i].id == team_id){
      return teams.teams[i];
    }
  }
}
