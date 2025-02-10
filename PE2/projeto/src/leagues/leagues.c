#include <stdio.h>
#include <stdlib.h>
#include "leagues.h"
#include "string.h"
#include "../teams/teams.h"
#include "../helpers/binary.h"
#include "../helpers/text.h"
#include "../helpers/string.h"
#include "../rounds/rounds.h"

void showLeagues(){
  cleanScreen();
  
  Leagues leagues;
  readBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));

  for(int i = 0; i < leagues.leagues_amount; i++){
    printf("ID: %s\n", leagues.leagues[i].name);
  }

  printf("\n");
  cleanInputBuffer();
  pressEnterToContinue();
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
  
  Leagues leagues;
  leagues.leagues_amount = 0;
  readBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));
  if(leagues.leagues_amount >= LEAGUES_MAX){
    printf("Número máximo de campeonatos atingido\n");
    cleanInputBuffer();
    pressEnterToContinue();
    return;
  }
  
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
    if(!getTeamName(temp)){
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
      strcpy(rounds[i].games[j].home_name, "Corinthians");
      strcpy(rounds[i].games[j].visitor_name, "Palmeiras");
      int temp = new_league.teams_ids[new_league.teams_amount - 1];
      for (int k = new_league.teams_amount - 1; k > 1; k--) {
        new_league.teams_ids[k] = new_league.teams_ids[k - 1];
      }
      new_league.teams_ids[1] = temp;
    }
  }
  memcpy(new_league.rounds, rounds, sizeof(rounds));

  leagues.leagues[leagues.leagues_amount] = new_league;

  writeBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));

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