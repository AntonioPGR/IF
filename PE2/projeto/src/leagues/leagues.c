#include <stdio.h>
#include <stdlib.h>
#include "leagues.h"
#include "string.h"
#include "../teams/teams.h"
#include "../helpers/binary/binary.h"
#include "../helpers/terminal/terminal.h"

// HELPERS
int findLeagueById(FILE *file, int league_id, League *foundLeague) {
  League league;
  while (fread(&league, sizeof(League), 1, file) == 1) {
    if (league.id == league_id) {
      if (foundLeague != NULL)
        *foundLeague = league;
      return 1;
    }
  }
  return 0;
}


// APP FUNCIONS
void showLeagues(){
  cleanScreen();

  FILE* file;
  if(!handleOpenBinaryFile(&file, "ab+", LEAGUES_FILENAME)) return;
  if(handleBinaryFileEmpty(file, sizeof(League), "campeonato")) { fclose(file); return; }

  League league;
  printf("|- ID -|- NOME -------------------|- TIMES -|\n");
  while(fread(&league, sizeof(League), 1, file)){
    printf("| %-4d | %-24s | %-7d |\n", league.id, league.name, league.teams_amount);
  }
  printf("|------|--------------------------|---------|\n\n");

  cleanBufferNContinue();
}

void showTeamsInLeague() {
  cleanScreen();
  
  FILE* file;
  if(!handleOpenBinaryFile(&file, "rb", LEAGUES_FILENAME)) return;
  if(handleBinaryFileEmpty(file, sizeof(League), "campeonato")) { fclose(file); return; }

  int league_id = scanInteger("ID do campeonato: ");
  League league;
  if(!findLeagueById(file, league_id, &league)){
    printf("Campeonato não encontrado\n");
    fclose(file);
    cleanBufferNContinue();
    return;
  }

  printTableLine(35);
  printf("| %-31s |\n", league.name);
  printTableLine(35);
  printf("|- ID -|- NOME -------------------|\n");
  Team team;
  for (int i = 0; i < league.teams_amount; i++) {
    getTeam(league.teams_ids[i], &team);
    printf("| %-4d | %-24s |\n", team.id, team.name);
  }
  printf("|------|--------------------------|\n\n");

  cleanBufferNContinue();
}

void createLeague() {
  cleanScreen();
  
  FILE* file;
  if(!handleOpenBinaryFile(&file, "ab+", LEAGUES_FILENAME)) return;

  League new_league;
  getInputLine("Nome do campeonato: ", 25, new_league.name);
  
  new_league.teams_amount = 0;
  while(
    new_league.teams_amount < LEAGUE_MIN_TEAMS || 
    new_league.teams_amount > LEAGUE_MAX_TEAMS || 
    new_league.teams_amount % 2 != 0
  ) {
    printf("Quantidade de times (N° PAR >= %d  e <= %d): ", LEAGUE_MIN_TEAMS, LEAGUE_MAX_TEAMS);
    scanf("%d", &new_league.teams_amount);
  }
  new_league.rounds_amount = new_league.teams_amount - 1;

  for (int i = 0; i < new_league.teams_amount; i++) {
    printf("ID do time %d: ", i + 1);
    int id;
    scanf("%d", &id);
    if(!doesTeamExists(id)){
      printf("Time não encontrado\n");
      i--;
      continue;
    }
    new_league.teams_ids[i] = id;
  }

  new_league.id = LEAGUES_DEFAULT_ID;
  if (getAmountInBinaryFile(file, sizeof(League)) > 0) {
    League last_league;
    fseek(file, -sizeof(League), SEEK_END);
    fread(&last_league, sizeof(League), 1, file);
    new_league.id = last_league.id + 1;
    rewind(file);
  }

  int teams_ids[new_league.teams_amount];
  for (int i = 0; i < new_league.teams_amount; i++) {
    teams_ids[i] = new_league.teams_ids[i];
  }
  
  for (int i = 0; i < new_league.teams_amount - 1; i++) {
    Round new_round;
    new_round.id = ROUNDS_DEFAULT_ID + i;
    
    for (int j = 0; j < new_league.teams_amount / 2; j++) {
      new_round.games[j].id = GAMES_DEFAULT_ID + j;
      new_round.games[j].home.team_id = teams_ids[j];
      new_round.games[j].visitor.team_id = teams_ids[new_league.teams_amount - 1 - j];
      new_round.games[j].home.score = -1;
      new_round.games[j].visitor.score = -1;
    }
    
    int temp = teams_ids[new_league.teams_amount - 1];
    for (int k = new_league.teams_amount - 1; k > 1; k--) {
      teams_ids[k] = teams_ids[k - 1];
    }
    teams_ids[1] = temp;
    new_league.rounds[i] = new_round;
  }

  fwrite(&new_league, sizeof(League), 1, file);
  fclose(file);
  printf("\nO campeonato foi cadastrado com sucesso!\n\n");
  cleanBufferNContinue();
}

