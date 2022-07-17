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

const int MAX = 100000;
int T, N, E, a, b, par[MAX], sz[MAX];

void make_set(int v) { par[v] = v, sz[v] = 1; }

int find_set(int v) {
  if (v == par[v]) return v;
  return par[v] = find_set(par[v]);
}

// Return parent idx afterwards
void union_sets(int x, int y) {
  if ((x = find_set(x)) == (y = find_set(y))) return;
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = par[x], sz[x] += sz[y];
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; i++) make_set(i);  // Init set
    cin >> E;
    for (int i = 0; i < E; i++) {
      cin >> a >> b;
      union_sets(a, b);
    }
    unordered_set<int> uniquePar;
    for (int i = 0; i < N; i++) uniquePar.insert(find_set(par[i]));
    cout << uniquePar.size() << endl;
  }
  return 0;
}