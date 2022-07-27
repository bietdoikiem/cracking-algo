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

struct cpr {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
  }
};

#define MAX 505
const int INF = INT_MAX;
int N, A, B, W, U, Q, V, u, w;
vector<pair<int, int>> adj[MAX];
vector<int> dist(MAX, INF);

void dijkstra(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, cpr> pq;
  pq.push({s, 0});
  dist[s] = 0;
  while (!pq.empty()) {
    pair<int, int> cur = pq.top();
    pq.pop();
    u = cur.first, w = cur.second;
    for (int i = 0; i < (int)adj[u].size(); i++) {
      pair<int, int> neighbor = adj[u][i];
      int nw = w + neighbor.second;
      if (nw < dist[neighbor.first]) {
        dist[neighbor.first] = nw;
        pq.push({neighbor.first, dist[neighbor.first]});
      }
    }
  }
}

void Solves() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A >> B >> W;
    adj[A].push_back({B, W});
    adj[B].push_back({A, W});
  }
  cin >> U;
  dijkstra(U);
  cin >> Q;
  while (Q--) {
    cin >> V;
    cout << (dist[V] != INF ? to_string(dist[V]) : "NO PATH") << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}