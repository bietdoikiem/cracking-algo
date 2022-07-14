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

int N, M, sheep, wolves;
pair<int, int> d;
char backyard[250][250];

bool isValid(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < N) && (y < M) && (backyard[x][y] != '#');
}

pair<int, int> bfs(pair<int, int> s) {
  int sheep = 0, wolves = 0;
  bool isEscapable = false;
  queue<pair<int, int>> q;
  if (backyard[s.first][s.second] == 'k') {
    sheep++;
  } else if (backyard[s.first][s.second] == 'v') {
    wolves++;
  }
  q.push(s), backyard[s.first][s.second] = '#';
  while (!q.empty()) {
    d = q.front(), q.pop();
    if (d.first == 0 || d.first == N - 1 || d.second == 0 ||
        d.second == M - 1) {
      isEscapable = true;
    }
    for (int i = 0; i < 4; i++) {
      int nx = d.first + dX[i], ny = d.second + dY[i];
      if (isValid(nx, ny)) {
        if (backyard[nx][ny] == 'k') {
          sheep++;
        } else if (backyard[nx][ny] == 'v') {
          wolves++;
        }
        q.push({nx, ny}), backyard[nx][ny] = '#';
      }
    }
  }
  // If escapable
  if (isEscapable) {
    return {sheep, wolves};
  }
  // Else calculate remaining sheep, wolves
  if (sheep > wolves) {
    wolves = 0;
  } else {
    sheep = 0;
  }
  return {sheep, wolves};
}

void Solves() {
  int survivedSheep = 0, survivedWolves = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (isValid(i, j)) {
        pair<int, int> np = bfs({i, j});
        survivedSheep += np.first, survivedWolves += np.second;
      }
    }
  }
  cout << survivedSheep << " " << survivedWolves << endl;
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> backyard[i][j];
    }
  }
  Solves();
  return 0;
}