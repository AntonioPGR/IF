#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){

  int n, l, c;
  while(cin >> n >> l >> c){

    int number_of_lines = 1;
    int current_line_len = 0;

    string s;
    for(int i = 0; i < n; i++){
      cin >> s;
      int word_len = s.length();

      if(current_line_len == 0){
        current_line_len += word_len;
        continue;
      }

      if(current_line_len + 1 + word_len <= c){
        current_line_len += 1 + word_len;
        continue;
      }

      number_of_lines++;
      current_line_len = word_len;

    }

    int pages = ceil((double)number_of_lines / l);
    cout << pages << endl;

  }

  return 0;
}