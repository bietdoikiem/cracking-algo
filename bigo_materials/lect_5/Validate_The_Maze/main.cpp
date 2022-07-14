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

int T, M, N;
char c, maze[20][20];
vector<pair<int, int>> points;
bool visited[20][20];

// If reaches the valid edge
bool isValidEdge(int x, int y) {
  return ((x == M - 1) || (y == N - 1) || (x == 0) || (y == 0)) &&
         maze[x][y] == '.';
}

// If it's valid to traverse through
bool isValid(int x, int y) {
  return (x < M) && (y < N) && (x >= 0) && (y >= 0) && maze[x][y] == '.' &&
         visited[x][y] == false;
}

void init() {
  points.clear();  // Clear source, dest points
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> c;
      maze[i][j] = c, visited[i][j] = false;
    }
  }
}

bool bfs(pair<int, int> s, pair<int, int> d) {
  queue<pair<int, int>> q;
  q.push({s.first, s.second});
  visited[s.first][s.second] = true;
  while (!q.empty()) {
    pair<int, int> coord = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = coord.first + dX[i];
      int ny = coord.second + dY[i];
      if (isValid(nx, ny)) {
        // Reaches dest
        if (nx == d.first && ny == d.second) return true;
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
  return false;
}

void Solves() {
  // Acquire source & dest points
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (isValidEdge(i, j)) {
        if (points.size() >= 2) {
          cout << "invalid" << endl;
          return;
        } else {
          points.push_back({i, j});
        }
      }
    }
  }
  // Check if enough valid entry points
  if (points.size() < 2) {
    cout << "invalid" << endl;
    return;
  }
  // Check if traversable between two points
  if (bfs({points[0].first, points[0].second},
          {points[1].first, points[1].second})) {
    cout << "valid" << endl;
  } else {
    cout << "invalid" << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> M >> N;
    init();
    Solves();
  }
  return 0;
}