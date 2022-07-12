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

#define MAX 1000

int Q, N, M, S, U, V, path[MAX];
bool visited[MAX];

void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void init() {
  for (int i = 0; i < N; i++) path[i] = -1, visited[i] = false;
}

int pathLen(int d) {
  if (S - 1 == d) return 0;
  if (path[d] == -1) return -500000;
  return 1 + pathLen(path[d]);
}

void bfs(vector<int> adj[]) {
  queue<int> q;
  visited[S - 1] = true, q.push(S - 1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < (int)adj[u].size(); i++) {
      int v = adj[u][i];
      if (!visited[v]) q.push(v), visited[v] = true, path[v] = u;
    }
  }
}

void Solves(vector<int> adj[]) {
  bfs(adj);
  for (int i = 0; i < N; i++) {
    if (i == S - 1) continue;
    int len = pathLen(i);
    len = len < 0 ? -1 : 6 * len;
    cout << len << " ";
  }
  cout << endl;
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> N >> M;
    vector<int> adj[N];  // In-scope adjacency list
    init();
    for (int i = 0; i < M; i++) {
      cin >> U >> V;
      addEdge(adj, U - 1, V - 1);
    }
    cin >> S;
    Solves(adj);
  }
  return 0;
}