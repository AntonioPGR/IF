#include <stdio.h> 
#include <string.h>

int main() {

  char str1[50], str2[50], final[100];
  int n;

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%s %s", str1, str2);

    for(int i = 0; i < 10; i++){
      if(i <= strlen(str1)) final[i*2] = str1[i];
      if(i <= strlen(str2)) final[i*2+1] = str2[i];
    }

    if((strlen(final) / 2) < strlen(str1)){
      for(int i = strlen(final); i/2 < strlen(str1); i++){
        final[i] = str1[i];
      }
    } else if((strlen(final) / 2) < strlen(str2)) {

      int get_pos = (strlen(final)/2);
      int add_pos = strlen(final);

      int iterations = strlen(str2) - (strlen(str2) - strlen(final));

      for(add_pos; add_pos/2 < iterations; add_pos++){
        final[add_pos] = str2[get_pos];
        get_pos++;
      }

    }

    printf("%s\n", final);

    for(int i = 0; i < strlen(final); i++){
      final[i] = '\0';
    }
  }

  return 0;
}