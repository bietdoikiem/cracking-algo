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

int n, m;
pair<int, int> s, d, r;
char cave[500][500];

bool isValid(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

void Solves() {
  queue<pair<int, int>> q;
  q.push({s.first, s.second}), cave[s.first][s.second] = 'X';
  while (!q.empty()) {
    r = q.front(), q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = r.first + dX[i], ny = r.second + dY[i];
      // If reaches goal
      if (isValid(nx, ny) && nx == d.first && ny == d.second &&
          cave[nx][ny] == 'X') {
        cout << "YES" << endl;
        return;
      }
      // If move-able
      if (isValid(nx, ny) && cave[nx][ny] == '.') {
        q.push({nx, ny}), cave[nx][ny] = 'X';
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> n >> m;
  // Parse matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> cave[i][j];
    }
  }
  // Start,End
  cin >> s.first >> s.second;
  cin >> d.first >> d.second;
  s.first--, s.second--, d.first--, d.second--;
  Solves();
  return 0;
}