#include <iostream>

using namespace std;

int main(){
  string str;
  while(getline(cin, str)){
    char current_letter = 32;
    int count = 0;
    for(int i = 0; i < str.size(); i++){
      if(i == 0){
        current_letter = tolower(str.at(0));
      } else if(str.at(i-1) == 32){
        if(tolower(str.at(i)) == tolower(current_letter)){
          count++;
          current_letter = 32;
        } else {
          current_letter = tolower(str.at(i));
        }
      }
    }
    cout << count << endl;
  }
}
