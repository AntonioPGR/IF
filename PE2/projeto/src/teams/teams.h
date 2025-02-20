#ifndef TEAMS_H
#define TEAMS_H

#define TEAMS_FILENAME "src/data/teams.bin"
#define TEAMS_DEFAULT_ID 1000
#define TEAMS_NAME_LENGHT 25

typedef struct{
  int id;
  char name[TEAMS_NAME_LENGHT];
} Team;

void createTeam();
void listTeams();
void deleteTeam();
void updateTeam();

int doesTeamExists(int team_id);
Team getTeam(int team_id);

#endif