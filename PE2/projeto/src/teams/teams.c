#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teams.h"
#include "../helpers/terminal/terminal.h"
#include "../helpers/binary/binary.h"

void checkTeamsFileIsInitialized() {
  // if (!doesFileExists(TEAMS_FILENAME)) {
  //   writeBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));
  // }
}

void listTeams() {
  cleanScreen();
  checkTeamsFileIsInitialized();

  FILE *file = fopen(TEAMS_FILENAME, "rb");
  if (file == NULL) {
    return;
  }
  
  Team team;
  printf("|---------------------------------|\n");
  printf("| %-32s|\n", "TIMES CADASTRADOS");
  printf("|---------------------------------|\n");
  printf("|- ID -|- NOME -------------------|\n");
  while(fread(&team, sizeof(Team), 1, file) == 1){
    printf("| %d | %-24s |\n", team.id, team.name);
  }
  printf("|------|--------------------------|\n\n");

  cleanInputBuffer();
  pressEnterToContinue();
}

// TEAM SCAN NAME
void createTeam() {
  cleanScreen();
  checkTeamsFileIsInitialized();

  FILE *file = fopen(TEAMS_FILENAME, "ab");

  if (file == NULL) {
    return;
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file) / sizeof(Team);

  Team new_team;
  cleanInputBuffer();
  printf("Nome do time: ");
  fgets(new_team.name, 25, stdin);
  if(new_team.name[strlen(new_team.name) - 1] == '\n') new_team.name[strlen(new_team.name) - 1] = '\0';

  new_team.id = size + TEAMS_DEFAULT_ID;

  fwrite(&new_team, sizeof(Team), 1, file);

  fclose(file);
  printf("\nTime salvo com sucesso!\n\n");

  pressEnterToContinue();
}

// NOT FOUND TEAM
// TEAM SCAN NAME
void updateTeam(){
  cleanScreen();

  // Team new_team;
  // printf("Id do time: ");
  // scanf("%d", &new_team.id);
  // cleanInputBuffer();
  // printf("Nome do time: ");
  // fgets(new_team.name, 25, stdin);
  // new_team.name[strcspn(new_team.name, "\n")] = '\0';

  // readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));

  // for(int i = 0; i < teams.teams_amount; i++){
  //   if(teams.teams[i].id == new_team.id){
  //     strcpy(teams.teams[i].name, new_team.name);
  //     break;
  //   }
  // }
  
  // writeBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));

  printf("\nO nome do time foi atualizado com sucesso!\n\n");
  pressEnterToContinue();
}

// NOT FOUND TEAM
void deleteTeam(){
  cleanScreen();

  // int team_id;
  // printf("Id do time: ");
  // scanf("%d", &team_id);

  // readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));
  // for(int i = 0; i < teams.teams_amount; i++){
  //   if(teams.teams[i].id == team_id){
  //     for(int j = i; j < teams.teams_amount - 1; j++){
  //       teams.teams[j] = teams.teams[j + 1];
  //     }
  //     teams.teams_amount--;
  //     writeBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));
  //     printf("\nO time foi deletado com sucesso!\n\n");
  //     cleanInputBuffer();
  //     pressEnterToContinue();
  //     return;
  //   }
  // }

  printf("\nTime não encontrado!\n\n");
  cleanInputBuffer();
  pressEnterToContinue();
}

int doesTeamExists(int team_id){
  // readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));

  // for(int i = 0; i < teams.teams_amount; i++){
  //   if(teams.teams[i].id == team_id){
  //     return 1;
  //   }
  // }
  return 0;
}

Team getTeam(int team_id){
  // readBinaryFile(TEAMS_FILENAME, &teams, sizeof(Teams));

  // for(int i = 0; i < teams.teams_amount; i++){
  //   if(teams.teams[i].id == team_id){
  //     return teams.teams[i];
  //   }
  // }
}
