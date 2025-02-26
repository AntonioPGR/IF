#include <stdio.h>
#include <stdlib.h>
#include "../leagues/leagues.h"
#include "../teams/teams.h"
#include "../helpers/binary/binary.h"
#include "../helpers/terminal/terminal.h"
#include "string.h"

void generateLeagueReport() {
  cleanScreen();

  FILE *file;
  if (!handleOpenBinaryFile(&file, "rb", LEAGUES_FILENAME)) return;
  if (handleBinaryFileEmpty(file, sizeof(League), "campeonato")) { fclose(file); return; }

  int league_id = scanInteger("ID do campeonato: ");
  League league;
  if (!findLeagueById(file, league_id, &league)) {
    printf("Campeonato não encontrado\n");
    fclose(file);
    cleanBufferNContinue();
    return;
  }

  fclose(file);

  // Abre o arquivo TXT para escrita
  char filename[50];
  snprintf(filename, sizeof(filename), "src/data/%d.txt", league.id);

  FILE *report = fopen(filename, "w");
  if (!report) {
    printf("Erro ao criar o relatório.\n");
    cleanBufferNContinue();
    return;
  }

  // HEADER
  fprintf(report, "----------------------------------------------\n");
  fprintf(report, "%s\n", league.name);
  fprintf(report, "----------------------------------------------\n\n");
  
  // TIMES PARTICIPANTES
  fprintf(report, "Times Participantes:\n");
  for (int i = 0; i < league.teams_amount; i++) {
    Team team;
    getTeam(league.teams_ids[i], &team);
    fprintf(report, "- %s\n", team.name);
  }
  fprintf(report, "\n");

  // TABELA DE PONTUACAO
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

  fprintf(report, "Tabela:\n");
  fprintf(report, "|- POS -|- ID -|- NOME -------------------|- V -|- E -|- D -|- GP -|- GC -|- SG -|- PNTS -|\n");
  for(int i = 0; i < league.teams_amount; i++){
    Team team;
    getTeam(teams_order[i].team_id, &team);
    TeamPontuation team_data = teams_order[i];
    fprintf(report, "|   %-2d  | %-4d | %-24s | %2d  | %2d  | %2d  | %3d  | %3d  | %3d  |   %-2d   |\n", i + 1, team.id, team.name, team_data.wins, team_data.draws, team_data.losses, team_data.goals_pro, team_data.goals_against, team_data.goals_difference, team_data.points);
  }
  fprintf(report, "|-------|------|--------------------------|-----|-----|-----|------|------|------|--------|\n\n");

  // MOSTRA RODADAS
  fprintf(report, "Rodadas:\n");
  for (int i = 0; i < league.rounds_amount; i++) {
    fprintf(report, "  Rodada %d:\n", i + 1);
    Round round = league.rounds[i];

    for (int j = 0; j < league.teams_amount / 2; j++) {
      Game game = round.games[j];
      Team home, visitor;
      getTeam(game.home.team_id, &home);
      getTeam(game.visitor.team_id, &visitor);

      fprintf(report, "    %s %d x %d %s\n", home.name, game.home.score, game.visitor.score, visitor.name);
    }
    fprintf(report, "\n");
  }

  fclose(report);
  printf("Relatório gerado com sucesso: %s\n", filename);
  cleanBufferNContinue();
}
