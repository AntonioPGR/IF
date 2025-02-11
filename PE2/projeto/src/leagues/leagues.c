#include <stdio.h>
#include <stdlib.h>
#include "leagues.h"
#include "string.h"
#include "../teams/teams.h"
#include "../helpers/binary.h"
#include "../helpers/text.h"
#include "../helpers/string.h"

void checkLeaguesFileIsInitialized(){
  if (!doesFileExists(LEAGUES_FILENAME)) {
    Leagues leagues;
    leagues.leagues_amount = 0;
    writeBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));
  }
}

void showLeagues(){
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));

  if(leagues.leagues_amount == 0){
    printf("SEM CAMPEONATOS\n");
  } else {
    printf("\n|- ID -|- NOME -------------------|- TIMES -|\n");
    for (int i = 0; i < leagues.leagues_amount; i++) {
      League league = leagues.leagues[i];
      printf("| %d | %-24s | %2d      |\n", league.id, league.name, league.teams_amount);
    }
    printf("|------|--------------------------|---------|\n\n");
  }

  cleanInputBuffer();
  pressEnterToContinue();
}

void showTeamsInLeague() {
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));

  if(leagues.leagues_amount == 0){
    printf("SEM CAMPEONATOS\n");
    cleanInputBuffer();
    pressEnterToContinue();
    return;
  }

  League league;
  int found = 0;
  do{
    int league_id;
    printf("ID do campeonato: ");
    scanf("%d", &league.id);
    for(int i = 0; i < leagues.leagues_amount; i++){
      if(leagues.leagues[i].id == league.id){
        league = leagues.leagues[i];
        found = 1;
        break;
      }
    }
  } while (!found);

  printf("|---------------------------------|\n");
  printf("| %-31s |\n", league.name);
  printf("|---------------------------------|\n");
  printf("|- ID -|- NOME -------------------|\n");
  for (int i = 0; i < league.teams_amount; i++) {
    Team team = getTeam(league.teams_ids[i]);
    printf("| %d | %-24s |\n", team.id, team.name);
  }
  printf("|------|--------------------------|\n\n");

  cleanInputBuffer();
  pressEnterToContinue();
}

void createLeague() {
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));
  if(leagues.leagues_amount >= LEAGUES_MAX){
    printf("Número máximo de campeonatos atingido\n");
    cleanInputBuffer();
    pressEnterToContinue();
    return;
  }
  
  League new_league;
  cleanInputBuffer();
  printf("Nome do campeonato: ");
  fgets(new_league.name, 25, stdin);
  new_league.name[strcspn(new_league.name, "\n")] = '\0';

  new_league.teams_amount = 0;
  while(
    new_league.teams_amount < 2 || 
    new_league.teams_amount > 26 || 
    new_league.teams_amount % 2 != 0
  ) {
    printf("Quantidade de times (N par de 2 a 26): ");
    scanf("%d", &new_league.teams_amount);
  }
  new_league.rounds_amount = new_league.teams_amount - 1;
  new_league.id = LEAGUES_DEFAULT_ID + leagues.leagues_amount;

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

  int teams_ids[new_league.teams_amount];
  for(int i = 0; i < new_league.teams_amount; i++){
    teams_ids[i] = new_league.teams_ids[i];
  }

  for(int i = 0; i < new_league.rounds_amount; i++){
    new_league.rounds[i].id = ROUNDS_DEFAULT_ID + i;
    new_league.rounds[i].games_amount = new_league.teams_amount / 2;
    for(int j = 0; j < new_league.rounds[i].games_amount; j++){
      new_league.rounds[i].games[j].id = GAMES_DEFAULT_ID + j;
      new_league.rounds[i].games[j].home_score = -1;
      new_league.rounds[i].games[j].home_id = teams_ids[j];
      new_league.rounds[i].games[j].visitor_score = -1;
      new_league.rounds[i].games[j].visitor_id = teams_ids[new_league.teams_amount - 1 - j];
    }
    int temp = teams_ids[new_league.teams_amount - 1];
    for (int k = new_league.teams_amount - 1; k > 1; k--) {
      teams_ids[k] = new_league.teams_ids[k - 1];
    }
    teams_ids[1] = temp;
  }

  leagues.leagues[leagues.leagues_amount] = new_league;
  leagues.leagues_amount++;

  writeBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));

  printf("\nO campeonato foi cadastrado com sucesso!\n\n");
  cleanInputBuffer();
  pressEnterToContinue();
}

void deleteLeague() {
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));

  if(leagues.leagues_amount == 0){
    printf("SEM CAMPEONATOS\n");
    cleanInputBuffer();
    pressEnterToContinue();
    return;
  }

  int league_id;
  printf("ID do campeonato: ");
  scanf("%d", &league_id);

  for(int i = 0; i < leagues.leagues_amount; i++){
    if(leagues.leagues[i].id == league_id){
      for(int j = i; j < leagues.leagues_amount - 1; j++){
        leagues.leagues[j] = leagues.leagues[j + 1];
      }
      leagues.leagues_amount--;
      writeBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));
      printf("\nO campeonato foi deletado com sucesso!\n\n");
      cleanInputBuffer();
      pressEnterToContinue();
      return;
    }
  }

  printf("Campeonato não encontrado\n");
  cleanInputBuffer();
  pressEnterToContinue();
}

void showLeagueGames(){
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));

  if(leagues.leagues_amount == 0){
    printf("SEM CAMPEONATOS\n");
    cleanInputBuffer();
    pressEnterToContinue();
    return;
  }

  League league;
  int found = 0;
  do{
    int league_id;
    printf("ID do campeonato: ");
    scanf("%d", &league.id);
    for(int i = 0; i < leagues.leagues_amount; i++){
      if(leagues.leagues[i].id == league.id){
        league = leagues.leagues[i];
        found = 1;
        break;
      }
    }
  } while (!found);

  printf("|----------------------------------------------------------------------------------|\n");
  printf("| %-80s |\n", league.name);
  printf("|----------------------------------------------------------------------------------|\n");
  printf("|- RODADA -|- ID -|- CASA -------------------|- VISITANTE --------------|- PLACAR -|\n");
  for(int i = 0; i < league.rounds_amount; i++){
    Round round = league.rounds[i];
    for(int j = 0; j < round.games_amount; j++){
      Game game = round.games[j];
      Team home_team = getTeam(game.home_id);
      Team visitor_team = getTeam(game.visitor_id);
      printf("|   %d   | %d | %-24s | %-24s |", round.id, game.id, home_team.name, visitor_team.name);
      if(game.home_score == -1) printf(" XX vs XX |\n");
      else printf(" %2d vs %2d |\n", game.home_score, game.visitor_score);
    }
    printf("|----------------------------------------------------------------------------------|\n");
  }

  cleanInputBuffer();
  pressEnterToContinue();
}