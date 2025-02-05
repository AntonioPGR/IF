#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rounds.h"
#include "../leagues/leagues.h"
#include "../helpers/string_helper.h"
#include "../helpers/file_helper.h"

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
}


void startRound(){
}