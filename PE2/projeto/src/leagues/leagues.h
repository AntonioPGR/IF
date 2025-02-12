#ifndef LEAGUES_H
#define LEAGUES_H

#include "../teams/teams.h" 

#define LEAGUES_FILENAME "src/data/leagues.bin"
#define LEAGUES_DEFAULT_ID 2000
#define LEAGUES_MAX 10
#define LEAGUES_MAX_TEAMS 26
#define LEAGUES_NAME_LENGHT 25

#define ROUNDS_DEFAULT_ID 3000
#define ROUNDS_MAX 999

#define GAMES_DEFAULT_ID 4000

typedef struct {
  int team_id;
  int points;
  int goals_pro;
  int goals_against;
  int goals_difference;
  int games_played;
  int wins;
  int draws;
  int losses;
} TeamPontuation;

typedef struct{
  int id;
  int home_id;
  int home_score;
  int visitor_id;
  int visitor_score;
} Game;

typedef struct {
  int id;
  int games_amount;
  Game games[LEAGUES_MAX_TEAMS/2];
} Round;

typedef struct{
  int id;
  char name[LEAGUES_NAME_LENGHT];
  int teams_amount;
  int teams_ids[LEAGUES_MAX_TEAMS];
  int rounds_amount;
  Round rounds[LEAGUES_MAX_TEAMS - 1];
} League;

typedef struct{
  int leagues_amount;
  League leagues[LEAGUES_MAX];
} Leagues;

void createLeague();
void showLeagues();
void showTeamsInLeague();
void deleteLeague();
void showLeagueGames();
void startRound();
void showTable();

#endif
