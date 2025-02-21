#ifndef LEAGUES_H
#define LEAGUES_H

#include "../teams/teams.h" 

#define LEAGUES_FILENAME "src/data/leagues.bin"
#define LEAGUES_DEFAULT_ID 2000
#define LEAGUES_NAME_LENGHT 25
#define ROUNDS_DEFAULT_ID 3000
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
  int team_id;
  int score;
} Score;

typedef struct{
  int id;
  Score home;
  Score visitor;
} Game;

typedef struct {
  int id;
  int lague_id;
  Game games[];
} Round;

typedef struct{
  int id;
  char name[LEAGUES_NAME_LENGHT];
  Team teams[];
} League;

void createLeague();
void showLeagues();
void showTeamsInLeague();
void deleteLeague();
void showLeagueGames();
void startRound();
void showTable();

#endif
