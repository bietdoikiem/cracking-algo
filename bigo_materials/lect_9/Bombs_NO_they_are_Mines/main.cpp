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

#define MAX 1005
int R, C, row, bombRows, bombCols, col, dist[MAX][MAX];
pair<int, int> S, E;
bool visited[MAX][MAX], grid[MAX][MAX];

bool isValid(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < R) && (y < C) && (!grid[x][y]) &&
         (!visited[x][y]);
}

void init() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      grid[i][j] = false, visited[i][j] = false, dist[i][j] = 0;
    }
  }
}

void bfs(int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});
  visited[sx][sy] = true;
  dist[sx][sy] = 0;
  while (!q.empty()) {
    pair<int, int> f = q.front();
    q.pop();
    int x = f.first, y = f.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dX[i], ny = y + dY[i];
      if (isValid(nx, ny)) {
        dist[nx][ny] = dist[x][y] + 1;
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}

void Solves() {
  while (cin >> R >> C && R && C) {
    init();
    cin >> bombRows;
    // Setup bombs at row
    while (bombRows--) {
      cin >> row >> bombCols;
      while (bombCols--) {
        cin >> col;
        grid[row][col] = true;
      }
    }
    // Parse start & end points
    cin >> S.first >> S.second >> E.first >> E.second;
    bfs(S.first, S.second);
    cout << dist[E.first][E.second] << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}