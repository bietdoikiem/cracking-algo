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

#define MAX 100001

int N, M, V1, V2, d, cost[MAX];
bool hasCat[MAX], visited[MAX];
vector<int> adj[MAX];

void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int bfs() {
  int res = 0;
  queue<int> q;
  q.push(1);
  visited[1] = true;
  cost[1] = hasCat[1] ? 1 : 0;
  while (!q.empty()) {
    d = q.front(), q.pop();
    // Check if reach the leaf
    int adjCount = (int)adj[d].size();
    if (adjCount == 1 && d != 1) res++;
    for (int i = 0; i < adjCount; i++) {
      int v = adj[d][i];
      cost[v] = hasCat[v] ? cost[d] + 1 : 0;
      if (cost[v] <= M && visited[v] == false) {
        q.push(v), visited[v] = true;
      }
    }
  }
  return res;
}

void Solves() {
  cout << bfs() << endl;
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> hasCat[i];
  while (N > 1) {
    cin >> V1 >> V2;
    addEdge(V1, V2);
    N--;
  }
  Solves();
  return 0;
}