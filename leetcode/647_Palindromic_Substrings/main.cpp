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

bool dp[1000][1000];

int countSubstrings(string s) {
  int n = (int)s.size(), res = 0;
  for (int i = 0; i < n; i++) dp[i][i] = true, res++;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) dp[i][i + 1] = true, res++;
  }
  for (int i = n - 3; i >= 0; i--) {
    for (int j = i + 2; j < n; j++) {
      if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true, res++;
    }
  }
  return res;
}

int main() {
  // NOTE: Already solved!
  return 0;
}