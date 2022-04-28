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

bool isValid(vector<vector<bool>>& V, const int& R, const int& C, int x,
             int y) {
  if (x < 0 || y < 0 || x >= R || y >= C) return false;
  if (V[x][y]) return false;
  return true;
}

void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q,
         vector<vector<bool>>& V, const int& R, const int& C, int sX, int sY) {
  q.push({sX, sY});
  V[sX][sY] = true;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    int x = cur.first;
    int y = cur.second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dX[i];
      int ny = y + dY[i];
      if (isValid(V, R, C, nx, ny) && heights[x][y] <= heights[nx][ny]) {
        q.push({nx, ny});
        V[nx][ny] = true;
      }
    }
  }
  return;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  const int R = heights.size();
  const int C = heights[0].size();
  vector<vector<int>> ans;
  queue<pair<int, int>> qPac, qAlt;
  vector<bool> col(C, false);
  vector<vector<bool>> vPac(R, col), vAlt(R, col);
  for (int i = 0; i < R; i++) {
    vPac[i][0] = true, vAlt[i][C - 1] = true;
    qPac.push({i, 0}), qAlt.push({i, C - 1});
  }
  for (int i = 0; i < C; i++) {
    vPac[0][i] = true, vAlt[R - 1][i] = true;
    qPac.push({0, i}), qAlt.push({R - 1, i});
  }
  bfs(heights, qPac, vPac, R, C, 0, 0);
  bfs(heights, qAlt, vAlt, R, C, R - 1, C - 1);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (vPac[i][j] && vAlt[i][j]) ans.push_back({i, j});
    }
  }
  return ans;
}

/* * DFS Version * */

void dfs(vector<vector<int>>& heights, vector<vector<bool>>& V, const int& R,
         const int& C, int x, int y) {
  V[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dX[i];
    int ny = y + dY[i];
    if (isValid(V, R, C, nx, ny) && heights[x][y] <= heights[nx][ny]) {
      dfs(heights, V, R, C, nx, ny);
      V[nx][ny] = true;
    }
  }
  return;
}

vector<vector<int>> pacificAtlanticDFS(vector<vector<int>>& heights) {
  const int R = heights.size();
  const int C = heights[0].size();
  vector<vector<int>> ans;
  vector<bool> col(C, false);
  vector<vector<bool>> vPac(R, col), vAlt(R, col);
  for (int i = 0; i < R; i++) {
    dfs(heights, vPac, R, C, i, 0);
    dfs(heights, vAlt, R, C, i, C - 1);
  }
  for (int i = 0; i < C; i++) {
    dfs(heights, vPac, R, C, 0, i);
    dfs(heights, vAlt, R, C, R - 1, i);
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (vPac[i][j] && vAlt[i][j]) ans.push_back({i, j});
    }
  }
  return ans;
}

int main() {
  // BFS
  vector<vector<int>> h1 = {{1, 2, 2, 3, 5},
                            {3, 2, 3, 4, 4},
                            {2, 4, 5, 3, 1},
                            {6, 7, 1, 4, 5},
                            {5, 1, 1, 2, 4}};
  cout << "ans1 (BFS): " << pacificAtlantic(h1) << endl;
  vector<vector<int>> h2 = {{10, 10, 10}, {10, 1, 10}, {10, 10, 10}};
  cout << "ans2 (BFS): " << pacificAtlantic(h2) << endl;
  vector<vector<int>> h3 = {{13}, {4},  {19}, {10}, {1}, {11}, {5},  {17}, {3},
                            {10}, {1},  {0},  {1},  {4}, {1},  {3},  {6},  {13},
                            {2},  {16}, {7},  {6},  {3}, {1},  {9},  {9},  {13},
                            {10}, {9},  {10}, {6},  {2}, {11}, {17}, {13}, {0},
                            {19}, {7},  {13}, {3},  {9}, {2}};
  cout << "ans3 (BFS): " << pacificAtlantic(h3) << endl;
  // DFS
  cout << "ans1 (DFS): " << pacificAtlanticDFS(h1) << endl;
  cout << "ans2 (DFS): " << pacificAtlanticDFS(h2) << endl;
  cout << "ans3 (DFS): " << pacificAtlanticDFS(h3) << endl;
  return 0;
}