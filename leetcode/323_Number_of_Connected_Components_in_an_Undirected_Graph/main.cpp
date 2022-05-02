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

bool V[2000];

void addEdge(vector<int> adj[], int src, int dest) {
  adj[src].push_back(dest), adj[dest].push_back(src);
}

void dfs(vector<int> adj[], int c) {
  V[c] = true;
  for (int u : adj[c]) {
    if (!V[u]) dfs(adj, u);
  }
}

int countComponents(int n, vector<vector<int>>& edges) {
  vector<int> adj[n];
  int res = 0;
  for (int i = 0; i < (int)edges.size(); i++) {
    addEdge(adj, edges[i][0], edges[i][1]);
  }
  for (int i = 0; i < n; i++) {
    if (!V[i]) dfs(adj, i), res++;
  }
  return res != 0 ? res : 1;
}

int main() {
  int n1 = 5;
  vector<vector<int>> e1 = {{0, 1}, {1, 2}, {3, 4}};
  cout << "res1: " << countComponents(n1, e1) << endl;
  int n2 = 5;
  vector<vector<int>> e2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
  cout << "res2: " << countComponents(n2, e2) << endl;
  return 0;
}