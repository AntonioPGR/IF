#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int main(){

  int n;
  cin >> n;
  cin.ignore();

  while(n--){

    string line;
    getline(cin, line);

    vector<vector<string>> words(51);

    stringstream ss(line);
    string token;
    while (ss >> token) {
      words[token.size()].push_back(token);
    }

    vector<string> answer;
    for(int i = 50; i > 0; i--){
      for(string& word : words[i]){
        answer.push_back(word);
      }
    }

    for(int i = 0; i < answer.size(); i++){
      if(i == answer.size() - 1) cout << answer[i] << endl;
      else cout << answer[i] << " ";
    }

  }
}