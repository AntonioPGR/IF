#ifndef LEAGUES_H
#define LEAGUES_H

#include "../teams/teams.h" 

#define LEAGUES_FILENAME "src/data/leagues.dat"
#define LEAGUES_DEFAULT_ID 2000

#define LEAGUE_MAX_TEAMS 20
#define LEAGUE_MIN_TEAMS 2

#define LEAGUES_NAME_LENGHT 25
#define ROUNDS_DEFAULT_ID 3000
#define GAMES_DEFAULT_ID 4000

typedef struct TeamPontuation{
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

typedef struct Score{
  int team_id;
  int score;
} Score;

typedef struct Game{
  int id;
  Score home;
  Score visitor;
} Game;

typedef struct Round{
  int id;
  Game games[LEAGUE_MAX_TEAMS - 1];
} Round;

typedef struct League{
  int id;
  char name[LEAGUES_NAME_LENGHT];
  int teams_amount;
  int teams_ids[LEAGUE_MAX_TEAMS];
  int rounds_amount;
  Round rounds[LEAGUE_MAX_TEAMS - 1];
} League;

int findLeagueById(FILE *file, int league_id, League *foundLeague);
void createLeague();
void showLeagues();
void showTeamsInLeague();
void deleteLeague();
void showLeagueGames();
void startRound();
void showTable();

#endif
