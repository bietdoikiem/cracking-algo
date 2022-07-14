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

int T, caseOrd, W, H, nx, ny;
char place[20][20];
pair<int, int> s, d;
bool visited[20][20];

bool isValid(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < H) && (y < W) && (place[x][y] == '.') &&
         (visited[x][y] == false);
}

int bfs() {
  int res = 0;
  queue<pair<int, int>> q;
  q.push({s.first, s.second});
  visited[s.first][s.second] = true;
  while (!q.empty()) {
    d = q.front(), q.pop(), res++;
    for (int i = 0; i < 4; i++) {
      nx = d.first + dX[i], ny = d.second + dY[i];
      if (isValid(nx, ny)) q.push({nx, ny}), visited[nx][ny] = true;
    }
  }
  return res;
}

void init() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> place[i][j];
      if (place[i][j] == '@') s = {i, j};

      visited[i][j] = false;
    }
  }
}

void Solves() {
  cout << "Case " << caseOrd << ": " << bfs() << endl;
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> T;
  for (caseOrd = 1; caseOrd <= T; caseOrd++) {
    cin >> W >> H;
    init();
    Solves();
  }
  return 0;
}