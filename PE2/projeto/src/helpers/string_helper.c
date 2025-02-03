#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void cleanScreen(){
  printf("\e[1;1H\e[2J");
}

void cleanInputBuffer(){
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}

char* getInputLine(int max_size, char* label){
  char* line = (char *) malloc(max_size*sizeof(char));
  printf("%s", label);
  cleanInputBuffer();
  fgets(line, max_size, stdin);
  line[strcspn(line, "\n")] = '\0';
  return line;
}

char* concatStringArray(char** elements) {
  size_t total_length = 0;
  for (int i = 0; elements[i] != NULL; i++) {
    total_length += strlen(elements[i]);
  }

  char* result = (char*) malloc(total_length + 1);
  if (result == NULL) {
    perror("Failed to allocate memory");
    return NULL;
  }

  result[0] = '\0';
  for (int i = 0; elements[i] != NULL; i++) {
    strcat(result, elements[i]);
  }

  return result;
}

char* integerToString(int number){
  int n_of_digits = floor(log10(abs(number))) + 1;
  char *str = (char *) malloc(n_of_digits*sizeof(char)+1);
  sprintf(str, "%d", number);
  return str;
}

char* findLastOccurrenceOf(char *str, char c){
  return strrchr(str, c);
}

int findLastIndexOf(char *str, char c){
  return findLastOccurrenceOf(str, c) - str;
}

char* findFirstOccurrenceOf(char *str, char c){
  return strchr(str, c);
}

int findFirstIndexOf(char *str, char c){
  return findFirstOccurrenceOf(str, c) - str;
}

char* findSubstring(char *str, char *sub){
  char *pos = strstr(str, sub);
  if(pos == NULL){
    return NULL;
  }
  return pos;
}

int findSubstringIndex(char *str, char *sub){
  char *pos = findSubstring(str, sub);
  if(pos == NULL){
    return -1;
  }
  return pos - str;
}

void cleanFirstCharacter(char *str){
  if(str[0] == 2) memmove(str, str + 1, strlen(str));
  if(str[0] == -64) memmove(str, str + 1, strlen(str));
}

void pressAnyKeyToContinue(){
  printf("Pressione qualquer tecla para continuar...");
  getchar();
}