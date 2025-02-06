#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../helpers/string.h"
#include "../helpers/binary.h"
#include "../helpers/text.h"
#include "teams.h"

#define FILENAME "/src/data/teams.bin"
#define DEFAULT_ID 1001

void initializeFile(){
  Teams teams;
  teams.teams_amount = 0;
  writeBynaryFile(FILENAME, &teams, sizeof(Teams));
}

void checkFileIsInitialized(){
  Teams buffer;
  readBinaryFile(FILENAME, &buffer, sizeof(Teams));
  if(&buffer == NULL){
    initializeFile();
  }
}

void listTeams(){
  cleanScreen();

  checkFileIsInitialized();

  Teams teams;
  readBinaryFile(FILENAME, &teams, sizeof(Teams));

  // printf("%d\n", teams.teams_amount);
  // for(int i = 0; i < teams.teams_amount; i++){
  //   printf("ID: %d\n", teams.teams[i].id);
  //   printf("Nome: %s\n\n", teams.teams[i].name);
  // }

  cleanInputBuffer();
  pressEnterToContinue();
}

void createTeam(){
  cleanScreen();

  Teams teams;
  readBinaryFile(FILENAME, &teams, sizeof(Teams));

  Team new_team;
  if(teams.teams_amount == 0) new_team.id = DEFAULT_ID;
  else new_team.id = teams.teams[teams.teams_amount - 1].id + 1;
  printf("Nome do time: ");
  scanf("%49s", new_team.name);

  teams.teams_amount++;
  teams.teams[teams.teams_amount - 1] = new_team;

  writeBynaryFile(FILENAME, &new_team, sizeof(Team));

  printf("\nO time foi cadastrado com sucesso!\n\n");
  pressEnterToContinue();
}

void updateTeam(){
  cleanScreen();
  char *team_id = getInputLine(5, "Id do time: ");
  char *new_name = getInputLine(50, "Novo nome do time: ");
  char *teams = readFile(FILENAME);
  if(strlen(teams) == 0){
    printf("SEM TIMES");
    return;
  }
  char *token = strtok(teams, ";");
  char *buffer = (char *) malloc(1000);
  buffer = "";
  while(token != NULL){
    char *undescore = findFirstOccurrenceOf(token, '_');
    if(undescore != NULL){
      *undescore = '\0';
      char *id = token;
      char *name = undescore+1;
      if(strcmp(id, team_id) == 0) name = new_name;
      char *concat[] = {buffer, id, "_", name, ";", NULL};
      buffer = concatStringArray(concat);
    }
    token = strtok(NULL, ";");
  }
  writeInFile(FILENAME, buffer);
  free(teams);

  printf("\nO nome do time foi atualizado com sucesso!\n\n");
  pressEnterToContinue();
}

void deleteTeam(){
  cleanScreen();

  char *team_id = getInputLine(5, "Id do time: ");
  char *teams = readFile(FILENAME);
  char *id_start = findSubstring(teams, team_id);
  char *id_end = findFirstOccurrenceOf(id_start, ';') + 1;
  memmove(id_start, id_end, strlen(teams));
  writeInFile(FILENAME, teams);
  free(teams);

  printf("\nO time foi deletado com sucesso!\n\n");
  cleanInputBuffer();
  pressEnterToContinue();
}

char* getTeamName(char* team_id){
  char* teams = readFile(FILENAME);
  if (teams == NULL || strlen(teams) == 0) return NULL;

  char* teams_copy = strdup(teams);  // Copy before modifying
  char* token = strtok(teams_copy, ";");
  while(token != NULL){
    if(strncmp(token, team_id, 4) == 0){
      char* team_name = strdup(token + 5);  // Copy team name before returning
      free(teams_copy);
      return team_name;
    }
    token = strtok(NULL, ";");
  }
  free(teams_copy);
  return NULL;
}
