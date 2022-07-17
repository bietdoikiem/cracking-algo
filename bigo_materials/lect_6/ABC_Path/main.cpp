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

// NOTE: All edges & corners adjacency
int dX[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dY[8] = {0, 1, 0, -1, -1, 1, 1, -1};

/***** SOLUTION BELOW HERE *****/

const int MAX = 50;
int H, W, C = 1, res;
char grid[MAX][MAX], tmp;

bool isValid(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < H) && (y < W) && (grid[x][y] != 'x');
}

void dfs(int x, int y, char c) {
  // cout << "current c: " << c << endl;
  res = max(res, c - 'A' + 1);
  tmp = grid[x][y], grid[x][y] = 'x';
  for (int i = 0; i < 8; i++) {
    int nx = x + dX[i], ny = y + dY[i];
    char nc = c + 1;
    if (isValid(nx, ny) && nc <= 'Z' && grid[nx][ny] == nc) {
      dfs(nx, ny, nc);
    }
  }
  grid[x][y] = tmp;
}

void Solves() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == 'A') {
        dfs(i, j, grid[i][j]);
      }
    }
  }
  cout << "Case " << C << ": " << res << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  while (cin >> H >> W && H && W) {
    // LOG(H, W);
    res = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cin >> grid[i][j];
      }
    }
    Solves();
    C++;
  }
  return 0;
}