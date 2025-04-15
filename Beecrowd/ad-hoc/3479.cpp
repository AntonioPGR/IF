#include <iostream>
#include <string>

using namespace std;

int main(){

  string date;
  cin >> date;

  int day = (date[0] - '0') * 10 + (date[1] - '0');
  int month = (date[3] - '0') * 10 + (date[4] - '0');

  switch (month){
    case 1:
      if(day <= 19) cout << "capricornio" << endl;
      else cout << "aquario" << endl;
      break;
    case 2:
      if(day <= 18) cout << "aquario" << endl;
      else cout << "peixes" << endl;
      break;
    case 3:
      if(day <= 20) cout << "peixes" << endl;
      else cout << "aries" << endl;
      break;
    case 4:
      if(day <= 20) cout << "aries" << endl;
      else cout << "touro" << endl;
      break;
    case 5:
      if(day <= 20) cout << "touro" << endl;
      else cout << "gemeos" << endl;
      break;
    case 6:
      if(day <= 20) cout << "gemeos" << endl;
      else cout << "cancer" << endl;
      break;
    case 7:
      if(day <= 22) cout << "cancer" << endl;
      else cout << "leao" << endl;
      break;
    case 8:
      if(day <= 22) cout << "leao" << endl;
      else cout << "virgem" << endl;
      break;
    case 9:
      if(day <= 22) cout << "virgem" << endl;
      else cout << "libra" << endl;
      break;
    case 10:
      if(day <= 22) cout << "libra" << endl;
      else cout << "escorpiao" << endl;
      break;
    case 11:
      if(day <= 21) cout << "escorpiao" << endl;
      else cout << "sagitario" << endl;
      break;
    case 12:
      if(day <= 21) cout << "sagitario" << endl;
      else cout << "capricornio" << endl;
      break;
  }

}