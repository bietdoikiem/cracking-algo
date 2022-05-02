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
int par[2000];
int sz[2000];

void make_set(int v) { par[v] = v, sz[v] = 1; }

int find_set(int v) {
  if (v == par[v]) return v;
  return par[v] = find_set(par[v]);
}

bool union_sets(int x, int y) {
  if ((x = find_set(x)) == (y = find_set(y))) return false;
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = par[x], sz[x] += sz[y];
  return true;
}

bool validTree(int n, vector<vector<int>>& edges) {
  int ne = (int)edges.size();
  if (ne != n - 1) return false;
  for (int i = 0; i < n; i++) make_set(i);
  for (int i = 0; i < ne; i++) {
    if (!union_sets(edges[i][0], edges[i][1])) return false;
  }
  return true;
}

int main() {
  cout << boolalpha;
  int n1 = 5;
  vector<vector<int>> e1 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
  cout << "res1: " << validTree(n1, e1) << endl;
  memset(par, 0, sizeof(par)), memset(sz, 0, sizeof(sz));  // Reset UF
  int n2 = 5;
  vector<vector<int>> e2 = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
  cout << "res2: " << validTree(n2, e2) << endl;
  int n3 = 4;
  vector<vector<int>> e3 = {{0, 1}, {2, 3}};
  cout << "res3: " << validTree(n3, e3) << endl;
  return 0;
}