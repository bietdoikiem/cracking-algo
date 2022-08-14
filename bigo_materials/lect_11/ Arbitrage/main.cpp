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

#define MAX 30
const int INF = 1e9 + 7;
int n, m, tc;
string cur, c1, c2;
double p, dist[MAX][MAX];
unordered_map<string, int> cIdx;

void init() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = i != j ? -INF : 1;
    }
  }
}

void Floyd() {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (dist[i][k] == -INF) continue;
      for (int j = 0; j < n; j++) {
        if (dist[k][j] != -INF && dist[i][k] * dist[k][j] > dist[i][j]) {
          dist[i][j] = dist[i][k] * dist[k][j];
        }
      }
    }
  }
}

void Solves() {
  while (cin >> n && n) {
    tc++;
    for (int i = 0; i < n; i++) {
      cin >> cur;
      cIdx[cur] = i;
    }
    init();
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> c1 >> p >> c2;
      if (c1 == c2) {
        dist[cIdx[c1]][cIdx[c2]] = max(dist[cIdx[c1]][cIdx[c2]], p);
      } else {
        dist[cIdx[c1]][cIdx[c2]] = p;
      }
    }
    Floyd();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << dist[i][j] << " ";
      }
      cout << endl;
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (dist[i][i] > 1.0) {
        flag = true;
        break;
      }
    }
    cout << "Case " << tc << ": " << (flag ? "Yes" : "No") << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}