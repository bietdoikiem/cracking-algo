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

int V[26];

void addEdge(vector<int> adj[], int src, int dest) { adj[src].push_back(dest); }
int charToOrder(char c) { return c - 'a'; }
char orderToChar(int o) { return o + 'a'; }

bool dfs(vector<int> adj[], stack<char>& s, int c) {
  V[c] = 1;
  for (int e : adj[c]) {
    if (V[e] == 0 && !dfs(adj, s, e)) return false;
    if (V[e] == 1) return false;
  }
  V[c] = 2, s.push(orderToChar(c));
  return true;
}

string alienOrder(vector<string>& words) {
  string res;
  vector<int> adj[26];
  stack<char> s;
  memset(V, 1, sizeof(V));  // Set unused vertices to -1
  // Init existing vertices
  for (auto& w : words) {
    for (int i = 0; i < (int)w.size(); i++) V[charToOrder(w[i])] = 0;
  }
  // Build adjacency list
  int curSize = 0, prevSize = 0;
  for (int i = 0; i < (int)words.size(); i++) {
    curSize = (int)words[i].size();
    if (i > 0) prevSize = (int)words[i - 1].size();
    bool isPrefix = true;
    for (int j = 0; j < curSize; j++) {
      if (i > 0 && j < prevSize && isPrefix && words[i - 1][j] != words[i][j]) {
        addEdge(adj, charToOrder(words[i - 1][j]), charToOrder(words[i][j]));
        isPrefix = false;
      }
      if (isPrefix && j == curSize - 1 && curSize < prevSize) return "";
    }
  }
  // Topological sort
  for (int i = 0; i < 26; i++) {
    if (V[i] == 0 && !dfs(adj, s, i)) return "";
  }
  while (!s.empty()) res.push_back(s.top()), s.pop();
  return res;
}

int main() {
  vector<string> w1 = {"wrt", "wrf", "er", "ett", "rftt"};
  cout << "res1: " << alienOrder(w1) << endl;  // "wertf"
  vector<string> w2 = {"z", "x"};
  cout << "res2: " << alienOrder(w2) << endl;  // "zx"
  vector<string> w3 = {"z", "x", "z"};
  cout << "res3: " << alienOrder(w3) << endl;  // ""
  vector<string> w4 = {"noodle", "sang", "noo"};
  cout << "res4: " << alienOrder(w4) << endl;  // ""
  vector<string> w5 = {"aac", "aabb", "aaba"};
  cout << "res5: " << alienOrder(w5) << endl;  // "cba"
  vector<string> w6 = {"abc", "ab"};
  cout << "res6: " << alienOrder(w6) << endl;  // ""
  return 0;
}