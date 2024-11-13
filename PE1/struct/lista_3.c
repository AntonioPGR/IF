#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student{
  char name[20];
  int id;
  int grades[5];
  float media;
} student;

int main(){
  int n;
  char tmp;
  printf("Insira o numero de alunos (1 a 5): ");
  scanf("%d", &n);
  scanf("%c", &tmp); // remove o \n
  printf("\n");

  printf("--- INSERCAO DE ESTUDANTES ---\n");
  student students[n];
  for(int i = 0; i < n; i++){
    printf("Aluno %d: \n", i);
    students[i].media = 0;

    printf("Nome: ");
    fgets(students[i].name, sizeof students[i].name, stdin);
    students[i].name[strlen(students[i].name)-1] = '\0';

    printf("Matricula: ");
    scanf("%d", &students[i].id);
    scanf("%c", &tmp);

    printf("Notas: ");
    for(int j = 0; j < 5; j++){
      scanf("%d", &students[i].grades[j]);
      students[i].media += students[i].grades[j];
    }
    students[i].media /= 5;

    scanf("%c", &tmp);
  }

  printf("\n--- RESULTADO ---\nNOME | ID | MEDIA | SITUACAO\n");
  for(int i = 0; i < n; i++){
    student current = students[i];
    printf("%s | %d | %.2f |", current.name, current.id, current.media);
    if(current.media >= 7) printf("APROVADO");
    else printf("REPROVADO");
    printf("\n");
  }

  return 0;
}