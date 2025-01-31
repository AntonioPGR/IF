#include <stdio.h>
#include <stdlib.h>
#include "leagues.h"
#include "../teams/teams.h"
#include "../helpers/string_helper.h"
#include "../helpers/file_helper.h"
#include "string.h"

#define FILENAME "src/data/leagues.txt"
#define DEFAULT_ID 2001

void createLeague(){
  League NewLeague;

  NewLeague.name = getInputLine(25, "Nome do campeonato: ");
  printf("Numero de times: ");
  scanf("%d", &NewLeague.teams_amount);

  char *leagues = readFile(FILENAME);

  char *leagues_copy = malloc(strlen(leagues)*sizeof(char));
  strcpy(leagues_copy, leagues);
  int new_id = DEFAULT_ID;
  int last_semicolon_idx = findLastIndexOf(leagues, ';');
  if(last_semicolon_idx > 0){
    leagues_copy[last_semicolon_idx] = '\0';
    int before_semicolon_idx = findLastIndexOf(leagues_copy, ';');
    if(before_semicolon_idx < 0) before_semicolon_idx = 0;
    char last_id[4];
    strncpy(last_id, leagues_copy + before_semicolon_idx, 4);
    last_id[4] = '\0';
    new_id = atoi(last_id) + 1;
  }
  NewLeague.id = integerToString(new_id);

  NewLeague.teams_ids = (char **) malloc(NewLeague.teams_amount*4*sizeof(char));
  for(int i = 0; i < NewLeague.teams_amount; i++){
    char prompt[50];
    sprintf(prompt, "Insira o id do %d time: ", i+1);
    NewLeague.teams_ids[i] = getInputLine(5, prompt);
  }

  char *text = (char*) malloc(1000);
  char *concat[] = {leagues, NewLeague.id, "_", NewLeague.name, "_", integerToString(NewLeague.teams_amount), "_", NULL};
  text = concatStringArray(concat);
  for(int i = 0; i < NewLeague.teams_amount; i++){
    if((i + 1) == NewLeague.teams_amount) {
      char *id_concat[] = {text, NewLeague.teams_ids[i], ";", NULL};
      text = concatStringArray(id_concat);
      continue;
    }
    char *id_concat[] = {text, NewLeague.teams_ids[i], ",", NULL};
    text = concatStringArray(id_concat);
  }
  
  cleanFirstCharacter(text);
  writeInFile(FILENAME, text);
  free(leagues);
  free(NewLeague.teams_ids);
  free(text);
  free(leagues_copy);
};

void showLeagues(){
  char *leagues = readFile(FILENAME);

  char* token = strtok(leagues, ";");
  while(token != NULL){
    char *name_start = findFirstOccurrenceOf(token, '_');
    if(name_start!=NULL){
      char *name = name_start + 1;
      int name_end = findFirstIndexOf(name, '_');
      name[name_end] = '\0';
      printf("%s\n", name);
    }
    token = strtok(NULL, ";");
  }
}