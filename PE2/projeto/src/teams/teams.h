typedef struct Team{
  int id;
  char name[25];
} Team;

typedef struct Teams{
  int teams_amount;
  Team teams[30];
} Teams;

void createTeam();

void listTeams();

void deleteTeam();

void updateTeam();

char* getTeamName(char* team_id);

void readBinaryFile(const char *filename, void *buffer, size_t size);