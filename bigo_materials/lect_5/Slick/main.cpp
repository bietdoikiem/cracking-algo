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

#define MAX_SLICK_SIZE 625001

int N, M, slicks[250][250], slickCount[MAX_SLICK_SIZE];
unordered_map<int, int> map;

bool isValid(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < N) && (y < M) && (slicks[x][y] != 0);
}

int bfs(pair<int, int> s) {
  int sz = 0;
  queue<pair<int, int>> q;
  q.push(s), slicks[s.first][s.second] = 0;
  while (!q.empty()) {
    pair<int, int> d = q.front();
    q.pop();
    sz++;
    for (int i = 0; i < 4; i++) {
      int nx = d.first + dX[i], ny = d.second + dY[i];
      if (isValid(nx, ny)) q.push({nx, ny}), slicks[nx][ny] = 0;
    }
  }
  return sz;
}

void init() {
  for (int i = 1; i <= N * M; i++) slickCount[i] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> slicks[i][j];
    }
  }
}

void Solves() {
  int total = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (slicks[i][j] == 1) {
        int sz = bfs({i, j});
        slickCount[sz]++;
        total++;
      }
    }
  }
  cout << total << endl;
  for (int i = 1; i <= N * M; i++) {
    if (slickCount[i] > 0) cout << i << " " << slickCount[i] << endl;
  }
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  while (cin >> N >> M && N && M) {
    init();
    Solves();
  }
  return 0;
}