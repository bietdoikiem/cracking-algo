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

#define MAX 2005

struct Edge {
  int u, v, w;
};
int T, N, M, U, V, W;
Edge edges[MAX];

bool BellmanFord(int s) {
  int u, v, w, nw, dist[N];
  for (int i = 0; i < N; i++) dist[i] = INT_MAX;
  dist[s] = 0;
  for (int i = 1; i <= N - 1; i++) {
    bool isSaturated = true;
    for (int j = 0; j < M; j++) {
      u = edges[j].u;
      v = edges[j].v;
      w = edges[j].w;
      nw = dist[u] + w;
      if (dist[u] != INT_MAX && nw < dist[v]) {
        dist[v] = nw;
        isSaturated = false;
      }
    }
    if (isSaturated) break;
  }
  // Check if it's still relax-able for negative cycle
  for (int i = 0; i < M; i++) {
    u = edges[i].u;
    v = edges[i].v;
    w = edges[i].w;
    nw = dist[u] + w;
    if (dist[u] != INT_MAX && nw < dist[v]) {
      return true;
    }
  }
  return false;
}

void Solves() {
  cin >> T;
  while (T--) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
      cin >> U >> V >> W;
      edges[i] = {U, V, W};
    }
    if (BellmanFord(0)) {
      cout << "possible" << endl;
    } else {
      cout << "not possible" << endl;
    }
  }
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}