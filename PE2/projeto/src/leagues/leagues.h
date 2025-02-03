typedef struct League{
  char* id;
  char* name;
  int teams_amount;
  char** teams_ids;
} League;

void createLeague();

// void updateLeague();

void showLeagues();

void showTeamsInLeague();

void deleteLeague();