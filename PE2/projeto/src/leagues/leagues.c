#include <stdio.h>
#include <stdlib.h>
#include "leagues.h"
#include "string.h"
#include "../teams/teams.h"
#include "../helpers/string.h"
#include "../helpers/text.h"
#include "../rounds/rounds.h"

#define FILENAME "src/data/leagues.txt"
#define DEFAULT_ID 2001

void showLeagues(){
  cleanScreen();
  char *leagues = readFile(FILENAME);
  if(strlen(leagues) == 0){
    printf("SEM CAMPEONATOS");
    return;
  }
  printf("- ID -|- NOME ---------\n");
  char* token = strtok(leagues, ";");
  while(token != NULL){
    char *name_start = findFirstOccurrenceOf(token, '_');
    if(name_start != NULL){
      *name_start = '\0';
      char *name = name_start + 1;
      int name_end = findFirstIndexOf(name, '_');
      name[name_end] = '\0';
      printf(" %s |  %s\n", token, name);
    }
    token = strtok(NULL, ";");
  }
  free(leagues);
  printf("\n");
  cleanInputBuffer();
  pressEnterToContinue();
}

void showTeamsInLeague() {
  cleanScreen();
  char *league_id = getInputLine(5, "Id do campeonato: ");
  char *leagues = readFile(FILENAME);
  if (strlen(leagues) == 0) {
      printf("SEM CAMPEONATOS");
      return;
  }
  char *token = strtok(leagues, ";");
  while (token != NULL) {
    if (strncmp(token, league_id, strlen(league_id)) == 0) {
      char *last_underscore = findLastOccurrenceOf(token, '_');
      if (last_underscore != NULL) {
        char *ids = last_underscore + 1;
        char *ids_token = strtok(ids, ",");
        while (ids_token != NULL) {
          printf("ID do time: %s\n", ids_token);
          ids_token = strtok(NULL, ",");
        }
      }
      break; 
    }
    token = strtok(NULL, ";");
  }
  free(leagues);
  free(league_id);
  printf("\n");
  cleanInputBuffer();
  pressEnterToContinue();
}

void createLeague() {
  cleanScreen();
  
  League NewLeague;
  NewLeague.name = getInputLine(25, "Nome do campeonato: ");
  NewLeague.teams_amount = getInputNumber("Quantidade de times: ");

  char *data = readFile(FILENAME);
  NewLeague.id = getNextMainId(data, DEFAULT_ID);

  NewLeague.teams_ids = (char **) malloc(NewLeague.teams_amount * sizeof(char *));
  for (int i = 0; i < NewLeague.teams_amount; i++) {
    char prompt[50];
    sprintf(prompt, "Insira o id do %d time: ", i + 1);
    NewLeague.teams_ids[i] = getInputLine(5, prompt);
  }

  createRounds(NewLeague);

  char *text = (char *) malloc(1000 * sizeof(char));
  snprintf(text, 1000, "%s%s_%s_%d_", data, NewLeague.id, NewLeague.name, NewLeague.teams_amount);
  for (int i = 0; i < NewLeague.teams_amount; i++) {
    strcat(text, NewLeague.teams_ids[i]);
    if (i < NewLeague.teams_amount - 1) {
      strcat(text, ",");
    }
  }
  strcat(text, ";");
  cleanFirstCharacter(text);
  writeInFile(FILENAME, text);

  printf("\nO campeonato foi cadastrado com sucesso!\n\n");
  cleanInputBuffer();
  pressEnterToContinue();
}

void deleteLeague() {
  cleanScreen();
  char *league_id = getInputLine(5, "Insira o ID do campeonato a ser deletado: ");
  char *leagues = readFile(FILENAME);
  if (strlen(leagues) == 0) {
    printf("Nenhum campeonato cadastrado.\n");
    free(league_id);
    pressEnterToContinue();
    return;
  }
  char *leagues_copy = strdup(leagues);
  char *token = strtok(leagues_copy, ";");
  char updated_leagues[1000] = "";
  int league_found = 0;
  while (token != NULL) {
    char *underscore = findFirstOccurrenceOf(token, '_');
    if (underscore != NULL) {
      char current_id[5];
      strncpy(current_id, token, underscore - token);
      current_id[underscore - token] = '\0';
      if (strcmp(current_id, league_id) == 0) {
        league_found = 1;
        printf("Campeonato com ID %s deletado.\n", league_id);
      } else {
        strcat(updated_leagues, token);
        strcat(updated_leagues, ";");
      }
    }
    token = strtok(NULL, ";");
  }
  free(leagues_copy);
  if (!league_found) {
    printf("Campeonato com ID %s não encontrado.\n", league_id);
  } else {
    writeInFile(FILENAME, updated_leagues);
  }
  free(league_id);
  free(leagues);
  pressEnterToContinue();
}