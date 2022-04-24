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
  for (auto& y : x) os << y << " ";
  return os << "}";
}

template <class T, size_t SIZE>
void printArr(T const (&x)[SIZE]) {
  cout << "{ ";
  for (auto& y : x) cout << y << " ";
  cout << "}" << endl;
}

template <class... Args>
auto& log(const Args&... args) {
  return ((cerr << " " << args), ...) << '\n';
}

#define LOG(...)                     \
  cerr << "[ " #__VA_ARGS__ " ] = "; \
  log(__VA_ARGS__) << '\n'

int dp[101][101];

int uniquePaths(int m, int n) {
  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (i == m - 1 && j == n - 1) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }
    }
  }
  return dp[0][0];
}

int main() {
  int m1 = 3;
  int n1 = 7;
  cout << "ans1: " << uniquePaths(m1, n1) << endl;
  memset(dp, 0, sizeof(dp));  // Reset DP cache
  int m2 = 3;
  int n2 = 2;
  cout << "ans2: " << uniquePaths(m2, n2) << endl;
  memset(dp, 0, sizeof(dp));
  return 0;
}