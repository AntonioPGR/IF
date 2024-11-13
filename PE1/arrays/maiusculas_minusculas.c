#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int option;
  char str[100];
  printf("Digite uma string: ");
  fgets(str, sizeof(str), stdin);

  printf("Escolha a conversão (1 para maiúsculas, 2 para minúsculas): ");
  scanf("%d", &option);

  for(int i = 0; i < strlen(str); i++){
    char current = str[i];
    if(current <= 90 && current >= 65 && option == 2) current += 32;
    if(current <= 122 && current >= 97 && option == 1) current -= 32;
    str[i] = current;
  }

  printf("%s", str);

  return 0;
}