#include <iostream>
#include <vector>

using namespace std;


// k = tamanho da janela
int maxSum(vector<int> arr, int k){
    int max_sum = 0;
    for (int i = 0; i < k; i++) max_sum += arr[i];

    int window_sum = max_sum;
    for (int i = k; i < arr.size(); i++) {
      window_sum += arr[i] - arr[i - k];
      max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main(){

  int n;
  while(cin >> n){

    int daily;
    cin >> daily;

    int temp;
    vector<int> days;
    for(int i = 0; i < n; i++){
      cin >> temp;
      days.push_back(temp);
    }

    int max_sum = 0;
    for(int i = 1; i <= days.size(); i++){
      int sum = maxSum(days, i);
      sum -= i * daily;
      if(sum > max_sum) max_sum = sum;
    }

    cout << max_sum << endl;

  }

  return 0;
}

// 18 35 6 80 15 21