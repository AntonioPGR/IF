#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../helpers/file_helper.h"

#define FILENAME "src/teams/teams.txt"

void registerTeam(){

  char name[50];
  printf("Nome do time: ");
  
  int c;
  while((c = getchar()) != '\n' && c != EOF);

  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = '\0';

  FILE *file = readFile(FILENAME);

  char teams[1000];
  char buffer[100];
  fgets(teams, sizeof(teams), file);
  fclose(file);

  int last_id = strrchr(teams, '_') - teams;
  int new_id = 1001;
  if(last_id > 0){
    char last_id_char[10];
    strncpy(last_id_char, teams + last_id - 4, 4);
    last_id_char[4] = '\0';
    int a = atoi(last_id_char);
    new_id = a+1;
  }

  char new_id_str[20];
  sprintf(new_id_str, "%d", new_id);
  
  strcat(teams, new_id_str);
  strcat(teams, "_");
  strcat(teams, name);
  strcat(teams, ";");

  if(teams[0] == 2) memmove(teams, teams + 1, strlen(teams));;

  file = fopen(FILENAME, "w");
  if (file == NULL) {
    perror("Failed to create file");
    return;
  }
  fprintf(file, "%s", teams);
  fclose(file);
}