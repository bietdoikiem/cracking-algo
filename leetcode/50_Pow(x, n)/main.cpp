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
  return n % 2 == 0 ? half * half : half * half * x;
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
  if (n == 0) return 1.0;
  long long N = n;
  if (n < 0) {
    x = 1 / x;
    N = -N;
  }
  double res = 1, curProd = x;
  for (long long i = N; i > 0; i /= 2) {
    if (i % 2 == 1) {
      res *= curProd;
    }
    curProd = curProd * curProd;
  }
  return res;
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
  cout << "res2: " << res2 << endl;  // 0.25
  cout << "res1 (iterative): " << myPowIterative(x1, n1) << endl;
  cout << "res2 (iterative): " << myPowIterative(x2, n2) << endl;
  return 0;
}