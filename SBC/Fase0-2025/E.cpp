#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

vector<int> get_prime_factors(int n) {
  vector<int> factors;
  if (n <= 1) return factors;
  if (n % 2 == 0) {
    factors.push_back(2);
    while (n % 2 == 0) n /= 2;
  }
  for (int i = 3; (long long)i * i <= n; i += 2) {
    if (n % i == 0) {
      factors.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) factors.push_back(n);
  return factors;
}

int main() {
  long long Y, K;
  cin >> Y >> K;
  long long X = 1;
  long long current_g = gcd(X, Y);
  X = X / current_g;
  long long remaining_k = K;

  while (remaining_k > 0) {
    long long x_phase = X / current_g;
    long long y_phase = Y / current_g;

    if (y_phase == 1) {
      X += remaining_k * current_g;
      remaining_k = 0;
      break;
    }

    vector<int> primes = get_prime_factors(y_phase);

    if (primes.empty()) {
      X += remaining_k * current_g;
      remaining_k = 0;
      break;
    }

    long long min_m = 1e18;
    for (int p : primes) {
      long long mod = x_phase % p;
      long long m_candidate = p - mod;
      if (m_candidate < min_m) min_m = m_candidate;
    }

    long long m = min_m;
    long long t = min(m, remaining_k);
    X += current_g * t;
    remaining_k -= t;

    if (remaining_k == 0) break;

    if (t == m) {
      long long new_x_phase = x_phase + m;
      long long new_d = gcd(new_x_phase, y_phase);
      X = new_x_phase * current_g;
      current_g *= new_d;
    }
  }

  cout << X << endl;

  return 0;
}