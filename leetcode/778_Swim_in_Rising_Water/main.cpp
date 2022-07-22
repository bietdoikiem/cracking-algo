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

struct Water {
  int x, y, w;
};

struct cpr {
  bool operator()(const Water& wt1, Water& wt2) { return wt1.w > wt2.w; }
};

int R, C;
Water fwt, nw;
bool visited[50][50];
priority_queue<Water, vector<Water>, cpr> pq;

bool isValid(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < R) && (y < C) && !visited[x][y];
}

int swimInWater(vector<vector<int>>& grid) {
  R = (int)grid.size(), C = (int)grid[0].size();
  int res = grid[0][0];
  pq.push({0, 0, grid[0][0]});
  visited[0][0] = true;
  while (!pq.empty()) {
    fwt = pq.top(), pq.pop();
    res = max(res, fwt.w);
    if (fwt.x == R - 1 && fwt.y == C - 1) break;
    for (int i = 0; i < 4; i++) {
      nw.x = fwt.x + dX[i], nw.y = fwt.y + dY[i];
      if (isValid(nw.x, nw.y)) {
        nw.w = grid[nw.x][nw.y];
        visited[nw.x][nw.y] = true;
        pq.push(nw);
      }
    }
  }
  return res;
}

int main() {
  // vector<vector<int>> grid = {{0, 1, 2, 3, 4},
  //                             {24, 23, 22, 21, 5},
  //                             {12, 13, 14, 15, 16},
  //                             {11, 17, 18, 19, 20},
  //                             {10, 9, 8, 7, 6}};
  // vector<vector<int>> grid = {{0, 2}, {1, 3}};
  vector<vector<int>> grid = {
      {3, 2},
      {0, 1},
  };
  cout << "res: " << swimInWater(grid) << endl;
  return 0;
}