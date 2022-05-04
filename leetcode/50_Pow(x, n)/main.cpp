#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

ostream& operator<<(ostream& os, pair<int, int> const& x) {
  os << x.first << ", " << x.second;
  return os;
}

template <class T>
ostream& operator<<(ostream& os, vector<T> const& x) {
  os << "{ ";
  for (auto y : x) os << y << " ";
  return os << "}";
}

template <class T, size_t SIZE>
void printArr(T const (&x)[SIZE]) {
  cout << "{ ";
  for (auto y : x) cout << y << " ";
  cout << "}" << endl;
}

template <class... Args>
auto& log(const Args&... args) {
  return ((cerr << " " << args), ...) << '\n';
}

#define LOG(...)                     \
  cerr << "[ " #__VA_ARGS__ " ] = "; \
  log(__VA_ARGS__) << '\n'

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

/***** SOLUTION BELOW HERE *****/

double helperPow(double x, int n) {
  if (n == 1) return x;
  double half = helperPow(x, n / 2);
  return n % 2 == 0 ? half * half : half * half * helperPow(x, n % 2);
}

double myPow(double x, int n) {
  if (n == 0) return 1.0;
  if (n >= 0) {
    return helperPow(x, n);
  }
  if (n == INT_MIN) {
    return helperPow(1 / x, INT_MAX) * 1 / x;
  }
  return helperPow(1 / x, -n);
}

double myPowIterative(double x, int n) {
  // ...
  return 0.0;
}

int main() {
  double x1 = 2.0;
  int n1 = 2;
  double res1 = myPow(x1, n1);
  cout << fixed << setprecision(5);
  cout << "res1: " << res1 << endl;  // 4
  double x2 = 2.0;
  int n2 = -2;
  double res2 = myPow(x2, n2);
  cout << "res2: " << setprecision(5) << res2 << endl;  // 0.25
  return 0;
}