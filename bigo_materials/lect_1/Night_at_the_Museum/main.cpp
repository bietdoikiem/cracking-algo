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

int Solution(string s) {
  int cost = 0;
  char cur = 'a';  // cur char
  for (auto& c : s) {
    int rot = cur - c;
    if (rot < 0) {
      cost += min(abs(rot), 26 + rot);
    } else {
      cost += min(rot, 26 - rot);
    }
    cur = c;
  }
  return cost;
}

int main() {
  // Parse input
  string s;
  cin >> s;
  // Solution
  int res = Solution(s);
  cout << res << endl;
  return 0;
}