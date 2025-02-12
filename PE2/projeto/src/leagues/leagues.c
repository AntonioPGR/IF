#include <stdio.h>
#include <stdlib.h>
#include "leagues.h"
#include "string.h"
#include "../teams/teams.h"
#include "../helpers/binary/binary.h"
#include "../helpers/terminal/terminal.h"

// SUPPORT
void checkLeaguesFileIsInitialized(){
  if (!doesFileExists(LEAGUES_FILENAME)) {
    Leagues leagues;
    leagues.leagues_amount = 0;
    writeBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));
  }
}

void readLeaguesFile(Leagues *leagues){
  readBinaryFile(LEAGUES_FILENAME, leagues, sizeof(Leagues));
}

int handleCheckNoLeagues(Leagues *leagues){
  if(leagues->leagues_amount == 0){
    printf("SEM CAMPEONATOS CADASTRADOS! \n\n");
    cleanBufferNContinue();
    return 1;
  }
  return 0;
}

int handleGetLeagueById(int id, Leagues *leagues, League *league){
  for(int i = 0; i < leagues->leagues_amount; i++){
    if(leagues->leagues[i].id == id){
      *league = leagues->leagues[i];
      return 1;
    }
  }
  printf("CAMPEONATO NÃO ENCONTRADO! \n\n");
  cleanBufferNContinue();
  return 0;
}


// APP FUNCIONS
void showLeagues(){
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readLeaguesFile(&leagues);
  if(handleCheckNoLeagues(&leagues)) return;

  printf("|- ID -|- NOME -------------------|- TIMES -|\n");
  for (int i = 0; i < leagues.leagues_amount; i++) {
    League league = leagues.leagues[i];
    printf("| %-4d | %-24s | %-7d |\n", league.id, league.name, league.teams_amount);
  }
  printf("|------|--------------------------|---------|\n\n");

  cleanBufferNContinue();
}

void showTeamsInLeague() {
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readLeaguesFile(&leagues);
  if(handleCheckNoLeagues(&leagues)) return;

  League league;
  int league_id = scanInteger("ID do campeonato: ");
  if(!handleGetLeagueById(league_id, &leagues, &league)) return;

  printTableLine(35);
  printf("| %-31s |\n", league.name);
  printTableLine(35);
  printf("|- ID -|- NOME -------------------|\n");
  for (int i = 0; i < league.teams_amount; i++) {
    Team team = getTeam(league.teams_ids[i]);
    printf("| %-4d | %-24s |\n", team.id, team.name);
  }
  printf("|------|--------------------------|\n\n");

  cleanBufferNContinue();
}

void createLeague() {
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readLeaguesFile(&leagues);

  if(leagues.leagues_amount >= LEAGUES_MAX){
    printf("Número máximo de campeonatos atingido\n");
    cleanBufferNContinue();
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
    for (int j = 0; j < new_league.rounds[i].games_amount; j++) {
      new_league.rounds[i].games[j].id = GAMES_DEFAULT_ID + j;
      new_league.rounds[i].games[j].home_score = -1;
      new_league.rounds[i].games[j].visitor_score = -1;
      if (i % 2 == 0) { 
        new_league.rounds[i].games[j].home_id = teams_ids[j];
        new_league.rounds[i].games[j].visitor_id = teams_ids[new_league.teams_amount - 1 - j];
      } else {
        new_league.rounds[i].games[j].home_id = teams_ids[new_league.teams_amount - 1 - j];
        new_league.rounds[i].games[j].visitor_id = teams_ids[j];
      }
    }
    int temp = teams_ids[new_league.teams_amount - 1];
    for (int k = new_league.teams_amount - 1; k > 1; k--) {
      teams_ids[k] = teams_ids[k - 1]; 
    }
    teams_ids[1] = temp;
  }

  leagues.leagues[leagues.leagues_amount] = new_league;
  leagues.leagues_amount++;

  writeBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));

  printf("\nO campeonato foi cadastrado com sucesso!\n\n");
  cleanBufferNContinue();
}

void deleteLeague() {
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readLeaguesFile(&leagues);
  if(handleCheckNoLeagues(&leagues)) return;

  int league_id = scanInteger("ID do campeonato: ");
  League league;
  if(!handleGetLeagueById(league_id, &leagues, &league)) return;

  for(int i = 0; i < leagues.leagues_amount; i++){
    if(leagues.leagues[i].id == league_id){
      for(int j = i; j < leagues.leagues_amount - 1; j++){
        leagues.leagues[j] = leagues.leagues[j + 1];
      }
      leagues.leagues_amount--;
      writeBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));
      break;
    }
  }

  printf("\nCampeonato deletado com sucesso!\n\n");
  cleanBufferNContinue();
}

void showLeagueGames(){
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readLeaguesFile(&leagues);
  if(handleCheckNoLeagues(&leagues)) return;

  int league_id = scanInteger("ID do campeonato: ");
  League league;
  if(!handleGetLeagueById(league_id, &leagues, &league)) return;

  printTableLine(84);
  printf("| %-80s |\n", league.name);
  printTableLine(84);
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
    printTableLine(84);
  }

  cleanBufferNContinue();
}