void deleteLeague() {
  cleanScreen();

  FILE* file;
  if(!handleOpenBinaryFile(&file, "rb", LEAGUES_FILENAME)) return;
  if(handleBinaryFileEmpty(file, sizeof(League), "campeonato")) { fclose(file); return; }

  League league;
  int league_id = scanInteger("ID do campeonato: ");
  if(!findLeagueById(file, league_id, &league)){
    printf("Campeonato não encontrado\n");
    fclose(file);
    cleanBufferNContinue();
    return;
  }

  int size = getAmountInBinaryFile(file, sizeof(League));
  League* leagues = malloc(size * sizeof(League));
  if(leagues == NULL){
    printf("Erro ao alocar memória\n");
    fclose(file);
    cleanBufferNContinue();
    return;
  }
  fread(leagues, sizeof(League), size, file);

  for(int i = 0; i < size; i++){
    if(leagues[i].id != league_id) continue;
    for(int j = i; j < size - 1; j++){
      leagues[j] = leagues[j + 1];
    }
    size--;
    break;
  }

  freopen(LEAGUES_FILENAME, "wb", file);
  fwrite(leagues, sizeof(League), size, file);
  printf("\nCampeonato deletado com sucesso!\n\n");
  fclose(file);
  free(leagues);
  cleanBufferNContinue();
}

void showLeagueGames() {
  cleanScreen();
  
  FILE* file;
  if(!handleOpenBinaryFile(&file, "rb", LEAGUES_FILENAME)) return;
  if(handleBinaryFileEmpty(file, sizeof(League), "campeonato")) { fclose(file); return; }

  League league;
  int league_id = scanInteger("ID do campeonato: ");
  if(!findLeagueById(file, league_id, &league)){
    printf("Campeonato não encontrado\n");
    fclose(file);
    cleanBufferNContinue();
    return;
  }

  printTableLine(86);
  printf("| %-82s |\n", league.name);
  printTableLine(86);
  printf("|- RODADA -|- JOGO -|- CASA -------------------|- VISITANTE --------------|- PLACAR -|\n");
  for(int i = 0; i < league.rounds_amount; i++){
    Round round = league.rounds[i];
    for(int j = 0; j < league.teams_amount / 2; j++){
      Game game = round.games[j];
      Team home, visitor;
      getTeam(game.home.team_id, &home);
      getTeam(game.visitor.team_id, &visitor);
      printf("|   %d   |  %d  | %-24s | %-24s |", round.id, game.id, home.name, visitor.name);
      if(game.home.score == -1) printf(" XX vs XX |\n");
      else printf(" %2d vs %2d |\n", game.home.score, game.visitor.score);
    }
    printTableLine(86);
  }

  fclose(file);
  cleanBufferNContinue();
}

void startRound() {
  cleanScreen();
  
  FILE* file;
  if(!handleOpenBinaryFile(&file, "rb", LEAGUES_FILENAME)) return;
  if(handleBinaryFileEmpty(file, sizeof(League), "campeonato")) { fclose(file); return; }

  League league;
  int league_id = scanInteger("ID do campeonato: ");
  if(!findLeagueById(file, league_id, &league)){
    printf("Campeonato não encontrado\n");
    fclose(file);
    cleanBufferNContinue();
    return;
  }

  int started = 0;
  for(int i = 0; i < league.rounds_amount; i++){
    if(league.rounds[i].games[0].home.score != -1) continue;
    for(int j = 0; j < league.teams_amount / 2; j++){
      Game game = league.rounds[i].games[j];
      Team home, visitor;
      getTeam(game.home.team_id, &home);
      getTeam(game.visitor.team_id, &visitor);
      while(game.home.score < 0 || game.visitor.score < 0){
        printf("Placar do jogo %s x %s ( X X )( Valores positivos ): ", home.name, visitor.name);
        scanf("%d %d", &game.home.score, &game.visitor.score);
      }
      league.rounds[i].games[j] = game;
    }
    started = 1;
    break;
  }

  if(!started){
    printf("Todos os jogos da rodada já foram iniciados\n");
  } else {
    freopen(LEAGUES_FILENAME, "wb", file);
    fwrite(&league, sizeof(League), 1, file);
    printf("\nRodada cadastrada com sucesso!\n\n");
  }
  fclose(file);
  cleanBufferNContinue();
}


