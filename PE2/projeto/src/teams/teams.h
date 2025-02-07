#ifndef TEAMS_H
#define TEAMS_H

#define TEAMS_FILENAME "src/data/teams.bin"
#define TEAMS_DEFAULT_ID 1000
#define TEAMS_MAX 80
#define TEAMS_NAME_LENGHT 25

typedef struct{
  int id;
  char name[TEAMS_NAME_LENGHT];
} Team;

typedef struct{
  int teams_amount;
  Team teams[TEAMS_MAX];
} Teams;

void createTeam();
void listTeams();
void deleteTeam();
void updateTeam();
char* getTeamName(int team_id);

#endif