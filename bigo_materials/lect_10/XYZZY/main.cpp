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

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

/***** SOLUTION BELOW HERE *****/

#define MAX 105
struct Edge {
  int s, d, w;
};
const int INF = 1e9 + 7, PLAYER_ENERGY = 100;
int n, pe, energy[MAX], dist[MAX], path[MAX];
vector<Edge> edges;
vector<vector<int>> adj;
bool visited[MAX];

bool dfs(int s, int d) {
  if (s == d) return true;
  visited[s] = true;
  for (int v : adj[s]) {
    if (!visited[v]) {
      if (dfs(v, d)) return true;
    }
  }
  return false;
}

bool BellmanFord(int s, int d) {
  dist[s] = 0;
  // Process edges
  for (int i = 0; i < n - 1; i++) {
    bool flag = false;
    for (Edge& e : edges) {
      if (dist[e.s] < 100 && dist[e.s] + e.w < dist[e.d]) {
        dist[e.d] = dist[e.s] + e.w;
        path[e.d] = e.s;
        flag = true;
      }
    }
    if (!flag) break;
  }
  // Check negative cycle
  for (Edge& e : edges) {
    if (dist[e.s] < 100 && dist[e.s] + e.w < dist[e.d]) {
      memset(visited, 0, sizeof(visited));
      if (dfs(e.s, d)) return true;
    }
  }
  return dist[d] < 100;
}

void Solves() {
  while (cin >> n && n != -1) {
    edges.clear();
    adj.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
      // Reset dist, path on N vertices
      dist[i] = INF, path[i] = -1;
      cin >> energy[i];
      int nr, r;
      cin >> nr;
      while (nr--) {
        cin >> r;
        edges.push_back({i, r, 0});
        adj[i].push_back(r);
      }
    }
    // Negate the edge
    for (Edge& e : edges) e.w = -energy[e.d];
    if (BellmanFord(1, n)) {
      cout << "winnable" << endl;
    } else {
      cout << "hopeless" << endl;
    }
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}