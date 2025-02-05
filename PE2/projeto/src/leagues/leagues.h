#pragma once

typedef struct{
  char* id;
  char* name;
  int teams_amount;
  char** teams_ids;
} League;

void createLeague();

void showLeagues();

void showTeamsInLeague();

void deleteLeague();