void startRound(){
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readLeaguesFile(&leagues);
  if(handleCheckNoLeagues(&leagues)) return;

  int league_id = scanInteger("ID do campeonato: ");
  League league;
  if(!handleGetLeagueById(league_id, &leagues, &league)) return;

  int league_pos = -1;
  for(int i = 0; i < leagues.leagues_amount; i++){
    if(leagues.leagues[i].id == league_id){
      league_pos = i;
      break;
    }
  }
  
  int round_pos = -1;
  for(int i = 0; i < league.rounds_amount; i++){
    if(league.rounds[i].games_amount > 0 && league.rounds[i].games[0].home_score == -1){
      round_pos = i;
      break;
    }
  }
  if(round_pos == -1){
    printf("Todas as rodadas já foram finalizadas\n");
    cleanBufferNContinue();
    return;
  }

  for(int i = 0; i < league.rounds[round_pos].games_amount; i++){
    Game game = league.rounds[round_pos].games[i];
    Team home_team = getTeam(game.home_id);
    Team visitor_team = getTeam(game.visitor_id);
    printf("Placar do jogo %d (%s x %s): ", game.id, home_team.name, visitor_team.name);
    scanf("%d %d", &game.home_score, &game.visitor_score);
    league.rounds[round_pos].games[i] = game;
  }
  leagues.leagues[league_pos] = league;

  writeBinaryFile(LEAGUES_FILENAME, &leagues, sizeof(Leagues));

  printf("\nA rodada foi finalizada com sucesso!\n\n");
  cleanBufferNContinue();
}

void showTable(){
  cleanScreen();
  checkLeaguesFileIsInitialized();
  
  Leagues leagues;
  readLeaguesFile(&leagues);
  if(handleCheckNoLeagues(&leagues)) return;

  int league_id = scanInteger("ID do campeonato: ");
  League league;
  if(!handleGetLeagueById(league_id, &leagues, &league)) return;

  TeamPontuation teams_order[league.teams_amount];

  for(int i = 0; i < league.teams_amount; i++){
    teams_order[i].team_id = league.teams_ids[i];
    teams_order[i].points = 0;
    teams_order[i].goals_pro = 0;
    teams_order[i].goals_against = 0;
    teams_order[i].goals_difference = 0;
    teams_order[i].games_played = 0;
    teams_order[i].wins = 0;
    teams_order[i].draws = 0;
    teams_order[i].losses = 0;
  }

  for(int i = 0; i < league.rounds_amount; i++){
    Round round = league.rounds[i];
    for(int j = 0; j < round.games_amount; j++){
      Game game = round.games[j];
      if(game.home_score == -1) continue;

      int home_pos = -1, visitor_pos = -1;
      for(int k = 0; k < league.teams_amount; k++){
        if(teams_order[k].team_id == game.home_id)  home_pos = k;
        else if(teams_order[k].team_id == game.visitor_id) visitor_pos = k;
        if(home_pos != -1 && visitor_pos != -1) break;
      }

      teams_order[home_pos].goals_pro += game.home_score;
      teams_order[visitor_pos].goals_pro += game.visitor_score;
      teams_order[home_pos].goals_against += game.visitor_score;
      teams_order[visitor_pos].goals_against += game.home_score;
      teams_order[home_pos].goals_difference += game.home_score - game.visitor_score;
      teams_order[visitor_pos].goals_difference += game.visitor_score - game.home_score;
      teams_order[home_pos].games_played += 1;
      teams_order[visitor_pos].games_played += 1;

      if(game.home_score > game.visitor_score){
        teams_order[home_pos].points += 3;
        teams_order[home_pos].wins += 1;
        teams_order[visitor_pos].losses += 1;
      } else if(game.home_score == game.visitor_score){
        teams_order[home_pos].points += 1;
        teams_order[home_pos].draws += 1;
        teams_order[visitor_pos].points += 1;
        teams_order[visitor_pos].draws += 1;
      } else {
        teams_order[visitor_pos].points += 3;
        teams_order[visitor_pos].wins += 1;
        teams_order[home_pos].losses += 1;
      }
    }
  }

  for(int i = 0; i < league.teams_amount; i++){
    for(int j = i + 1; j < league.teams_amount; j++){
      if(teams_order[i].points < teams_order[j].points){
        TeamPontuation temp = teams_order[i];
        teams_order[i] = teams_order[j];
        teams_order[j] = temp;
      }
    }
  }

  printTableLine(91);
  printf("| %-87s |\n", league.name);
  printTableLine(91);
  printf("|- POS -|- ID -|- NOME -------------------|- V -|- E -|- D -|- GP -|- GC -|- SG -|- PNTS -|\n");
  for(int i = 0; i < league.teams_amount; i++){
    Team team = getTeam(teams_order[i].team_id);
    TeamPontuation team_data = teams_order[i];
    printf("|   %-2d  | %-4d | %-24s | %2d  | %2d  | %2d  | %3d  | %3d  | %3d  |   %-2d   |\n", i + 1, team.id, team.name, team_data.wins, team_data.draws, team_data.losses, team_data.goals_pro, team_data.goals_against, team_data.goals_difference, team_data.points);
  }
  printf("|-------|------|--------------------------|-----|-----|-----|------|------|------|--------|\n");

  cleanBufferNContinue();
}