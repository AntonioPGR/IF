#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

int main(){

  string line;
  while(getline(cin, line)){
    stringstream ss(line);
    string token;
    vector<string> words;
    while (ss >> token) {
      bool is_word = true;
      if (
        !token.empty() && 
        token[token.size() - 1] == '.' &&
        token.size() >= 2 &&
        token[token.size() - 2] != '.'
      ) token.pop_back();
      for(char c : token){
        if(!isalpha(c)){
          is_word = false;
          break;
        }
      }
      if(is_word) words.push_back(token);
    }

    int sum = 0;
    for(string s : words){
      sum += s.size();
    }

    int media = (words.size() == 0) ? 0 : sum / words.size();

    if(media <= 3) cout << 250 << endl;
    else if(media <= 5) cout << 500 << endl;
    else cout << 1000 << endl;
  }

  return 0;
}