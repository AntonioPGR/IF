#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../helpers/file_helper.h"
#include "../helpers/string_helper.h"

#define FILENAME "src/data/teams.txt"
#define DEFAULT_ID 1001

void createTeam(){
  char *name = getInputLine(25, "Nome do time: ");
  char *teams = readFile(FILENAME);
  int new_id = DEFAULT_ID;
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
  printf("- ID -|- NOME ---------\n");
  char *token = strtok(teams, ";");
  while(token != NULL){
    char *undescore = findFirstOccurrenceOf(token, '_');
    if(undescore != NULL){
      *undescore = '\0';
      char *id = token;
      char *name = undescore+1;
      printf(" %s |  %s\n", id, name);
    }
    token = strtok(NULL, ";");
  }
  free(teams);
}

void deleteTeam(){
  char *team_id = getInputLine(5, "Id do time: ");
  char *teams = readFile(FILENAME);
  char *id_start = findSubstring(teams, team_id);
  char *id_end = findFirstOccurrenceOf(id_start, ';') + 1;
  memmove(id_start, id_end, strlen(teams));
  writeInFile(FILENAME, teams);
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
}