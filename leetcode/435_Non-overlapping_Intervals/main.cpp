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

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end(),
       [](auto& a, auto& b) { return a[0] < b[0]; });
  int res = 0, e = intervals[0][1];
  for (int i = 1; i < (int)intervals.size(); i++) {
    if (intervals[i][0] < e) {  // If overlap
      res += 1, e = min(e, intervals[i][1]);
    } else {
      e = intervals[i][1];  // If no overlap
    }
  }
  return res;
}

int main() {
  vector<vector<int>> i1 = {
      {1, 2},
      {2, 3},
      {3, 4},
      {1, 3},
  };
  cout << "res1: " << eraseOverlapIntervals(i1) << endl;
  vector<vector<int>> i2 = {{1, 2}, {1, 2}, {1, 2}};
  cout << "res2: " << eraseOverlapIntervals(i2) << endl;
  vector<vector<int>> i3 = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
  cout << "res3: " << eraseOverlapIntervals(i3) << endl;
  vector<vector<int>> i4 = {{1, 2}, {2, 3}};
  cout << "res4: " << eraseOverlapIntervals(i4) << endl;
  return 0;
}