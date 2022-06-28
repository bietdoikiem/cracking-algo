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

int Solution(vector<pair<int, int>>& segments, int n) {
  int minL = INT_MAX, maxR = INT_MIN, res = 0;
  for (int i = 0; i < n; i++) {
    if (segments[i].first <= minL && segments[i].second >= maxR) {
      res = i + 1;
    } else if (segments[i].first < minL || segments[i].second > maxR) {
      res = -1;
    }
    minL = min(minL, segments[i].first);
    maxR = max(maxR, segments[i].second);
  }
  return res;
}

int main() {
  // Parse input
  int n;
  cin >> n;
  vector<pair<int, int>> segments(n, {0, 0});
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &segments[i].first, &segments[i].second);
  }
  cout << Solution(segments, n) << endl;
  return 0;
}