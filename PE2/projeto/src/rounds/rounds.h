#pragma once
#include "../leagues/leagues.h"

typedef struct{
  char* id_home;
  char* score_home;
  char* id_visitor;
  char* score_visitor;
} Round;

typedef struct{
  char* id;
  char* league_id;
  Round** rounds;
} LeagueRounds;

void createRounds(League league);

void showRounds();

void startRound();