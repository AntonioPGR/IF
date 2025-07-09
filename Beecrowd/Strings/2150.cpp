#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string vowels_string, quote;

  while (getline(cin, vowels_string) && getline(cin, quote)) {
    map<char, int> vowels;
    for (char v : vowels_string) vowels[tolower(v)] = 0;

    for (char l : quote) {
      if (vowels.find(tolower(l)) != vowels.end()) vowels[tolower(l)]++;
    }

    int count = 0;
    for (const auto& pair : vowels) {
      count += pair.second;
    }

    cout << count << endl;
  }

  return 0;
}
