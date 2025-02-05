#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rounds.h"
#include "../leagues/leagues.h"
#include "../helpers/string_helper.h"
#include "../helpers/file_helper.h"
#include "../teams/teams.h"

#define FILENAME "src/data/rounds.txt"
#define DEFAULT_ID 3001

void createRounds(League league) {
  LeagueRounds leagueRounds;
  leagueRounds.league_id = league.id;

  char *data = readFile(FILENAME);
  leagueRounds.id = getNextMainId(data, DEFAULT_ID);

  int rounds_amount = league.teams_amount - 1;
  int games_per_round = league.teams_amount / 2;

  leagueRounds.rounds = (Round **) malloc(rounds_amount * sizeof(Round *));
  for (int i = 0; i < rounds_amount; i++) {
    leagueRounds.rounds[i] = (Round *) malloc(games_per_round * sizeof(Round));
  }

  for (int i = 0; i < rounds_amount; i++) {
    for (int j = 0; j < games_per_round; j++) {
      leagueRounds.rounds[i][j].id_home = league.teams_ids[j];
      leagueRounds.rounds[i][j].id_visitor = league.teams_ids[league.teams_amount - j - 1];
      leagueRounds.rounds[i][j].score_home = "X";
      leagueRounds.rounds[i][j].score_visitor = "X";
    }
    char* temp = league.teams_ids[league.teams_amount - 1];
    for (int k = league.teams_amount - 1; k > 1; k--) {
      league.teams_ids[k] = league.teams_ids[k - 1];
    }
    league.teams_ids[1] = temp;
  }

  char* text = (char *) malloc(1000 * sizeof(char));
  snprintf(text, 1000, "%s", data);
  for(int i = 0; i < (league.teams_amount - 1); i++){
    snprintf(text, 1000, "%s%s_%s_", text, leagueRounds.id, leagueRounds.league_id);
    for(int j = 0; j < games_per_round; j++){
      snprintf(text, 1000, "%s%s#%s#%s#%s", text, leagueRounds.rounds[i][j].id_home, leagueRounds.rounds[i][j].score_home, leagueRounds.rounds[i][j].id_visitor, leagueRounds.rounds[i][j].score_visitor);
      if(j < games_per_round - 1) strcat(text, ",");
    }
    strcat(text, ";");

    int temp = atoi(leagueRounds.id);
    temp++;
    leagueRounds.id = integerToString(temp);
  }

  cleanFirstCharacter(text);
  writeInFile(FILENAME, text);
}

void showRounds(){
  cleanScreen();

  char* league_id = getInputLine(5, "Digite o ID do campeonato: ");
  printf("\n");

  char* data = readFile(FILENAME);
  char* token = strtok(data, ";");
  while (token != NULL){
    char league_round_id[5];
    strncpy(league_round_id, token + 5, 4);
    league_round_id[4] = '\0';
    int size = strlen(token);
    if(strcmp(league_round_id, league_id) == 0){
      char* rounds_str = token + 10;
      char* round_str = strtok(rounds_str, ",");
      while(round_str != NULL){
        printf("%s\n", round_str);
        printf("%d", round_str - rounds_str);
        char home_team_id[5], score_home[2], visitor_team_id[5], score_visitor[2];
        sscanf(round_str, "%[^#]#%[^#]#%[^#]#%s", home_team_id, score_home, visitor_team_id, score_visitor);
        printf("| %s - %s x %s - %s |", home_team_id, score_home, score_visitor, visitor_team_id);
        round_str = strtok(NULL, ",");
      }
      printf("\n");
    }
    token = strtok(token + size + 1, ";");
  }
  printf("\n");

  cleanInputBuffer();
  pressEnterToContinue();
}


void startRound(){
}