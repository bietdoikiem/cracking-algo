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

bool canAttendMeetings(vector<vector<int>>& intervals) {
  int n = (int)intervals.size();
  if (n == 0) return true;
  sort(intervals.begin(), intervals.end(),
       [](auto& a, auto& b) { return a[0] < b[0]; });
  int pE = intervals[0][1];
  for (int i = 1; i < n; i++) {
    if (intervals[i][0] < pE) return false;
    pE = intervals[i][1];
  }
  return true;
}

int main() {
  cout << boolalpha;
  vector<vector<int>> i1 = {{0, 30}, {5, 10}, {15, 20}};
  cout << "res1: " << canAttendMeetings(i1) << endl;
  vector<vector<int>> i2 = {{7, 10}, {2, 4}};
  cout << "res2: " << canAttendMeetings(i2) << endl;
  return 0;
}