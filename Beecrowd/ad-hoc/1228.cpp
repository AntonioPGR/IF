#include <iostream>
#include <vector>

using namespace std;

struct Driver{
  int start;
  int end;
};

int main(){

  int drivers_number;
  while(cin >> drivers_number){
    Driver default_driver;
    default_driver.start = 0;
    default_driver.end = 0;

    vector<Driver> drivers(drivers_number, default_driver);
    for(int i = 0; i<drivers_number; i++){
      int driver_number;
      cin >> driver_number;
      drivers.at(driver_number-1).start = i+1;
    }
    for(int i = 0; i<drivers_number; i++){
      int driver_number;
      cin >> driver_number;
      drivers.at(driver_number-1).end = i+1;
    }

    int sum = 0;
    for(Driver d1 : drivers){
      for(Driver d2 : drivers){
        if(d1.start > d2.start && d1.end < d2.end) {
          sum++;
        }
      }
    }

    cout << sum << endl;
  }

}
