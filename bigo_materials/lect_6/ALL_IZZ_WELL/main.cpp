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

const string s = "ALLIZZWELL";
const int MAX = 100, sLen = (int)s.size();
int T, R, C, curIdx;
char grid[MAX][MAX];
bool visited[MAX][MAX];

bool isValid(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < R) && (y < C) && (!visited[x][y]);
}

bool dfs(int x, int y, int ni) {
  visited[x][y] = true;
  for (int i = 0; i < 8; i++) {
    int nx = x + dX[i], ny = y + dY[i];
    if (isValid(nx, ny) && grid[nx][ny] == s[ni]) {
      if (ni == sLen - 1 || dfs(nx, ny, ni + 1)) return true;
    }
  }
  visited[x][y] = false;
  return false;
}

void Solves() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (grid[i][j] == s[0]) {
        memset(visited, false, sizeof(visited));
        if (dfs(i, j, 1)) {
          cout << "YES" << endl;
          return;
        }
      };
    }
  }
  cout << "NO" << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> T;
  while (T--) {
    cin >> R >> C;
    // LOG(R, C);
    curIdx = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cin >> grid[i][j];
        visited[i][j] = false;
      }
    }
    Solves();
  }
  return 0;
}