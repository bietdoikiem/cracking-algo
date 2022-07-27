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

#define MAX 105
struct cpr {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
  }
};
int N, E, T, M, a, b, tu, res;
vector<pair<int, int>> adj[MAX];
vector<int> dist(MAX, INT_MAX);

void dijkstra(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, cpr> pq;
  dist[s] = 0;
  pq.push({s, 0});
  while (!pq.empty()) {
    pair<int, int> cur = pq.top();
    pq.pop();
    int u = cur.first, w = cur.second;
    for (auto& neighbor : adj[u]) {
      int nw = w + neighbor.second;
      if (nw < dist[neighbor.first]) {
        dist[neighbor.first] = nw;
        pq.push({neighbor.first, dist[neighbor.first]});
      }
    }
  }
}

void Solves() {
  cin >> N >> E >> T >> M;
  while (M--) {
    cin >> a >> b >> tu;
    adj[a].push_back({b, tu});
  }
  for (int i = 1; i < N + 1; i++) {
    for (int i = 1; i < N + 1; i++) dist[i] = INT_MAX;
    dijkstra(i);
    if (dist[E] <= T) res++;
  }
  cout << res << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}