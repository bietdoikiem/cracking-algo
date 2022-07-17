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

const int MAX = 10001;
int T, N, M, U, V;
char visited[MAX];

bool cycleDetector(unordered_set<int> adj[], int s) {
  visited[s] = 1;  // 1 - In-processing
  for (auto& v : adj[s]) {
    if (visited[v] == 0) {  // 0 - Unvisited
      if (cycleDetector(adj, v)) return true;
    } else if (visited[v] == 1) {
      return true;
    }
  }
  visited[s] = 2;  // 2 - Done processing
  return false;
}

void Solves(unordered_set<int> adj[]) {
  for (int i = 1; i <= N; i++) {
    if (cycleDetector(adj, i)) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) visited[i] = 0;  // Reset visited
    unordered_set<int> adj[N + 1];
    while (M--) {
      cin >> U >> V;
      adj[U].insert(V);
    }
    Solves(adj);
  }
  return 0;
}