#include <stdio.h>
#include <string.h>

void registerTeam(){

  char name[50];
  printf("Nome do time: ");
  
  int c;
  while ((c = getchar()) != '\n' && c != EOF); 
  fgets(name, sizeof(name), stdin);

  FILE *file;
  file = fopen("teams/teams.txt", "r");
  if(file == NULL){
    file = fopen("teams/teams.txt", "w");
  }

  char times[100];
  fgets(times, 100, file);

  file = fopen("teams/teams.txt", "w");
  fprintf(file, strcat(times, name));
  fclose(file);

}