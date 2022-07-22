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

// NOTE: 2 is border of 1st island, 3 is border of 2nd island
int M, N, borders[2] = {2, 3};
pair<int, int> p;
bool toggleIsland, visited[101][101];

bool isValid(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < M) && (y < N);
}

// Mark border for two islands
void bfsBorder(vector<vector<int>>& grid, int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy}), visited[sx][sy] = true;
  while (!q.empty()) {
    p = q.front(), q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = p.first + dX[i], ny = p.second + dY[i];
      if (isValid(nx, ny)) {
        if (grid[nx][ny] == 0) {
          grid[p.first][p.second] = borders[toggleIsland];  // Set as border
        } else if (!visited[nx][ny] && grid[nx][ny] == 1) {
          q.push({nx, ny}), visited[nx][ny] = true;
        }
      }
    }
  }
  return;
}

// Find minimum required bridge length
int bfsBridge(vector<vector<int>>& grid) {
  int bridgeLen = 0;
  queue<pair<int, int>> q;
  // Append border cells to queue
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == borders[toggleIsland]) {
        q.push({i, j});
        visited[i][j] = true;
      }
    }
  }
  while (!q.empty()) {
    int qSz = (int)q.size();
    for (int i = 0; i < qSz; i++) {
      p = q.front(), q.pop();
      int x = p.first, y = p.second;
      for (int i = 0; i < 4; i++) {
        int nx = x + dX[i], ny = y + dY[i];
        if (isValid(nx, ny) && !visited[nx][ny]) {
          if (grid[nx][ny] == 0) {
            q.push({nx, ny});
            visited[nx][ny] = true;
          } else if (grid[nx][ny] == borders[!toggleIsland]) {
            return bridgeLen;
          }
        }
      }
    }
    bridgeLen++;
  }
  return bridgeLen;
}

// Solution function
int shortestBridge(vector<vector<int>>& grid) {
  M = grid.size(), N = grid[0].size(), toggleIsland = false;
  // M - rows, N - columns
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && grid[i][j] == 1) {
        bfsBorder(grid, i, j);
        toggleIsland = !toggleIsland;  // Switch
      }
    }
  }
  // Reset visited
  memset(visited, false, sizeof(visited));
  return bfsBridge(grid);
}

int main() {
  // vector<vector<int>> g1 = {{0, 1}, {1, 0}};
  // int res1 = shortestBridge(g1);
  // cout << "res1: " << res1 << endl;
  vector<vector<int>> g2 = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
  int res2 = shortestBridge(g2);
  cout << "res2: " << res2 << endl;
  // vector<vector<int>> g3 = {{1, 1, 1, 1, 1},
  //                           {1, 0, 0, 0, 1},
  //                           {1, 0, 1, 0, 1},
  //                           {1, 0, 0, 0, 1},
  //                           {1, 1, 1, 1, 1}};
  // int res3 = shortestBridge(g3);
  // cout << "res3: " << res3 << endl;
  return 0;
}