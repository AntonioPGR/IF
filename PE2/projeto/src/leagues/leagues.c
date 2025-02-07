#include <stdio.h>
#include <stdlib.h>
#include "leagues.h"
#include "string.h"
#include "../teams/teams.h"
#include "../helpers/string.h"
#include "../helpers/text.h"
#include "../rounds/rounds.h"

void showLeagues(){
  // cleanScreen();
  // char *leagues = readFile(FILENAME);
  // if(strlen(leagues) == 0){
  //   printf("SEM CAMPEONATOS");
  //   return;
  // }
  // printf("- ID -|- NOME ---------\n");
  // char* token = strtok(leagues, ";");
  // while(token != NULL){
  //   char *name_start = findFirstOccurrenceOf(token, '_');
  //   if(name_start != NULL){
  //     *name_start = '\0';
  //     char *name = name_start + 1;
  //     int name_end = findFirstIndexOf(name, '_');
  //     name[name_end] = '\0';
  //     printf(" %s |  %s\n", token, name);
  //   }
  //   token = strtok(NULL, ";");
  // }
  // free(leagues);
  // printf("\n");
  // cleanInputBuffer();
  // pressEnterToContinue();
}

void showTeamsInLeague() {
  // cleanScreen();
  // char *league_id = getInputLine(5, "Id do campeonato: ");
  // char *leagues = readFile(FILENAME);
  // if (strlen(leagues) == 0) {
  //     printf("SEM CAMPEONATOS");
  //     return;
  // }
  // char *token = strtok(leagues, ";");
  // while (token != NULL) {
  //   if (strncmp(token, league_id, strlen(league_id)) == 0) {
  //     char *last_underscore = findLastOccurrenceOf(token, '_');
  //     if (last_underscore != NULL) {
  //       char *ids = last_underscore + 1;
  //       char *ids_token = strtok(ids, ",");
  //       while (ids_token != NULL) {
  //         printf("ID do time: %s\n", ids_token);
  //         ids_token = strtok(NULL, ",");
  //       }
  //     }
  //     break; 
  //   }
  //   token = strtok(NULL, ";");
  // }
  // free(leagues);
  // free(league_id);
  // printf("\n");
  // cleanInputBuffer();
  // pressEnterToContinue();
}

void createLeague() {
  cleanScreen();
  
  League new_league;
  printf("Nome do campeonato: ");
  scanf("%24s", new_league.name);

  new_league.teams_amount = 0;
  while(
    new_league.teams_amount < 2 || 
    new_league.teams_amount > 26 || 
    new_league.teams_amount % 2 != 0
  ) {
    printf("Quantidade de times (N par de 2 a 26): ");
    scanf("%d", &new_league.teams_amount);
  }

  for (int i = 0; i < new_league.teams_amount; i++) {
    printf("ID do time %d: ", i + 1);
    int temp;
    scanf("%d", &temp);
    if(!doesTeamExists(temp)){
      printf("Time não encontrado\n");
      i--;
      continue;
    }
    new_league.teams_ids[i] = temp;
  }

  new_league.rounds_amount = new_league.teams_amount - 1;

  Round rounds[new_league.rounds_amount];
  for (int i = 0; i < new_league.rounds_amount; i++) {
    rounds[i].id = ROUNDS_DEFAULT_ID + i;
    for (int j = 0; j < new_league.teams_amount / 2; j++) {
      rounds[i].games[j].id = GAMES_DEFAULT_ID + j;
      rounds[i].games[j].home_score = -1;
      rounds[i].games[j].visitor_score = -1;
    }
  }

  printf("\nO campeonato foi cadastrado com sucesso!\n\n");
  cleanInputBuffer();
  pressEnterToContinue();
}

void deleteLeague() {
  // cleanScreen();
  // char *league_id = getInputLine(5, "Insira o ID do campeonato a ser deletado: ");
  // char *leagues = readFile(FILENAME);
  // if (strlen(leagues) == 0) {
  //   printf("Nenhum campeonato cadastrado.\n");
  //   free(league_id);
  //   pressEnterToContinue();
  //   return;
  // }
  // char *leagues_copy = strdup(leagues);
  // char *token = strtok(leagues_copy, ";");
  // char updated_leagues[1000] = "";
  // int league_found = 0;
  // while (token != NULL) {
  //   char *underscore = findFirstOccurrenceOf(token, '_');
  //   if (underscore != NULL) {
  //     char current_id[5];
  //     strncpy(current_id, token, underscore - token);
  //     current_id[underscore - token] = '\0';
  //     if (strcmp(current_id, league_id) == 0) {
  //       league_found = 1;
  //       printf("Campeonato com ID %s deletado.\n", league_id);
  //     } else {
  //       strcat(updated_leagues, token);
  //       strcat(updated_leagues, ";");
  //     }
  //   }
  //   token = strtok(NULL, ";");
  // }
  // free(leagues_copy);
  // if (!league_found) {
  //   printf("Campeonato com ID %s não encontrado.\n", league_id);
  // } else {
  //   writeInFile(FILENAME, updated_leagues);
  // }
  // free(league_id);
  // free(leagues);
  // pressEnterToContinue();
}