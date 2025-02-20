#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teams.h"
#include "../helpers/terminal/terminal.h"
#include "../helpers/binary/binary.h"

// SUPORT
void getTeamName(char* label, char* input){
  cleanInputBuffer();
  printf("%s", label);
  fgets(input, TEAMS_NAME_LENGHT, stdin);
  if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
}

int doesFileOpen(FILE **file, const char* operation ) {
  *file = fopen(TEAMS_FILENAME, operation);
  if (*file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    pressEnterToContinue();
    return 0;
  }
  return 1;
}

int isFileEmpty(FILE *file) {
  int amount = getAmountInBinaryFile(file, sizeof(Team));
  if (amount == 0) {
    printf("Nenhum time cadastrado!\n\n");
    cleanBufferNContinue();
    return 1;
  }
  return 0;
}


// APP FUNCTIONS
void listTeams() {
  cleanScreen();

  FILE *file;
  if (!doesFileOpen(&file, "rb")) return;
  if (isFileEmpty(file)) { fclose(file); return; }

  Team team;
  printf("|---------------------------------|\n");
  printf("| %-32s|\n", "TIMES CADASTRADOS");
  printf("|---------------------------------|\n");
  printf("|- ID -|- NOME -------------------|\n");
  while (fread(&team, sizeof(Team), 1, file) == 1) {
    printf("| %d | %-24s |\n", team.id, team.name);
  }
  printf("|------|--------------------------|\n\n");

  fclose(file);
  cleanBufferNContinue();
}


void createTeam() {
  cleanScreen();

  FILE *file;
  if(!doesFileOpen(&file, "ab+")) return;

  Team new_team;
  getTeamName("Nome do time: ", new_team.name);

  int size = getAmountInBinaryFile(file, sizeof(Team));
  new_team.id = TEAMS_DEFAULT_ID;
  if (size > 0) {
    Team last_team;
    fseek(file, -sizeof(Team), SEEK_END); 
    fread(&last_team, sizeof(Team), 1, file); 
    new_team.id = last_team.id + 1;
    rewind(file);
} 

  fwrite(&new_team, sizeof(Team), 1, file);

  fclose(file);
  printf("\nTime salvo com sucesso!\n\n");
  pressEnterToContinue();
}


void updateTeam(){
  cleanScreen();

  FILE *file;
  if (!doesFileOpen(&file, "rb+")) return;
  if (isFileEmpty(file)) { fclose(file); return; }

  int id = scanInteger("Id do time: ");

  Team team;
  int updated = 0;
  while(fread(&team, sizeof(Team), 1, file) == 1 && updated == 0){
    if(team.id != id) continue;

    getTeamName("Nome do time: ", team.name);
    fseek(file, -sizeof(Team), SEEK_CUR);
    fwrite(&team, sizeof(Team), 1, file);
    fflush(file);
    updated = 1;
  }
  fclose(file);

  if(updated) printf("\nO time foi atualizado com sucesso!\n\n");
  else printf("\nTime não encontrado!\n\n");

  pressEnterToContinue();
}


void deleteTeam(){
  cleanScreen();

  FILE *file;
  if (!doesFileOpen(&file, "rb+")) return;
  if (isFileEmpty(file)) { fclose(file); return; }

  int size = getAmountInBinaryFile(file, sizeof(Team));
  Team *teams = (Team *) malloc(size * sizeof(Team));
  if (teams == NULL) {
    printf("Erro ao alocar memória.\n");
    fclose(file);
    return;
  }
  fread(teams, sizeof(Team), size, file);

  int id = scanInteger("Id do time: ");
  int found = 0;
  for (int i = 0; i < size; i++) {
    if(teams[i].id != id) continue;
    found = 1;
    for (int j = i; j < size - 1; j++) {
      teams[j] = teams[j + 1];
    }
    size--;
    break;
  }

  if (!found) printf("\nTime com ID %d não encontrado.\n\n", id);
  else {
    freopen(TEAMS_FILENAME, "wb", file); // fecha o arquivo, reabre para escrita evitando ambniguidade
    fwrite(teams, sizeof(Team), size, file);
    printf("\nTime removido com sucesso!\n\n");
  }

  free(teams);
  fclose(file);
  cleanBufferNContinue();
}


int doesTeamExists(int team_id){
  FILE *file;
  if(!doesFileOpen(&file, "rb")) return 0;
  Team team;
  while(fread(&team, sizeof(Team), 1, file) == 1){
    if(team.id == team_id){
      fclose(file);
      return 1;
    }
  }
  fclose(file);
  return 0;
}


Team getTeam(int team_id){
  FILE *file;
  Team team;
  if(!doesFileOpen(&file, "rb")){
    while(fread(&team, sizeof(Team), 1, file) == 1){
      if(team.id == team_id){
        fclose(file);
        return team;
      }
    }
  }
}