void showTable() {
  cleanScreen();
  
  FILE* file;
  if(!handleOpenBinaryFile(&file, "rb", LEAGUES_FILENAME)) return;
  if(handleBinaryFileEmpty(file, sizeof(League), "campeonato")) { fclose(file); return; }

  League league;
  int league_id = scanInteger("ID do campeonato: ");
  if(!findLeagueById(file, league_id, &league)){
    printf("Campeonato não encontrado\n");
    fclose(file);
    cleanBufferNContinue();
    return;
  }


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

  if(league.rounds[0].games[0].home.score == -1){
    for (int i = 0; i < league.teams_amount - 1; i++) {
      for (int j = i + 1; j < league.teams_amount; j++) {
        Team team_i, team_j;
        getTeam(teams_order[i].team_id, &team_i);
        getTeam(teams_order[j].team_id, &team_j);
        if (strcmp(team_i.name, team_j.name) > 0) {
          TeamPontuation temp = teams_order[i];
          teams_order[i] = teams_order[j];
          teams_order[j] = temp;
        }
      }
    }
  } else {
    for(int i = 0; i < league.rounds_amount; i++){
      Round round = league.rounds[i];
      for(int j = 0; j < league.teams_amount/2; j++){
        Game game = round.games[j];
        if(game.home.score == -1) continue;

        int home_pos = -1, visitor_pos = -1;
        for(int k = 0; k < league.teams_amount; k++){
          if(teams_order[k].team_id == game.home.team_id)  home_pos = k;
          else if(teams_order[k].team_id == game.visitor.team_id) visitor_pos = k;
          if(home_pos != -1 && visitor_pos != -1) break;
        }

        teams_order[home_pos].goals_pro += game.home.score;
        teams_order[visitor_pos].goals_pro += game.visitor.score;
        teams_order[home_pos].goals_against += game.visitor.score;
        teams_order[visitor_pos].goals_against += game.home.score;
        teams_order[home_pos].goals_difference += game.home.score - game.visitor.score;
        teams_order[visitor_pos].goals_difference += game.visitor.score - game.home.score;
        teams_order[home_pos].games_played += 1;
        teams_order[visitor_pos].games_played += 1;

        if(game.home.score > game.visitor.score){
          teams_order[home_pos].points += 3;
          teams_order[home_pos].wins += 1;
          teams_order[visitor_pos].losses += 1;
        } else if(game.home.score == game.visitor.score){
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
        if(teams_order[i].points == teams_order[j].points){
          if(teams_order[i].goals_difference < teams_order[j].goals_difference){
            TeamPontuation temp = teams_order[i];
            teams_order[i] = teams_order[j];
            teams_order[j] = temp;
          }
        }
      }
    }
  }

  printTableLine(91);
  printf("| %-87s |\n", league.name);
  printTableLine(91);
  printf("|- POS -|- ID -|- NOME -------------------|- V -|- E -|- D -|- GP -|- GC -|- SG -|- PNTS -|\n");
  for(int i = 0; i < league.teams_amount; i++){
    Team team;
    getTeam(teams_order[i].team_id, &team);
    TeamPontuation team_data = teams_order[i];
    printf("|   %-2d  | %-4d | %-24s | %2d  | %2d  | %2d  | %3d  | %3d  | %3d  |   %-2d   |\n", i + 1, team.id, team.name, team_data.wins, team_data.draws, team_data.losses, team_data.goals_pro, team_data.goals_against, team_data.goals_difference, team_data.points);
  }
  printf("|-------|------|--------------------------|-----|-----|-----|------|------|------|--------|\n");

  cleanBufferNContinue();
}

// deletar time cadastrado em campeonato