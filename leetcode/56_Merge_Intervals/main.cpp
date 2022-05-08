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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end(),
       [](auto const& a, auto const& b) { return a[0] < b[0]; });
  vector<vector<int>> res;
  int b = intervals[0][0], e = intervals[0][1];
  for (int i = 1; i < (int)intervals.size(); i++) {
    // Begin overlap
    if (intervals[i][0] >= b && intervals[i][0] <= e)
      e = max(e, intervals[i][1]);
    // End overlap
    if (intervals[i][0] <= e && intervals[i][0] > b)
      e = max(e, intervals[i][1]);
    // If not overlap (greater)
    if (intervals[i][0] > e) {
      res.push_back({b, e});
      b = intervals[i][0], e = intervals[i][1];
    }
  }
  res.push_back({b, e});  // Add the remaining interval
  return res;
}

int main() {
  vector<vector<int>> i1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  cout << "res1: " << merge(i1) << endl;
  return 0;
}