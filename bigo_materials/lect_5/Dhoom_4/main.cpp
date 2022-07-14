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

#define MAX 100000

ll s, d, n, keys[1001], dist[MAX], MOD_NUM = MAX;

void init() {
  for (int i = 0; i < MAX; i++) dist[i] = -1;
}

int bfs() {
  queue<ll> q;
  q.push(s);
  dist[s] = 0;  // 0 cost at starting point
  while (!q.empty()) {
    s = q.front(), q.pop();
    if (s == d) break;
    for (int i = 0; i < n; i++) {
      ll tmp = (s * keys[i]) % MOD_NUM;
      if (dist[tmp] == -1) q.push(tmp), dist[tmp] = dist[s] + 1;
    }
  }
  return dist[d];
}

void Solves() {
  cout << bfs() << endl;
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> s >> d;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> keys[i];
  init();
  Solves();
  return 0;
}