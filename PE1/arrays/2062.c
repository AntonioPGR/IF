#include <stdio.h>
#include <string.h>

void cleanArray(char* str){
  memset(str, '\0', sizeof(str));
}

int main(){
  
  int n;
  char input[200000];
  cleanArray(input);

  // START
  scanf("%d", &n);

  fgets(input, sizeof(input), stdin);
  if(input[0] == '\n'){
    fgets(input, sizeof(input), stdin);
  }

  for(int j = 0; j < strlen(input); j++){
    if(
      ((input[j] == 'O' && input[j+1] == 'B') || (input[j] == 'U' && input[j+1] == 'R'))
      && 
      (input[j+3] <= 32)
      && 
      (input[j-1] <= 32)
    ){
      input[j+2] = 'I';
    }
  }
  printf("%s\n", input);

  return 0;
}