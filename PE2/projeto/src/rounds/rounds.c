#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rounds.h"
#include "../leagues/leagues.h"
#include "../helpers/string.h"
#include "../helpers/text.h"
#include "../teams/teams.h"

// void checkFileIsInitialized() {
//   // if (!doesFileExists(FILENAME)) {
//   //   Teams teams;
//   //   teams.teams_amount = 0;
//   //   writeBinaryFile(FILENAME, &teams, sizeof(Teams));
//   // }
// }

void createRounds(League league) {
  // LeagueRounds leagueRounds;
  // leagueRounds.league_id = league.id;
  // char *data = readFile(FILENAME);
  // leagueRounds.id = getNextMainId(data, DEFAULT_ID);
  // int rounds_amount = league.teams_amount - 1;
  // int games_per_round = league.teams_amount / 2;
  // leagueRounds.rounds = (Round **) malloc(rounds_amount * sizeof(Round *));
  // for (int i = 0; i < rounds_amount; i++) {
  //   leagueRounds.rounds[i] = (Round *) malloc(games_per_round * sizeof(Round));
  // }
  
  // for (int i = 0; i < rounds_amount; i++) {
  //   for (int j = 0; j < games_per_round; j++) {
  //     leagueRounds.rounds[i][j].id_home = league.teams_ids[j];
  //     leagueRounds.rounds[i][j].id_visitor = league.teams_ids[league.teams_amount - j - 1];
  //     leagueRounds.rounds[i][j].score_home = "X";
  //     leagueRounds.rounds[i][j].score_visitor = "X";
  //   }
  //   char* temp = league.teams_ids[league.teams_amount - 1];
  //   for (int k = league.teams_amount - 1; k > 1; k--) {
  //     league.teams_ids[k] = league.teams_ids[k - 1];
  //   }
  //   league.teams_ids[1] = temp;
  // }

  // char* text = (char *) malloc(1000 * sizeof(char));
  // snprintf(text, 1000, "%s", data);
  // for(int i = 0; i < (league.teams_amount - 1); i++){
  //   snprintf(text, 1000, "%s%s_%s_", text, leagueRounds.id, leagueRounds.league_id);
  //   for(int j = 0; j < games_per_round; j++){
  //     snprintf(text, 1000, "%s%s#%s#%s#%s", text, leagueRounds.rounds[i][j].id_home, leagueRounds.rounds[i][j].score_home, leagueRounds.rounds[i][j].id_visitor, leagueRounds.rounds[i][j].score_visitor);
  //     if(j < games_per_round - 1) strcat(text, ",");
  //   }
  //   strcat(text, ";");
  //   int temp = atoi(leagueRounds.id);
  //   temp++;
  //   leagueRounds.id = integerToString(temp);
  // }
  // cleanFirstCharacter(text);
  // writeInFile(FILENAME, text);
}

void showRounds(){
  // cleanScreen();
  // char* league_id = getInputLine(5, "Digite o ID do campeonato: ");
  // printf("\n");
  // char* data = readFile(FILENAME);
  // if (data == NULL || strlen(data) == 0) return;
  // char* data_copy = strdup(data);
  // char* token = strtok(data_copy, ";");
  // int round_count = 0;
  // while (token != NULL){
  //   char league_round_id[5];
  //   strncpy(league_round_id, token + 5, 4);
  //   league_round_id[4] = '\0';

  //   if(strcmp(league_round_id, league_id) == 0){
  //     char* rounds_str = strdup(token + 10);
  //     char* round_str = strtok(rounds_str, ",");

  //     printf("| %dª Rodada |", ++round_count);
  //     while(round_str != NULL){
  //       char home_team_id[5], score_home[2], visitor_team_id[5], score_visitor[2];
  //       sscanf(round_str, "%[^#]#%[^#]#%[^#]#%s", home_team_id, score_home, visitor_team_id, score_visitor);
  //       char* home_name = getTeamName(home_team_id);
  //       char* visitor_name = getTeamName(visitor_team_id);
  //       if (home_name && visitor_name) printf("| %s - %s x %s - %s |", home_name, score_home, score_visitor, visitor_name);
  //       round_str = strtok(round_str + strlen(round_str) + 1, ",");
  //     }
  //     printf("\n");
  //     free(rounds_str);
  //   }
  //   token = strtok(token + strlen(token) + 1, ";");
  // }
  // free(data_copy);
  // printf("\n");
  // cleanInputBuffer();
  // pressEnterToContinue();
}

void startRound(){
  // cleanScreen();
}