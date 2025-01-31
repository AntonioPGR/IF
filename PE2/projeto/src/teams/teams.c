#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../helpers/file_helper.h"
#include "../helpers/string_helper.h"

#define FILENAME "src/data/teams.txt"
#define DEFAULT_ID 1001

void registerTeam(){
  char *name = getInputLine(25, "Nome do time: ");
  char *teams = readFile(FILENAME);
  int new_id = 1001;
  int last_id_idx = findLastIndexOf(teams, '_') - 4;
  if(last_id_idx > 0){
    char last_id[4];
    strncpy(last_id, teams + last_id_idx, 4);
    last_id[4] = '\0';
    new_id = atoi(last_id) + 1;
  }
  char *new_id_str = integerToString(new_id);
  char* concat[] = {teams, new_id_str, "_", name, ";", NULL};
  teams = concatStringArray(concat);
  cleanFirstCharacter(teams);
  writeInFile(FILENAME, teams);
  free(teams);
}

void listTeams(){
  char *teams = readFile(FILENAME);
  if(strlen(teams) == 0){
    printf("SEM TIMES");
    return;
  }
  char *token = strtok(teams, ";");
  while(token != NULL){
    char *undescore = strchr(token, '_');
    if(undescore != NULL){
      *undescore = '\0';
      char *id = token;
      char *name = undescore+1;
      printf("ID: %s, Name: %s\n", id, name);
    }
    token = strtok(NULL, ";");
  }
  free(teams);
}

void deleteTeam(){
  char *team_id = getInputLine(5, "Id do time:");

  char *teams = readFile(FILENAME);
  char *position = strstr(teams, team_id);

  if (position == NULL) {
    printf("ID não encontrado.\n");
    return;
  } 

  int index = position - teams;
  char *substituition_start = teams + index;
  char *next_semicolon = strchr(substituition_start, ';');
  int end_index = next_semicolon - teams;
  memmove(teams + index, teams + end_index + 1, strlen(teams));
  writeInFile(FILENAME, teams);
  teams[strlen(teams) - end_index + index - 1] = '\0';

  free(teams);
}

void updateTeam(){
  char *team_id = getInputLine(5, "Id do time: ");

  char *new_name = getInputLine(50, "Novo nome do time: ");

  char *teams = readFile(FILENAME);
  if(strlen(teams) == 0){
    printf("SEM TIMES");
    return;
  }

  char *token = strtok(teams, ";");
  char buffer[1000] = "";
  while(token != NULL){
    char *undescore = strchr(token, '_');
    if(undescore != NULL){
      *undescore = '\0';
      char *id = token;
      char *name = undescore+1;
      strcat(buffer, id);
      strcat(buffer, "_");
      if(strcmp(id, team_id) == 0) strcat(buffer, new_name);
      else strcat(buffer, name);
      strcat(buffer, ";");
    }
    token = strtok(NULL, ";");
  }
  writeInFile(FILENAME, buffer);
  free(teams);

}