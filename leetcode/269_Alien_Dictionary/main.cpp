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

void addEdge(vector<int> dictAdj[], int s, int d) { dictAdj[s].push_back(d); }

int toAlpOrder(char c) { return c - 'a'; }
char alpToChar(int c) { return c + 'a'; }

bool dfs(vector<int> dictAdj[], int V[], stack<char>& s, int c) {
  V[c] = 1;  // Mark as visiting
  for (int e : dictAdj[c]) {
    // Visit unvisited node
    if (V[e] == 0) {
      if (!dfs(dictAdj, V, s, e)) return false;
    }
    if (V[e] == 1) return false;  // Cycle detected
  }
  V[c] = 2;              // Mark as visited
  s.push(alpToChar(c));  // Push to topological order
  return true;
}

string alienOrder(vector<string>& words) {
  int n = (int)words.size();
  memset(V, 1, sizeof(V));  // Reset color to -1
  const int A = 26;
  vector<int> dictAdj[A];
  stack<char> s;
  string res;
  // Init visited vertices
  for (auto& w : words) {
    for (int i = 0; i < (int)w.size(); i++) {
      V[w[i] - 'a'] = 0;
    }
  }
  // Build adjacency list
  int prevSz = 0, curSz = 0;
  for (int i = 0; i < n; i++) {
    curSz = words[i].size();
    if (i > 0) {
      prevSz = words[i - 1].size();
    }
    bool isPrefix = true;
    for (int j = 0; j < curSz; j++) {
      if (i > 0 && j < prevSz && isPrefix && words[i][j] != words[i - 1][j]) {
        addEdge(dictAdj, toAlpOrder(words[i - 1][j]), toAlpOrder(words[i][j]));
        isPrefix = false;
      }
      if (isPrefix && j == curSz - 1 && curSz < prevSz) return "";
    }
  }
  // Topological sorting
  for (int i = 0; i < A; i++) {
    if (V[i] == 0 && !dfs(dictAdj, V, s, i)) return "";
  }
  while (!s.empty()) {
    res.push_back(s.top());
    s.pop();
  }
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