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
int Solution(vector<int> minutes) {
  int n = (int)minutes.size(), res = 0;
  for (int i = 0; i < n; i++) {
    // Init minute
    if (i == 0) {
      if (minutes[i] > 15) return 15;
      res = minutes[i];
      continue;
    }
    // Other minutes
    // Check if the gap between last res and cur minute
    if (minutes[i] - res > 15) {
      return res + 15;
    }
    res = minutes[i];
  }
  return min(90, res + 15);
}

int main() {
  // Parse input
  int n;
  cin >> n;
  vector<int> minutes(n);
  for (int i = 0; i < n; i++) scanf("%d", &minutes[i]);
  cout << Solution(minutes) << endl;
  return 0;
}