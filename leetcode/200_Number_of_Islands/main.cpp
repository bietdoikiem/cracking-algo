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

void bfs(vector<vector<char>>& grid, queue<pair<int, int>>& q, const int& R,
         const int& C, int sX, int sY) {
  q.push({sX, sY});
  grid[sX][sY] = '2';
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    int x = cur.first;
    int y = cur.second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dX[i];
      int ny = y + dY[i];
      if (!(nx < 0 || ny < 0 || nx >= R || ny >= C) && grid[nx][ny] == '1') {
        q.push({nx, ny});
        grid[nx][ny] = '2';
      }
    }
  }
  return;
}

int numIslands(vector<vector<char>>& grid) {
  const int R = grid.size();
  const int C = grid[0].size();
  queue<pair<int, int>> q;
  int ans = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (grid[i][j] == '1') {
        bfs(grid, q, R, C, i, j);
        ans += 1;
      }
    }
  }
  return ans;
}

/* * DFS Solution * */
void dfs(vector<vector<char>>& grid, const int& R, const int& C, int x, int y) {
  grid[x][y] = '2';
  for (int i = 0; i < 4; i++) {
    int nx = x + dX[i];
    int ny = y + dY[i];
    if (!(nx < 0 || ny < 0 || nx >= R || ny >= C) && grid[nx][ny] != '2' &&
        grid[nx][ny] == '1') {
      dfs(grid, R, C, nx, ny);
    }
  }
  return;
}

int numIslandsDFS(vector<vector<char>>& grid) {
  const int R = grid.size();
  const int C = grid[0].size();
  int ans = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (grid[i][j] == '1') {
        dfs(grid, R, C, i, j);
        ans += 1;
      }
    }
  }
  return ans;
}

int main() {
  vector<vector<char>> g1 = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'},
  };
  cout << "ans1 (BFS): " << numIslands(g1) << endl;
  vector<vector<char>> g2 = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'},
  };
  cout << "ans2 (BFS): " << numIslands(g2) << endl;
  // DFS
  g1 = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'},
  };
  cout << "ans1 (DFS): " << numIslandsDFS(g1) << endl;
  g2 = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'},
  };
  cout << "ans2 (DFS): " << numIslandsDFS(g2) << endl;
  return 0;
}