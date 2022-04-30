#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

template <class T>
ostream& operator<<(ostream& os, vector<T> const& x) {
  os << "{ ";
  for (auto y : x) os << y << " ";
  return os << "}";
}

/***** SOLUTION BELOW HERE *****/
class UnionFind {
 public:
  vector<int> parent;
  vector<int> rank;

  void init(int n) {
    parent.clear(), parent.resize(n, 0);
    rank.clear(), rank.resize(n, 0);
  }

  void make_set(int v) {
    parent[v] = v;
    rank[v] = 1;
  }

  int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);  // Path compression
  }

  void union_sets(int x, int y) {
    if ((x = find_set(x)) == (y = find_set(y))) return;
    // Union by rank
    if (rank[x] < rank[y]) {
      swap(x, y);
    }
    parent[y] = x;
    rank[x] += rank[y];
  }
};

int main() {
  UnionFind ufSet;
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  int n = (int)nums.size();
  ufSet.init(n);
  for (int i = 0; i < n; i++) {
    ufSet.make_set(i);
  }
  ufSet.union_sets(1, 3);
  cout << ufSet.parent << endl;
  cout << ufSet.rank << endl;
  return 0;
}