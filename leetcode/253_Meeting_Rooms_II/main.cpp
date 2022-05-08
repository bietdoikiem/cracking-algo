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

int minMeetingRooms(vector<vector<int>>& intervals) {
  int n = (int)intervals.size();
  sort(intervals.begin(), intervals.end(),
       [](auto& a, auto& b) { return a[0] < b[0]; });  // Sort by beginning time
  int res = 0;
  priority_queue<int, vector<int>, greater<int>> mh;
  for (int i = 0; i < n; i++) {
    if (!mh.empty() && mh.top() <= intervals[i][0]) {
      mh.pop(), mh.push(intervals[i][1]);
    } else {
      mh.push(intervals[i][1]);
    }
    res = max(res, (int)mh.size());
  }
  return res;
}

int main() {
  vector<vector<int>> i1 = {{0, 30}, {5, 10}, {15, 20}};
  cout << "res1: " << minMeetingRooms(i1) << endl;
  vector<vector<int>> i2 = {{1, 2}, {2, 3}};
  cout << "res2: " << minMeetingRooms(i2) << endl;
  vector<vector<int>> i3 = {{7, 10}, {2, 4}};
  cout << "res3: " << minMeetingRooms(i3) << endl;
  return 0;
}