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

const int MAX = 50001;
int T, N, U, V, W, maxLen, maxId, dist[MAX];
bool visited[MAX];

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w) {
  adj[u].push_back({v, w});
  adj[v].push_back({u, w});
}

void dfs(vector<pair<int, int>> adj[], int s, int curDist) {
  visited[s] = true;
  for (int i = 0; i < (int)adj[s].size(); i++) {
    int v = adj[s][i].first, w = adj[s][i].second;
    if (!visited[v]) {
      dist[v] = curDist + w;
      if (dist[v] > maxLen) maxLen = dist[v], maxId = v;
      dfs(adj, v, dist[v]);
    }
  }
}

void Solves(vector<pair<int, int>> adj[]) {
  dfs(adj, 1, 0);
  memset(visited, 0, sizeof(visited));
  dfs(adj, maxId, 0);
  cout << maxLen << endl;
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> T;
  while (T--) {
    cin >> N;
    vector<pair<int, int>> adj[N + 1] = {};
    // Init
    maxLen = 0, maxId = 0;
    for (int i = 1; i < N + 1; i++) dist[i] = 0, visited[i] = false;
    for (int i = 0; i < N - 1; i++) {
      cin >> U >> V >> W;
      addEdge(adj, U, V, W);
    }
    // Print adjacency list
    // for (int i = 1; i < N + 1; i++) cout << adj[i] << endl;
    Solves(adj);
  }
  return 0;
}