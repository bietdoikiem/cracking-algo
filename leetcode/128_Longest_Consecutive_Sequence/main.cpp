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

int longestConsecutive(vector<int>& nums) {
  unordered_set<int> s(nums.begin(), nums.end());
  int res = 0;
  for (auto& e : nums) {
    if (s.find(e) == s.end()) continue;
    int next = e + 1, prev = e - 1;
    while (s.find(next) != s.end()) s.erase(next), next++;
    while (s.find(prev) != s.end()) s.erase(next), prev++;
    res = max(res, next - prev - 1);
  }
  return res;
}

int par[100000];
int sz[100000];

void make_set(int v) { par[v] = v, sz[v] = 1; }
int find_set(int v) {
  if (v == par[v]) return v;
  return par[v] = find_set(par[v]);
}
// Modified union to return larger size set
int union_sets(int x, int y) {
  if ((x = find_set(x)) == (y = find_set(y))) return sz[x];
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = par[x], sz[x] += sz[y];
  return sz[x];
}

int longestConsecutiveDSU(vector<int>& nums) {
  int n = (int)nums.size();
  for (int i = 0; i < n; i++) make_set(i);  // Init DSU
  unordered_map<int, int> umap;
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (umap.find(nums[i]) != umap.end()) continue;  // Skip duplicate
    int curSz = sz[i];
    if (umap.find(nums[i] + 1) != umap.end()) {
      curSz = union_sets(i, umap[nums[i] + 1]);
    }
    if (umap.find(nums[i] - 1) != umap.end()) {
      curSz = union_sets(i, umap[nums[i] - 1]);
    }
    umap[nums[i]] = i;
    res = max(res, curSz);
  }
  return res;
}

int main() {
  vector<int> n1 = {100, 4, 200, 1, 3, 2};
  cout << "res1: " << longestConsecutive(n1) << endl;
  vector<int> n2 = {};
  cout << "res2: " << longestConsecutive(n2) << endl;
  cout << "res1 (DSU): " << longestConsecutiveDSU(n1) << endl;
  memset(par, 0, sizeof(par)), memset(sz, 0, sizeof(sz));  // Reset global vars
  cout << "res2 (DSU): " << longestConsecutiveDSU(n2) << endl;
  return 0;
}