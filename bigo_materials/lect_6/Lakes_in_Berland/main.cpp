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

struct Point {
  int x, y;
};

struct Lake {
  Point pt;
  int area;
};

struct compare {
  bool operator()(const Lake& a, const Lake& b) { return a.area > b.area; }
};

const int INVALID_AREA = -250000;
int N, M, K, res;
char bmap[50][50];
bool visited[50][50];
priority_queue<Lake, vector<Lake>, compare> lakes;

bool isValid(Point pt) {
  return (pt.x >= 0) && (pt.y >= 0) && (pt.x < N) && (pt.y < M) &&
         (bmap[pt.x][pt.y] == '.') && (!visited[pt.x][pt.y]);
}

bool isNotBorder(Point pt) {
  return (pt.x > 0) && (pt.y > 0) && (pt.x < N - 1) && (pt.y < M - 1);
}

int dfsArea(Point s) {
  int cnt = 1;
  visited[s.x][s.y] = true;
  for (int i = 0; i < 4; i++) {
    Point npt = {s.x + dX[i], s.y + dY[i]};
    if (isValid(npt)) {
      if (isNotBorder(npt)) {
        cnt += dfsArea(npt);
      } else {
        cnt = INVALID_AREA;
      }
    }
  }
  return cnt;
}

void dfsFill(Point s) {
  bmap[s.x][s.y] = '*';
  visited[s.x][s.y] = true;
  for (int i = 0; i < 4; i++) {
    Point npt = {s.x + dX[i], s.y + dY[i]};
    if (isValid(npt)) dfsFill(npt);
  }
}

void Solves() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      Point npt = {i, j};
      if (isValid(npt) && isNotBorder(npt)) {
        int area = dfsArea(npt);
        if (area > 0) lakes.push({npt, area});
      }
    }
  }
  // Reset visited
  memset(visited, false, sizeof(visited));
  int d = (int)lakes.size() - K;  // To be deleted
  while (d--) {
    Lake l = lakes.top();
    lakes.pop();
    res += l.area;
    dfsFill(l.pt);
  }
  // Display matrix
  cout << res << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cout << bmap[i][j];
    cout << endl;
  }
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> bmap[i][j];
  }
  Solves();
  return 0;
}