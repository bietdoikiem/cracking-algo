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

#define MAX 205

struct Edge {
  int s, d;
  ll w;
};
const ll INF = 1e9;
int T, N, M, Q, q, U, V, busyness[MAX], p[MAX];
ll W, d[MAX];
set<int> cycle;
vector<Edge> edges;

int affectedNode(int s) {
  if (p[s] == -1) return s;
  if (cycle.find(p[s]) != cycle.end()) return -INF;
  return affectedNode(p[s]);
}

void BellmanFord(int s) {
  d[s] = 0;
  int x = 0;
  for (int i = 0; i < N; i++) {
    x = -1;
    for (Edge& e : edges) {
      if (d[e.s] < INF && d[e.s] + e.w < d[e.d]) {
        // Avoid integer flow if use int
        d[e.d] = max(-INF, d[e.s] + e.w);
        p[e.d] = e.s;
        x = e.d;
      }
    }
  }
  // Check for negative cycle
  if (x != -1) {
    for (int i = 0; i < N; i++) x = p[x];
    for (int v = x;; v = p[v]) {
      cycle.insert(v);
      if (v == x && cycle.size() > 1) break;
    }
    // Nodes in the cycle
    for (auto& v : cycle) {
      d[v] = -INF;
    }
  }
}

void Solves() {
  cin >> T;
  string str;
  for (int i = 0; i < T; i++) {
    getline(cin, str);  // Skip line
    cout << "Case " << i + 1 << ":" << endl;
    // Init components
    edges.clear(), cycle.clear();
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> busyness[i];
      d[i] = INF;
      p[i] = -1;
    }
    // Process edges
    cin >> M;
    while (M--) {
      cin >> U >> V;
      ll w = busyness[V] - busyness[U];
      W = (w * w * w);
      edges.push_back({U, V, W});
    }
    BellmanFord(1);
    // Process query
    cin >> Q;
    while (Q--) {
      cin >> q;
      cout << (d[q] >= 3 && d[q] < INF && affectedNode(q) != -INF
                   ? to_string(d[q])
                   : "?")
           << endl;
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}