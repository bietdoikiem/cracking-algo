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

#define MAX 26

int par[MAX], sz[26], T;
char maxLetter, u, v;

void make_set(int n) {
  for (int i = 0; i <= n; i++) par[i] = i, sz[i] = 1;
}

int find_set(int v) {
  if (par[v] == v) return v;
  return par[v] = find_set(par[v]);
}

void union_sets(int x, int y) {
  if ((x = find_set(x)) == (y = find_set(y))) return;
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = par[x], sz[x] += sz[y];
}

void Solves() {
  string s;
  getline(cin, s);
  T = stoi(s);
  getline(cin, s);  // Skip blank line
  while (T--) {
    set<int> sub;
    getline(cin, s);  // get Max letter
    maxLetter = s[0];
    make_set(maxLetter - 'A');
    while (getline(cin, s) && !s.empty()) {
      u = s[0], v = s[1];
      union_sets(u - 'A', v - 'A');
    }
    for (int i = 0; i <= (maxLetter - 'A'); i++) {
      sub.insert(find_set(i));
    }
    cout << sub.size() << endl;
    if (T) cout << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}