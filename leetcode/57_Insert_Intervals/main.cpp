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

vector<vector<int>> insert(vector<vector<int>>& intervals,
                           vector<int>& newInterval) {
  vector<vector<int>> res;
  int nB = newInterval[0], nE = newInterval[1];
  bool isInserted = false;
  for (auto& i : intervals) {
    if (i[1] < nB) res.push_back({i[0], i[1]});
    if (nB >= i[0] && nB <= i[1]) nB = i[0], nE = max(nE, i[1]);
    if (nE >= i[0] && i[0] >= nB) nE = max(nE, i[1]);
    if (i[0] > nE) {
      if (!isInserted) res.push_back({nB, nE}), isInserted = true;
      res.push_back({i[0], i[1]});
    }
  }
  if (!isInserted) res.push_back({nB, nE});
  return res;
}

int main() {
  vector<vector<int>> i1 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> n1 = {4, 8};
  cout << "res1: " << insert(i1, n1) << endl;
  return 0;
}