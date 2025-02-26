#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teams.h"
#include "../helpers/terminal/terminal.h"
#include "../helpers/binary/binary.h"

// APP FUNCTIONS
void listTeams() {
  cleanScreen();

  FILE *file;
  if (!handleOpenBinaryFile(&file, "rb", TEAMS_FILENAME)) return;
  if (handleBinaryFileEmpty(file, sizeof(Team), "time")) { fclose(file); return; }

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
  if(!handleOpenBinaryFile(&file, "ab+", TEAMS_FILENAME)) return;

  Team new_team;
  getInputLine("Nome do time: ", 25, new_team.name);

  int size = getAmountInBinaryFile(file, sizeof(Team));
  new_team.id = TEAMS_DEFAULT_ID;
  // Pega o ultimo ID e incrementa
  if (size > 0) {
    Team last_team;
    fseek(file, -sizeof(Team), SEEK_END); 
    fread(&last_team, sizeof(Team), 1, file); 
    new_team.id = last_team.id + 1;
    rewind(file);
  } 

  fwrite(&new_team, sizeof(Team), 1, file);

  fclose(file);
  printf("\nTime cadastrado com sucesso!\n\n");
  pressEnterToContinue();
}


void updateTeam(){
  cleanScreen();

  FILE *file;
  if (!handleOpenBinaryFile(&file, "rb+", TEAMS_FILENAME)) return;
  if (handleBinaryFileEmpty(file, sizeof(Team), "time")) { fclose(file); return; }

  int id = scanInteger("Id do time: ");

  // Caminha no vetor para trocar o time
  Team team;
  int updated = 0;
  while(fread(&team, sizeof(Team), 1, file) == 1 && updated == 0){
    if(team.id != id) continue;

    getInputLine("Nome do time: ", 25, team.name);
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
  if (!handleOpenBinaryFile(&file, "rb+", TEAMS_FILENAME)) return;
  if (handleBinaryFileEmpty(file, sizeof(Team), "time")) { fclose(file); return; }

  int size = getAmountInBinaryFile(file, sizeof(Team));
  Team *teams = (Team *) malloc(size * sizeof(Team));
  if (teams == NULL) {
    printf("Erro ao alocar memória.\n");
    fclose(file);
    pressEnterToContinue();
    return;
  }
  fread(teams, sizeof(Team), size, file);

  int id = scanInteger("Id do time: ");
  // Se o id for o do time deletado, retira ele do vetor
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


// Verifica se o tiie existe e retorna verdadeiro ou falso
int doesTeamExists(int team_id){
  FILE *file;
  if(!handleOpenBinaryFile(&file, "rb", TEAMS_FILENAME)) return 0;
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


// Retorna o time por meio do ponteiro
void getTeam(int team_id, Team* team){
  FILE *file;
  Team search_team;
  if(handleOpenBinaryFile(&file, "rb", TEAMS_FILENAME)){
    while(fread(&search_team, sizeof(Team), 1, file) == 1){
      if(search_team.id == team_id){
        *team = search_team;
        fclose(file);
        return;
      }
    }
    fclose(file);
  }
}
