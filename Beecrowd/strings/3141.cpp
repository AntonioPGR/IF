#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {

  string name;
  string today_date;
  string birth_date;

  getline(cin, name);
  cin >> today_date;
  cin >> birth_date;

  int today_year = stoi(today_date.substr(6, 10));
  int today_month = stoi(today_date.substr(3, 5));
  int today_day = stoi(today_date.substr(0, 2));

  int birth_year = stoi(birth_date.substr(6, 10));
  int birth_month = stoi(birth_date.substr(3, 5));
  int birth_day = stoi(birth_date.substr(0, 2));

  int age = today_year - birth_year;
  if(today_month < birth_month) age--;
  else if(today_month == birth_month && today_day < birth_day) age--;

  if(birth_day == today_day && birth_month == today_month) cout << "Feliz aniversario!" << endl;
  cout << "Voce tem " << age << " anos." << name << endl;

  return 0;
}
