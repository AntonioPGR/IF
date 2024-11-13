#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

  int n, sum;
  char str[50], number[50];
  scanf("%d\n", &n);

  for(int i = 0; i < n; i++){
    sum = 0;
    fgets(str, sizeof(str), stdin);
    
    for(int j = 0; j < strlen(str); j++){
      if(isdigit(str[j])){
        number[strlen(number)] = str[j];
        number[strlen(number)] = '\0';
      } else {
        if(number[0] != '\0'){
          sum += atoi(number);
          memset(number, 0, strlen(number));
        }
      }
    }

    printf("%d\n", sum);
  }

  return 0;
}